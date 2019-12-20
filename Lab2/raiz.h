//
//  raiz.h
//  Lab2
//
//  Created by Felipe Viberti on 28/08/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#ifndef raiz_h
#define raiz_h

#include <stdio.h>

int secante (double x0, double x1, int p,double (*f) (double x), double* r);

int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r);

#endif /* raiz_h */
