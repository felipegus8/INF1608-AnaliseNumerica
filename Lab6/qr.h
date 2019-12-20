//
//  qr.h
//  Lab6
//
//  Created by Felipe Viberti on 25/09/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#ifndef qr_h
#define qr_h

#include <stdio.h>
#include "matriz.h"
#include "sistlinear.h"

void QR (int m, int n, double** A, double** Q, double** R);

double mmqQR (int m, int n, double** Q, double** R, double* b, double* x);
#endif /* qr_h */
