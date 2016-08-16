/*
  Calculating the homogenous free energy
*/
double homogenousfE( ){

  double  *avphi;
  double  fE_homo;

  avphi=create_1d_double_array(ChainType,"avphi");

  avphi[0]=pAave; // A average
  avphi[1]=pBave; // B average
  avphi[2]=pIave; // I average
  
  fE_homo=0.0;

  for(int i=0;i<ChainType;i++){
    for(int j=i;j<ChainType;j++){
      fE_homo+=avphi[i]*avphi[j]*chiMatrix[i][j];
    }
  }
  if(pAave!=0){
	  fE_homo+=pAave*log(pAave);
  }
  if(pBave!=0){
	  fE_homo+=(pBave/kappa)*log(pBave);
  }
  if(pIave!=0){
	  fE_homo+=(NA*pIave)*log(pIave);
  }
  destroy_1d_double_array(avphi);

  return fE_homo;

}
