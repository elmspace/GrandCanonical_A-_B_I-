reset

#path= "../PHI/"
path= "../PHI/"
#path= "../PHI/" # Elmspace
path= "../PHI/" # Mac

set pm3d
set iso 10
set samp 10
set palette model RGB
set dgrid3d 64,64,1
set pm3d flush begin ftriangles scansforward interpolate 10,5
   
unset key
unset sur
set hidden3d
set view map 
set autoscale
set size square

   splot path."phi_yz.dat" using 1:2:($3)
pause(-1)
