//
//  main.c
//  Lab4
//
//  Created by Felipe Viberti on 11/09/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include <stdio.h>
#include "interp.h"

double fatorial(double x)
{
    if (x == 0)
        return 1;
    
    return (x * fatorial(x - 1));
}

int main(int argc, const char * argv[]) {
    double a = 0.0, b = PI / 2, j, valNewton, valSin, limChebyshev;
    int n = 6, i;
    
    double* xi = vetcria(n);
    double* bi = vetcria(n);
    
    Chebyshev(n, a, b, xi);
    
    NewtonCoef(n, xi, sin, bi);
    
    for (i = 0; i < n; i++)
        printf("Amostra x%d: %.16g\n", i, xi[i]);

    for (i = 0; i < n; i++)
        printf("Coeficiente b%d: %.16g\n", i, bi[i]);
    
    printf("\n");
    
    limChebyshev = (pow((b - a) / 2, n) / pow(2, n - 1)) * (1 / fatorial(n));
    
    for (j = a; j < b; j += 0.15)
    {
        valNewton = NewtonAval(n, xi, bi, j);
        valSin = sin(j);
        
        printf("NewtonAval: %.16g \nsin: %.16g \nErro: %.16g \nLim. Chebyshev: %.16g\n\n\n", valNewton, valSin, fabs(valNewton - valSin), limChebyshev);
    }

    return 0;
}
