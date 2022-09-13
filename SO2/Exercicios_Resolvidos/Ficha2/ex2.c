#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#define TAM 200

int _tmain(int argc, TCHAR *argv[]){
  HKEY hKey;
  TCHAR chave_nome[TAM], par_nome[TAM], par_valor[TAM], name[TAM];
  DWORD value = 5, getValue, tam = (DWORD)sizeof(DWORD), nameSize = sizeof(name);
  unsigned int i = 0;

  #ifdef UNICODE 
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stderr), _O_WTEXT);
  #endif

    //  1) Abre-se a chave para verificar se existe
    if (RegOpenKey(
        HKEY_CURRENT_USER,
        _T("Software\\Aula"),
        &hKey
    ) != ERROR_SUCCESS) {
        //  2) Se nao existir, cria-se uma chave obtendo um handle
        if (RegCreateKeyEx(
            HKEY_CURRENT_USER,
            _T("Software\\Aula"),
            NULL,
            NULL,
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS,
            NULL,
            &hKey,
            NULL
        ) != ERROR_SUCCESS) {
            _tprintf(_T("Não foi possivel cria a chave. Erro[%d]\n"), GetLastError());
            return -1;
        }

        _tprintf(_T("Chave criada com sucesso.\n"));
    }

    _tprintf(_T("Chave aberta com sucesso.\n"));

    //  3) Manipula-se a chave usando o handle obtido
    if(RegSetValueEx(
        hKey,
        _T("NOME"),
        0,
        REG_DWORD,
        &value,
        sizeof(value)
    ) != ERROR_SUCCESS) {
        _tprintf(_T("Não foi possivel modificar o valor da chave. Erro[%d]\n"), GetLastError());
        return -1;
    }

    _tprintf(_T("Chave modificada com sucesso.\n"));

    //  4) Obter o valor da chave
    if (RegQueryValueEx(
        hKey,
        _T("NOME"),
        0,
        NULL,
        &getValue,
        &tam
    ) != ERROR_SUCCESS) {
        _tprintf(_T("Não foi possivel obter o valor da chave. Erro[%d]\n"), GetLastError());
        return -1;
    }

    _tprintf(_T("Valor [%d] obtido com sucesso.\n"), getValue);

    //  5) Listar todos os valores 
    while (RegEnumValue(
        hKey,
        i,
        &name,
        &nameSize,
        NULL,
        NULL,
        NULL,
        NULL
    ) != ERROR_NO_MORE_ITEMS) {
        _tprintf(_T("Encontrou a chave com o nome [%s]\n"), name);
        i++;
    }

    //  6) Eliminar o valor
    if (RegDeleteKeyValue(
        HKEY_CURRENT_USER,
        _T("Software\\Aula"),
        _T("NOME")
    ) != ERROR_SUCCESS) {
        _tprintf(_T("Não foi possivel eliminar o valor da chave. Erro[%d]\n"), GetLastError());
        return -1;
    }

    _tprintf(_T("Valor eliminado com sucesso.\n"));

     //  7) Eliminar a chave
    if (RegDeleteKey(
        HKEY_CURRENT_USER,
        _T("Software\\Aula")
    ) != ERROR_SUCCESS) {
        _tprintf(_T("Não foi possivel eliminar a chave. Erro[%d]\n"), GetLastError());
        return -1;
    }
    
    _tprintf(_T("Chave eliminada com sucesso.\n"));

    //  8) Fecha-se o handle
    RegCloseKey(hKey);

   return 0;
}