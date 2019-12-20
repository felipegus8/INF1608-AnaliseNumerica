//
//  main.c
//  Lab7
//
//  Created by Felipe Viberti on 09/10/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include <stdio.h>
#include "integral.h"
double f(double x) {
    return cos(x) - 2 * sin(x);
}

double f1(double x) {
    return -sin(x) - 2*cos(x);
}

double integral1(double x) {
    double denominador = sqrt(pow(x, 2) + 9);
    
    return x/denominador;
}

double integral2(double x) {
    return pow(x, 2) * log(x);
}

double integral3(double x) {
    return pow(x, 2) * sin(x);
}

double Emin() {
    // (3 * EMAQ / f'''(0))^(-1/3)
    // f'''(0) = 2
    double maq = pow(2, -52);
    
    return cbrt(3 * maq / 2);
}
int main(void) {
    double hO = h_otimo(f, f1, 0.0);
    
    printf("h otimo: %g \n", hO);
    
    printf("S(n = 16) = %.14g | S(n = 32) = %.14g\n", simpson(integral1, 0, 4, 16), simpson(integral1, 0, 4, 32));
    printf("M(n = 16) = %.14g | M(n = 32) = %.14g\n", pontomedio(integral1, 0, 4, 16), pontomedio(integral1, 0, 4, 32));
    
    printf("S(n = 16) = %.14g | S(n = 32) = %.14g\n", simpson(integral2, 1, 3, 16), simpson(integral2, 1, 3, 32));
    printf("M(n = 16) = %.14g | M(n = 32) = %.14g\n", pontomedio(integral2, 1, 3, 16), pontomedio(integral2, 1, 3, 32));
    
    printf("S(n = 16) = %.14g | S(n = 32) = %.14g\n", simpson(integral3, 0, M_PI, 16), simpson(integral3, 0, M_PI, 32));
    printf("M(n = 16) = %.14g | M(n = 32) = %.14g\n", pontomedio(integral3, 0, M_PI, 16), pontomedio(integral3, 0, M_PI, 32));
    
    printf("\n");
    printf("O metodo de Simpson é mais preciso que o do Ponto Médio.\nQuanto mais passos, mais preciso é o resultado.\n");
    printf("\n");
    return 0;
}
