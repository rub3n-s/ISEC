
#include <stdio.h>
void media_coluna_matriz(int n_lin, int n_col, float m[n_lin][n_col], int *min, int *max)
{
    float media_coluna[n_col], val_max=0, val_min=0;
    int i, j;
    for(j=0;j<n_col; j++)
    {
        *(media_coluna+j)=0;
        //media_coluna[j]=0;
        for(i=0; i<n_lin; i++)
            *(media_coluna+j)+=*(m[i]+j);

        media_coluna[j]=*(media_coluna+j)/n_lin;
        printf("\nA media da coluna %d e %f",j,*(media_coluna+j));
    }
   // val_max=*media_coluna;
    val_max=media_coluna[0];
    val_min=*media_coluna;
    for (j=1;j<n_col;j++)
    {
       if(val_min >= *(media_coluna+j))
        {
            val_min= *(media_coluna+j);
            *min=j;
    }
        if(*(media_coluna+j)>val_max)
        {
            val_max=*(media_coluna+j);
            *max=j;
        }
}
}

int main(int argc, char** argv) {
    float m1[3][2] = {{1.0, 4.5},{-2.5, 8.9},{0.3, 1.4}};
    float m2[2][6] = {{1.0,1.6, 4.2, 1.4,  0.5,-3.4},{2.5, 8.1, 0.9, -0.1, 0.8,3.5}};
    int min1=0, max1=0, min2=0, max2=0;

    printf("\nMatriz m1: ");
    media_coluna_matriz(3, 2,  m1, &min1, &max1);

    printf("\nMatriz m2: ");
    media_coluna_matriz(2, 6,  m2, &min2, &max2);

    printf("\nMatriz m1: (%d, %d)\n", min1, max1);
    printf("\nMatriz m2: (%d, %d)\n", min2, max2);
    return 0;
}
