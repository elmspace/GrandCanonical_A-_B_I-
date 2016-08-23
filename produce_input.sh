#!/bin/bash

if [ $# -eq 1 ]; then
  cut -d " " -f 4- "./PHI/allphi.dat" > "./PHI/$1"

else
  echo "No filename provided."

fi
