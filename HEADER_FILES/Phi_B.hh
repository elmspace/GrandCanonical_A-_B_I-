double Phi_B(double ****W){

	double      Q;

	// Here is the for loop for doing the qint, setting it to 1.0
	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int l=0;l<Nz;l++){
				qint[i][j][l]=1.0;
			}
		}
	}

	// Here we will solve the diffusion question
	solveModDiffEqn_FFT(qB,W[1],qint,ds,Ns[1],1,k_vector);

	// Here we are doing the sum to get the single chain partition function
	Q=0.0;
	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int l=0;l<Nz;l++){
				Q+=qB[i][j][l][Ns[1]];
			}
		}
	}
	// Normalizing with respect to the volume of the box, note DXYZ is not used because dxyz is skipped in integrand
	Q/=Nx*Ny*Nz;

	// Here we do the concentration calculation
	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int l=0;l<Nz;l++){

				phi[1][i][j][l]=0.0;

				for(int s=0;s<(Ns[1]+1);s++){
					if(s==0 || s==Ns[1]){
						phi[1][i][j][l]+=0.5*qB[i][j][l][s]*qB[i][j][l][Ns[1]-s]*ds;
					}else{
						phi[1][i][j][l]+=qB[i][j][l][s]*qB[i][j][l][Ns[1]-s]*ds;
					}
				}

				phi[1][i][j][l]*=(pBave/(Q*kappa));

			}
		}
	}

	return Q;

}
