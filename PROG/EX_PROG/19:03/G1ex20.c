#include<string.h>
#include<stdio.h>
#include<locale.h>
#include<windows.h>
#define NUM_MSG 24
void traduz_mes(char *ptr[][2], char mes[10], int n_lin)
{
int i;
    for(i=0; i<n_lin; i++)
    {
        if(stricmp(ptr[i][0],mes)==0)
        {
            puts(ptr[i][1]);
            break;

        }
    }
}
int main()
{
    setlocale(LC_ALL,"portuguese");
    char *ptr[12][2]= {{"janeiro", "january"}, {"fevereiro","february"},{"março","march"}, {"abril","april"},
    {"maio","may"},{"junho","june"},{"julho","july"},{"agosto","august"}, {"setembro","september"},
    {"outubro","october"},{"novembro","november"},{"dezembro","december"} };
    char mes[10];
    unsigned int cp = 1252;
    printf("mês: ");
    SetConsoleCP(cp);
    gets(mes);
    traduz_mes(ptr,mes,12);
}
