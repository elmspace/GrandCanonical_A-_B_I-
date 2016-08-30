/*
  This function is the core of the program, it calculates the free energy of the system.
*/
void FreeEnergy( ){
  
  const int savefreq=10;
  int iter;
  int msg;
  
  double currentfE, oldfE, deltafE; 
  double QA,QB,QI; 
  double fEW, fEchi, fES, fE_charge; 
  double deltaW;
  double fE_homo;
  
  msg=1;
  oldfE=1.0e2;
  std::ofstream outputFile("./RESULTS/fE.dat");
  std::ofstream outputFile2("./RESULTS/avgphi.dat", std::fstream::app);
  do{
    
    // Calculate the homogenous free energy
    //fE_homo=homogenousfE( );
    
    Wave_Vectors(dxyz);
    currentfE=0.0;
    deltafE=0.0;
    
    iter=0;  
    do{
      fEW=0.0;
      fEchi=0.0;
      fES=0.0;
      
      // Solving the MDE
      QA=Phi_A(w);
      QB=Phi_B(w);
      QI=Phi_I(w);
      Phi_e( );
      // Solving the PBE
      Solve_PB_Equation( );
      // Calculating the incompressibility
      Incompressibility( );
      TotalCharge( );
      ChargeNeutrality( );
      
      fEW=0.0;
      fEchi=0.0;
      deltaW=0.0;           
      fE_charge=0.0;
      
      // Calculating the gradient of the electrostatic potential
      Gradient(V,0,dxyz,Gradient_V_x);
      Gradient(V,1,dxyz,Gradient_V_y);
      Gradient(V,2,dxyz,Gradient_V_z);
      
      // Calculating the contribution to the free energy from electrostatics
      fE_charge=0.0;
      for(int i=0;i<Nx;i++){
      	for(int j=0;j<Ny;j++){
      	  for(int k=0;k<Nz;k++){
	         fE_charge -= ((12.0*Pi*epsilon)/tau)*(pow(Gradient_V_x[i][j][k],2)+pow(Gradient_V_y[i][j][k],2)+pow(Gradient_V_z[i][j][k],2))*(dxyz[0]*dxyz[1]*dxyz[2]);
	         fE_charge += (NA*phi_e[i][j][k]*V[i][j][k])*(dxyz[0]*dxyz[1]*dxyz[2]);
	        }
	      }
      }
      fE_charge/=((Nx*dxyz[0])*(Ny*dxyz[1])*(Nz*dxyz[2]));
      
      // Contribution from the 
      
      // Calculaing the new omega fields and other contributions to the free energy
      for(int i=0;i<Nx;i++){
      	for(int j=0;j<Ny;j++){
	        for(int k=0;k<Nz;k++){
	          for(int ii=0;ii<ChainType;ii++){
	            newW[ii][i][j][k] = 0.0;  
	            for(int jj=0;jj<ChainType;jj++){
		            newW[ii][i][j][k] += ((chiMatrix[ii][jj]*phi[jj][i][j][k]));
             		fEchi += phi[ii][i][j][k]*chiMatrix[ii][jj]*phi[jj][i][j][k]*dxyz[0]*dxyz[1]*dxyz[2];
	            }
	            newW[ii][i][j][k] += eta[i][j][k];
	            fEW += (newW[ii][i][j][k]*phi[ii][i][j][k]*dxyz[0]*dxyz[1]*dxyz[2]);
	            delW[ii][i][j][k] = newW[ii][i][j][k]-w[ii][i][j][k];
	            deltaW += fabs(delW[ii][i][j][k]);
	          }
	          w_e[i][j][k] = NA*V[i][j][k] + etaHat; // Also includes the contribution from charge neutrality 
	        }
	      }
      }
      fES=exp(muA)*QA + exp(kappaB*muB)*QB + exp(kappaI*muI)*QI;
      
      deltaW/=(Nx*Ny*Nz);
      fEchi/=(2.0*((Nx*dxyz[0])*(Ny*dxyz[1])*(Nz*dxyz[2])));
      fEW/=(((Nx*dxyz[0])*(Ny*dxyz[1])*(Nz*dxyz[2])));
      
      // Total free energy
      currentfE=-fES-fEW+fEchi-fE_charge;//-fE_homo;
      
      // Difference between the curent of old free energy
      deltafE=fabs(currentfE-oldfE);
      
      if(RunTimePrint==1){
	// Output
	std::cout<<iter<<"  fE: "<<currentfE<< "  dfE: " << deltafE <<"  dW: " << deltaW<<"  dPhi(Nx/2)(Ny/2)(Nz/2): "<<delphi[Nx/2][Ny/2][Nz/2]<< " Phi A: " <<phi_average[0]<< " Phi B: " <<phi_average[1]<<" Phi I: " <<phi_average[2]<<std::endl;
      }      
      
      // Using simple mixing to update the omega fields
      for(int i=0;i<Nx;i++){
      	for(int j=0;j<Ny;j++){
      	  for(int k=0;k<Nz;k++){
      	    for(int chain=0;chain<ChainType;chain++){
	            w[chain][i][j][k]+=(epsilon_w*delW[chain][i][j][k]-epsilon_p*delphi[i][j][k]);
	          }
      	  }
	      }
      }
      
      // Save the data every _savefreq_ number of iteration
      if((iter%savefreq)==0){
      	saveData();
      }
      
      oldfE=currentfE;
      iter++;
    }while(deltaW>precision);
    
    
    outputFile <<dxyz[0]*Nx<<" "<<dxyz[1]*Ny<<" "<<dxyz[2]*Nz<<" "<<currentfE<<" "<<chi[4]<<std::endl;
	outputFile2<< xAB <<" "<< phi_average[0] <<" "<< phi_average[1] <<" "<< muB <<" "<<muI<<std::endl;	
	
    
    if(Box_min==1){
      
      // Minimizing with respect to box size
      Box_Minimization( );
      
      if(oldfE<currentfE){
      	msg=0;
      }
      if(msg==1){
      	oldfE=currentfE;
      }
    }else{
      msg=0;
    }
    
  }while(msg==1);
  
  outputFile <<"Done"<<std::endl;
  outputFile.close();
  outputFile2.close();
  saveData();
  
  
}
