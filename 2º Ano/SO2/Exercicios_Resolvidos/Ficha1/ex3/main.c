#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <fcntl.h>

#define MAX 256

int _tmain(int argc,  char* argv[]) {
	TCHAR str[MAX], frase[MAX] = _T("Olá mundo!");

#ifdef UNICODE
	setmode(_fileno(stdin), _O_WTEXT);
	setmode(_fileno(stdout), _O_WTEXT);
#endif

	do {
		_tprintf(_T("Frase: %s. Tamanho: %d \n"), frase, _tcslen(frase));
		fflush(stdin);
		_tprintf(_T("String: "));
		_tscanf_s(_T("%255"), str, MAX);
	} while (_tcscmp(str, "fim") != 0);

	return 0;
}