#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <windows.h>

#define FILEMAPPING_NAME _T("FILEMAPPING_NAME")
#define SEMAPHORE_UNIQUE _T("SEMAPHORE_UNIQUE")
#define SEMAPHORE_WRITE _T("SEMAPHORE_WRITE")
#define SEMAPHORE_READ _T("SEMAPHORE_READ")
#define MUTEX_NAME _T("MUTEX_NAME")
#define BUFFERCIRCULAR_SIZE 10

typedef struct {
	int id;
	int value;
} BufferCellStruct;

typedef struct {
	int nConsumers;
	int nProducers;
	int writeIndex;
	int readIndex;
	BufferCellStruct buffer[BUFFERCIRCULAR_SIZE];
} BufferCircular;

typedef struct {
	BufferCircular* sharedMemory;
	HANDLE hSemaphoreWrite;
	HANDLE hSemaphoreRead;
	HANDLE hMutex;
	BOOL* stop;
	int id;
} ThreadStruct;

int randomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

DWORD WINAPI consumerThread(LPVOID lParam) {
	ThreadStruct* data = (ThreadStruct*)lParam;
	BufferCellStruct cell;
	int counter = 0, sum = 0;

	while (!*data->stop) {
		// Esperamos por uma posicao para ler
		WaitForSingleObject(data->hSemaphoreRead, INFINITE);

		// Esperamos que o mutex esteja livre
		WaitForSingleObject(data->hMutex, INFINITE);

		// Vamos copiar da proxima posicao de leitura do buffer circular para a nossa variavel cell
		CopyMemory(&cell,
			&data->sharedMemory->buffer[data->sharedMemory->readIndex],
			sizeof(BufferCellStruct)
		);
		// Incrementamos a posicao de leitura para o proximo consumidor ler na posicao seguinte
		data->sharedMemory->readIndex++;

		// Se apos o incremento a posicao de leitura chegar ao fim, tenho de voltar ao inicio
		if (data->sharedMemory->readIndex == BUFFERCIRCULAR_SIZE) data->sharedMemory->readIndex = 0;

		// Libertamos o mutex
		ReleaseMutex(data->hMutex);

		// Libertamos o semoforo. Temos de libertar uma posicao de escrita
		ReleaseSemaphore(data->hSemaphoreWrite, 1, NULL);

		counter++;
		sum += cell.value;
		_tprintf(TEXT("C%i consumiu %i.\n"), data->id, cell.value);
	}

	_tprintf(TEXT("C%i consumiu %i items, somando um valor acumulado de %i.\n"), data->id, counter, sum);

	return 0;
}

DWORD WINAPI producerThread(LPVOID lParam) {
	ThreadStruct* data = (ThreadStruct*)lParam;
	BufferCellStruct cell;
	int counter = 0;

	while (!*data->stop) {
		cell.id = data->id;
		cell.value = randomInt(10, 99);

		// Esperamos por uma posicao para escrever
		WaitForSingleObject(data->hSemaphoreWrite, INFINITE);

		// Esperamos que o mutex esteja livre
		WaitForSingleObject(data->hMutex, INFINITE);

		// Vamos copiar a variavel cell para a memoria partilhada (para a posicao de escrita)
		CopyMemory(
			&data->sharedMemory->buffer[data->sharedMemory->writeIndex],
			&cell,
			sizeof(BufferCellStruct)
		);
		// Incrementamos a posicao de escrita para o proximo produtor escrever na posicao seguinte
		data->sharedMemory->writeIndex++;

		// Se apos o incremento a posicao de escrita chegar ao fim, tenho de voltar ao inicio
		if (data->sharedMemory->writeIndex == BUFFERCIRCULAR_SIZE) data->sharedMemory->writeIndex = 0;

		// Libertamos o mutex
		ReleaseMutex(data->hMutex);

		// Libertamos o semoforo. Temos de libertar uma posicao de leitura
		ReleaseSemaphore(data->hSemaphoreWrite, 1, NULL);

		counter++;
		_tprintf(TEXT("P%i produziu %i.\n"), data->id, cell.value);
		Sleep(randomInt(2, 4) * 1000);
	}

	_tprintf(TEXT("P%i produziu %i items.\n"), data->id, counter);

	return 0;
}

