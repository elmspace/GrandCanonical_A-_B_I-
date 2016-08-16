reset

path= "../RESULTS/" # Mac
path= "../RESULTS/"

set autoscale
set key r c
set nokey
set xr [0.0 : 1.0]

plot path."Spinodal.dat" using 2:1 pt 6 lc 3 w p,\
     path."Spinodal.dat" using 3:1 pt 6 lc 3 w p


pause(-1)

reset

path= "../RESULTS/"

set autoscale
set key r c
set xr [0.0 : 1.0]

plot   path."HomfE.dat" using 1:2 title "A" w lp

pause(-1)
