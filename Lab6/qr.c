//
//  qr.c
//  Lab6
//
//  Created by Felipe Viberti on 25/09/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include "qr.h"

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
void dividevetornumero(int n,double *w ,double numero,double **Q,int j) {
    int i = 0;
    for (i=0;i<n;i++) {
        Q[i][j] = w[i] / numero;
    }
}

void multiplicavetornumero(int n,double *w,double numero,double *resultado) {
    int  i = 0;
    for (i=0;i<n;i++) {
        resultado[i] = w[i] * numero;
    }
}

void subtractvectors(int n,double *w,double *multiplicado,double *resultado) {
    int  i = 0;
    for (i=0;i<n;i++) {
        resultado[i] = w[i] - multiplicado[i];
    }
}

void extraivalorescoluna(int n,double **Q, int j,double *resultado) {
    int i = 0;
    for (i=0;i<n;i++) {
         resultado[i] = Q[i][j];
     }
}

void QR (int m, int n, double** A, double** Q, double** R) {
    int i = 0, j = 0;
    double *w = vetcria(m);
    double *resultado = vetcria(m);
    double *colunadeQ = vetcria(m);
    for (j=0;j<=n-1;j++) {
        extraivalorescoluna(m, A, j, w);
        for(i = 0;i<=j-1;i++) {
            extraivalorescoluna(m,Q, i, colunadeQ);
            R[i][j] = escalar(m, colunadeQ, w);
            multiplicavetornumero(m, colunadeQ, R[i][j],resultado);
            subtractvectors(m, w, resultado, w);
        }
        R[j][j] = norma2(m, w);
        dividevetornumero(m, w, R[j][j], Q,j);
    }
}

double mmqQR (int m, int n, double** Q, double** R, double* b, double* x) {
    double **transpostaQ = matcria(n, m);
    double *vetorresultado = vetcria(m);
    transposta(m, n, Q, transpostaQ);
    multmv(n, m, transpostaQ, b, vetorresultado);
    substituicoes(n, R, vetorresultado, x);
    return 0;
}



