//
//  main.c
//  Lab6
//
//  Created by Felipe Viberti on 25/09/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include <stdio.h>
#include "qr.h"
int main(int argc, const char * argv[]) {
    double **Q1 = matcria(5, 3);
    double **R1 = matcria(5, 3);
    double **Q2 = matcria(5, 4);
    double **R2 = matcria(5, 4);
    int k = 0;
    double **A1, *b1, *x1;
    double **A2, *b2, *x2;
    
    A1 = matcria(5, 3);
    b1 = matcria(1, 5)[0];
    x1 = matcria(1, 3)[0];
    
    A1[0][0] = 3.0; A1[0][1] = -1.0; A1[0][2] = 2.0; b1[0] = 10.0;
    A1[1][0] = 4.0; A1[1][1] = 1.0; A1[1][2] = 0.0; b1[1] = 10.0;
    A1[2][0] = -3.0; A1[2][1] = 2.0; A1[2][2] = 1.0; b1[2] = -5.0;
    A1[3][0] = 1.0; A1[3][1] = 1.0; A1[3][2] = 5.0; b1[3] = 15.0;
    A1[4][0] = -2.0; A1[4][1] = 0.0; A1[4][2] = 3.0; b1[4] = 0.0;
    
    QR(5, 3, A1,Q1, R1);
    imprime(5, 3, Q1, "%g");
    printf("\n");
    imprime(5, 3, R1, "%g");
    
    mmqQR(5, 3, Q1, R1, b1, x1);
    printf("\n");

    for(k=0;k<3;k++) {
        printf("%.16g\n",x1[k]);
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    A2 = matcria(5, 4);
    b2 = matcria(1, 5)[0];
    x2 = matcria(1, 4)[0];
    
    A2[0][0] = 4.0; A2[0][1] = 2.0; A2[0][2] = 3.0; A2[0][3] = 0.0; b2[0] = 10.0;
    A2[1][0] = -2.0; A2[1][1] = 3.0; A2[1][2] = -1.0; A2[1][3] = 1.0; b2[1] = 0.0;
    A2[2][0] = 1.0; A2[2][1] = 3.0; A2[2][2] = -4.0; A2[2][3] = 2.0; b2[2] = 2.0;
    A2[3][0] = 1.0; A2[3][1] = 0.0; A2[3][2] = 1.0; A2[3][3] = -1.0; b2[3] = 0.0;
    A2[4][0] = 3.0; A2[4][1] = 1.0; A2[4][2] = 3.0; A2[4][3] = -2.0; b2[4] = 5.0;
   
    QR(5, 4, A2,Q2, R2);
    imprime(5, 4, Q2, "%g");
    printf("\n");
    imprime(5, 4, R2, "%g");
    
    mmqQR(5, 4, Q2, R2, b2, x2);
    printf("\n");
    
    for(k=0;k<4;k++) {
        printf("%.16g\n",x2[k]);
    }
    return 0;
}
