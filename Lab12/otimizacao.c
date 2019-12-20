//
//  otimizacao.c
//  Lab12
//
//  Created by Felipe Viberti on 13/11/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include "otimizacao.h"

int secaoaurea (double a, double b, double (*f) (double x), double tol, double* xmin) {
    double g = (sqrt(5) - 1) / 2,x1,x2,fx1,fx2;
    int qtd_iteracoes = 0;
    x1 = a + ((1-g) * (b-a));
    x2 = a + g * (b-a);
    fx1 = f(x1);
    fx2 = f(x2);
    while((fabs(fx1 - fx2)) > tol) {
        qtd_iteracoes++;
        if (fx1 < fx2) {
            b = x2;
            x2 = x1;
            x1 = a + ((1-g) * (b-a));
        }
        else {
            a = x1;
            x1 = x2;
            x2 = a + g * (b-a);
        }
        fx1 = f(x1);
        fx2 = f(x2);
    }
    *xmin = (x1 + x2) / 2;
    return qtd_iteracoes;
}

int parabolica (double r, double s, double t, double (*f) (double x), double tol, double* xmin) {
    double x,fs,ft,fr;
    int qtd_iteracoes = 0;
    fs = f(s);
    ft = f(t);
    fr = f(r);
    x = ((r + s) / 2) - (((fs - fr) * (t - r) * (t - s)) / (2 * ((s - r) * (ft - fs) - (fs - fr) * (t-s))));
    
    while (fabs(fs - ft) > tol) {
        
        qtd_iteracoes++;
        r = s;
        s = t;
        t = x;
        fr = f(r);
        fs = f(s);
        ft = f(t);
        x = ((r + s) / 2) - (((fs - fr) * (t - r) * (t - s)) / (2 * ((s - r) * (ft - fs) - (fs - fr) * (t-s))));
    }
    
    *xmin = (s + t) / 2;
    return qtd_iteracoes;
}
