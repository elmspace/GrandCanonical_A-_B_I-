#!/usr/bin/python

import os
from os import system
import sys

PA_values = [0.00000000001, 0.0000000001,0.000000001,0.00000001,0.0000001,0.000001,0.00001,0.0001,0.001,0.01,0.1]
for PA in PA_values:
    system('nohup main ' + str(PA) + ' &> ' + str(PA) +'.out &')
