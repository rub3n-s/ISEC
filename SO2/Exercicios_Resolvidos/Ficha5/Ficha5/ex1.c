#include <windows.h>
#include <tchar.h>
#include <math.h>

#include <stdio.h>
#include <fcntl.h> 
#include <io.h>


// funcionalidade relacionada com temporização

static double PerfCounterFreq; // n ticks por seg.

void initClock() {
	LARGE_INTEGER aux;
	if (!QueryPerformanceFrequency(&aux))
		_tprintf(TEXT("\nSorry - No can do em QueryPerfFreq\n"));
	PerfCounterFreq = (double)(aux.QuadPart); // / 1000.0;
	_tprintf(TEXT("\nTicks por sec.%f\n"), PerfCounterFreq);
}

__int64 startClock() {
	LARGE_INTEGER aux;
	QueryPerformanceCounter(&aux);
	return aux.QuadPart;
}

double stopClock(__int64 from) {
	LARGE_INTEGER aux;
	QueryPerformanceCounter(&aux);
	return (double)(aux.QuadPart - from) / PerfCounterFreq;
}

// estrutura de dados para controlar as threads

typedef struct {
	int limInf;
	int limSup;
	int *contador;
	HANDLE hMutex;
	HANDLE hEvent;
	LPCRITICAL_SECTION criticalSection;
} TDados;

// função da(s) thread(s)
DWORD WINAPI threadFunc(LPVOID lParam);

// número * máximo * de threads
// podem (e devem) ser menos
#define MAX_THREADS 20

int _tmain(int argc, TCHAR * argv[]) {	
	// matriz de handles das threads
	HANDLE hThreads[MAX_THREADS];
	
	// handle para o mutex
	HANDLE hMutex;

	// handle para evento de notificao de que a thread terminou
	HANDLE hEvent;

	// critical section
	CRITICAL_SECTION criticalSection;

	// Matriz de dados para as threads;
	TDados tdados[MAX_THREADS];
	
	// número efectivo de threads
	int numthreads;
	
	// limite superior
	unsigned int limsup;

	// variáveis para cronómetro
	__int64 clockticks;
	double duracao;

	unsigned int range;
	unsigned int inter;

	int multiplos3 = 0;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif 

	initClock();

	// Inicializar o SpinCount
	InitializeCriticalSectionAndSpinCount(
		&criticalSection, 
		500
	);

	_tprintf(TEXT("\nLimite sup. -> "));
	_tscanf_s(TEXT("%u"), &limsup);

	_tprintf(TEXT("\nNum threads -> "));
	_tscanf_s(TEXT("%u"), &numthreads);
	
	if (numthreads > MAX_THREADS)
		numthreads = MAX_THREADS;

	// obter o intervalo
	int intervalo = limsup / numthreads;

	// cria o mutex
	hMutex = CreateMutex(NULL, FALSE, NULL);
	
	// cria o evento
	hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	
	for (int i = 0; i < numthreads; i++) {
		// definir o limite superir e inferior de cada thread
		tdados[i].limInf = intervalo * i + 1;
		tdados[i].limSup = intervalo + intervalo * i;
		tdados[i].hMutex = hMutex;
		tdados[i].hEvent = hEvent;
		tdados[i].criticalSection = &criticalSection;
		tdados[i].contador = &multiplos3;		

		hThreads[i] = CreateThread(
			NULL,
			0,
			threadFunc,
			&tdados[i],
			CREATE_SUSPENDED,		// substituir por 0 caso nao seja para começarem suspensas
			NULL
		);

		if (hThreads[i] == NULL) {
			_tprintf(_T("[CreateThread] Erro a criar a thread: %d"), GetLastError());
			return -1;
		}
	}

	for (int i = 0; i < numthreads; i++)
		ResumeThread(hThreads[i]);

	// 1ª OPCAO) WaitForSingleObject
	/*for (int i = 0; i < numthreads; i++)
		WaitForSingleObject(hThreads[i], INFINITE);

	// 2ª OPCAO) WaitForMultipleObjects - Espera que todas acabem
	WaitForMultipleObjects(numthreads, hThreads, TRUE, INFINITE);*/

	// 3ª OPCAO) WaitForMultipleObjects - Desbloqueia sempre que uma thread termina
	int counter = numthreads, idx = 0;
	DWORD ret;
	do {
		ret = WaitForMultipleObjects(counter, hThreads, FALSE, 5000);

		idx = ret - WAIT_OBJECT_0;

		counter--;

		for (int i = 0; i < counter; i++)
			hThreads[i] = hThreads[i + 1];

		SetEvent(hEvent);
	} while (counter > 0);

	clockticks = startClock();

	// FAZER aguarda / controla as threads 
	//       manda as threads parar

	duracao = stopClock(clockticks);
	_tprintf(TEXT("\nSegundos=%f\n"), duracao);

	// FAZER apresenta resultados
	_tprintf(TEXT("\nContador=%d\n"), multiplos3);

	// Cód. ref. para aguardar por uma tecla – caso faça falta
	// _tprintf(TEXT("\nCarregue numa tecla"));
	// _gettch();

	return 0;
}

DWORD WINAPI threadFunc(LPVOID lParam) {
	TDados* dados = (TDados*)lParam;
	_tprintf(_T("A iniciar thread: [%d] a [%d]\n"), dados->limInf, dados->limSup);
	for (int i = dados->limInf; i < dados->limSup; i++) {
		if (i % 3 == 0) {
			EnterCriticalSection(dados->criticalSection);
			
			//WaitForSingleObject(dados->hMutex, INFINITE);
			(*dados->contador)++;
			//ReleaseMutex(dados->hMutex);

			LeaveCriticalSection(dados->criticalSection);
		}
	}

	// Fica a espera do SetEvent para desbloquear
	WaitForSingleObject(dados->hEvent, INFINITE);
	ResetEvent(dados->hEvent);
	_tprintf(_T("A terminar thread: [%d] a [%d]\n"), dados->limInf, dados->limSup);
	return 0;
}