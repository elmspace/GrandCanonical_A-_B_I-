#!/usr/bin/python

import os
from os import system
import sys

PA_values = [0.00000000005, 0.0000000005,0.000000005,0.00000005,0.0000005,0.000005,0.00005,0.0005,0.005,0.05,0.5]
for PA in PA_values:
    system('nohup main ' + str(PA) + ' &> ' + str(PA) +'.out &')
