//
//  main.c
//  Lab12
//
//  Created by Felipe Viberti on 13/11/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//
//
#include <stdio.h>
#include "otimizacao.h"
#include <stdlib.h>
double f1(double x)
{
    return pow(x,2) + sin(x);
}

double f2(double x) {
    return pow(x,6) - (11 * pow(x,3)) + (17 * pow(x,2)) - (7 * x) + 1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int qtd_iteracoes;
    double tol = 0.00001, a = -2, b = 2,*xmin,r = -2,s = 0, t = 4;
    xmin = (double*) malloc(sizeof(double));
    qtd_iteracoes = secaoaurea(a, b, f1, tol, xmin);
    printf("Valor: %.16g\n",*xmin);
    printf("QTD_Iteracoes:%d\n",qtd_iteracoes);
    xmin = (double*) malloc(sizeof(double));
    qtd_iteracoes = parabolica(r, s, t, f2, tol, xmin);
    printf("Valor: %.16g\n",*xmin);
    printf("QTD_Iteracoes:%d\n",qtd_iteracoes);
    return 0;
}
