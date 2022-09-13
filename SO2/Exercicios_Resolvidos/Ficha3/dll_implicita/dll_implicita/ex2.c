#include <tchar.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
----------------------------------------
			LIGACAO IMPLICITA
----------------------------------------

	1)	Definir um estrutura com o tipo de dados de retorno
	2)	Definir o nome da funcao pretendida como ponteiro
	3)	O tipo de dados de retorno da funcao
	4)	Apenas a DLL (.dll) deve estar na pasta DEBUG do projeto (mesma pasta que o executavel)

	Notas:
		-	HINSTANCE ou HMODULE (mesma coisa)
		-	alinea a), b), c) -> a dll nao e partilhada entre processos, logo o valor do factor e independente em cada um
*/

typedef double(*applyFactorFunc)(double);

int _tmain(int argc, TCHAR* argv[]) {
	HINSTANCE hLib;
	double val;

	// Atraves do GetProcAddress sera devolvido o endereco das variaveis correspondentes na DLL
	double* varAdd;
	applyFactorFunc procAdd;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	//	1)	Carregar a biblioteca
	hLib = LoadLibrary(_T("SO2_F3_DLL.dll"));		// localizacao: pasta DEBUG
	
	if (hLib == NULL) {
		_tprintf(_T("DLL nao encontrada. Erro[%d]"), GetLastError());
		return -1;
	}

	_tprintf(_T("DLL carregada com sucesso.\n"));

	//	2)	Obter o endereço dos dados que prentedemos dentro da DLL
	varAdd = (double*)GetProcAddress(hLib, "factor");	// handle da biblioteca e nome da variavel que prentendemos na DLL
	procAdd = (applyFactorFunc)GetProcAddress(hLib, "applyFactor");	// guarda o retorno da funcao applyFactor

	if (varAdd != NULL && procAdd != NULL) {
		do {
			_tprintf(_T("\nFactor > "));
			_tscanf_s(_T("%lf"), varAdd); // lf -> long float para doubles

			_tprintf(_T("\nValue > "));
			_tscanf_s(_T("%lf"), &val); // lf -> long float para doubles

			_tprintf(_T("\n%lf * %lf = %lf\n"), *varAdd, val, procAdd(val));
		} while (*varAdd != -1);

		// Libertar a biblioteca
		FreeLibrary(hLib);
	}

	return 0;
}