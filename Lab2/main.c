//
//  main.c
//  Lab2
//
//  Created by Felipe Viberti on 28/08/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raiz.h"
double f(double x)
{
    return cos(x) - x * x * x + x;
}

double g(double m)
{
    return 0.653333 * m * (1.0 - exp(-135.0 / m)) - 35.0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    double x0, x1, x2;
    int precisao = 6, iteracoesSecante, iteracoesIQI;
    double* raizSecante;
    double* raizIQI;
    
    raizSecante = (double*) malloc(sizeof(double));
    raizIQI = (double*) malloc(sizeof(double));

    x0 = 0.0;
    x1 = 20.0;
    
    iteracoesSecante = secante(x0, x1, precisao, f, raizSecante);
    printf("Numero de Iteracoes:%d\n",iteracoesSecante);
    printf("Raiz pela secante:%.16g\n",*raizSecante);
    
    x2 = 40.0;
    
    iteracoesIQI = IQI(x0, x1, x2, precisao, f, raizIQI);
    printf("Numero de Iteracoes:%d\n",iteracoesIQI);
    printf("Raiz pela IQI:%.16g\n",*raizIQI);
    
    *raizSecante = 0;
    *raizIQI = 0;
    
    x0 = 40.0;
    x1 = 80.0;
    
    iteracoesSecante = secante(x0, x1, precisao, g, raizSecante);
    printf("Numero de Iteracoes:%d\n",iteracoesSecante);
    printf("Raiz pela secante:%.16g\n",*raizSecante);
    
    x2 = 120.0;
    
    iteracoesIQI = IQI(x0, x1, x2, precisao, g, raizIQI);
    printf("Numero de Iteracoes:%d\n",iteracoesIQI);
    printf("Raiz pela secante:%.16g\n",*raizIQI);
    
    return 0;
}


