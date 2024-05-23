#include "middle.h"

#include <cmath>


//Функция поиска корня:
double FindRoot(double (*f)(double),double a,double b,double eps){
    double c;
    int iterations = 0;
    while( ((b-a)/2>eps) && iterations < 5){
        iterations++;
        c=(a+b)/2;
        if((f(a)*f(c))>0) a=c;
        else b=c;
    }
    return c;
}
