//
//  main.c
//  Lab3
//
//  Created by Felipe Viberti on 04/09/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "sistlinear.h"
double** matcria (int m, int n) {
    int i;
    double ** matriz;
    
    matriz = malloc(m * sizeof(double *));
    
    for (i = 0; i < m; i++) {
        matriz[i] = malloc(n * sizeof(double));
    }
    
    return matriz;
}

void imprime (int m, int n, double** A, char* format) {
    int i, j;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf(format, A[i][j]);
            printf(" ");
        }
        printf("\n\n");
    }
}

int main(int argc, const char * argv[]) {
    int i;
    int n1, n2;
    double **A1, *b1, *x1;
    double **A2, *b2, *x2;
    
    n1 = 3;
    A1 = matcria(n1, n1);
    b1 = matcria(1, n1)[0];
    x1 = matcria(1, n1)[0];
    
    A1[0][0] = 1.0; A1[0][1] = -1.0; A1[0][2] = 0.0; b1[0] = 0.0;
    A1[1][0] = -1.0; A1[1][1] = 2.0; A1[1][2] = 1.0; b1[1] = 2.0;
    A1[2][0] = 0.0; A1[2][1] = 1.0; A1[2][2] = 2.0; b1[2] = 3.0;
    
    printf("Matriz antes da função de gauss:\n");
    imprime(3,3,A1,"%.16g");
    
    gauss(3, A1, b1, x1);
    
    printf("Matriz depois da função de gauss:\n");
    imprime(3,3,A1,"%.16g");
    
    //Testando Pivotamento de Gauss
    A1[0][0] = 0.0; A1[0][1] = 1.0; A1[0][2] = 2.0; b1[0] = 3.0;
    A1[1][0] = -1.0; A1[1][1] = 2.0; A1[1][2] = 1.0; b1[1] = 2.0;
    A1[2][0] = 1.0; A1[2][1] = -1.0; A1[2][2] = 0.0; b1[2] = 0.0;
  
    printf("Matriz antes da função de gauss:\n");
    imprime(3,3,A1,"%.16g");
    
    gauss(3, A1, b1, x1);
    
    printf("Matriz depois da função de gauss:\n");
    imprime(3,3,A1,"%.16g");
    
    n2 = 6;
    A2 = matcria(n2, n2);
    b2 = matcria(1, n2)[0];
    x2 = matcria(1, n2)[0];
    
    A2[0][0] = 3.0; A2[0][1] = -1.0; A2[0][2] = 0.0; A2[0][3] = 0.0; A2[0][4] = 0.0; A2[0][5] = 0.5; b2[0] = 2.5;
    A2[1][0] = -1.0; A2[1][1] = 3.0; A2[1][2] = -1.0; A2[1][3] = 0.0; A2[1][4] = 0.5; A2[1][5] = 0.0; b2[1] = 1.5;
    A2[2][0] = 0.0; A2[2][1] = -1.0; A2[2][2] = 3.0; A2[2][3] = -1.0; A2[2][4] = 0.0; A2[2][5] = 0.0; b2[2] = 1.0;
    A2[3][0] = 0.0; A2[3][1] = 0.0; A2[3][2] = -1.0; A2[3][3] = 3.0; A2[3][4] = -1.0; A2[3][5] = 0.0; b2[3] = 1.0;
    A2[4][0] = 0.0; A2[4][1] = 0.5; A2[4][2] = 0.0; A2[4][3] = -1.0; A2[4][4] = 3.0; A2[4][5] = -1.0; b2[4] = 1.5;
    A2[5][0] = 0.5; A2[5][1] = 0.0; A2[5][2] = 0.0; A2[5][3] = 0.0; A2[5][4] = -1.0; A2[5][5] = 3.0; b2[5] = 2.5;
    
    printf("Matriz antes da fatoração de cholesky:\n");
    imprime(n2,n2,A2,"%.16g");
    
    cholesky(n2, A2);
    
    printf("Matriz depois da fatoração de cholesky:\n");
    imprime(n2,n2,A2,"%.16g");
    
    substituicoes(n2, A2, b2, x2);
    
    for(i = 0;i<6;i++) {
        printf("%.16g\n",x2[i]);
    }

    return 0;
}
