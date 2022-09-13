#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

#define PIPE_NAME _T("\\\\.\\pipe\\teste")
#define MAX_SIZE 256
#define MAX_CLIENTS 5

typedef struct {
    HANDLE hPipe; 
    OVERLAPPED overlap;
    BOOL active;
} PipeStruct;

typedef struct {
    PipeStruct pipe[MAX_CLIENTS];
    HANDLE hMutex;
    BOOL* stop;
} ThreadData;

DWORD WINAPI criarPipes(LPVOID lParam) {
    ThreadData* data = (ThreadData*)lParam;
    TCHAR buffer[MAX_SIZE];
    DWORD nBytes;
    HANDLE hEvents[MAX_CLIENTS];
    HANDLE hThreadRead[MAX_CLIENTS];
    BOOL ret;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        _tprintf(_T("[ESCRITOR] Criar a copia [%d] do pipe '%s' ... (CreateNamedPipe)\n"), i, PIPE_NAME);

        //  1) Criar o evento
        hEvents[i] = CreateEvent(
            NULL,
            TRUE,
            FALSE,
            NULL
        );

        if (hEvents[i] == NULL) {
            _tprintf(_T("Erro a criar o evento.\n"));
            return -1;
        }

        //  2) Criar o namedPipe
        data->pipe[i].hPipe = CreateNamedPipe(
            PIPE_NAME,              // nome do pipe
            PIPE_ACCESS_OUTBOUND | FILE_FLAG_OVERLAPPED,   // sentido da informacao, OUTBOUND - envia informacao (escreve)
            PIPE_WAIT | PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE,
            MAX_CLIENTS,
            sizeof(buffer), sizeof(buffer),
            1000,
            NULL
        );

        if (data->pipe[i].hPipe == INVALID_HANDLE_VALUE) {
            _tprintf(_T("[ERRO] Criar Named Pipe! (CreateNamedPipe)"));
            exit(-1);
        }

        // overlap pode vir com lixo dentro associado a ponteiro
        // boa pratica, que deve ser sempre feita e limpar para garantir que nao ha lixo
        ZeroMemory(&data->pipe[i].overlap, sizeof(data->pipe[i].overlap));
        data->pipe[i].active = FALSE;
        data->pipe[i].overlap.hEvent = hEvents[i];

        //  3) Abrir a conexao
        if (ConnectNamedPipe(data->pipe[i].hPipe, &data->pipe[i].overlap)) {
            _tprintf(_T("[ERRO] Ligacao ao leitor! (ConnectNamedPipe\n"));
            exit(-1);
        }
    }

    while (!*data->stop) {
        _tprintf(_T("[ESCRITOR] Esperar ligacao de um leitor... (ConnectNamedPipe)\n"));

        // Esperar pelos eventos
        ret = WaitForMultipleObjects(MAX_CLIENTS, hEvents, TRUE, INFINITE);
        
        // obter o indice
        int k = ret - WAIT_OBJECT_0;

        if (k >= 0 && k < MAX_CLIENTS) {
            _tprintf(_T("\n[SERVIDOR] Cliente %d chegou...\n"), k);

            if (GetOverlappedResult(data->pipe[k].hPipe, &data->pipe[k].overlap, &nBytes, FALSE)) {
                ResetEvent(hEvents[k]);

                WaitForSingleObject(data->hMutex, INFINITE);

                if (!data->pipe[k].active) {
                    hThreadRead[k] = CreateThread(
                        NULL,
                        0,
                        ler,
                        &data,
                        0,
                        NULL
                    );

                    if (hThreadRead == NULL) {
                        _tprintf(_T("Erro a criar a thread de leitura"));
                        return -1;
                    }
                }
                ReleaseMutex(data->hMutex, INFINITE);
                
            }
        }

        _tprintf(_T("[ESCRITOR] Desligar o pipe (DisconnectNamedPipe)\n"));

        if (!DisconnectNamedPipe(data->pipe[k].hPipe)) {
            _tprintf(_T("[ERRO] Desligar o pipe! (DisconnectNamedPipe)"));
            exit(-1);
        }
    }

    return 0;
}

DWORD WINAPI escrever(LPVOID lParam) {
    ThreadData* data = (ThreadData*)lParam;
    TCHAR buffer[MAX_SIZE];
    DWORD nBytes;

    while (!*data->stop) {
        do {
            _tprintf(_T("[ESCRITOR] Frase: "));
            _fgetts(buffer, 256, stdin);
            buffer[_tcslen(buffer) - 1] = '\0';

            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (!WriteFile(data->pipe[i].hPipe, buffer, (DWORD)_tcslen(buffer) * sizeof(TCHAR), &nBytes, NULL)) {
                    _tprintf(_T("[ERRO] Escrever no pipe! (WriteFile)\n"));
                    exit(-1);
                }
            }

            _tprintf(_T("[ESCRITOR] Enviei %d bytes ao leitor... (WriteFile)\n"), nBytes);
        } while (_tcscmp(buffer, _T("fim")));
    }

    return 0;
}

int _tmain(int argc, LPTSTR argv[]) {
    TCHAR buf[256];
    ThreadData data;
    BOOL stop = FALSE;

#ifdef UNICODE
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stderr), _O_WTEXT);
#endif

    data.stop = &stop;
    data.hMutex = CreateMutex(NULL, FALSE, NULL);

    HANDLE hThreadPipe = CreateThread(
        NULL,
        0,
        criarPipes,
        &data,
        0,
        NULL
    );

    if (hThreadPipe == NULL) {
        _tprintf(_T("[ERRO] Criar a thread!\n"));
        return -1;
    }

    WaitForSingleObject(hThreadPipe,INFINITE);

    Sleep(2000);
    
    return 0;
}
