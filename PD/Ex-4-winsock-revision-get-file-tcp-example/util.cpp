#include "util.h"

/*______________________________ writeN _______________________________________
Escreve n bytes no socket em causa. Devolve o numero de bytes escritos ou
SOCKET_ERROR caso ocorra um erro ou 0 caso a ligacao seja encerrada.
______________________________________________________________________________*/

int writeN(SOCKET sock,char * buffer,int nbytes){

	int nLeft,nWritten = 0;

	nLeft=nbytes;

	while(nLeft>0){

		nWritten=send(sock,buffer,nLeft, 0);

		if(nWritten == 0 || nWritten == SOCKET_ERROR)
			return(nWritten); /*Erro ou End Of File (0) */

		nLeft-=nWritten;
		buffer+=nWritten;

	}

	return(nWritten);
}

/*______________________________ readLine _______________________________________
Le uma linha de texto (conjunto de caracteres terminados em '\n') 
no socket em causa.

Regressa quando encontra o caractere '\n', quando o buffer fica cheio,
quando a ligacao TCP e' encerrada ou quando quando ocorre um erro.

Devolve o numero de bytes lidos ou SOCKET_ERROR caso ocorra um erro.
______________________________________________________________________________*/

int readLine(SOCKET sock,char * buffer,int nbytes){

	int nread;

	int i;
	char c;

	i = 0;

	while(i < nbytes-1){ /* -1 para deixar espaco ao '\0' */
		
		nread = recv(sock, &c, sizeof(c), 0);
	
		if(nread == SOCKET_ERROR)
			return nread; /*Erro*/

		if(nread == 0)
			break; /*End Of File*/

		if(c == '\r')
			continue; /*Ignora o '\r' numa sequencia "\r\n"*/
		
		if(c == '\n')
			break; /*Final da linha*/

		buffer[i++] = c;
	}
	
	buffer[i] = '\0';
	
	return i;
}
