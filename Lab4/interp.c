//
//  interp.c
//  Lab4
//
//  Created by Felipe Viberti on 11/09/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include "interp.h"
#include <math.h>

void Chebyshev (int n, double a, double b, double* xi) {
    int beta, i = 0;
    
    for (beta = 1; beta <= (2 * n) - 1; beta += 2) {
        
        //Fórmula
        xi[i] = ((b - a) / 2) * (cos((beta * PI) / (2 * n))) + ((a + b) / 2);
        i+=1;
    }
}

void NewtonCoef (int n, double* xi, double (*f) (double), double* bi) {
    int i, j;
    
    //Cache
    double** matriz = matcria(n, n);
    
    for(j = 0; j < n; j++) {
        
        for(i = n-1; i >= 0; i--) {
            if (i == j)
                matriz[i][j] = f(xi[i]);
            else
                if (i < j)
                    matriz[i][j] = (matriz[i+1][j] - matriz[i][j-1]) / (xi[j] - xi[i]);
            
            if (i == 0)
                bi[j] = matriz[i][j];
        }
    }
    
    //Liberar cache
    matlibera(n, matriz);
}

double NewtonAval (int n, double* xi, double* bi, double x) {
    int i;
    double val = 0.0;
    
    for (i = n - 1; i >= 0; i--) {
        if (i > 0)
            val = (bi[i] + val) * (x - xi[i - 1]);
        else
            val += bi[i];
    }
    
    return val;
}
