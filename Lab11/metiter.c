//
//  metiter.c
//  Lab11
//
//  Created by Felipe Viberti on 07/11/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include "metiter.h"

#define DBL_MAX 1.79769313486231470e+308

int Jacobi (int n, double** A, double* b, double* x, double tol) {
    int i, j, qtdIteracoes = 0;
    double maxError = DBL_MAX;
    double **LU = matcria(n, n);
    double *xk = x, *xk1 = (double *) malloc(sizeof(double) * n);
  
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                //Zerando a diagonal
                LU[i][j] = 0.0;
            }
            else {
                //Colocando valores de A em LU (exceto diagonal)
                LU[i][j] = A[i][j];
            }
        }
    }
    while(maxError > tol) {
        maxError = 0.0;
        multv(n, n, LU, xk, xk1);
        for(i = 0; i < n; i++) {
            xk1[i] = (b[i] - xk1[i])/A[i][i];
        }
       
        for(i = 0; i < n; i++) {
            //Cálculo do erro
            maxError += (xk1[i] - xk[i]) * (xk1[i] - xk[i]);
            xk[i] = xk1[i];
        }
        maxError = sqrt(maxError);
        qtdIteracoes++;
    }
    
    return qtdIteracoes;
}

int GradConj (int n, double** A, double* b, double* x, double tol) {
    int i, k;
    double alpha, beta, num = 0, den = 0;
    
    double * Ax = (double *) malloc(sizeof(double) * n), *rk0 = (double *) malloc(sizeof(double) * n),
    *rk1 = (double *) malloc(sizeof(double) * n), *dk0 = (double *) malloc(sizeof(double) * n),
    *dk1 = (double *) malloc(sizeof(double) * n), *Ad = (double *) malloc(sizeof(double) * n),
    *xn = (double *) malloc(sizeof(double) * n);


    multv(n, n, A, x, Ax);
    for (i = 0; i < n; i++) {
        rk0[i] = b[i] - Ax[i];
        dk0[i] = rk0[i];
    }


    for (k = 0; k < n; k++) {
        num = 0;
        den = 0;
        if (norma2(n, rk0) < tol)
            //Solução válida
            break;
        
        multv(n, n, A, dk0, Ad);
        for (i = 0; i < n; i++) {
            num += pow(rk0[i],2);
            den += dk0[i] * Ad[i];
        }
        alpha = num/den;
        
        for (i = 0; i < n; i++)
            xn[i] = x[i] + alpha * dk0[i];
        
            for (i = 0; i < n; i++)
                rk1[i] = rk0[i] + alpha * Ad[i];
        
                num = 0;
                den = 0;
                for (i = 0; i < n; i++) {
                    den += pow(rk0[i],2);
                    num += pow(rk1[i], 2);
                }
        beta = num/den;
        
        for (i = 0; i < n; i++)
            dk1[i] = rk1[i] + beta * dk0[i];
        
            for (i = 0; i < n; i++) {
                x[i] = xn[i];
                rk0[i] = rk1[i];
                dk0[i] = dk1[i];
            }
    }

    return k;
}
