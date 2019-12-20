//
//  main.c
//  Lab8
//
//  Created by Felipe Viberti on 16/10/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include <stdio.h>
#include "simpson.h"

double f1(double x)
{
    return x / sqrt(x * x + 9.0);
}

double f2(double x)
{
    return (1.0 / sqrt(2.0 * M_PI)) * exp((-x*x) / 2.0);
}

double f3(double x)
{
    return (2.0 / sqrt(M_PI)) * exp(-x*x);
}

int main(int argc, const char * argv[]) {
    double a = 0, b = 1, tol = 1e-7;
    printf("Primeira Função\n");
    
    printf("Adaptive Simpson: %.7g\nQuadratura2: %.7g\nQuadratura3: %.7g\n", AdaptiveSimpson(a, b, f1, tol), Quadratura2(a, b, f1), Quadratura3(a, b, f1));
    
    a = -1;
    b = 1;
    
    printf("\n\nSegunda Função\n");
    printf("Adaptive Simpson: %.7g\nQuadratura2: %.7g\nQuadratura3: %.7g\n", AdaptiveSimpson(a, b, f2, tol), Quadratura2(a, b, f2), Quadratura3(a, b, f2));
    
    a = 0;
    b = 3;
    
    printf("\n\nTerceira Função\n");
    printf("Adaptive Simpson: %.7g\nQuadratura2: %.7g\nQuadratura3: %.7g\n", AdaptiveSimpson(a, b, f3, tol), Quadratura2(a, b, f3), Quadratura3(a, b, f3));

    return 0;
}
