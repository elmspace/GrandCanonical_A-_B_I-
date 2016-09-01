/*
 In this file we save data to either be used for next generation calculation,
 or for visualization purposes. Plotting scripts can be found in PLOT and MATLAB files.
*/
void saveData( ){

  int I, J, K;
  std::cout<<"Saving data . . ."<<std::endl;
  
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writing to data files (1D phi output in the x-direction)
  std::ofstream outputFilex("./PHI/phi_x"+string_PA+".dat");
  J=Ny/2;
  K=Nz/2;
  for(int i=0;i<Nx;i++){
    outputFilex <<i*dxyz[0]<<" "<<phi[0][i][J][K]<<" "<<phi[1][i][J][K]<<" "<<phi[2][i][J][K]<<std::endl;
  }
  outputFilex.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writing to data files (1D phi output in the y-direction)
  std::ofstream outputFiley("./PHI/phi_y"+string_PA+".dat");
  I=Ny/2;
  K=Nz/2;
  for(int j=0;j<Ny;j++){
    outputFiley <<j*dxyz[0]<<" "<<phi[0][I][j][K]<<" "<<phi[1][I][j][K]<<" "<<phi[2][I][j][K]<<std::endl;
  }
  outputFiley.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writing to data files (1D phi output in the z-direction)
  std::ofstream outputFilez("./PHI/phi_z"+string_PA+".dat");
  I=Nx/2;
  J=Ny/2;
  for(int k=0;k<Nz;k++){
    outputFilez <<k*dxyz[2]<<" "<<phi[0][I][J][k]<<" "<<phi[1][I][J][k]<<" "<<phi[2][I][J][k]<<std::endl;
  }
  outputFilez.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writing to data files (2D phi out put, in the x-y plane)
  std::ofstream outputFilexy("./PHI/phi_xy"+string_PA+".dat");
  K=Nz/2;
  for(int i=0;i<Nx;i++){
    for(int j=0;j<Ny;j++){
      outputFilexy <<i*dxyz[0]<<" "<<j*dxyz[1]<<" "<<phi[0][i][j][K]<<" "<<phi[1][i][j][K]<<" "<<phi[2][i][j][K]<<std::endl;
    }
  }
  outputFilexy.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writing to data files (2D phi out put, in the x-z plane)
  std::ofstream outputFilexz("./PHI/phi_xz"+string_PA+".dat");
  J=Ny/2;
  for(int i=0;i<Nx;i++){
    for(int k=0;k<Nz;k++){
      outputFilexz <<i*dxyz[0]<<" "<<k*dxyz[2]<<" "<<phi[0][i][J][k]<<" "<<phi[1][i][J][k]<<" "<<phi[2][i][J][k]<<std::endl;
    }
  }
  outputFilexz.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writing to data files (2D phi out put, in the y-z plane)
  std::ofstream outputFileyz("./PHI/phi_yz"+string_PA+".dat");
  I=Nx/2;
  for(int j=0;j<Ny;j++){
    for(int k=0;k<Nz;k++){
      outputFileyz <<j*dxyz[1]<<" "<<k*dxyz[2]<<" "<<phi[0][I][j][k]<<" "<<phi[1][I][j][k]<<" "<<phi[2][I][j][k]<<std::endl;
    }
  }
  outputFileyz.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writing to data files (All of the phi matrix)
  std::ofstream outputFileAllPhi("./PHI/allphi"+string_PA+".dat");
  for(int i=0;i<Nx;i++){
   for(int j=0;j<Ny;j++){
    for(int k=0;k<Nz;k++){
        outputFileAllPhi <<i<<" "<<j<<" "<<k<<" "<<phi[0][i][j][k]<<" "<<phi[1][i][j][k]<<" "<<phi[2][i][j][k]<<std::endl;
      }
    }
  }
  outputFileAllPhi.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writing to data files (All of the omega matrix)
  std::ofstream outputFileOmega("./PHI/omega.dat");
  for(int i=0;i<Nx;i++){
    for(int j=0;j<Ny;j++){
      for(int k=0;k<Nz;k++){
        outputFileOmega <<i<<" "<<j<<" "<<k<<" "<<w[0][i][j][k]<<" "<<w[1][i][j][k]<<" "<<w[2][i][j][k]<<std::endl;
      }
    }
  }
  outputFileOmega.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
