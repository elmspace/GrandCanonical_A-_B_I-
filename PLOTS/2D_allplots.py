#!/usr/bin/python
import os
from os import system
import subprocess
import sys

for i in range(1,50):
    chi=0.1*i
    os.environ['chi'] = str(chi)
    system('gnuplot -persist ./plot_xy.p &')
    system('gnuplot -persist ./plot_yz.p &')
    system('gnuplot -persist ./plot_xz.p &')
