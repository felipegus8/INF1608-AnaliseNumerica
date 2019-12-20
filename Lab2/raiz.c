//
//  raiz.c
//  Lab2
//
//  Created by Felipe Viberti on 28/08/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include "raiz.h"
#include <math.h>
int secante (double x0, double x1, int p,double (*f) (double x), double* r) {
    double x2,erro;
    int numeroDeIteracoes = 0;
    erro = 0.5 * pow(10.0, -p);
    x2 = x1 - ((f(x1) * (x1 - x0)) / ((f(x1) - f(x0))));
    while (fabs(f(x2)) > erro) {
       
        x0 = x1;
        x1 = x2;
        x2 = x1 - ((f(x1) * (x1 - x0)) / ((f(x1) - f(x0))));
        numeroDeIteracoes++;
        if (numeroDeIteracoes > 100) {
            printf("Função não converge");
            return 0;
        }
        
    }
    *r = x2;
    return numeroDeIteracoes;
}


int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r) {
    double A[3][3] = {0}, Ac[3][3] = {0};
    
    int numeroIteracoes = 0;
    double valorx0 = f(x0), valorx1 = f(x1), valorx2 = f(x2), erro, c, detA, detAc;
    
    *r = valorx2;
    
    erro = 0.5 * pow(10.0, -p);
    
    while(fabs(valorx2) > erro)
    {
        if (numeroIteracoes == 100 || fabs(*r) >= 1e7)
            return 0;
        
        A[0][0] = valorx0 * valorx0;
        A[0][1] = valorx0;
        A[0][2] = 1;
        A[1][0] = valorx1 * valorx1;
        A[1][1] = valorx1;
        A[1][2] = 1;
        A[2][0] = valorx2 * valorx2;
        A[2][1] = valorx2;
        A[2][2] = 1;
        
        detA = A[0][0] * ((A[1][1] * A[2][2]) - (A[2][1] * A[1][2])) -
        A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]) +
        A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);
        
        Ac[0][0] = valorx0 * valorx0;
        Ac[0][1] = valorx0;
        Ac[0][2] = x0;
        Ac[1][0] = valorx1 * valorx1;
        Ac[1][1] = valorx1;
        Ac[1][2] = x1;
        Ac[2][0] = valorx2 * valorx2;
        Ac[2][1] = valorx2;
        Ac[2][2] = x2;
        
        detAc = Ac[0][0] * ((Ac[1][1] * Ac[2][2]) - (Ac[2][1] * Ac[1][2])) -
        Ac[0][1] * (Ac[1][0] * Ac[2][2] - Ac[2][0] * Ac[1][2]) +
        Ac[0][2] * (Ac[1][0] * Ac[2][1] - Ac[2][0] * Ac[1][1]);
        
        c = detAc / detA;
        
        x0 = x1;
        x1 = x2;
        x2 = c;
        
        valorx0 = valorx1;
        valorx1 = valorx2;
        valorx2 = f(x2);
        
        *r = c;
        
        numeroIteracoes++;
    }
    
    return numeroIteracoes;
}
