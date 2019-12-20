//
//  main.c
//  Lab11
//
//  Created by Felipe Viberti on 06/11/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include <stdio.h>
#include "metiter.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    double **A1, *b1, *x1;
    double **A2, *b2, *x2, *x3,*x4;
    int qtd_iteracoes = 0,i = 0;
    double tol = 1e-7;
    
    A1 = matcria(2, 2);
    b1 = matcria(1, 2)[0];
    x1 = matcria(1, 2)[0];
    
    A1[0][0] = 3.0; A1[0][1] = 1.0; b1[0] = 5.0;
    A1[1][0] = 1.0; A1[1][1] = 2.0; b1[1] = 5.0;
    
    A2 = matcria(6, 6);
    b2 = matcria(1, 6)[0];
    x2 = matcria(1, 6)[0];
    
    A2[0][0] = 3.0; A2[0][1] = -1.0; A2[0][2] = 0.0; A2[0][3] = 0.0; A2[0][4] = 0.0; A2[0][5] = 0.5; b2[0] = 2.5;
    A2[1][0] = -1.0; A2[1][1] = 3.0; A2[1][2] = -1.0; A2[1][3] = 0.0; A2[1][4] = 0.5; A2[1][5] = 0.0; b2[1] = 1.5;
    A2[2][0] = 0.0; A2[2][1] = -1.0; A2[2][2] = 3.0; A2[2][3] = -1.0; A2[2][4] = 0.0; A2[2][5] = 0.0; b2[2] = 1.0;
    A2[3][0] = 0.0; A2[3][1] = 0.0; A2[3][2] = -1.0; A2[3][3] = 3.0; A2[3][4] = -1.0; A2[3][5] = 0.0; b2[3] = 1.0;
    A2[4][0] = 0.0; A2[4][1] = 0.5; A2[4][2] = 0.0; A2[4][3] = -1.0; A2[4][4] = 3.0; A2[4][5] = -1.0; b2[4] = 1.5;
    A2[5][0] = 0.5; A2[5][1] = 0.0; A2[5][2] = -1.0; A2[5][3] = 3.0; A2[5][4] = -1.0; A2[5][5] = 3.0; b2[5] = 2.5;
   
    qtd_iteracoes = Jacobi(2, A1, b1, x1, tol);
    printf("Iterações Jacobi Matriz 1: %d\n", qtd_iteracoes);
    printf("Solução Jacobi 1:");
    for (i = 0; i < 2;i++) {
        printf("\t%.16g\t", x1[i]);
    }
    
    qtd_iteracoes = Jacobi(6, A2, b2, x2, tol);
    printf("\nIterações Jacobi Matriz 2: %d\n", qtd_iteracoes);
    printf("Solução Jacobi 2: ");
    for (i = 0; i < 5;i++) {
        printf("%.16g\t", x2[i]);
    }
    
    x3 = matcria(1, 2)[0];
    x4 = matcria(1, 6)[0];
    
    qtd_iteracoes = GradConj(2, A1, b1, x3, tol);
    printf("\nIterações GradConj Matriz 1: %d\n", qtd_iteracoes);
    printf("Solução grad conj 1: ");
    for (i = 0; i < 2;i++) {
        printf("%.16g\t", x3[i]);
    }
    
    qtd_iteracoes = GradConj(6, A2, b2, x4, tol);
    printf("\nIterações GradConj Matriz 2: %d\n", qtd_iteracoes);
    printf("Solução grad conj 2: ");
    for (i = 0; i < 5;i++) {
        printf("%.16g\t", x4[i]);
    }
    
    return 0;
}
