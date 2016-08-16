/*
  In this header file, we will be using FFTW to solve the PB equation
*/
void Solve_PB_Equation( ){

  int ss;

  for(int i=0;i<Nx;i++){
    for(int j=0;j<Ny;j++){
      for(int k=0;k<Nz;k++){
	ss=k+Nz*(j+Ny*i);
	input_PB[ss][0]=(-(NA*tau)/(epsilon*24.0*Pi))*(phi_e[i][j][k]);
	input_PB[ss][1]=0.0;
      }
    }
  }
  fftw_execute(forward_plan_PB);

  for(int i=0;i<Nx;i++){
    for(int j=0;j<Ny;j++){
      for(int k=0;k<Nz;k++){
	ss=k+Nz*(j+Ny*i);
	if(k_vector[i][j][k]==0.0){
	  transformed_PB[ss][0]=0.0; 
	  transformed_PB[ss][1]=0.0;
	}else{
	  transformed_PB[ss][0]/=-k_vector[i][j][k]; 
	  transformed_PB[ss][1]/=-k_vector[i][j][k]; 
	}
      }
    }
  }
  fftw_execute(inverse_plan_PB);

  for(int i=0;i<Nx;i++){
    for(int j=0;j<Ny;j++){
      for(int k=0;k<Nz;k++){
	ss=k+Nz*(j+Ny*i);
	V[i][j][k]=(final_PB[ss][0]/(Nx*Ny*Nz));
      }
    }
  }
  

}
