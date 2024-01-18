import matplotlib.pyplot as plt
import numpy as np

plt.style.use('_mpl-gallery')

# make data
sets = np.fromfile("exp", dtype=float, sep="\n")
x = np.linspace(0, 10, 256, dtype=float)
o = np.power(x, 2)
for z in sets:
	y = pow(x, z)
	fig, ax = plt.subplots()
	ax.plot(x, y, color='b', label="trained")
	ax.plot(x, o, color='r', label="original")
	ax.set(xlim=(0,10),ylim=(0,10))
	ax.legend()
	plt.savefig("{index}.jpg".format(index=z))
