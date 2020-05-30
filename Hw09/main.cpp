#include <iostream>
#include "funciones.h"
#include <math.h>
#include <fstream>

using namespace std;

int main(){
    
//Definiendo los parametros iniciales del ejercicio.     
    double dt = 0.1;
    double v0 = 20.0;
    double y0 = 8.5;
    double t0 = 0.0;
    
//Cantidad de datos a calcular "+2" para asegurar que ya se encuentra en el suelo pues el tiempo total es 4.387s aproximado a 4.4 por el dt utilizado en el ejercicio.     
    int tnet = ((T(v0, y0)/dt)+2); 

//Creacion de arrays para guardar el tiempo y la posición de la piedra.     
    double * pos = new double[tnet];
    double * ti = new double[tnet];
    ofstream salida("datos.txt");

//Agregando los valores iniciales de tiempo y posición.    
    ti[0] = t0;
    pos[0] = y0; 
    cout << " - A continuación, se presentan los valores de tiempo y posición de la piedra hasta llegar al suelo." << endl;
    
//Se imprimen en pantalla los valores calculados.     
    cout << "Tiempo [s] , Posición[m]" <<endl; 
    for (int i=0; i< tnet; i++){

//Agregando los valores tiempo y poscion a partir del primer dt. 
        ti [i+1] = rungekutta4(dt, t0, y0, v0)[0];
        pos[i+1] = rungekutta4(dt, t0, y0, v0)[1];

//Actualizacion de tiempo con el dt. 
        t0+=dt; 
        cout << ti[i] << "        ,      " << pos[i] << endl;
        
//Actualizando el archivo datos.txt con los datos obtenidos.         
        salida << ti[i]<< "," << pos[i] << endl;
        
    }
    
    
    return 0;
   
}