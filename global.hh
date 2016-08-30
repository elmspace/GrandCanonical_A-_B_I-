/*
   Global.hh conatins variables which will be used all throughout the program
   The path for fftw libraries for the devices which this code will be used on is included
*/

//#include </usr/local/include/fftw3.h>                                // This is for My Mac Pro
//#include </opt/sharcnet/fftw/3.3.2/intel/include/fftw3.h>          // This is for Sharcnet
#include </usr/include/fftw3.h>                                    // This is for use on Landua
//#include </usr/local/include/fftw3.h>                              // This is for elmspace2
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <stdio.h>     
#include <iostream>  
#include <fstream>
#include <complex>
#include <stdlib.h>   
#include <math.h>     
#include <string>
#include <sstream>
#include <time.h>      

#define SSTR( x ) static_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Box resolution
#define Nx 20
#define Ny 20
#define Nz 20

#define ChainType 3
#define Pi 3.14159265358979262

// Box minimization 1=on/0=off
int Box_min = 0;

// Print during run time
int RunTimePrint= 1;

// Setting Parameters
// Degree of polymerization
double NA = 1000;
double NB = NA;
double NI = 1;

// Charge fraction value [0..1]
double PA = 1.0e-20;//.00001;

// Average phis
double pAave = 0.5;
double pBave = 1-pAave;
double pIave = pAave*PA;

// Relative chain length
double kappaB = NB/NA;
double kappaI = NI/NA;

// Chemical potentials
double muA = 0.0;
double muB = 2.0;
double muI = 0.0;

// Total charge in system
double Phi_e_total;

// Look at theory pdf for this
double tau = 456.0; //Using T=300K, b=1nm, tau=700 almost exactly 

// Dielectric constant
double epsilon = 1.0;

// Flory-Higgins parameter
double xAB = 0.0;
double xAI = 0.0;
double xBI = 0.0;

std::string string_chi=SSTR(xAB);


// Box size
double Lx = 4.0;
double Ly = 4.0;
double Lz = 4.0;

// Mixing parameters
double epsilon_w = 0.05;
double epsilon_p = 0.05;

// Calculation percision
double precision=1.0e-3;

// Box minimization step sizes
double del_Box=0.1;

// Step size along contour of the chain
double ds = 1.0/NA;

// Auxiliary fields
double ****w, ****phi;
double ***w_e, ***phi_e;
double ***eff_wA, ***eff_wI;

// Electric potential
double ***V;

// Gradient of electric potential
double ***Gradient_V_x;
double ***Gradient_V_y;
double ***Gradient_V_z;

// Incomp Legrange parameter
double ***eta;

// Chanrge neutrality parameter
double etaHat = 0.0;

// Other parameters
double *chi;
double **chiMatrix;
int *Ns;
double ***k_vector;
double *dxyz;
double *Kx,*Ky,*Kz;
double *phi_average;

// Used for convergance measuring
double ***delphi;
double ****delW;
double ****newW;

// Used for box minimization
double *dxyz_temp;
double *box_x,*box_y,*box_z;
double *box_fE;
double ****w_temp;

// End-integrated propagators
double ****qA;
double ****qB;
double ***qI;
double ***qint;

// Used in the Diffusion solver
double ***wds, ***kds;

// Action parameters
int Iomega;
int LAM, HEX, BCC;

// FFTW Parameters
fftw_plan forward_plan, inverse_plan;
fftw_complex *input_q, *transformed_q, *final_q;
fftw_plan forward_plan_PB,inverse_plan_PB;
fftw_complex *input_PB, *transformed_PB, *final_PB;



