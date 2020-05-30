#!/bin/bash

echo "Se esta estudiando el movimiento rectilineo uniformemente-acelerado de una roca y se grafica su movimiento: " 
echo ""
echo ""

g++ main.cpp #Compilando archivo main.cpp

./a.out #Ejecutando el archivo a.out

python grafica.py #Ejecutando el script grafica.py, graficando los valores obtenidos ubicados en datos.txt y guarbando la grafica en grafico.pdf

