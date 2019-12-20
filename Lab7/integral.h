//
//  integral.h
//  Lab7
//
//  Created by Felipe Viberti on 09/10/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#ifndef integral_h
#define integral_h

#include <stdio.h>
#include <math.h>
double derivada (double (*f) (double x), double x, double h);

double h_otimo (double (*f) (double x), double (*fl) (double x), double x);

double richardson (double (*f) (double x), double x, double h);

double simpson (double (*f) (double), double a, double b, int n);

double pontomedio (double (*f) (double), double a, double b, int n);


#endif /* integral_h */
