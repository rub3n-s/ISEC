#include <tchar.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "SO2_F3_DLL.h"

/*
----------------------------------------
			LIGACAO EXPLICITA
----------------------------------------

	1)	Incluir o .h na pasta mesma pasta que o ficheiro do main
	2)	Incluir o ficheiro .dll e .lib na pasta DEBUG (mesma que os executaveis)
	3)	Dizer onde tem de procurar o .lib
	4)	Properties -> Linker -> Input -> Copiar o nome do ficheiro.lib (adicionar como um dependencia)
	5)	Linker -> General -> Additional Library Directories	

	Notas:
		-	.lib -> permite usar a dll como um biblioteca estatica
		-	$(OutDir) -> atalho que permite obter o caminho ate a pasta pretendida em qualquer maquina
*/

int _tmain(int argc, TCHAR* argv[]) {
	double val;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	do {
		_tprintf(_T("\nFactor > "));
		_tscanf_s(_T("%lf"), &factor); // lf -> long float para doubles

		_tprintf(_T("\nValue > "));
		_tscanf_s(_T("%lf"), &val); // lf -> long float para doubles

		_tprintf(_T("\n%lf * %lf = %lf\n"), factor, val, applyFactor(val));
	} while (factor != -1);

	return 0;
}