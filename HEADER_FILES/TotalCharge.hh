/*
  Calculating the total charge in the system
  idealy we want this to be zero over the entire system
*/
void TotalCharge( ){

  Phi_e_total = 0.0;
  
  for(int i=0;i<Nx;i++){
    for(int j=0;j<Ny;j++){
      for(int k=0;k<Nz;k++){	
	Phi_e_total += (phi[2][i][j][k] - PA*phi[0][i][j][k]);
      }
    }
  }
  Phi_e_total/=((Nx*dxyz[0])*(Ny*dxyz[1])*(Nz*dxyz[2])); // Total charge per volume
  
  std::cout<<"Total charge: "<<Phi_e_total<<std::endl;
}
