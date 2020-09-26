import pandas
import numpy as np
from matplotlib import pyplot as plt

lin_file = 'lin.csv'
bin_file = 'bin.csv'
fol_file = 'fol.csv'

lindata = pandas.read_csv(lin_file, delimiter=";")
bindata = pandas.read_csv(bin_file, ';')
foldata = pandas.read_csv(fol_file, ';')


plt.subplot(1,2,1)
plt.plot(lindata["n"], lindata["t"], color="r", label="Linear")

plt.title('Búsquedas con algoritmo lineal')
plt.xlabel('Número de elementos en el arreglo')
plt.ylabel('Tiempo [ms]')
plt.legend()

plt.subplot(1,2,2)
plt.plot(bindata['n'], bindata['t']*1000, color='g', label='Binary')
plt.plot(foldata['n'], foldata['t']*1000, color='b', label='Folding')

plt.title('Búsquedas con algoritmos logaritmicos')
plt.xlabel('Número de elementos en el arreglo')
plt.ylabel('Tiempo [us]')
plt.legend()


plt.show()
