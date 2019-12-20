//
//  taylor.c
//  Lab1
//
//  Created by Felipe Viberti on 21/08/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include "taylor.h"

double cos2 (double x) {
    // No grau 1 vale 1 e a expressao do grau 2 dá zero
    return 1.0 - (2.0 * 1.0 * 0.0 * x);
}

double cos2_rmxax(double x) {
    //Usando a terceira derivada 8 sinc cosc e c = pi
    return 0 * (x * x * x);
}

double raiz(double x) {
    return 1 + (1.0/2.0 * (x - 1)) + (((-1.0 / 4.0) / 2.0) * ((x - 1.0) * (x - 1.0)));
}

//Intervalo entre 1 e 2
double raiz_rmax(double x) {
    return (0.0390625 * (x-1.0) * (x-1.0) * (x-1.0) * (x-1.0)) * 0.9375;
}


