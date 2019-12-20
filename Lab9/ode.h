//
//  ode.h
//  Lab9
//
//  Created by Felipe Viberti on 23/10/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#ifndef ode_h
#define ode_h
#include <math.h>
#include <stdio.h>

double PontoMedio (double t0, double t1, double h, double y0, double (*f) (double t, double y));

double PontoMedioAdapt (double t0, double t1, double h0, double y0, double (*f) (double t, double y), double tol);

#endif /* ode_h */
