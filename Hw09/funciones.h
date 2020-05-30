# include <iostream>
# include <math.h>
# include <fstream>

using namespace std;

//Posición de la piedra respecto al tiempo velocidad inicial y posición inicial. 
double Y (double t, double v0, double y){
    return (y + (v0*t) - (0.5*9.81*pow(t,2)));
}

//Velocidad de la piedra respecto a su velocidad inicial y tiempo.
double V (double v0, double t){
    return (v0 - (9.81*t));
}

//Cuadratica para calcular el tiempo total del movimiento de la roca siendo 4.387 segundos. 
double T (double v0, double y){
    return ((-v0-(sqrt(pow(v0,2)-(4*(-9.82/2)*y))))/(2*(-9.81/2)));
}

//Se implementa el metodo Runge Kutta de 4to Orden. 
double* rungekutta4(double dt, double t, double y0, double v0){
    
    double yn;
    double tn;
    double * f = new double[2];
        
    double k1 = V(Y(t, v0, y0), t ) * dt;
    double k2 = V(Y(t, v0, y0) + (k1/2.0), t + (dt/2.0)) * dt;
    double k3 = V(Y(t, v0, y0) + (k2/2.0), t + (dt/2.0)) * dt;
    double k4 = V(Y(t, v0, y0) +   (k3)  , t +   (dt)  ) * dt;
    
    
//Calculado la posicion a partir de las constantes del RK 4.              
    yn = (Y(t, v0, y0) + (( k1 + (2*k2) + (2*k3) + k4)/6.0));
    
//Actualizacion de tiempo.                  
    tn = t+dt;

//Array con los valores de tiempo y posición.     
    f[0] = tn;
    f[1] = yn;
        
    return f;    
}    
