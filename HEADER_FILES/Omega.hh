/*
  Setting the initial values for the omega fields
  For now they are simple, but you can read in from initial files also
  This was mainly for testing
*/
void omega( ){

  int i,j,k;


  // Setting all omega to zero
  /*
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	w[0][i][j][k]=0.0;
	w[1][i][j][k]=0.0;
	w[2][i][j][k]=0.0;
      }
    }
  }
*/  
  
  // Setting Omega fields manually:
  //____________________________________________________
  // Random
  
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	w[0][i][j][k]= (rand() % 100)/100.0;
	w[1][i][j][k]= (rand() % 100)/100.0;
	w[2][i][j][k]= (rand() % 100)/100.0;
      }
    }
  }
  
  // Step function
 /* for(i=0;i<(Nx/2);i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	w[0][i][j][k]=-5.0;
	w[1][i][j][k]=0.0;
	w[2][i][j][k]=0.0;	
      }
    }
  }*/
  //_____________________________________________________



}
