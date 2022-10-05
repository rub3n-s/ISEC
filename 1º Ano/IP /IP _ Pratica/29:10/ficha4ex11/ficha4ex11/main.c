//
//  main.c
//  ficha4ex11
//
//  Created by Rúben Mendes Santos on 29/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int faltas, aprovados = 0, reprovados = 0, nota_negativa = 0;
    float prova1, prova2, nota = 0.0, soma_notas = 0.0;
//    const int NUM_ALUNOS = 12, NUM_AULAS = 50;
    
    for(int i = 1; i<= 12; i++) {
        printf("Aluno %d => ", i);
        printf("Faltas Prova 1 Prova 2:\n");
        scanf("%d f%f %f", &faltas, &prova1, &prova2);
        
        if (faltas < (50 * 0.25)) {
            nota += (prova1 + prova2) / 2.0;
            
            if (nota < 9.5) {
                nota_negativa++;
                reprovados++;
                printf("Reprovado!");
            }
            else {
                aprovados++;
                printf("Aprovado!");
            }
        }
        else
            reprovados++;
        
        soma_notas += nota;
    }
    
//    for(int i = 1; i<= 12; i++) {
//        if(faltas*100.0/NUM_AULAS) > 25 {
//            reprovados_por_faltas++;
//            printf("ReprIPIPovado por faltas\n");
//        } else {
//            nota_aluno = (prova1+ prova2) / 2.0;
//
//            if (nota_aluno > 9.5) {
//                aprovados++;
//                printf("Aprovado");
//            } else {
//                nota_negativa++;
//                printf("Reprovado por nota negativa");
//            }
//            soma+= nota_aluno;
//        }
//    }
//
//    media_turma = soma / (aprovados+nota_negativa);
//    int reprovados = reprovados_por_faltas + notas_negativas;
    
    printf("Média = %.2f\n", soma_notas / (aprovados + nota_negativa));
    printf("Aprovados = %d\n", aprovados);
    printf("Reprovados = %d\n", reprovados + nota_negativa);
    printf("Notas negativas = %d\n", nota_negativa);
        
    return 0;
}
