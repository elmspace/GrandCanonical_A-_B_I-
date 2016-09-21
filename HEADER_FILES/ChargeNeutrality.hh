/*
  Calculating the eta_hat which should enforce the charge neutrality
*/
void ChargeNeutrality(double delta_W ){
  double correction_strength=1.0;
  int new_charge_sign=1;

  if(Phi_e_total>0) new_charge_sign=1;
  else if (Phi_e_total<0) new_charge_sign=-1;
  if(delta_W>precision){
    if(charge_sign==new_charge_sign && iter>4){
      if(fabs(old_Phi_e_total)>=fabs(Phi_e_total) || iter<300){
        //correction_strength=etaHat*1e13+1;
        etaHat+=new_charge_sign*2.0;
      }
    }
    else{
      etaHat+=new_charge_sign/10.;
      //correction_strength=1e16;
    }
  }else{
    // If the charge_sign flipped under n reductions, use one more reduction
    if(new_charge_sign!=charge_sign){
      number_of_reductions++;
      repeated_same_sign=0;
    }
    else{
      repeated_same_sign++;
    }
    if(repeated_same_sign>10) {number_of_reductions--;}
    if(number_of_reductions<=max_number_of_reductions){
      etaHat+=10*new_charge_sign/(1.0*pow(2.0,number_of_reductions));
    }
  }

  /*
  while(fabs(correction_strength*Phi_e_total)>fabs(etaHat/5.)){
    correction_strength/=10;
  }*/
  /*
  etaHat += correction_strength*Phi_e_total;
 */ 
  charge_sign=new_charge_sign; 
  old_Phi_e_total=Phi_e_total;
//  etaHat -= (0.0 - Phi_e_total);
  std::cout<<"etaHat: "<<etaHat<<std::endl;
 
}
