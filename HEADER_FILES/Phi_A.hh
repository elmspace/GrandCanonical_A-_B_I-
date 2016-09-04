/*
  Calculating PhiA
*/
double Phi_A(double ****W){

	double      Q;
 
	// Here is the for loop for doing the qint, setting it to 1.0
	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int l=0;l<Nz;l++){
				qint[i][j][l] = 1.0;
				eff_wA[i][j][l] = W[0][i][j][l] - PA*w_e[i][j][l];
			}
		}
	}
  
  
	// Here we will solve the diffusion question
	solveModDiffEqn_FFT(qA,eff_wA,qint,ds,Ns[0],1,k_vector);
	// Here we are doing the sum to get the single chain partition function
	Q=0.0;
	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int l=0;l<Nz;l++){
				Q+=qA[i][j][l][Ns[0]];
			}
		}
	}
	// Normalizing with respect to the volume of the box
	Q/=Nx*Ny*Nz;
  
	// Here we do the concentration calculation
	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int l=0;l<Nz;l++){
				phi[0][i][j][l]=0.0;
				for(int s=0;s<(Ns[0]+1);s++){
					if(s==0 || s==Ns[0]){
						phi[0][i][j][l]+=0.5*qA[i][j][l][s]*qA[i][j][l][Ns[0]-s]*ds;
					}else{
						phi[0][i][j][l]+=qA[i][j][l][s]*qA[i][j][l][Ns[0]-s]*ds;
					}
				}
				phi[0][i][j][l]*=exp(muA);
			}
		}
	}

	return Q;
}
