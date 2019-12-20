//
//  sistlinear.h
//  Lab3
//
//  Created by Felipe Viberti on 04/09/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#ifndef sistlinear_h
#define sistlinear_h

#include <stdio.h>

void gauss (int n, double** A, double* b, double* x);

void cholesky (int n, double** A);

void substituicoes (int n, double** A, double* b, double* x);


#endif /* sistlinear_h */
