//
//  matriz.h
//  Analise_Numerica
//
//  Created by Felipe Viberti on 15/08/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#ifndef matriz_h
#define matriz_h

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

double* vetcria(int n);

void vetlibera(double* v);

double escalar(int n, double* v, double* w);

double norma2(int n, double* v);

double** matcria (int m, int n);

void mat_libera (int m, double** A);

void transposta (int m, int n, double** A, double** T);

void multv (int m, int n, double** A, double* v, double* w);

void multm (int m, int n, int q, double** A, double** B, double** C);

void imprime (int m, int n, double** A, char* format);

#endif /* matriz_h */
