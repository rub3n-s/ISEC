typedef struct {
    unsigned int ID;
    TCHAR username[16];
    TCHAR password[16];
    unsigned int saldo;
} cliente;

cliente clientes[3];  // são sempre três clientes.

// inserir dados fixos iniciais para os 3 clientes.

typedef struct {
   unsigned int tipo;       // 1 = depósito, 2 = levantamento
   unsigned int quantia;    // quanto foi levantado / depositado
   usigned int ID;          // quem fez a operação
} operacao;

operação historico[200];
unsigned int numOperacoes;

// este código é apenas uma sugestão para simplificar o problema
