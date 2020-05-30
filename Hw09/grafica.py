import pandas as pd
import matplotlib.pyplot as plt

#Leyendo el archivo y convirtinedo con ayuda de pandas.
salida = pd.read_table('datos.txt', sep=',', header=None)
salida.columns = ['Tiempo', 'Posicion']

#Ploteando los datos de Posición vs Tiempo.
plt.figure(figsize=(10,7))
plt.scatter(salida.Tiempo, salida.Posicion, color='grey')
plt.grid()
plt.title('Posición de la piedra vs tiempo')
plt.xlabel('Tiempo [s]')
plt.ylabel('Posición [m]')

#Etiquetas a la posición inicial y a la posición final aproximada de la piedra pues el tiempo final es 4.387s se aproxima a 4.4 por el dt utilizado. 
plt.annotate('Pos. Inicial (0.0s , 8.5m)',xy=(salida.Tiempo[0],salida.Posicion[0]), color='red')
plt.annotate('P. Final (4.4s , -0.28m)',xy=(salida.Tiempo[44],salida.Posicion[44]), color='red')

#Guardando la grafica como grafico.pdf. 
plt.savefig('grafico.pdf')