#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fcntl.h>
#include <tchar.h>

#define LETTERS 26
#define FILE_NAME _T("alfabeto.txt")
int _tmain(int argc, TCHAR* argv[]) {
	HANDLE hFile;
	HANDLE hFileMapping;

	char* buffer, aux;
	TCHAR auxT;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	buffer = malloc(sizeof(TCHAR) * LETTERS);

	_tprintf(_T("File Inverter - 8 bits\n"));

	_tprintf(_T("CreateFile\n"));

	//	1)	CreateFile
	hFile = CreateFile(
		FILE_NAME,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (hFile == INVALID_HANDLE_VALUE) {
		_tprintf(_T("Erro a criar o ficheiro: %s\n"), GetLastError());
		return -1;
	}

	_tprintf(_T("\nCreateFileMapping\n"));

	//	2)	CreateFileMapping
	hFileMapping = CreateFileMapping(
		hFile,
		NULL,
		PAGE_READWRITE,
		0,	
		LETTERS,	// 26 bytes -> carateres do tipo char (classico), cada um ocupa 1 byte
		NULL
	);

	if (hFileMapping == INVALID_HANDLE_VALUE) {
		_tprintf(_T("Erro a criar o ficheiro: %d\n"), GetLastError());
		return -1;
	}

	_tprintf(_T("\nMapViewOfFile\n"));

	//	3)	MapViewOfFile
	buffer = (char*)MapViewOfFile(
		hFileMapping,
		FILE_MAP_READ | FILE_MAP_WRITE,
		0,
		0,
		LETTERS
	);

	if (buffer == NULL) {
		_tprintf(_T("Error: MapViewOfFile (%d)"), GetLastError());
		CloseHandle(hFileMapping);
		CloseHandle(hFile);
		return 1;
	}

	//	4)	Imprimir o array obtido 
	for (int i = 0; i < LETTERS; i++)
		_tprintf(_T("%c"), buffer[i]);
	_tprintf(_T("\n"));

	//	5)	Inverter
	for (unsigned int i = 0; i < LETTERS / 2; i++) {
		aux = buffer[i];
		buffer[i] = buffer[LETTERS - 1 - i];
		buffer[LETTERS - 1 - i] = aux;
	}

	_tprintf(_T("\nShowing inverted file contents\n"));
	for (unsigned int i = 0; i < LETTERS; i++) {
		auxT = buffer[i];
		_tprintf(_T("%c"), auxT);
	}

	_tprintf(_T("\nDONE\n"));

	UnmapViewOfFile(buffer);

	CloseHandle(hFileMapping);
	CloseHandle(hFile);
	return 0;
}