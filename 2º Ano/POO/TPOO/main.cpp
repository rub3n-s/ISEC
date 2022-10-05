

#include <iostream>
#include "Comando.h"
int main()
{
	Mundo m;               //Objeto mundo
	Comando cmd(m);        //Objeto comando criado com referencia a objeto mundo
	cmd.configuracao();
}

