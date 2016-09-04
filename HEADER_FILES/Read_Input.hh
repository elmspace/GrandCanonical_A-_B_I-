#include <fstream>
#include <iostream>
void Read_Input(bool phi_in, bool omega_in, bool eta_in, bool V_in, bool Omega_e_in, bool etaHat_in, std::string string_addon_in)
{
  if(phi_in){
    std::ifstream phi_input("./INPUT/phi"+string_addon_in+".in");
    if(phi_input.is_open()){
      for(int i=0;i<Nx;i++){
        for(int j=0;j<Ny;j++){
          for(int k=0;k<Nz;k++){
            phi_input >> phi[0][i][j][k];
            phi_input >> phi[1][i][j][k];
            phi_input >> phi[2][i][j][k];
            phi_input >> phi_e[i][j][k];
          }
        }
      }
    }
    else{
      std::cerr << "Phi input file invalid."<<std::endl;
      exit(1);
    }
  }

  if(omega_in){
    std::ifstream omega_input("./INPUT/omega"+string_addon_in+".in");
    if(omega_input.is_open()){
      for(int i=0;i<Nx;i++){
        for(int j=0;j<Ny;j++){
          for(int k=0;k<Nz;k++){
            omega_input >> w[0][i][j][k];
            omega_input >> w[1][i][j][k];
            omega_input >> w[2][i][j][k];
          }
        }
      }
    }
    else{
      std::cerr << "Omega input file invalid."<<std::endl;
      exit(1);
    }
  }

  if(eta_in){
    std::ifstream eta_input("./INPUT/eta"+string_addon_in+".in");
    if(eta_input.is_open()){
      for(int i=0;i<Nx;i++){
        for(int j=0;j<Ny;j++){
          for(int k=0;k<Nz;k++){
            eta_input >> eta[i][j][k];
          }
        }
      }
    }
    else{
      std::cerr << "Eta input file invalid."<<std::endl;
      exit(1);
    }
  }


  if(V_in){
    std::ifstream V_input("./INPUT/V"+string_addon_in+".in");
    if(V_input.is_open()){
      for(int i=0;i<Nx;i++){
        for(int j=0;j<Ny;j++){
          for(int k=0;k<Nz;k++){
            V_input >> V[i][j][k];
          }
        }
      }
    }

    else{
      std::cerr << "V input file invalid."<<std::endl;
      exit(1);
    }
  }
  if(Omega_e_in){
    std::ifstream Omega_e_input("./INPUT/omega_e"+string_addon_in+".in");
    if(Omega_e_input.is_open()){
      for(int i=0;i<Nx;i++){
        for(int j=0;j<Ny;j++){
          for(int k=0;k<Nz;k++){
            Omega_e_input >> w_e[i][j][k];
          }
        }
      }
    }
  }

    else{
      std::cerr << "w_e input file invalid."<<std::endl;
      exit(1);
    }
  if(etaHat_in){
    std::ifstream etaHat_input("./INPUT/etaHat"+string_addon_in+".in");
    if(etaHat_input.is_open()){
      etaHat_input >> etaHat;
    }
    else{
      std::cerr << "EtaHat input file invalid."<<std::endl;
      exit(1);
    }
  }


}
