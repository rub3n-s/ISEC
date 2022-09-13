#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fcntl.h>
#include <tchar.h>

#define MSG_SIZE 256
#define SEMAPHORE_UNIQUE _T("SEMAPHORE_UNIQUE")
#define EVENT_NAME _T("EVENT_NAME")
#define FILEMAPPING_NAME _T("FILEMAPPING")

DWORD WINAPI imprime(LPVOID lParam);

typedef struct {
	TCHAR message[MSG_SIZE];
	BOOL* stop;
} SharedMemory;

typedef struct {
	SharedMemory* sharedMemory;
	HANDLE hEvent;
	BOOL* stop;
} ThreadData;

int _tmain(int argc, TCHAR* argv[]) {
	HANDLE hSemaphoreUnique;
	HANDLE hFile;
	HANDLE hFileMapping;
	HANDLE hOpenFileMapping;
	HANDLE hEvent;
	BOOL stop = FALSE;
	SharedMemory *sharedMemory;

	ThreadData threadData;
	HANDLE hThread;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	// cria um semaforo unico para verificar se é o escritor
	hSemaphoreUnique = CreateSemaphore(
		NULL, 
		1,
		2,
		SEMAPHORE_UNIQUE
	);

	if (GetLastError() == ERROR_ALREADY_EXISTS) {
		_tprintf(_T("Semaforo ja existe. A ler da memoria partilhada...\n"));

		threadData.stop = &stop;

		hThread = CreateThread(
			NULL,
			0,
			imprime,
			&threadData,
			0,
			NULL
		);

		if (hThread == NULL) {
			_tprintf(_T("Erro a criar a thread: %d\n"), GetLastError());
			return -1;
		}

		WaitForSingleObject(hThread, INFINITE);

		_tprintf(_T("\nA encerrar...\n"));
	} 
	else {
		// cria o evento para avisar as threads
		hEvent = CreateEvent(
			NULL, 
			TRUE, 
			FALSE, 
			EVENT_NAME
		);

		_tprintf(_T("CreateFile\n"));
		//	1)	CreateFile
		/*hFile = CreateFile(
			FILEMAPPING_NAME,
			GENERIC_READ | GENERIC_WRITE,
			0,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		);

		if (hFile == INVALID_HANDLE_VALUE) {
			_tprintf(_T("Erro a criar o ficheiro: %d\n"), GetLastError());
			return -1;
		} */

		_tprintf(_T("\nCreateFileMapping\n"));
		//	2)	CreateFileMapping
		hFileMapping = CreateFileMapping(
			INVALID_HANDLE_VALUE,
			NULL,
			PAGE_READWRITE,
			0,
			sizeof(SharedMemory),
			FILEMAPPING_NAME
		);

		if (hFileMapping == INVALID_HANDLE_VALUE) {
			_tprintf(_T("Erro a criar o ficheiro: %d\n"), GetLastError());
			return -1;
		}

		_tprintf(_T("\nMapViewOfFile\n"));

		//	3)	MapViewOfFile
		sharedMemory = (SharedMemory*)MapViewOfFile(
			hFileMapping,
			FILE_MAP_ALL_ACCESS,
			0,
			0,
			0
		);

		if (sharedMemory == NULL) {
			_tprintf(_T("Error: MapViewOfFile (%d)"), GetLastError());
			CloseHandle(hFileMapping);
			//CloseHandle(hFile);
			return 1;
		}

		sharedMemory->stop = &stop;

		while (!stop) {
			_tprintf(_T("Enviar mensagem: "));
			_getts_s(sharedMemory->message, MSG_SIZE);
		
			if (_tcscmp(sharedMemory->message, _T("fim")) == 0) {
				stop = TRUE;
				_tprintf(_T("\nSolicitou encerrar...\n"));
			}

			SetEvent(hEvent);
		}

		UnmapViewOfFile(sharedMemory);

		CloseHandle(hFileMapping);
		//CloseHandle(hFile);
	}
	return 0;
}

DWORD WINAPI imprime(LPVOID lParam) {
	ThreadData* data = (ThreadData*)lParam;
	
	HANDLE hEvent;
	HANDLE hOpenFileMapping;

	// abrir o evento que foi criado no outro processo
	hEvent = OpenEvent(
		EVENT_ALL_ACCESS, 
		FALSE, 
		EVENT_NAME
	);

	if (hEvent == NULL) {
		_tprintf(_T("Erro a abrir o evento: %d\n"), GetLastError());
		*data->stop = TRUE;
	}

	while (!*data->stop) {
		if (WaitForSingleObject(hEvent, 1000) == WAIT_TIMEOUT)
			continue;

		ResetEvent(hEvent);

		hOpenFileMapping = OpenFileMapping(
			FILE_MAP_READ,
			FALSE,
			FILEMAPPING_NAME
		);

		if (hOpenFileMapping == NULL) {
			_tprintf(_T("Erro a abrir o FileMapping: %d\n"), GetLastError());
			*data->stop = TRUE;
			break;
		}

		data->sharedMemory = (SharedMemory*)MapViewOfFile(
			hOpenFileMapping,
			FILE_MAP_READ,
			0,
			0,
			sizeof(SharedMemory)
		);

		if (data->sharedMemory == NULL) {
			_tprintf(_T("Erro a criar a vista do FileMapping: %d\n"), GetLastError());
			*data->stop = TRUE;
			break;
		}

		_tprintf(_T("Mensagem recebida: %s\n"), data->sharedMemory->message);		
	}

	return 0;
}