//
//  ode.c
//  Lab9
//
//  Created by Felipe Viberti on 23/10/19.
//  Copyright © 2019 Felipe Viberti. All rights reserved.
//

#include "ode.h"

double PontoMedio (double t0, double t1, double h, double y0, double (*f) (double t, double y)) {
    double t = 0,ydelta = 0,next = 0,yt = y0;
    ydelta = h * f(t,y0);
    for(t = t0;t<t1;t+=h) {
        if(t + h > t1) {
            h = t1-t;
        }
        next = yt + h * f(((t+h)/2),yt + (ydelta / 2));
        yt = next;
        ydelta = h * f(t,yt);
    }
    return yt;
}

double PontoMedioAdapt (double t0, double t1, double h0, double y0, double (*f) (double t, double y), double tol) {
    
    double  t, t2,y,nexty1 = 0,nexty2,h,halfh,erro,gama,delta,ydelta;
    t = t0;
    h = h0;
    y = y0;
    ydelta = h * f(t,y0);
    
    while (t < t1) {
        if(t + h > t1) {
            h = t1 - t;
        }
        nexty1 = y + (h * f((t + (h/2)),y + (ydelta/2)));
        
        nexty2 = y;
        halfh = h/2.0;
        t2 = t;
       
        for(int i = 0; i < 2 ; i++) {
            ydelta  = halfh * f(t2,nexty2);
            nexty2 = nexty2 + ((halfh * f((t2 + (halfh/2)),nexty2 + (ydelta/2))));
            t2 += halfh;
        }
        
        delta = nexty2 - nexty1;
        erro = delta/3.0;
        
        gama = cbrt(tol/fabs(erro));
        
        if (gama >= 1.0) {
            //Só atualiza se gama for maior que 1
            y = nexty2 + erro;
            t += h;
        }
        //Isso ocorre independente do valor de gama
        ydelta = h * f(t,y0);
        h = h * gama;
    }
    return y;
}
