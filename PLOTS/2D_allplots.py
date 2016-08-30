#!/usr/bin/python
import os
from os import system
import subprocess
import sys

<<<<<<< HEAD
chi_values = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2, 2.5, 3, 3.5, 4, 4.5]
for chi in chi_values:
=======
for i in range(1,50):
    chi=0.1*i
>>>>>>> 94d89dd3a7adaa903a1a8ab2f436d7eba9aad647
    os.environ['chi'] = str(chi)
    system('gnuplot -persist ./plot_xy.p &')
    system('gnuplot -persist ./plot_yz.p &')
    system('gnuplot -persist ./plot_xz.p &')
