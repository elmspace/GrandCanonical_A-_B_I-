/*
  Calculating the eta_hat which should enforce the charge neutrality
*/
void ChargeNeutrality( ){
  double correction_strength=1.0;
  int new_charge_sign=1;

  if(Phi_e_total>0) new_charge_sign=1;
  else if (Phi_e_total<0) new_charge_sign=-1;

  if(charge_sign==new_charge_sign && iter>4){
    if(fabs(old_Phi_e_total)>fabs(Phi_e_total)){
      correction_strength=etaHat*1000+1;
    }
  }
  else{
    correction_strength=1;
  }
  while(fabs(correction_strength*Phi_e_total)>fabs(etaHat/5.)){
    correction_strength/=10;
  }
  
  etaHat += correction_strength*Phi_e_total;
  
  charge_sign=new_charge_sign; 
  old_Phi_e_total=Phi_e_total;
//  etaHat -= (0.0 - Phi_e_total);
  std::cout<<"etaHat: "<<etaHat<<std::endl;
 
}
