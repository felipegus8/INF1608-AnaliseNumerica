//
//  integral.c
//  Lab7
//
//  Created by Felipe Viberti on 09/10/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include "integral.h"


double derivada (double (*f) (double x), double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

double h_otimo (double (*f) (double x), double (*fl) (double x), double x) {
    int i = 0;
    double h, derivadaNumerica, derivadaAnalitica, erro;
    
    for (i = 12; i > 0; i--) {
        h = pow(10.0, -i);
        
        derivadaNumerica = derivada(f, x, h);
        derivadaAnalitica = fl(x);
        
        erro = fabs(derivadaNumerica - derivadaAnalitica);
        
        if (erro <= h)
            break;
    }
    
    return erro;
}

double richardson (double (*f) (double x), double x, double h) {
    double mult = pow(2,x);
    return (mult * f(h/2) - f(h)) / (mult - 1);
}


double simpson (double (*f) (double), double a, double b, int n) {
    double h = (b - a) / n;
    double meio = (a + b) / 2;
    
    
    return (h / 6) * (f(a) + 4 * f(meio) + f(b));
}

double pontomedio (double (*f) (double), double a, double b, int n) {
    double h = (b - a) / n;
    double xi = a, integral = 0;
    
    while (xi < b) {
        integral += h * f(xi + h/2);
        xi += h;
    }
    
    return integral;
}
