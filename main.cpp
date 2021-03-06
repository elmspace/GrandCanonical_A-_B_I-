// Include files are mainly in HEADER_FILES
// Look at Global file for path to FFTW libraries


#include "./global.hh"
#include "./HEADER_FILES/Memory.hh"
#include "./HEADER_FILES/Allocate.hh"  
#include "./HEADER_FILES/Read_Input.hh"
#include "./HEADER_FILES/Parameters.hh"
#include "./HEADER_FILES/Save_Data.hh"
#include "./HEADER_FILES/Wave_Vectors.hh"
#include "./HEADER_FILES/Omega.hh"
#include "./HEADER_FILES/Solve_Diffusion_Equation.hh"
#include "./HEADER_FILES/Solve_PB_Equation.hh"
#include "./HEADER_FILES/Phi_A.hh"
#include "./HEADER_FILES/Phi_B.hh"
#include "./HEADER_FILES/Phi_I.hh"
#include "./HEADER_FILES/Phi_e.hh"
//#include "./HEADER_FILES/Homogenous_Free_Energy.hh"                // For now, I will comment this out, need to write a Homogenous Free energy function for the Grand Theory
#include "./HEADER_FILES/Incompressibility.hh"
#include "./HEADER_FILES/Box_Minimization_Free_Energy.hh"
#include "./HEADER_FILES/Box_Minimization.hh"
#include "./HEADER_FILES/Gradient.hh"
#include "./HEADER_FILES/ChargeNeutrality.hh"
#include "./HEADER_FILES/TotalCharge.hh"
#include "./HEADER_FILES/Free_Energy.hh"

// The order of calculations are set in Mod files
// You can also do this here, but I am trying to keep things clean here
#include "./MODS/Mod1.hh"

using namespace std;

int main(int argc, char *argv[]){
  if (argc!=3){
    cout<<"usage: "<< argv[0] <<" <muB> <chi_AB>"<<std::endl;
    return 1;
  }
  else{
    muB=atof(argv[1]);
    xAB=atof(argv[2]);
    string_muB=SSTR(muB);
    string_chi=SSTR(xAB);
    string_addon=string_chi+"."+string_muB+"."+string_PA;
    Mod1();
  }
  
  return 0;
}
