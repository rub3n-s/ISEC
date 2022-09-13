//
//  main.c
//  ex15
//
//  Created by rsantos on 06/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#define L1 3
#define C1 2

int unicaMat(int nLin, int nCol, int mat[][nCol]) {
    int num[nLin * nCol], k = 0, l = 0;
    
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            num[k] = mat[i][j];
            k++;
        }
    }
    
    return 1;
}

int main(int argc, const char * argv[]) {
    int mat[L1][C1]={{1,2},{3,4},{5,6}};
    
    printf("%d\n", unicaMat(L1, C1, mat));
    
    return 0;
}
