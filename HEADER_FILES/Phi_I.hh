/*
	Calculating Phi_I
*/
double Phi_I(double ****W){

	double      Q;

	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int k=0;k<Nz;k++){
				eff_wI[i][j][k] = W[2][i][j][k] + w_e[i][j][k];
				qI[i][j][k] = exp(-eff_wI[i][j][k]/NA); //should N be here?
			}
		}
	}

	// Here we are doing the sum to get the single chain partition function
	Q=0.0;
	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int k=0;k<Nz;k++){
				Q+=qI[i][j][k];
			}
		}
	}
	// Normalizing with respect to the volume of the box
	Q/=Nx*Ny*Nz;

	// Here we do the concentration calculation
	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int k=0;k<Nz;k++){

			  phi[2][i][j][k]=(exp(kappaI*muI)/kappaI)*qI[i][j][k];

			}
		}
	}

	return Q;

}
