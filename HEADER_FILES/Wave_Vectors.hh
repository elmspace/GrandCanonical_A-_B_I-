/*
  Here we define the wave vectors used in the Pseudo spectral method
*/
void Wave_Vectors(double *DXYZ){

	double          lx,ly,lz;

	lx=DXYZ[0]*Nx;
	ly=DXYZ[1]*Ny;
	lz=DXYZ[2]*Nz;
 
	for(int i=0;i<(int)Nx/2;i++){Kx[i]=(2.0*Pi*i)/lx;}
	for(int i =(int)Nx/2; i<Nx;i++){Kx[i]=(2.0*Pi*(Nx-i))/lx;}

	for(int i=0;i<(int)Ny/2;i++){Ky[i]=(2.0*Pi*i)/ly;}
	for(int i=(int)Ny/2;i<Ny;i++){Ky[i]=(2.0*Pi*(Ny-i))/ly;}

	for(int i=0;i<(int)Nz/2;i++){Kz[i]=(2.0*Pi*i)/lz;}
	for(int i=(int)Nz/2;i<Nz;i++){Kz[i]=(2.0*Pi*(Nz-i))/lz;}
    
	for(int i=0;i<Nx;i++){Kx[i]*=Kx[i];}
	for(int i=0;i<Ny;i++){Ky[i]*=Ky[i];}
	for(int i=0;i<Nz;i++){Kz[i]*=Kz[i];}

	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int k=0;k<Nz;k++){
				k_vector[i][j][k]=Kx[i]+Ky[j]+Kz[k];
			}
		}
	}

}
