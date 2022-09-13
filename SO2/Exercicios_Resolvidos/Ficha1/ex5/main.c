#include <windows.h> 
#include <tchar.h> 
#include <fcntl.h> 
#include <io.h>
#include <stdio.h>

#define MAX 256

int _tmain(int argc, LPTSTR argv[]) {
	TCHAR moduleName[MAX];

#ifdef UNICODE 
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif 


	// alinea a)
	GetModuleFileNameW(NULL, moduleName, MAX);
	_tprintf(_T("Nome do meu executavel: %s\n"), moduleName);

	//alinea b)

	PROCESS_INFORMATION pi;
	STARTUPINFO si;

	do {
		fflush(stdin);
		_tprintf(_T("FIM - para sair\n"));
		_fgetts(moduleName, MAX, stdin);

		moduleName[_tcslen(moduleName) - 1] = '\0';

		if (!_tcscmp("FIM", moduleName)) {
			ZeroMemory(&si, sizeof(STARTUPINFO));
			si.cb = sizeof(STARTUPINFO);

			if (CreateProcessW(
				NULL,	// caminho para o executavel
				moduleName, // nome do executavel
				NULL,	// atributo de seguran�a
				NULL,	// atributo de seguran�a
				0,	// handles
				0,	// flgs para prioridades
				NULL, // var de ambiente
				NULL,	// dir atual
				&si,	// configuracao de arranque do processo
				&pi	// onde fica informa�ao do process (PID e HANDLE)
			)) {
				_tprintf(TEXT("Programa a ser lançado.\n"));
			}
			else {
				_tprintf(TEXT("Ocorreu um erro.\n"));
			}

			// 5 - d) WaitForSingleObject
			// INFINITE - at� o processo terminar nao pede outro objeto (tempo indefinido)
			WaitForSingleObject(pi.hProcess, INFINITE);
		}
	} while (_tccmp("FIM", moduleName) != 0);
	return 0;

}