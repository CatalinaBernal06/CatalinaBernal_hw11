import numpy as np
import matplotlib.pyplot as plt

dat = np.loadtxt('tray.txt')
x = dat[:,0]
v = dat[:,1]
t = dat[:,2]

plt.figure()
plt.plot(x, t, label = 'x vs t')
plt.title('Posicion vs Tiempo')
plt.xlabel('Tiempo')
plt.ylabel('Posicion []')
plt.legend()
plt.savefig('pos.png')

plt.figure()
plt.plot(v, t, label = 'v vs t')
plt.title('Velocidad vs Tiempo')
plt.xlabel('Tiempo')
plt.ylabel('Velocidad []')
plt.legend()
plt.savefig('vel.png')

plt.figure()
plt.plot(v, x, label = 'phase')
plt.title('Velocidad vs Posicion')
plt.xlabel('Velocidad []')
plt.ylabel('Posicion []')
plt.legend()
plt.savefig('phase.png')
