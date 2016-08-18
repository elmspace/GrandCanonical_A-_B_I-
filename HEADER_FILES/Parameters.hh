/*
  In Parameters.hh we set some of the basic parameters
  Most of the parameters are set in global.hh
*/
void Parameters( ){
  
  // Set to 1 to read from restart file
  // Set to 0 to set manually
  Iomega=0;
  
  // Set the morphology 1=on 0=off
  LAM=0;
  HEX=0;
  BCC=0;
  
  // Space resolution
  dxyz[0]=Lx/Nx;
  dxyz[1]=Ly/Ny;
  dxyz[2]=Lz/Nz;

  // Degree of polymerization
  Ns[0]=int(NA);
  Ns[1]=int(NB);
  Ns[2]=int(NI);

  // Interaction parameters
  chi[0]=xAB;
  chi[1]=xAI;
  chi[2]=xBI;

  // Setting up the interaction matrix 3x3
  chiMatrix[0][0]=0.0;     // xAA
  chiMatrix[0][1]=chi[0];     // xAB
  chiMatrix[0][2]=chi[1];     // xAI
 
  chiMatrix[1][0]=chi[0];     // xAB
  chiMatrix[1][1]=0.0;     // xBB
  chiMatrix[1][2]=chi[2];     // xBI
 
  chiMatrix[2][0]=chi[1];     // xAI
  chiMatrix[2][1]=chi[2];     // xBI
  chiMatrix[2][2]=0.0;     // xII
  
  for(int i=0; i<Nx; i++){
    for(int j=0; j<Ny;j++){
      for(int k=0;k<Nz;k++){
	phi[0][i][j][k]=pAave;
	phi[1][i][j][k]=pBave;
	phi[2][i][j][k]=pIave;
      }
    }
  }
  
}
