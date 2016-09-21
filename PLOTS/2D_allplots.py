#!/usr/bin/python
import os
from os import system
import subprocess
import sys

muB_values = [-2, -1.8,-1.6,-1.4,-1.2,-1,-0.8,-0.6,-0.4,-0.2,-0.1,-0.075,-0.05,-0.025,0,0.025,0.05,0.075,0.1,0.2,0.4,0.6,0.8,1,1.2,1.4,1.6,1.8,2]
for muB in muB_values:
    os.environ['PA'] = "2.2."+str(muB)
    system('gnuplot -persist ./plot_xy.p &')
    system('gnuplot -persist ./plot_yz.p &')
    system('gnuplot -persist ./plot_xz.p &')
