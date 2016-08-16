/*
 This folder I am trying to calculate the over form of the free energy as a function of
 concentration. And determine co-existing regions (This was mainly for testing)
*/
using namespace std;

void Mod0(){
  
  int M = 2000;
  int done;
  double m,b,y;
  double p_left, p_right;
  double slope_diff, eps_val = 1.0e-4;
  double fE_homo;
  double dPhi = 1.0/double(M);

  double *p, *f, *df;

  p=create_1d_double_array(M,"p");
  f=create_1d_double_array(M,"f");
  df=create_1d_double_array(M,"df");

  Allocate(1);

  std::ofstream outputFile3("./RESULTS/Spinodal.dat");
	
  // Run over some parameter
  xAB=0;
  do{
    
    
    //___________________________________________________________________________
    Parameters( );
    pAave = 0;
    pIave = pAave*PA;
    pBave = 1.0-pAave-pIave;
    
    // Calculating the homogenous free energy **********
    std::ofstream outputFile("./RESULTS/HomfE.dat");
    for(int i=0; i<M; i++){
      fE_homo=homogenousfE( );
      outputFile<<pAave<<" "<<fE_homo<<endl;
      p[i]=pAave;
      f[i]=fE_homo;
      pAave = (i+1)*dPhi;
      pIave = pAave*PA;
      pBave = 1.0-pAave-pIave;
    }
    outputFile.close();
    // **************************************************
    
    // Calculating the slope of free energy *************
    for(int i=1;i<(M-1);i++){ 
      df[i]=(f[i+1]-f[i-1])/(2.0*dPhi);
    }
    df[0]=(f[1]-f[0])/dPhi;
    df[M-1]=(f[M-1]-f[M-2])/dPhi;
    // **************************************************
    std::ofstream outputFile7("./RESULTS/HomdfE.dat");
    for(int i=0; i<M; i++){
      outputFile7<<dPhi*i<<" "<<df[i]<<endl;
    }
    outputFile7.close();
    
    done = 0;
    for(int i=0;i<M;i++){
      for(int j=M-1;j>i;j--){
	slope_diff = df[i] - df[j];
	if(abs(slope_diff)<eps_val){
	  m = (f[i]-f[j])/(p[i]-p[j]);
	  b = f[i] - m*p[i];
	  for(int k=i+1;k<j;k++){
	    y = m*p[k]+b;
	    if(f[k]<y){
	      break;
	    }else{
			p_left = p[i];
			p_right = p[j];
			done = 1;
			cout<<xAB<<" "<<p_left<<" "<<p_right<<endl;
			outputFile3<<xAB<<" "<<p_left<<" "<<p_right<<endl;
			break;
	    }
	  }
	}
	if(done==1){break;}
      }
    }

    //_________________________________________________________________________________
    xAB+=0.1;
  }while(xAB<15);

  outputFile3.close();

  destroy_1d_double_array(p);
  destroy_1d_double_array(f);
  destroy_1d_double_array(df);
  Allocate(-1);
 
}
