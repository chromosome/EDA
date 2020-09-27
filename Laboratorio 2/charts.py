import pandas
import numpy as np
from matplotlib import pyplot as plt

build_file = 'sa_build.csv'
var_n = 'var_size_random_pattern.csv'
rand_p = 'fixed_size_random_pattern.csv'
common_w = 'most_common_words.csv'

build_t = pandas.read_csv(build_file, ';')
var_n_t = pandas.read_csv(var_n, ';')
rand_p_t = pandas.read_csv(rand_p, ';')
most_cw_t = pandas.read_csv(common_w, ';')


fig = plt.figure()
fig.subplots_adjust(left=None, bottom=None, right=None, top=None, wspace=0.3, hspace=0.2)

### SUFFIX ARRAY BUILD
ax = fig.add_subplot(2,2,1)
ax.plot(build_t['n'], build_t['time'], color='#fcb609')

ax.set_title("a)")#Tiempos de construcción\ndel Suffix Array")
ax.set_ylabel("Tiempo [s]")
ax.set_xlabel("Tamaño del texto")
ax.set_xticks([1e7, 2e7, 3e7, 4e7, 5e7])
ax.set_xticklabels(['10M', '20M', '30M', '40M', '50M'])

### VARING TXT SIZE
ax2 = fig.add_subplot(2,2,2)
ax3 = ax2.twinx()
lns1 = ax2.plot(var_n_t['n'], var_n_t['time_sa']*1000, color='#fb4aeb', label='SuffixArray')
lns2 = ax3.plot(var_n_t['n'], var_n_t['time_bf']/1000, color='#56f7f4', label='Brute Force')

ax2.set_title("b)")#Búsqueda en textos de tamaño variable")
ax2.set_ylabel('Tiempo [\u03BCs]')
ax3.set_ylabel('Tiempo [s]')
ax3.set_yticks(np.linspace(0,0.5,6))
ax2.set_yticks(np.linspace(0,7,8))
ax2.set_xlabel('Tamaño del texto')
ax2.set_xticks([1e7, 2e7, 3e7, 4e7, 5e7])
ax2.set_xticklabels(['10M', '20M', '30M', '40M', '50M'])

lns = lns1+lns2
labs = [l.get_label() for l in lns]
ax2.legend(lns, labs, loc='lower right')


### RANDOM PATTERN
ax4 = fig.add_subplot(2,2,3)
ax5 = ax4.twinx()
order = np.argsort(rand_p_t['p_size'])
lns1 = ax4.plot(rand_p_t['p_size'][order], rand_p_t['time_sa'][order]*1000, color='#fb4aeb', label='SuffixArray')
lns2 = ax5.plot(rand_p_t['p_size'][order], rand_p_t['time_bf'][order]/1000, color='#56f7f4', label='Brute Force')

ax4.set_title("c)")#Búsqueda con patrones\naleatorios")
ax4.set_ylabel('Tiempo [\u03BCs]')
ax5.set_ylabel('Tiempo [s]')
ax5.set_yticks(np.linspace(0.2,0.6,5))
ax4.set_xlabel("Tamaño del patron")


lns = lns1+lns2
labs = [l.get_label() for l in lns]
ax4.legend(lns, labs, loc='lower right')

### MOST COMMON WORDS
ax6 = plt.subplot(2,2,4)
ax7 = ax6.twinx()
x = np.arange(len(most_cw_t['word']))
width = 0.30
lns1 = ax6.bar(x-width/2, most_cw_t['time_sa']*1000, width, color='#fb4aeb', label='SuffixArray')
lns2 = ax7.bar(x+width/2, most_cw_t['time_bf']/1000, width, color='#56f7f4', label='Brute Force')

ax6.set_title("d)")#Búsqueda de las 10 palabras\nmás comunes del Ingles")
ax6.set_ylabel('Tiempo [\u03BCs]')
ax7.set_ylabel('Tiempo [s]')
ax7.set_yticks(np.linspace(0.15,0.6,4))

# lns = lns1+lns2
# labs = [l.get_label() for l in lns]
ax7.legend(lns, labs, loc='lower right')

ax6.set_xticks(x)
ax6.set_xticklabels(most_cw_t['word'])#, rotation='vertical')
ax6.set_xlabel('Palabras')

plt.show()
