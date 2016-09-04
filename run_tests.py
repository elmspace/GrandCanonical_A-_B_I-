#!/usr/bin/python

import os
from os import system
import sys

muB_values = [-2.0, -1.8,-1.6,-1.4,-1.2,-1.0,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.2,1.4,1.6,1.8,2.0]
for muB in muB_values:
    system('nohup main ' + str(muB) + ' &> ' + str(muB) +'.out &')
