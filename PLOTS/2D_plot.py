import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import pylab as pl

x,y,z,phiA,phiB,phiI,phie = np.loadtxt('../PHI/allphi2.139.0.01.dat').T
phiAxy=phiA[0::20]
phiBxy=phiB[0::20]
phiIxy=phiI[0::20]
phiexy=phie[0::20]

nx=x.max()-x.min()+1
ny=y.max()-y.min()+1
grid = phiBxy.reshape((nx,ny))

fig, ax = plt.subplots(dpi=10)
im = ax.imshow(grid,extent=(x.min(),x.max(),y.max(),y.min()), interpolation='bicubic', cmap=cm.seismic)

fig.colorbar(im, ax=ax)

im.set_clim(0.0,1.0)

#pl.plot(x,phiA,'r')
#pl.plot(x,phiB,'b')


plt.show()
