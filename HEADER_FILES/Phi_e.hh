/*
Calculating the total charge at position r
*/
void Phi_e( ){

	for(int i=0;i<Nx;i++){
		for(int j=0;j<Ny;j++){
			for(int k=0;k<Nz;k++){
				phi_e[i][j][k] = phi[2][i][j][k] - PA*phi[0][i][j][k];
			}
		}
	}

}
