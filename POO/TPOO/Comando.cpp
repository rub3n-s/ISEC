#include "Comando.h"

initializer_list <string> listaComandos = {
	"carrega",
	"cria"
};

initializer_list <string> listaContinentes = {
"planicie", 
"montanha",
"fortaleza",
"mina",
"duna",
"castelo"
};

vector <string> listaCmd(listaComandos);
vector <string> listaCon(listaContinentes);

Comando::Comando(Mundo& m) {
	mundo = &m;
}

bool Comando::verificaCmd(string cmd) {
	for (int i = 0; i < listaCmd.size(); i++)
	{
		if (listaCmd[i] == cmd)
		{
			return true;
			break;
		}
	}
	return false;
}

bool Comando::verificaCon(string c) {
	for (int i = 0; i < listaCon.size(); i++)
	{
		if (listaCon[i] == c)
		{
			return true;
			break;
		}
	}
	return false;
}
bool Comando::verificaInt(string in,int &cri) {
	if (in == " ") {
		return false;
	}
	  stringstream ss(in);
	    if (!(ss >> cri)) {
		return false;
		}
		else if (cri <= 0) {
			return false;
		}
		return true;
}

bool Comando::carregaFicheiro(string f) {
	ifstream fich(f);
	string comandoP;
	if (fich) {
		string str;
		while (getline(fich, str)) {
			istringstream is(str);
			is >> comandoP;
			cout << comandoP;
			if (comandoP == "cria") {
				if (!criaCmd(is)) {
				  return false;
				}
			}
			
		}
		fich.close();
	}
	else {
		cout << "Ficheiro nao abriu" << endl;
		return false;
	}
	return true;
}

bool Comando::criaCmd(istringstream& iss) {
	string arg1;
	string arg2;
	int criados;
	iss >> arg1 >> arg2;
	if (verificaInt(arg2, criados)) {
		if (verificaCon(arg1)) {
			mundo->recebeContinente(arg1, criados);
			return true;
		}
		else if (arg1 == "refugio" || arg1 == "pescaria") {
			mundo->recebeIlha(arg1, criados);
			return true;
		}
		else {
			cout << "Nenhum territorio" << endl;
			return false;
		}
	}
	else {
		cout << "Tem de inserir um numero positivo" << endl;
		return false;
	}
}




void Comando::configuracao() {
	
	string comando, comandoP;
	istringstream iss;
	string arg1, arg2;          //argumentos para separaçao
	
	do {
		int criados;
		cin.clear();
		iss.clear();
		comandoP.clear();
		arg1.clear();
		arg2.clear();
		cout << "Comando: " << endl;
		getline(cin, comando);
		iss.str(comando);
		iss >> comandoP;
		if (comandoP != "carrega" && comandoP != "cria") {
			cout << "Comando invalido apenas comandos carrega e cria nesta fase" << endl;
		}
	    if (comandoP == "carrega") {
			    iss >> arg1;              //ficheiro de texto
				if (carregaFicheiro(arg1)) {
					cout << mundo->listaContinente() << endl;
					cout << mundo->listaIlha() << endl;
					cout << "Sucesso" << endl;
				}
		}
		if (comandoP == "cria") {
			if (criaCmd(iss)) {
				cout << "Sucesso" << endl;
			}
			else {
				cout << "InSucesso" << endl;
			}
            cout << mundo->listaContinente() << endl;
			cout << mundo->listaIlha() << endl;
		}
	} while (1);
}


