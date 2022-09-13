#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>

#define LIM_INF 1
#define LIM_SUP 1000
#define MAX_THREADS 2
#define MAX_SIZE 256

DWORD WINAPI threadSoma(LPVOID lParam);
DWORD WINAPI typeToExit(LPVOID lParam);

typedef struct {
	int* soma;
	int op;
	int limSup;
	int limInf;
	HANDLE hMutex;
	BOOL *stop;
} ThreadStruct;

int _tmain(int argc, TCHAR* argv[]) {
	ThreadStruct data[MAX_THREADS];
	BOOL stop = FALSE;
	HANDLE hThread[MAX_THREADS + 1];
	HANDLE hMutex;
	DWORD ret;
	int somaPares = 0, somaPrimos = 0;

	hMutex = CreateMutex(NULL, FALSE, NULL);

	for (int i = 0; i < MAX_THREADS; i++) {
		if (i == 0) {
			data[i].soma = &somaPares;
			data[i].limInf = 500;
			data[i].limSup = 3000;
		}
		else {
			data[i].soma = &somaPrimos;
			data[i].limInf = 700;
			data[i].limSup = 7000;
		}
		data[i].stop = &stop;
		data[i].hMutex = hMutex;
		data[i].op = i;

		hThread[i] = CreateThread(
			NULL,
			0,
			threadSoma,
			&data[i],
			0,
			NULL
		);

		if (hThread[i] == NULL) {
			_tprintf(_T("[CreateThread] Erro a criar a thread: %d"), GetLastError());
			return -1;
		}
	}	

	// thread que fica a espera de um input para terminar o programa
	hThread[2] = CreateThread(
		NULL,
		0,
		typeToExit,
		&stop,
		0,
		NULL
	);

	if (hThread[2] == NULL) {
		_tprintf(_T("[CreateThread] Erro a criar a thread: %d"), GetLastError());
		return -1;
	}

	// 1ª OPCAO) WaitForSingleObject
	//WaitForSingleObject(hThread[0], INFINITE);
	//WaitForSingleObject(hThread[1], INFINITE);

	// 2ª OPCAO) WaitForMultipleObjects, apenas desbloqueia quando ambas terminaram	
	//WaitForMultipleObjects(MAX_THREADS, hThread, TRUE, INFINITE);

	//_tprintf(_T("\nResultados:"));
	//_tprintf(_T("\nSoma Pares: %d"), somaPares);
	//_tprintf(_T("\nSoma Primos: %d\n"), somaPrimos);

	// 3ª OPCAO) WaitForMultipleObjects, espera que ambas terminem mas desbloqueia assim que uma terminar
	int count = MAX_THREADS;
	do {
		ret = WaitForMultipleObjects(
			count,
			hThread, // ponteiro para o primeiro elemento do array
			FALSE, // true -> apenas quando ambas terminarem, false -> desbloqueia assim que 1 das threads terminar 
			5000 // configurar TIMEOUT para a cada 5 segundos mostrar uma mensagem (alinea g)
		);

		if (ret == WAIT_TIMEOUT) {
			// a cada 5 segundos vai ter um TIMEOUT
			_tprintf(_T("\nTIMEOUT"));
		}
		else {
			int idx = ret - WAIT_OBJECT_0;

			switch (idx) {
				case 0:
					_tprintf(_T("\nSoma Pares: %d"), somaPares);
					break;
				case 1:
					_tprintf(_T("\nSoma Primos: %d"), somaPrimos);
					break;
				default:
					_tprintf(_T("\nA terminar programa ..."));
					return 0;
			}

			count--;

			for (int i = 0; i < count; i++)
				hThread[i] = hThread[i + 1];
		}
	} while (count > 0);

	return 0;
}

DWORD WINAPI threadSoma(LPVOID lParam) {
	ThreadStruct* data = (ThreadStruct*)lParam;
	int counterPrimos = 0, counterPares = 0;

	switch (data->op) {
		case 0:		// soma pares
			_tprintf(_T("\nTHREAD PARES INICIOU ..."));
			for (int i = LIM_INF; i <= LIM_SUP; i++) {
				if (counterPares == 200) {
					Sleep(1000);
					counterPares = 0;
				}				
				if (i % 2 == 0) {
					WaitForSingleObject(data->hMutex, INFINITE);
					*data->soma += i;
					ReleaseMutex(data->hMutex);
					counterPares++;
				}
				
			}
			break;
		case 1:		// soma primos
			_tprintf(_T("\nTHREAD PRIMOS INICIOU ..."));
			for (int i = LIM_INF; i <= LIM_SUP; i++) {
				if (counterPrimos == 15) {
					Sleep(1000);
					counterPrimos = 0;
				}				
				if (LIM_SUP % i == 0) {
					WaitForSingleObject(data->hMutex, INFINITE);
					*data->soma += i;
					ReleaseMutex(data->hMutex);
					counterPrimos++;
				}				
			}
			break;
	}

	return 0;
}

DWORD WINAPI typeToExit(LPVOID lParam) {
	TCHAR buffer[MAX_SIZE];
	BOOL* data = (BOOL*)lParam;
	while (!*data) {
		_getts_s(buffer, MAX_SIZE);
		*data = TRUE;
	}
	return (0);
}