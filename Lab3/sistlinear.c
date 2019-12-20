//
//  sistlinear.c
//  Lab3
//
//  Created by Felipe Viberti on 04/09/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include "sistlinear.h"
#include <math.h>

void gauss (int n, double** A, double* b, double* x) {
    int counter = 0,i = 0,j = 0,k = 0, p = 0;
    double aux,fator,s;
    //Zerando o vetor solução recebido
    for (counter = 0; counter < n; counter++) {
        x[counter] = 0.0;
    }
    for (j = 0; j < n-1; j++) {
        p = j;
        // Fazendo o pivotamento
        for (k = j + 1; k< n;k++) {
            if (fabs(A[k][j]) > fabs(A[p][j])) {
                p = k;
            }
        }
        for(k = j; k < n; k++) {
            aux = A[p][k];
            A[p][k] = A[j][k];
            A[j][k] = aux;
        }
        aux = b[p];
        b[p] = b[j];
        b[j] = aux;
        
        //Remover coluna j
        for (i=j+1;i<n;i++) {
            fator = A[i][j] / A[j][j];
            
            for(k = j; k < n; k++) {
                A[i][k] = A[i][k] - A[j][k] * fator;
            }
            b[i] = b[i] - b[j] * fator;
        }
    }
    
    for (i = n-1;i>=0;i--) {
        s = 0.0;
        for (j= i+ 1; j <= n-1;j++) {
            s = s + A[i][j] * x[j];
        }
        x[i] = (b[i] - s) / A[i][i];
    }
}

void cholesky (int n, double** A) {
    double x, r;
    int i, j, k;
    
    for(j = 0; j < n; j++) {
        //Se i = j
        x = A[j][j];
        
        for(k = 0; k < j; k++)
            x -= A[j][k] * A[j][k];
        
        x = sqrt(x);
        
        A[j][j] = x;
        r = 1.0 / x;
        
        // Se i != j
        for(i = j+1; i < n; i++) {
            x = A[i][j];
            
            for(k = 0; k < j; k++)
                x -= A[i][k] * A[i][j];
            
            A[i][j] = x * r;
            A[j][i] = A[i][j]; // para matriz transposta
        }
    }
}



void substituicoes (int n, double** A, double* b, double* x)
{
    int i, j;
    double s;
    
    // forward substitution
    for (i=0; i<n; i++) {
        s = 0;
        for (j=0; j<i; ++j)
            s += A[i][j]*x[j];
        x[i] = b[i] - s;
    }
    // backward substitution
    for (i=n-1; i>=0; i--) {
        s = 0;
        for (j=i+1; j<n; ++j)
            s += A[i][j]*x[j];
        x[i] = (x[i] - s) / A[i][i];
    }
}

