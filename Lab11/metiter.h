//
//  metiter.h
//  Lab11
//
//  Created by Felipe Viberti on 07/11/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#ifndef metiter_h
#define metiter_h
#include "matriz.h"
#include <stdio.h>
#include <math.h>

int Jacobi (int n, double** A, double* b, double* x, double tol);

int GradConj (int n, double** A, double* b, double* x, double tol);

#endif /* metiter_h */