int _tmain(int argc, TCHAR* argv[]) {
	HANDLE hSemaphoreWrite;
	HANDLE hSemaphoreRead;
	HANDLE hFileMapping;

	HANDLE hThread;
	ThreadStruct tData;
	BufferCellStruct sharedMemory;
	BOOL firstProcess = FALSE;
	BOOL stop = FALSE;
	int op;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	srand((unsigned int)time(NULL));

	_tprintf(_T("1. Produtor\n2. Consumidor\n0. Sair\n\nOpcao: "));
	_tscanf(_T("%d"), op);

	//	---------------------------------------------------------------------
	//	1) criar o semaforo de escrita
	tData.hSemaphoreWrite = CreateSemaphore(
		NULL,
		0,
		BUFFERCIRCULAR_SIZE,
		SEMAPHORE_WRITE
	);

	if (tData.hSemaphoreWrite == NULL) {
		_tprintf(_T("Erro a criar o semaforo de escrita: %d\n"), GetLastError());
		return -1;
	}

	//	---------------------------------------------------------------------
	//	2) criar o semaforo do produtor
	tData.hSemaphoreRead = CreateSemaphore(
		NULL,
		0,
		0,
		SEMAPHORE_READ
	);

	if (tData.hSemaphoreRead == NULL) {
		_tprintf(_T("Erro a criar o semaforo de leitura: %d\n"), GetLastError());
		return -1;
	}

	//	---------------------------------------------------------------------
	//	3) criar o mutex
	tData.hMutex = CreateMutex(
		NULL,
		FALSE,
		MUTEX_NAME
	);

	if (tData.hMutex == NULL) {
		_tprintf(_T("Erro a criar o mutex: %d\n"), GetLastError());
		return -1;
	}

	//	---------------------------------------------------------------------
	//	4) Abrir o FileMapping para verificar se ja foi criado
	hFileMapping = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		FILEMAPPING_NAME
	);

	// caso nao exista...
	if (hFileMapping == NULL) {
		// indicar que e o primeiro processo
		firstProcess = TRUE;

		hFileMapping = CreateFileMapping(
			INVALID_HANDLE_VALUE,
			NULL,
			0,
			0,
			sizeof(BufferCircular),
			FILEMAPPING_NAME
		);

		if (hFileMapping == NULL) {
			_tprintf(_T("Erro a criar o FileMapping: %d\n"), GetLastError());
			return -1;
		}
	}

	// Mapeamos o bloco de memoria para o espaco de enderacamento do nosso processo
	tData.sharedMemory = MapViewOfFile(
		hFileMapping,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		0
	);

	if (tData.sharedMemory == NULL) {
		_tprintf(_T("Erro a mapear o FileMapping: %d\n"), GetLastError());
		return -1;
	}

	if (firstProcess == TRUE) {
		tData.sharedMemory->nConsumers = 0;
		tData.sharedMemory->nProducers = 0;
		tData.sharedMemory->writeIndex = 0;
		tData.sharedMemory->readIndex = 0;
	}

	tData.stop = &stop;

	// verifica qual a opcao para lancar a thread
	switch (op) {
	case 1:			// produtor
		// temos de usar o mutex para aumentar o nProducers para termos os ids corretos
		WaitForSingleObject(tData.hMutex, INFINITE);
		tData.sharedMemory->nProducers++;
		tData.id = tData.sharedMemory->nProducers;
		ReleaseMutex(tData.hMutex);

		hThread = CreateThread(
			NULL,
			0,
			producerThread,
			&tData,
			0,
			NULL
		);

		break;
	case 2:			// consumidor
		// Temos de usar o mutex para aumentar o nConsumers para termos os ids corretos
		WaitForSingleObject(tData.hMutex, INFINITE);
		tData.sharedMemory->nConsumers++;
		tData.id = tData.sharedMemory->nConsumers;
		ReleaseMutex(tData.hMutex);

		hThread = CreateThread(
			NULL,
			0,
			consumerThread,
			&tData,
			0,
			NULL
		);

		break;
	default:
		_tprintf(_T("\nA encerrar o programa...\n"));
	}

	if (hThread == NULL) {
		_tprintf(_T("Erro a criar a thread: %d\n"), GetLastError());
		Close(hFileMapping);
		UnmapViewOfFile(tData.sharedMemory);
		return -1;
	}

	fflush(stdin);
	fflush(stdout);

	_tprintf(TEXT("Escreva qualquer coisa para sair...\n"));
	_tscanf_s(TEXT("%i"), &op);
	tData.stop = TRUE;

	// Esperar que a thread termine
	WaitForSingleObject(hThread, INFINITE);

	UnmapViewOfFile(tData.sharedMemory);

	return 0;
}

DWORD WINAPI consumerThread(LPVOID lParam) {
	ThreadStruct* data = (ThreadStruct*)lParam;
	BufferCellStruct cell;
	int counter = 0, sum = 0;

	while (!*data->stop) {
		// Esperamos por uma posicao para ler
		WaitForSingleObject(data->hSemaphoreRead, INFINITE);

		// Esperamos que o mutex esteja livre
		WaitForSingleObject(data->hMutex, INFINITE);

		// Vamos copiar da proxima posicao de leitura do buffer circular para a nossa variavel cell
		CopyMemory(&cell,
			&data->sharedMemory->buffer[data->sharedMemory->readIndex],
			sizeof(BufferCellStruct)
		);
		// Incrementamos a posicao de leitura para o proximo consumidor ler na posicao seguinte
		data->sharedMemory->readIndex++;

		// Se apos o incremento a posicao de leitura chegar ao fim, tenho de voltar ao inicio
		if (data->sharedMemory->readIndex == BUFFERCIRCULAR_SIZE) data->sharedMemory->readIndex = 0;

		// Libertamos o mutex
		ReleaseMutex(data->hMutex);

		// Libertamos o semoforo. Temos de libertar uma posicao de escrita
		ReleaseSemaphore(data->hSemaphoreWrite, 1, NULL);

		counter++;
		sum += cell.value;
		_tprintf(TEXT("C%i consumiu %i.\n"), data->id, cell.value);
	}

	_tprintf(TEXT("C%i consumiu %i items, somando um valor acumulado de %i.\n"), data->id, counter, sum);

	return 0;
}