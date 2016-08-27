reset

#path= "../PHI/" # Mac
path= "../PHI/"

set autoscale
set key r c
set t wxt persist

plot   path."phi_y"."2.1".".dat" using 1:2 title "A" w lp,\
path."phi_y"."2.1".".dat" using 1:3 title "B" w lp,\
path."phi_y"."2.1".".dat" using 1:4 title "I" w lp



