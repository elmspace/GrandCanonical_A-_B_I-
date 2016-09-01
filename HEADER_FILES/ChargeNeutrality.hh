/*
  Calculating the eta_hat which should enforce the charge neutrality
*/
void ChargeNeutrality( ){
  double correction_strength=1.0;
  int new_charge_sign=0;
  if(Phi_e_total>0) new_charge_sign=1;
  else if (Phi_e_total<0) new_charge_sign=-1;
  if(charge_sign==new_charge_sign || etaHat>1e4){
  //if(etaHat>0 && Phi_e_total<0)
    correction_strength=etaHat*10+1;
  }
  else{
    correction_strength=1;
  }
  etaHat += correction_strength*Phi_e_total;
  charge_sign=new_charge_sign; 
//  etaHat -= (0.0 - Phi_e_total);
  std::cout<<"etaHat: "<<etaHat<<std::endl;
 
}
