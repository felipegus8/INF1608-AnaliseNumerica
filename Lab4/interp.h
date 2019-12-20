//
//  interp.h
//  Lab4
//
//  Created by Felipe Viberti on 11/09/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#ifndef interp_h
#define interp_h
#define PI 3.14159265358979323846

#include "matriz.h"
#include <stdio.h>

void Chebyshev (int n, double a, double b, double* xi);

void NewtonCoef (int n, double* xi, double (*f) (double), double* bi);

double NewtonAval (int n, double* xi, double* bi, double x);


#endif /* interp_h */
