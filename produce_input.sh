#!/bin/bash

if [ $# -eq 1 ]; then
  cut -d " " -f 4- "./PHI/allphi${1}.dat" > "./INPUT/phi${1}.in" 
  cut -d " " -f 4- "./PHI/omega${1}.dat" > "./INPUT/omega${1}.in"
  cut -d " " -f 4- "./PHI/eta${1}.dat" > "./INPUT/eta${1}.in"
  cut -d " " -f 4- "./PHI/V${1}.dat" > "./INPUT/V${1}.in"
  cut -d " " -f 4- "./PHI/omega_e${1}.dat" > "./INPUT/omega_e${1}.in"
  cp "./PHI/etaHat${1}.dat" "./INPUT/etaHat${1}.in"
else
  echo "Usage: $0 <input suffix>"

fi
