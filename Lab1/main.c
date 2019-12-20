//
//  main.c
//  Lab1
//
//  Created by Felipe Viberti on 16/08/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "taylor.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    double x = 2,valorAprox, valorFunc;
    
    valorAprox = cos2(x);
    valorFunc = cos(0) * cos(0);
    
    printf("Valor aprox da função:%.16g\n",valorAprox);
    printf("Valor usando math.h:%.16g\n",valorFunc);
    
    printf("Resíduo da função:%.16g\n",cos2_rmxax(x));
    
    if (fabs(cos2_rmxax(x)) <= fabs(valorFunc - valorAprox)) {
        printf("Aproximacao correta\n");
    }
    else {
        printf("Aproximacao errada\n");
    }

    valorAprox = raiz(x);
    valorFunc = sqrt(x);
    
    printf("Valor aprox da raiz:%.16g\n",valorAprox);
    printf("Valor usando math.h:%.16g\n",valorFunc);
    
    printf("Resíduo da raiz: %.16g\n",raiz_rmax(x));
    
    if (fabs(raiz_rmax(x)) < fabs(valorFunc - valorAprox)) {
        printf("Aproximacao correta\n");
    }
    else {
        printf("Aproximacao errada\n");
    }
    
    return 0;
}
