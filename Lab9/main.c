//
//  main.c
//  Lab9
//
//  Created by Felipe Viberti on 23/10/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include <stdio.h>
#include "ode.h"

double derivadaf1(double t,double y)
{
    return (t*y) + pow(t,3);
}

double f1(double t)
{
    return exp(t*t/2) - pow(t,2) - 2;
}

int main(int argc, const char * argv[]) {
    
    double  h1 = 0.01,h2 = 0.001,h3 = 0.0001,y0 = -1, t0 = 0, t1 = 2.4, resultado_exato = f1(2.4), resultado, tol = 0.0001;
    
    resultado = PontoMedio (t0,t1,h1,y0,derivadaf1);
    printf("Ponto Medio 1: = %.16g\n",resultado);
    printf("Erro relativo = %.16g\n",fabs((resultado_exato - resultado)/resultado));
    
    resultado = PontoMedio (t0,t1,h2,y0,derivadaf1);
    printf("\nPonto Medio 2: =  %.16g\n",resultado);
    printf("Erro relativo = %.16g\n",fabs((resultado_exato - resultado)/resultado));
    
    resultado = PontoMedio (t0,t1,h3,y0,derivadaf1);
    printf("\nPonto Medio 3: =  %.16g\n",resultado);
    printf("Erro relativo = %.16g\n",fabs((resultado_exato - resultado)/resultado));
    
    resultado = PontoMedioAdapt (t0,t1,h3,y0,derivadaf1,tol);
    printf("\nPonto Medio Adapativo =  %.16g\n",resultado);
    printf("Erro relativo = %.16g\n\n",fabs((resultado_exato - resultado)/resultado));
}
