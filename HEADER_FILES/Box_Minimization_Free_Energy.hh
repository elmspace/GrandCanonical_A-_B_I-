/*
  In this function, which is being called by Box_Minimization function
  will calculate the entropy of the system for a small change in box size
*/
double FreeEnergy_Box_Edition( ){

  double  QA,QB,QI; 
  double  fES,currentfE; 

  Wave_Vectors(dxyz_temp);
  
  QA=Phi_A(w_temp);
  QB=Phi_B(w_temp);
  QI=Phi_I(w_temp);
  
  fES=exp(muA)*QA + exp(kappaB*muB)*QB + exp(kappaI*muI)*QI;
  currentfE=-fES;
  
  return currentfE;
  
}
