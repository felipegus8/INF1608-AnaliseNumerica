//
//  simpson.h
//  Lab8
//
//  Created by Felipe Viberti on 16/10/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#ifndef simpson_h
#define simpson_h

#include <stdio.h>
#include <math.h>

double DoubleSimpson (double a, double b, double (*f) (double x), double* v);

double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol);

double Quadratura2 (double a, double b, double (*f) (double x));

double Quadratura3 (double a, double b, double (*f) (double x));


#endif /* simpson_h */
