#!/usr/bin/python

import os
from os import system
import sys
import time

chi_values = [1.1,1.2,1.3,1.4,1.5,1.6,1.7, 3.8, 3.9, 4, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6, 4.7, 4.8, 4.9, 5, 5.6, 5.7, 5.8, 5.9, 6]
muB_values = [-2, -1.8,-1.6,-1.4,-1.2,-1,-0.8,-0.6,-0.4,-0.2,-0.1,-0.075,-0.05,-0.025,0,0.025,0.05,0.075,0.1,0.2,0.4,0.6,0.8,1,1.2,1.4,1.6,1.8,2]
for chi in chi_values:
    for muB in muB_values:
        system('nohup main ' + str(muB) + ' ' + str(chi) + ' &> ' +str(chi) +'.'+ str(muB) +'.out &')
    
    time.sleep(20*60)
