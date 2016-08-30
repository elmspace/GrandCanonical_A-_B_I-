#!/usr/bin/python
import os
from os import system
import subprocess
import sys

chi_values = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2, 2.5, 3, 3.5, 4, 4.5]
for chi in chi_values:
    os.environ['chi'] = str(chi)
    system('gnuplot -persist ./plot_xy.p &')
    system('gnuplot -persist ./plot_yz.p &')
    system('gnuplot -persist ./plot_xz.p &')
