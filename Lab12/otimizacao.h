//
//  otimizacao.h
//  Lab12
//
//  Created by Felipe Viberti on 13/11/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#ifndef otimizacao_h
#define otimizacao_h
#include <math.h>
#include <stdio.h>

int secaoaurea (double a, double b, double (*f) (double x), double tol, double* xmin);

int parabolica (double r, double s, double t, double (*f) (double x), double tol, double* xmin);

#endif /* otimizacao_h */
