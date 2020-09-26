import pandas
import numpy as np
from matplotlib import pyplot as plt

bin_file = 'bin_p_g.csv'
fol_file = 'fol_p_g.csv'

bindata = pandas.read_csv(bin_file, ';')
foldata = pandas.read_csv(fol_file, ';')

plt.plot(bindata['n'], bindata['t']*1000, color='g', label='Binary')
plt.plot(foldata['n'], foldata['t']*1000, color='b', label='Folding')

plt.title('Búsquedas con algoritmos logaritmicos')
plt.xlabel('Ventana de elementos')
plt.ylabel('Tiempo [us]')
plt.legend()


plt.show()
