#include <iostream>
using namespace std;

int bienvenida (){
    cout << "Esta funcion calcula el factorial de un numero entero dado por el usuario" << endl;
}

int factorial(int n){
    if(n<=1){
        return 1;
    } 
    else {
        return n*factorial(n-1);
    }
}

int main (){
    int numero;
    cout <<"Esta funcion calcula el factorial de un numero entero dado por el usuario" << endl;
    cout << "Ingrese el numero entero para calcular su factorial:" << endl;
    cin >> numero;
    cout << "El factorial de " << numero << " es: " << factorial(numero) << endl;
    return 0;
}