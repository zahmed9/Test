# ifndef __CINT__
#include <iostream>
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <string>       // std::string
#include <sstream>      // std::stringstream, std::stringbuf
#include "TStopwatch.h"

#include "pim.h"
#include "eloss.h"

using std::setw;
using std::setprecision;
using std::cout;
using std::cin;
using std::endl;
using namespace std;

//---------------------------------------------------------
double pim::test() {

  double x = fRandom->Uniform(0.0, 1000.0);
  
  return x;
}
//---------------------------------------------------------


//---------------------------------------------------------
void pim::Initilize() {

  fRandom = new TRandom2(0);
  fRandom->GetSeed();

  allset                                      = false;
  print                                       = false;
  kCalcFermi                                  = false;
  kCalcBremss                                 = false;
  kCalcIon                                    = false;

  fDiff                                       = 1e-6;
  fS_I_RF                                     = 0;
  fS_F_RF                                     = 0;
  fS_I_Col                                    = 0;
  fS_F_Col                                    = 0;
  fS_I_RF_GeV                                 = 0;
  fS_F_RF_GeV                                 = 0;
  fS_I_Col_GeV                                = 0;
  fS_F_Col_GeV                                = 0;
  fPion_Alpha                                 = 0;
  fPion_Beta                                  = 0;
  fNRecorded                                  = 0;
  fNGenerated                                 = 0;
  fRatio                                      = 0;
  fWLessShell                                 = 0;
  fWLess1P9                                   = 0;
  fWSqNeg                                     = 0;
  fSDiff                                      = 0;
  fScatElecEnergyLess                         = 0;
  fScatElecThetaLess                          = 0;
  fPionEnergyCMLess                           = 0;
  fSNotEqual                                  = 0;
  fRand                                       = 0;
  fVertex_X                                   = 0;
  fVertex_Y                                   = 0;
  fVertex_Z                                   = 0;
  fElectron_Kin_Col_GeV                       = 11.0;
  fElectron_Kin_Col                           = fElectron_Kin_Col_GeV * 1000.0;
  fElectron_Mass                              = 0.511;
  fElectron_Mass_GeV                          = fElectron_Mass/1000.0;
  fProton_Mass                                = 939.57; // It is the mass of Neutron. The target is Neutron in SoLID DVMP.
  fProton_Mass_GeV                            = fProton_Mass/1000.0;
  fNeutron_Mass                               = 938.27; // Its is the mass of Proton which in SoLID DVMP is outgoing reocil Proton
  fNeutron_Mass_GeV                           = fNeutron_Mass/1000.0;
  fRecoilProton_Mass                          = 938.27;
  fRecoilProton_Mass_GeV                      = fRecoilProton_Mass/1000.0;
  fPion_Mass                                  = 139.57;
  fPion_Mass_GeV                              = fPion_Mass/1000.0;
  fAlpha                                      = 1./137.036;
  fMom_Ratio                                  = 0.460029;
  fMom_Dif                                    = 0.01;
  fPi                                         = TMath::Pi(); 
  fProton_Energy_Col                          = 0;
  fProton_Mom_Col                             = 0;
  fProton_Theta_Col                           = 0;
  fProton_Phi_Col                             = 0;
  fProton_MomZ_Col                            = 0;
  fProton_MomX_Col                            = 0;
  fProton_MomY_Col                            = 0;
  fProton_Energy_Col_GeV                      = 0;
  fProton_Mom_Col_GeV                         = 0;
  fProton_MomX_Col_GeV                        = 0;
  fProton_MomY_Col_GeV                        = 0;
  fProton_MomZ_Col_GeV                        = 0;
  fBetaX_Col_RF                               = 0;
  fBetaY_Col_RF                               = 0;
  fBetaZ_Col_RF                               = 0;
  fBeta_Col_RF                                = 0;
  fGamma_Col_RF                               = 0;
  fProton_MomX_RF                             = 0;
  fProton_MomY_RF                             = 0;
  fProton_MomZ_RF                             = 0;
  fProton_Mom_RF                              = 0;
  fProton_Energy_RF                           = 0;
  fProton_Energy_RF_GeV                       = 0;
  fProton_MomX_RF_GeV                         = 0;
  fProton_MomY_RF_GeV                         = 0;
  fProton_MomZ_RF_GeV                         = 0;
  fProton_Mom_RF_GeV                          = 0;
  fProton_Kin_Col_GeV                         = 0;
  fScatElec_Angle                             = 0;
  fScatElec_Alpha_RF                          = 0;
  fScatElec_Beta_RF                           = 0;

  fRadiation_Lenght_Air                       = 0;
  fElectron_Targ_Thickness                    = 0;
  fElectron_Targ_Thickness_RadLen             = 0;
  fElectron_Targ_BT                           = 0;
  fElectron_Targ_Bremss_Loss                  = 0;
  fElectron_Targ_Ion_Loss                     = 0;
  fElectron_Air_Thickness                     = 0;
  fElectron_Air_Thickness_RadLen              = 0;
  fElectron_Air_BT                            = 0;
  fElectron_Air_Bremss_Loss                   = 0;
  fElectron_Air_Ion_Loss                      = 0;
  fElectron_Corrected_Theta_Col               = 0;
  fElectron_Corrected_Phi_Col                 = 0;
  fElectron_Corrected_Energy_Col              = 0;
  fElectron_Corrected_Mom_Col                 = 0;
  fElectron_Corrected_MomX_Col                = 0;
  fElectron_Corrected_MomY_Col                = 0;
  fElectron_Corrected_MomZ_Col                = 0;
  fElectron_Delta_Mom_Col                     = 0;
  fElectron_Corrected_Energy_Col_GeV          = 0;
  fElectron_Corrected_Mom_Col_GeV             = 0;
  fElectron_Corrected_MomX_Col_GeV            = 0;
  fElectron_Corrected_MomY_Col_GeV            = 0;
  fElectron_Corrected_MomZ_Col_GeV            = 0;
  fElectron_Delta_Mom_Col_GeV                 = 0;
  fElectron_Energy_Col                        = 0;
  fElectron_MomZ_Col                          = 0;
  fElectron_MomX_Col                          = 0;
  fElectron_MomY_Col                          = 0;
  fElectron_Theta_Col                         = 0;
  fElectron_Phi_Col                           = 0;
  fElectron_Mom_Col                           = 0;
  fElectron_Energy_Col_GeV                    = 0;
  fElectron_Mom_Col_GeV                       = 0;
  fElectron_MomX_Col_GeV                      = 0;
  fElectron_MomY_Col_GeV                      = 0;
  fElectron_MomZ_Col_GeV                      = 0;

  fScatElec_Targ_Thickness                    = 0;
  fScatElec_Targ_Thickness_RadLen             = 0;
  fScatElec_Targ_BT                           = 0;
  fScatElec_Targ_Bremss_Loss                  = 0;
  fScatElec_Targ_Ion_Loss                     = 0;
  fScatElec_Air_Thickness                     = 0;
  fScatElec_Air_Thickness_RadLen              = 0;
  fScatElec_Air_BT                            = 0;
  fScatElec_Air_Bremss_Loss                   = 0;
  fScatElec_Air_Ion_Loss                      = 0;
  fScatElec_Corrected_Theta_Col               = 0;
  fScatElec_Corrected_Phi_Col                 = 0;
  fScatElec_Corrected_Energy_Col              = 0;
  fScatElec_Corrected_Mom_Col                 = 0;
  fScatElec_Corrected_MomX_Col                = 0;
  fScatElec_Corrected_MomY_Col                = 0;
  fScatElec_Corrected_MomZ_Col                = 0;
  fScatElec_Delta_Mom_Col                     = 0;
  fScatElec_Corrected_Energy_Col_GeV          = 0;
  fScatElec_Corrected_Mom_Col_GeV             = 0;
  fScatElec_Corrected_MomX_Col_GeV            = 0;
  fScatElec_Corrected_MomY_Col_GeV            = 0;
  fScatElec_Corrected_MomZ_Col_GeV            = 0;
  fScatElec_Delta_Mom_Col_GeV                 = 0;
  fScatElec_Energy_Col                        = 0;
  fScatElec_MomZ_Col                          = 0;
  fScatElec_MomX_Col                          = 0;
  fScatElec_MomY_Col                          = 0;
  fScatElec_Theta_Col                         = 0;
  fScatElec_Phi_Col                           = 0;
  fScatElec_Mom_Col                           = 0;
  fScatElec_Energy_Col_GeV                    = 0;
  fScatElec_Mom_Col_GeV                       = 0;
  fScatElec_MomX_Col_GeV                      = 0;
  fScatElec_MomY_Col_GeV                      = 0;
  fScatElec_MomZ_Col_GeV                      = 0;

  fPion_Targ_Thickness                        = 0;
  fPion_Targ_Thickness_RadLen                 = 0;
  fPion_Targ_BT                               = 0;
  fPion_Targ_Bremss_Loss                      = 0;
  fPion_Targ_Ion_Loss                         = 0;
  fPion_Air_Thickness                         = 0;
  fPion_Air_Thickness_RadLen                  = 0;
  fPion_Air_BT                                = 0;
  fPion_Air_Bremss_Loss                       = 0;
  fPion_Air_Ion_Loss                          = 0;
  fPion_Corrected_Theta_Col                   = 0;
  fPion_Corrected_Phi_Col                     = 0;
  fPion_Corrected_Energy_Col                  = 0;
  fPion_Corrected_Mom_Col                     = 0;
  fPion_Corrected_MomX_Col                    = 0;
  fPion_Corrected_MomY_Col                    = 0;
  fPion_Corrected_MomZ_Col                    = 0;
  fPion_Delta_Mom_Col                         = 0;
  fPion_Corrected_Energy_Col_GeV              = 0;
  fPion_Corrected_Mom_Col_GeV                 = 0;
  fPion_Corrected_MomX_Col_GeV                = 0;
  fPion_Corrected_MomY_Col_GeV                = 0;
  fPion_Corrected_MomZ_Col_GeV                = 0;
  fPion_Delta_Mom_Col_GeV                     = 0;
  fPion_Energy_Col                            = 0;
  fPion_MomZ_Col                              = 0;
  fPion_MomX_Col                              = 0;
  fPion_MomY_Col                              = 0;
  fPion_Theta_Col                             = 0;
  fPion_Phi_Col                               = 0;
  fPion_Mom_Col                               = 0;
  fPion_Energy_Col_GeV                        = 0;
  fPion_Mom_Col_GeV                           = 0;
  fPion_MomX_Col_GeV                          = 0;
  fPion_MomY_Col_GeV                          = 0;
  fPion_MomZ_Col_GeV                          = 0;

  fNeutron_Targ_Thickness                     = 0;
  fNeutron_Targ_Thickness_RadLen              = 0;
  fNeutron_Targ_BT                            = 0;
  fNeutron_Targ_Bremss_Loss                   = 0;
  fNeutron_Targ_Ion_Loss                      = 0;
  fNeutron_Air_Thickness                      = 0;
  fNeutron_Air_Thickness_RadLen               = 0;
  fNeutron_Air_BT                             = 0;
  fNeutron_Air_Bremss_Loss                    = 0;
  fNeutron_Air_Ion_Loss                       = 0;
  fNeutron_Corrected_Theta_Col                = 0;
  fNeutron_Corrected_Phi_Col                  = 0;
  fNeutron_Corrected_Energy_Col               = 0;
  fNeutron_Corrected_Mom_Col                  = 0;
  fNeutron_Corrected_MomX_Col                 = 0;
  fNeutron_Corrected_MomY_Col                 = 0;
  fNeutron_Corrected_MomZ_Col                 = 0;
  fNeutron_Delta_Mom_Col                      = 0;
  fNeutron_Corrected_Energy_Col_GeV           = 0;
  fNeutron_Corrected_Mom_Col_GeV              = 0;
  fNeutron_Corrected_MomX_Col_GeV             = 0;
  fNeutron_Corrected_MomY_Col_GeV             = 0;
  fNeutron_Corrected_MomZ_Col_GeV             = 0;
  fNeutron_Delta_Mom_Col_GeV                  = 0;
  fNeutron_Energy_Col                         = 0;
  fNeutron_MomZ_Col                           = 0;
  fNeutron_MomX_Col                           = 0;
  fNeutron_MomY_Col                           = 0;
  fNeutron_Theta_Col                          = 0;
  fNeutron_Phi_Col                            = 0;
  fNeutron_Mom_Col                            = 0;
  fNeutron_Energy_Col_GeV                     = 0;
  fNeutron_Mom_Col_GeV                        = 0;
  fNeutron_MomX_Col_GeV                       = 0;
  fNeutron_MomY_Col_GeV                       = 0;
  fNeutron_MomZ_Col_GeV                       = 0;

  fRecoilProton_Targ_Thickness                = 0;
  fRecoilProton_Targ_Thickness_RadLen         = 0;
  fRecoilProton_Targ_BT                       = 0;
  fRecoilProton_Targ_Bremss_Loss              = 0;
  fRecoilProton_Targ_Ion_Loss                 = 0;
  fRecoilProton_Air_Thickness                 = 0;
  fRecoilProton_Air_Thickness_RadLen          = 0;
  fRecoilProton_Air_BT                        = 0;
  fRecoilProton_Air_Bremss_Loss               = 0;
  fRecoilProton_Air_Ion_Loss                  = 0;
  fRecoilProton_Theta_Col                     = 0;
  fRecoilProton_Phi_Col                       = 0;
  fRecoilProton_Energy_Col                    = 0;
  fRecoilProton_Mom_Col                       = 0;
  fRecoilProton_MomX_Col                      = 0;
  fRecoilProton_MomY_Col                      = 0;
  fRecoilProton_MomZ_Col                      = 0;
  fRecoilProton_Corrected_Energy_Col          = 0;
  fRecoilProton_Corrected_Mom_Col             = 0;
  fRecoilProton_Corrected_MomX_Col            = 0;
  fRecoilProton_Corrected_MomY_Col            = 0;
  fRecoilProton_Corrected_MomZ_Col            = 0;
  fRecoilProton_Corrected_Theta_Col           = 0;
  fRecoilProton_Corrected_Phi_Col             = 0;
  fRecoilProton_Delta_Mom_Col                 = 0;
  fRecoilProton_Energy_Col_GeV                = 0;
  fRecoilProton_Mom_Col_GeV                   = 0;
  fRecoilProton_MomX_Col_GeV                  = 0;
  fRecoilProton_MomY_Col_GeV                  = 0;
  fRecoilProton_MomZ_Col_GeV                  = 0;
  fRecoilProton_Corrected_Energy_Col_GeV      = 0;
  fRecoilProton_Corrected_Mom_Col_GeV         = 0;
  fRecoilProton_Corrected_MomX_Col_GeV        = 0;
  fRecoilProton_Corrected_MomY_Col_GeV        = 0;
  fRecoilProton_Corrected_MomZ_Col_GeV        = 0;
  fRecoilProton_Delta_Mom_Col_GeV             = 0;

  fSSAsym                                     = 0;
  fT                                          = 0;
  fT_GeV                                      = 0;
  fProton_Kin_Col                             = 0;
  fQsq_Value                                  = 0;
  fQsq_Dif                                    = 0;
  fQsq_GeV                                    = 0;
  fQsq                                        = 0;
  fW_GeV_Col                                  = 0;
  fW_Col                                      = 0;
  fW                                          = 0;   
  fW_GeV                                      = 0;
  fWSq                                        = 0;   
  fWSq_GeV                                    = 0;
  fScatElec_Mom_RF                            = 0;
  fScatElec_Mom_RF_GeV                        = 0;
  fScatElec_Energy_RF                         = 0;
  fScatElec_Energy_RF_GeV                     = 0;
  fElec_ScatElec_Theta_RF                     = 0;
  fScatElec_Cone_Phi_RF                       = 0;
  fScatElec_Theta_RF                          = 0;
  fScatElec_Phi_RF                            = 0;
  fScatElec_MomX_RF                           = 0;
  fScatElec_MomZ_RF                           = 0;
  fScatElec_MomY_RF                           = 0;
  fElectron_Energy_RF                         = 0;
  fElectron_Mom_RF                            = 0;
  fElectron_Theta_RF                          = 0;
  fElectron_Phi_RF                            = 0;
  fElectron_MomX_RF                           = 0;
  fElectron_MomZ_RF                           = 0;
  fElectron_MomY_RF                           = 0;
  fPhoton_Energy_RF                           = 0;
  fPhoton_Mom_RF                              = 0;
  fPhoton_Energy_RF_GeV                       = 0;
  fPhoton_Mom_RF_GeV                          = 0;

  fProton_Energy_CM                           = 0;
  fProton_Energy_CM_GeV                       = 0;
  fProton_Mom_CM                              = 0;
  fProton_Mom_CM_GeV                          = 0;

  fPhoton_Energy_CM                           = 0;
  fPhoton_Mom_CM                              = 0;
  fPhoton_Energy_CM_GeV                       = 0;
  fPhoton_Mom_CM_GeV                          = 0;

  fPion_Theta_CM                              = 0;
  fPion_Phi_CM                                = 0;
  fPion_Energy_CM                             = 0;
  fPion_Mom_CM                                = 0;
  fPion_Energy_CM_GeV                         = 0;
  fPion_Mom_CM_GeV                            = 0;

  fBeta_CM_RF                                 = 0;
  fGamma_CM_RF                                = 0;

  fNeutron_Theta_CM                           = 0;
  fNeutron_Phi_CM                             = 0;
  fNeutron_Energy_CM                          = 0;
  fNeutron_Energy_CM_GeV                      = 0;
  fNeutron_Mom_CM                             = 0;
  fNeutron_Mom_CM_GeV                         = 0;
  fPhoton_MomZ_RF                             = 0;
  fPhoton_MomX_RF                             = 0;
  fPhoton_MomY_RF                             = 0;
  fPhoton_Theta_RF                            = 0;
  fPhoton_Phi_RF                              = 0;
  fPion_Energy_RF                             = 0;
  fPion_Mom_RF                                = 0;
  fPion_Energy_RF_GeV                         = 0;
  fPion_Mom_RF_GeV                            = 0;
  fPiqVec_Theta_RF                            = 0;
  fPion_Mom_RotRF                             = 0;
  fPion_Mom_RotRF_GeV                         = 0;
  fPion_MomX_RotRF                            = 0;
  fPion_MomY_RotRF                            = 0;
  fPion_MomZ_RotRF                            = 0;
  fPion_Theta_RotRF                           = 0;
  fPion_Phi_RotRF                             = 0;
  fPion_MomX_RotRF_GeV                        = 0;
  fPion_MomY_RotRF_GeV                        = 0;
  fPion_MomZ_RotRF_GeV                        = 0;
  fT_Para                                     = 0;
  fT_Para_GeV                                 = 0;
  fEpsilon                                    = 0;
  fx                                          = 0;
  fy                                          = 0;
  fz                                          = 0;
  fNeutron_Energy_RotRF                       = 0;
  fNeutron_Energy_RotRF_GeV                   = 0;
  fNeutron_Mom_RotRF                          = 0;
  fNeutron_Mom_RotRF_GeV                      = 0;
  fNeutron_qVec_Theta_RF                      = 0;
  fNeutron_MomX_RotRF                         = 0;
  fNeutron_MomY_RotRF                         = 0;
  fNeutron_MomZ_RotRF                         = 0;
  fNeutron_Theta_RotRF                        = 0;
  fNeutron_Phi_RotRF                          = 0;
  fElectron_MomX_RF_GeV                       = 0;
  fElectron_MomY_RF_GeV                       = 0;
  fElectron_MomZ_RF_GeV                       = 0;
  fPhoton_MomX_RF_GeV                         = 0;
  fPhoton_MomY_RF_GeV                         = 0;
  fPhoton_MomZ_RF_GeV                         = 0;
  fScatElec_MomX_RF_GeV                       = 0;
  fScatElec_MomY_RF_GeV                       = 0;
  fScatElec_MomZ_RF_GeV                       = 0;
  fNeutron_MomX_RotRF_GeV                     = 0;
  fNeutron_MomY_RotRF_GeV                     = 0;
  fNeutron_MomZ_RotRF_GeV                     = 0;
  fPhoton_MomX_Col_GeV                        = 0;
  fPhoton_MomY_Col_GeV                        = 0;
  fPhoton_MomZ_Col_GeV                        = 0;
  fPion_MomX_Col_GeV                          = 0;
  fPion_MomY_Col_GeV                          = 0;
  fPion_MomZ_Col_GeV                          = 0;
 
  fPhoton_Theta_Col                           = 0;
  fPhoton_Phi_Col                             = 0;
  fPhoton_Energy_Col                          = 0;
  fPhoton_Mom_Col                             = 0;
  fPhoton_MomX_Col                            = 0;
  fPhoton_MomZ_Col                            = 0;
  fPhoton_MomY_Col                            = 0;
  fPhoton_Energy_Col_GeV                      = 0;
  fPhoton_Mom_Col_GeV                         = 0;
  fPhoton_MomX_Col_GeV                        = 0;
  fPhoton_MomZ_Col_GeV                        = 0;
  fPhoton_MomY_Col_GeV                        = 0;

  fWFactor                                    = 0;
  fA                                          = 0;
  fZASigma                                    = 0;
  fZASigmaPara                                = 0;
  fFlux_Factor_Col                            = 0;
  fFlux_Factor_RF                             = 0;
  fJacobian_CM                                = 0;
  fJacobian_CM_RF                             = 0;
  fJacobian_CM_Col                            = 0;
  fZASig_T                                    = 0;
  fZASig_L                                    = 0;
  fZASig_L2                                   = 0;
  fZASig_LT                                   = 0;
  fZASig_TT                                   = 0;

}
//---------------------------------------------------------


//---------------------------------------------------------
double pim::fermiMomentum() {

  double fMom;
  bool kFermi = true;
    while ( kFermi ) {
      double fProton_Rand_Mom_Col      = fRandom->Uniform( 0, 300.0);
      double fProton_Rand_Mom_Col_Prob = fRandom->Uniform( fProb[300], fProb[0] );
      int    fProton_Mom_Int           = std::ceil( fProton_Rand_Mom_Col );
      double f3He_Value                = fProb[ fProton_Mom_Int - 1 ];

      if ( fProton_Rand_Mom_Col_Prob <= f3He_Value ) {
	fMom = fProton_Rand_Mom_Col;	
	kFermi = false;
      }
    }

    return fMom;
}
//---------------------------------------------------------


//---------------------------------------------------------
int main()
{
  // g++ -o pim pim.C `root-config --cflags --glibs`
  TStopwatch tTime;
  tTime.Start(); 

  pim myPim;

  myPim.Initilize();

  cout << "Enter the number of events:";
  cin >> fNEvents;
  cout << endl;

  //  fNFile = 1;

  cout << "Enter the file number:";
  cin >> fNFile;
  cout << endl;

  // print             = true;
  // kCalcFermi        = true;
  // kCalcBremss       = true;
  // kCalcIon          = true;
  stringstream ssElectronK;
  ssElectronK << setprecision(4) << fElectron_Kin_Col_GeV;

  TString sRFile = "./RootFiles/DVMP_Ee_";
  TString sLFile = "./LundFiles/DVMP_Ee_";
  sRFile += ssElectronK.str();
  sLFile += ssElectronK.str();
  sRFile += "_Events_";
  sLFile += "_Events_";
  sRFile += fNEvents;
  sLFile += fNEvents;

  if ( kCalcFermi ){
    sRFile += "_Fermi_";
    sLFile += "_Fermi_";
  }

  if ( kCalcBremss ){
    sRFile += "_Bremss_";
    sLFile += "_Bremss_";
  }

  if ( kCalcIon ){
    sRFile += "_Ion_";
    sLFile += "_Ion_";
  }    

  sRFile += "_File_";
  sLFile += "_File_";
  sRFile += fNFile;
  sLFile += fNFile;
  sRFile += ".root";
  sLFile += ".lund";

  ofstream ppiOut (sLFile);

  TFile *f = new TFile(sRFile,"recreate");
  TTree t1("t1","Pion Form Fator Study");

  t1.Branch("Rand",                                      &fRand,                                      "fRand/D");
  t1.Branch("NRecorded",                                 &fNRecorded,                                 "fNRecorded/I");
  t1.Branch("NGenerated",                                &fNGenerated,                                "fNGeneratedd/I");
  t1.Branch("Ratio",                                     &fRatio,                                     "fRatiod/D");
  t1.Branch("WLessShell",                                &fWLessShell,                                "fWLessShell/I");
  t1.Branch("WLess1P9",                                  &fWLess1P9,                                  "fWLess1P9/I");
  t1.Branch("WSqNeg",                                    &fWSqNeg,                                    "fWSqNeg/I");
  t1.Branch("SDiff",                                     &fSDiff,                                     "fSDiff/I");
  t1.Branch("SConserve",                                 &kSConserve,                                 "kSConserve/B");

  t1.Branch("Pion_Alpha",                                &fPion_Alpha,                                "fPion_Alpha/D");
  t1.Branch("Pion_Beta",                                 &fPion_Beta,                                 "fPion_Beta/D");
  t1.Branch("Beta_CM_RF",                                &fBeta_CM_RF,                                "fBeta_CM_RF/D");
  t1.Branch("Gamma_CM_RF",                               &fGamma_CM_RF,                               "fGamma_CM_RF/D");
  t1.Branch("BetaX_Col_RF",                              &fBetaX_Col_RF,                              "fBetaX_Col_RF/D");
  t1.Branch("BetaY_Col_RF",                              &fBetaY_Col_RF,                              "fBetaY_Col_RF/D");
  t1.Branch("BetaZ_Col_RF",                              &fBetaZ_Col_RF,                              "fBetaZ_Col_RF/D");
  t1.Branch("Beta_Col_RF",                               &fBeta_Col_RF,                               "fBeta_Col_RF/D");
  t1.Branch("Gamma_Col_RF",                              &fGamma_Col_RF,                              "fGamma_Col_RF/D");
  t1.Branch("S_I_Col",                                   &fS_I_Col,                                   "fS_I_Col/D");
  t1.Branch("S_F_Col",                                   &fS_F_Col,                                   "fS_F_Col/D");
  t1.Branch("S_I_RF",                                    &fS_I_RF,                                    "fS_I_RF/D");
  t1.Branch("S_F_RF",                                    &fS_F_RF,                                    "fS_F_RF/D");
  t1.Branch("S_I_Col_GeV",                               &fS_I_Col_GeV,                               "fS_I_Col_GeV/D");
  t1.Branch("S_F_Col_GeV",                               &fS_F_Col_GeV,                               "fS_F_Col_GeV/D");
  t1.Branch("S_I_RF_GeV",                                &fS_I_RF_GeV,                                "fS_I_RF_GeV/D");
  t1.Branch("S_F_RF_GeV",                                &fS_F_RF_GeV,                                "fS_F_RF_GeV/D");

  t1.Branch("W",                                         &fW,                                         "fW/D");
  t1.Branch("W_GeV",                                     &fW_GeV,                                     "fW_GeV/D");
  t1.Branch("WSq",                                       &fWSq,                                       "fWSq/D");
  t1.Branch("WSq_GeV",                                   &fWSq_GeV,                                   "fWSq_GeV/D");
  t1.Branch("Qsq",                                       &fQsq,                                       "fQsq/D");
  t1.Branch("Qsq_GeV",                                   &fQsq_GeV,                                   "fQsq_GeV/D");
  t1.Branch("T_Para",                                    &fT_Para,                                    "fT_Para/D");
  t1.Branch("T_Para_GeV",                                &fT_Para_GeV,                                "fT_Para_GeV/D");
  t1.Branch("T",                                         &fT,                                         "fT/D");
  t1.Branch("T_GeV",                                     &fT_GeV,                                     "fT_GeV/D");
  t1.Branch("Epsilon",                                   &fEpsilon,                                   "fEpsilon/D");
  t1.Branch("x",                                         &fx,                                         "fx/D");
  t1.Branch("y",                                         &fy,                                         "fy/D");
  t1.Branch("z",                                         &fz,                                         "fz/D");

  t1.Branch("Target_Energy_RF",                          &fProton_Energy_RF,                          "fProton_Energy_RF/D");
  t1.Branch("Target_Mom_RF",                             &fProton_Mom_RF,                             "fProton_Mom_RF/D");
  t1.Branch("Target_MomZ_RF",                            &fProton_MomZ_RF,                            "fProton_MomZ_RF/D");
  t1.Branch("Target_MomX_RF",                            &fProton_MomX_RF,                            "fProton_MomX_RF/D");
  t1.Branch("Target_MomY_RF",                            &fProton_MomY_RF,                            "fProton_MomY_RF/D");
  t1.Branch("Target_Energy_RF_GeV",                      &fProton_Energy_RF_GeV,                      "fProton_Energy_RF_GeV/D");
  t1.Branch("Target_Mom_RF_GeV",                         &fProton_Mom_RF_GeV,                         "fProton_Mom_RF_GeV/D");
  t1.Branch("Target_MomZ_RF_GeV",                        &fProton_MomZ_RF_GeV,                        "fProton_MomZ_RF_GeV/D");
  t1.Branch("Target_MomX_RF_GeV",                        &fProton_MomX_RF_GeV,                        "fProton_MomX_RF_GeV/D");
  t1.Branch("Target_MomY_RF_GeV",                        &fProton_MomY_RF_GeV,                        "fProton_MomY_RF_GeV/D");

  t1.Branch("Elec_ScatElec_Theta_RF",                    &fElec_ScatElec_Theta_RF,                    "fElec_ScatElec_Theta_RF/D");
  t1.Branch("ScatElec_Cone_Phi_RF",                      &fScatElec_Cone_Phi_RF,                      "fScatElec_Cone_Phi_RF/D");
  t1.Branch("ScatElec_Theta_RF",                         &fScatElec_Theta_RF,                         "fScatElec_Theta_RF/D");
  t1.Branch("ScatElec_Phi_RF",                           &fScatElec_Phi_RF,                           "fScatElec_Phi_RF/D");
  t1.Branch("ScatElec_Energy_RF",                        &fScatElec_Energy_RF,                        "fScatElec_Energy_RF/D");
  t1.Branch("ScatElec_Mom_RF",                           &fScatElec_Mom_RF,                           "fScatElec_Mom_RF/D");
  t1.Branch("ScatElec_MomX_RF",                          &fScatElec_MomX_RF,                          "fScatElec_MomX_RF/D");
  t1.Branch("ScatElec_MomZ_RF",                          &fScatElec_MomZ_RF,                          "fScatElec_MomZ_RF/D");
  t1.Branch("ScatElec_MomY_RF",                          &fScatElec_MomY_RF,                          "fScatElec_MomY_RF/D");
  t1.Branch("ScatElec_Energy_RF_GeV",                    &fScatElec_Energy_RF_GeV,                    "fScatElec_Energy_RF_GeV/D");
  t1.Branch("ScatElec_Mom_RF_GeV",                       &fScatElec_Mom_RF_GeV,                       "fScatElec_Mom_RF_GeV/D");
  t1.Branch("ScatElec_MomX_RF_GeV",                      &fScatElec_MomX_RF_GeV,                      "fScatElec_MomX_RF_GeV/D");
  t1.Branch("ScatElec_MomZ_RF_GeV",                      &fScatElec_MomZ_RF_GeV,                      "fScatElec_MomZ_RF_GeV/D");
  t1.Branch("ScatElec_MomY_RF_GeV",                      &fScatElec_MomY_RF_GeV,                      "fScatElec_MomY_RF_GeV/D");

  t1.Branch("Photon_Theta_RF",                           &fPhoton_Theta_RF,                           "fPhoton_Theta_RF/D");
  t1.Branch("Photon_Phi_RF",                             &fPhoton_Phi_RF,                             "fPhoton_Phi_RF/D"); 
  t1.Branch("Photon_Energy_RF",                          &fPhoton_Energy_RF,                          "fPhoton_Energy_RF/D");
  t1.Branch("Photon_Mom_RF",                             &fPhoton_Mom_RF,                             "fPhoton_Mom_RF/D");
  t1.Branch("Photon_MomX_RF",                            &fPhoton_MomX_RF,                            "fPhoton_MomX_RF/D");
  t1.Branch("Photon_MomY_RF",                            &fPhoton_MomY_RF,                            "fPhoton_MomY_RF/D");
  t1.Branch("Photon_MomZ_RF",                            &fPhoton_MomZ_RF,                            "fPhoton_MomZ_RF/D");
  t1.Branch("Photon_Energy_RF_GeV",                      &fPhoton_Energy_RF_GeV,                      "fPhoton_Energy_RF_GeV/D");
  t1.Branch("Photon_Mom_RF_GeV",                         &fPhoton_Mom_RF_GeV,                         "fPhoton_Mom_RF_GeV/D");
  t1.Branch("Photon_MomX_RF_GeV",                        &fPhoton_MomX_RF_GeV,                        "fPhoton_MomX_RF_GeV/D");
  t1.Branch("Photon_MomY_RF_GeV",                        &fPhoton_MomY_RF_GeV,                        "fPhoton_MomY_RF_GeV/D");
  t1.Branch("Photon_MomZ_RF_GeV",                        &fPhoton_MomZ_RF_GeV,                        "fPhoton_MomZ_RF_GeV/D");

  t1.Branch("Electron_Theta_RF",                         &fElectron_Theta_RF,                         "fElectron_Theta_RF/D");
  t1.Branch("Electron_Phi_RF",                           &fElectron_Phi_RF,                           "fElectron_Phi_RF/D");
  t1.Branch("Electron_Energy_RF",                        &fElectron_Energy_RF,                        "fElectron_Energy_RF/D");
  t1.Branch("Electron_Mom_RF",                           &fElectron_Mom_RF,                           "fElectron_Mom_RF/D");
  t1.Branch("Electron_MomX_RF",                          &fElectron_MomX_RF,                          "fElectron_MomX_RF/D");
  t1.Branch("Electron_MomY_RF",                          &fElectron_MomY_RF,                          "fElectron_MomY_RF/D");
  t1.Branch("Electron_MomZ_RF",                          &fElectron_MomZ_RF,                          "fElectron_MomZ_RF/D");
  t1.Branch("Electron_Energy_RF_GeV",                    &fElectron_Energy_RF_GeV,                    "fElectron_Energy_RF_GeV/D");
  t1.Branch("Electron_Mom_RF_GeV",                       &fElectron_Mom_RF_GeV,                       "fElectron_Mom_RF_GeV/D");
  t1.Branch("Electron_MomX_RF_GeV",                      &fElectron_MomX_RF_GeV,                      "fElectron_MomX_RF_GeV/D");
  t1.Branch("Electron_MomY_RF_GeV",                      &fElectron_MomY_RF_GeV,                      "fElectron_MomY_RF_GeV/D");
  t1.Branch("Electron_MomZ_RF_GeV",                      &fElectron_MomZ_RF_GeV,                      "fElectron_MomZ_RF_GeV/D");

  t1.Branch("Proton_Energy_CM",                          &fProton_Energy_CM,                          "fProton_Energy_CM/D");
  t1.Branch("Proton_Mom_CM",                             &fProton_Mom_CM,                             "fProton_Mom_CM/D");
  t1.Branch("Proton_Energy_CM_GeV",                      &fProton_Energy_CM_GeV,                      "fProton_Energy_CM_GeV/D");
  t1.Branch("Proton_Mom_CM_GeV",                         &fProton_Mom_CM_GeV,                         "fProton_Mom_CM_GeV/D");

  t1.Branch("Photon_Energy_CM",                          &fPhoton_Energy_CM,                          "fPhoton_Energy_CM/D");
  t1.Branch("Photon_Mom_CM",                             &fPhoton_Mom_CM,                             "fPhoton_Mom_CM/D");
  t1.Branch("Photon_Energy_CM_GeV",                      &fPhoton_Energy_CM_GeV,                      "fPhoton_Energy_CM_GeV/D");
  t1.Branch("Photon_Mom_CM_GeV",                         &fPhoton_Mom_CM_GeV,                         "fPhoton_Mom_CM_GeV/D");

  t1.Branch("Pion_Theta_CM",                             &fPion_Theta_CM,                             "fPion_Theta_CM/D");
  t1.Branch("Pion_Phi_CM",                               &fPion_Phi_CM,                               "fPion_Phi_CM/D");
  t1.Branch("Pion_Energy_CM",                            &fPion_Energy_CM,                            "fPion_Energy_CM/D");
  t1.Branch("Pion_Mom_CM",                               &fPion_Mom_CM,                               "fPion_Mom_CM/D");
  t1.Branch("Pion_Energy_CM_GeV",                        &fPion_Energy_CM_GeV,                        "fPion_Energy_CM_GeV/D");
  t1.Branch("Pion_Mom_CM_GeV",                           &fPion_Mom_CM_GeV,                           "fPion_Mom_CM_GeV/D");

  t1.Branch("Neutron_Theta_CM",                          &fNeutron_Theta_CM,                          "fNeutron_Theta_CM/D");
  t1.Branch("Neutron_Phi_CM",                            &fNeutron_Phi_CM,                            "fNeutron_Phi_CM/D");
  t1.Branch("Neutron_Energy_CM",                         &fNeutron_Energy_CM,                         "fNeutron_Energy_CM/D");
  t1.Branch("Neutron_Mom_CM",                            &fNeutron_Mom_CM,                            "fNeutron_Mom_CM/D");
  t1.Branch("Neutron_Energy_CM_GeV",                     &fNeutron_Energy_CM_GeV,                     "fNeutron_Energy_CM_GeV/D");
  t1.Branch("Neutron_Mom_CM_GeV",                        &fNeutron_Mom_CM_GeV,                        "fNeutron_Mom_CM_GeV/D");

  t1.Branch("Pion_Theta_RotRF",                          &fPion_Theta_RotRF,                          "fPion_Theta_RotRF/D");
  t1.Branch("Pion_Phi_RotRF",                            &fPion_Phi_RotRF,                            "fPion_Phi_RotRF/D");
  t1.Branch("PiqVec_Theta_RF",                           &fPiqVec_Theta_RF,                           "fPiqVec_Theta_RF/D");
  t1.Branch("Pion_Energy_RF",                            &fPion_Energy_RF,                            "fPion_Energy_RF/D");
  t1.Branch("Pion_Mom_RF",                               &fPion_Mom_RF,                               "fPion_Mom_RF/D");
  t1.Branch("Pion_MomX_RotRF",                           &fPion_MomX_RotRF,                           "fPion_MomX_RotRF/D");
  t1.Branch("Pion_MomY_RotRF",                           &fPion_MomY_RotRF,                           "fPion_MomY_RotRF/D");
  t1.Branch("Pion_MomZ_RotRF",                           &fPion_MomZ_RotRF,                           "fPion_MomZ_RotRF/D");
  t1.Branch("Pion_Energy_RF_GeV",                        &fPion_Energy_RF_GeV,                        "fPion_Energy_RF_GeV/D");
  t1.Branch("Pion_Mom_RF_GeV",                           &fPion_Mom_RF_GeV,                           "fPion_Mom_RF_GeV/D");
  t1.Branch("Pion_MomX_RotRF_GeV",                       &fPion_MomX_RotRF_GeV,                       "fPion_MomX_RotRF_GeV/D");
  t1.Branch("Pion_MomY_RotRF_GeV",                       &fPion_MomY_RotRF_GeV,                       "fPion_MomY_RotRF_GeV/D");
  t1.Branch("Pion_MomZ_RotRF_GeV",                       &fPion_MomZ_RotRF_GeV,                       "fPion_MomZ_RotRF_GeV/D");

  t1.Branch("Neutron_qVec_Theta_RF",                     &fNeutron_qVec_Theta_RF,                     "fNeutron_qVec_Theta_RF/D");
  t1.Branch("Neutron_Theta_RotRF",                       &fNeutron_Theta_RotRF,                       "fNeutron_Theta_RotRF/D");
  t1.Branch("Neutron_Phi_RotRF",                         &fNeutron_Phi_RotRF,                         "fNeutron_Phi_RotRF/D");
  t1.Branch("Neutron_Energy_RotRF",                      &fNeutron_Energy_RotRF,                      "fNeutron_Energy_RotRF/D");
  t1.Branch("Neutron_Mom_RotRF",                         &fNeutron_Mom_RotRF,                         "fNeutron_Mom_RotRF/D");
  t1.Branch("Neutron_MomX_RotRF",                        &fNeutron_MomX_RotRF,                        "fNeutron_MomX_RotRF/D");
  t1.Branch("Neutron_MomY_RotRF",                        &fNeutron_MomY_RotRF,                        "fNeutron_MomY_RotRF/D");
  t1.Branch("Neutron_MomZ_RotRF",                        &fNeutron_MomZ_RotRF,                        "fNeutron_MomZ_RotRF/D");
  t1.Branch("Neutron_Energy_RotRF_GeV",                  &fNeutron_Energy_RotRF_GeV,                  "fNeutron_Energy_RotRF_GeV/D");
  t1.Branch("Neutron_Mom_RotRF_GeV",                     &fNeutron_Mom_RotRF_GeV,                     "fNeutron_Mom_RotRF_GeV/D");
  t1.Branch("Neutron_MomX_RotRF_GeV",                    &fNeutron_MomX_RotRF_GeV,                    "fNeutron_MomX_RotRF_GeV/D");
  t1.Branch("Neutron_MomY_RotRF_GeV",                    &fNeutron_MomY_RotRF_GeV,                    "fNeutron_MomY_RotRF_GeV/D");
  t1.Branch("Neutron_MomZ_RotRF_GeV",                    &fNeutron_MomZ_RotRF_GeV,                    "fNeutron_MomZ_RotRF_GeV/D");

  t1.Branch("Target_Energy_Col",                         &fProton_Energy_Col,                         "fProton_Energy_Col/D");
  t1.Branch("Target_Mom_Col",                            &fProton_Mom_Col,                            "fProton_Mom_Col/D");
  t1.Branch("Target_Theta_Col",                          &fProton_Theta_Col,                          "fProton_Theta_Col/D");
  t1.Branch("Target_Phi_Col",                            &fProton_Phi_Col,                            "fProton_Phi_Col/D");
  t1.Branch("Target_MomZ_Col",                           &fProton_MomZ_Col,                           "fProton_MomZ_Col/D");
  t1.Branch("Target_MomX_Col",                           &fProton_MomX_Col,                           "fProton_MomX_Col/D");
  t1.Branch("Target_MomY_Col",                           &fProton_MomY_Col,                           "fProton_MomY_Col/D");
  t1.Branch("Target_Energy_Col_GeV",                     &fProton_Energy_Col_GeV,                     "fProton_Energy_Col_GeV/D");
  t1.Branch("Target_Mom_Col_GeV",                        &fProton_Mom_Col_GeV,                        "fProton_Mom_Col_GeV/D");
  t1.Branch("Target_MomZ_Col_GeV",                       &fProton_MomZ_Col_GeV,                       "fProton_MomZ_Col_GeV/D");
  t1.Branch("Target_MomX_Col_GeV",                       &fProton_MomX_Col_GeV,                       "fProton_MomX_Col_GeV/D");
  t1.Branch("Target_MomY_Col_GeV",                       &fProton_MomY_Col_GeV,                       "fProton_MomY_Col_GeV/D");

  t1.Branch("Photon_Theta_Col",                          &fPhoton_Theta_Col,                          "fPhoton_Theta_Col/D");
  t1.Branch("Photon_Phi_Col",                            &fPhoton_Phi_Col,                            "fPhoton_Phi_Col/D");
  t1.Branch("Photon_Energy_Col",                         &fPhoton_Energy_Col,                         "fPhoton_Energy_Col/D");
  t1.Branch("Photon_Mom_Col",                            &fPhoton_Mom_Col,                            "fPhoton_Mom_Col/D");
  t1.Branch("Photon_MomX_Col",                           &fPhoton_MomX_Col,                           "fPhoton_MomX_Col/D");
  t1.Branch("Photon_MomZ_Col",                           &fPhoton_MomZ_Col,                           "fPhoton_MomZ_Col/D");
  t1.Branch("Photon_MomY_Col",                           &fPhoton_MomY_Col,                           "fPhoton_MomY_Col/D");
  t1.Branch("Photon_Energy_Col_GeV",                     &fPhoton_Energy_Col_GeV,                     "fPhoton_Energy_Col_GeV/D");
  t1.Branch("Photon_Mom_Col_GeV",                        &fPhoton_Mom_Col_GeV,                        "fPhoton_Mom_Col_GeV/D");
  t1.Branch("Photon_MomX_Col_GeV",                       &fPhoton_MomX_Col_GeV,                       "fPhoton_MomX_Col_GeV/D");
  t1.Branch("Photon_MomZ_Col_GeV",                       &fPhoton_MomZ_Col_GeV,                       "fPhoton_MomZ_Col_GeV/D");
  t1.Branch("Photon_MomY_Col_GeV",                       &fPhoton_MomY_Col_GeV,                       "fPhoton_MomY_Col_GeV/D");

  t1.Branch("Electron_Theta_Col",                        &fElectron_Theta_Col,                        "fElectron_Theta_Col/D");
  t1.Branch("Electron_Phi_Col",                          &fElectron_Phi_Col,                          "fElectron_Phi_Col/D");
  t1.Branch("Electron_Mom_Col",                          &fElectron_Mom_Col,                          "fElectron_Mom_Col/D");
  t1.Branch("Electron_Energy_Col",                       &fElectron_Energy_Col,                       "fElectron_Energy_Col/D");
  t1.Branch("Electron_MomZ_Col",                         &fElectron_MomZ_Col,                         "fElectron_MomZ_Col/D");
  t1.Branch("Electron_MomX_Col",                         &fElectron_MomX_Col,                         "fElectron_MomX_Col/D");
  t1.Branch("Electron_MomY_Col",                         &fElectron_MomY_Col,                         "fElectron_MomY_Col/D");
  t1.Branch("Electron_Energy_Col_GeV",                   &fElectron_Energy_Col_GeV,                   "fElectron_Energy_Col_GeV/D");
  t1.Branch("Electron_MomZ_Col_GeV",                     &fElectron_MomZ_Col_GeV,                     "fElectron_MomZ_Col_GeV/D");
  t1.Branch("Electron_MomX_Col_GeV",                     &fElectron_MomX_Col_GeV,                     "fElectron_MomX_Col_GeV/D");
  t1.Branch("Electron_MomY_Col_GeV",                     &fElectron_MomY_Col_GeV,                     "fElectron_MomY_Col_GeV/D");
  t1.Branch("Electron_Targ_Bremss_Loss",                 &fElectron_Targ_Bremss_Loss,                 "fElectron_Targ_Bremss_Loss/D");
  t1.Branch("Electron_Targ_Ion_Loss",                    &fElectron_Targ_Ion_Loss,                    "fElectron_Targ_Ion_Loss/D");
  t1.Branch("Electron_Air_Bremss_Loss",                  &fElectron_Air_Bremss_Loss,                  "fElectron_Air_Bremss_Loss/D");
  t1.Branch("Electron_Air_Ion_Loss",                     &fElectron_Air_Ion_Loss,                     "fElectron_Air_Ion_Loss/D");
  t1.Branch("Electron_Corrected_Energy_Col",             &fElectron_Corrected_Energy_Col,             "fElectron_Corrected_Energy_Col/D");
  t1.Branch("Electron_Corrected_Mom_Col",                &fElectron_Corrected_Mom_Col,                "fElectron_Corrected_Mom_Col/D");
  t1.Branch("Electron_Corrected_MomX_Col",               &fElectron_Corrected_MomX_Col,               "fElectron_Corrected_MomX_Col/D");
  t1.Branch("Electron_Corrected_MomY_Col",               &fElectron_Corrected_MomY_Col,               "fElectron_Corrected_MomY_Col/D");
  t1.Branch("Electron_Corrected_MomZ_Col",               &fElectron_Corrected_MomZ_Col,               "fElectron_Corrected_MomZ_Col/D");
  t1.Branch("Electron_Corrected_Theta_Col",              &fElectron_Corrected_Theta_Col,              "fElectron_Corrected_Theta_Col/D");
  t1.Branch("Electron_Corrected_Phi_Col",                &fElectron_Corrected_Phi_Col,                "fElectron_Corrected_Phi_Col/D");
  t1.Branch("Electron_Delta_Mom_Col",                    &fElectron_Delta_Mom_Col,                    "fElectron_Delta_Mom_Col/D");
  t1.Branch("Electron_Corrected_Energy_Col_GeV",         &fElectron_Corrected_Energy_Col_GeV,         "fElectron_Corrected_Energy_Col_GeV/D");
  t1.Branch("Electron_Corrected_Mom_Col_GeV",            &fElectron_Corrected_Mom_Col_GeV,            "fElectron_Corrected_Mom_Col_GeV/D");
  t1.Branch("Electron_Corrected_MomX_Col_GeV",           &fElectron_Corrected_MomX_Col_GeV,           "fElectron_Corrected_MomX_Col_GeV/D");
  t1.Branch("Electron_Corrected_MomY_Col_GeV",           &fElectron_Corrected_MomY_Col_GeV,           "fElectron_Corrected_MomY_Col_GeV/D");
  t1.Branch("Electron_Corrected_MomZ_Col_GeV",           &fElectron_Corrected_MomZ_Col_GeV,           "fElectron_Corrected_MomZ_Col_GeV/D");
  t1.Branch("Electron_Delta_Mom_Col_GeV",                &fElectron_Delta_Mom_Col_GeV,                "fElectron_Delta_Mom_Col_GeV/D");

  t1.Branch("ScatElec_Theta_Col",                        &fScatElec_Theta_Col,                        "fScatElec_Theta_Col/D");
  t1.Branch("ScatElec_Phi_Col",                          &fScatElec_Phi_Col,                          "fScatElec_Phi_Col/D");
  t1.Branch("ScatElec_Mom_Col",                          &fScatElec_Mom_Col,                          "fScatElec_Mom_Col/D");
  t1.Branch("ScatElec_Energy_Col",                       &fScatElec_Energy_Col,                       "fScatElec_Energy_Col/D");
  t1.Branch("ScatElec_MomZ_Col",                         &fScatElec_MomZ_Col,                         "fScatElec_MomZ_Col/D");
  t1.Branch("ScatElec_MomX_Col",                         &fScatElec_MomX_Col,                         "fScatElec_MomX_Col/D");
  t1.Branch("ScatElec_MomY_Col",                         &fScatElec_MomY_Col,                         "fScatElec_MomY_Col/D");
  t1.Branch("ScatElec_Energy_Col_GeV",                   &fScatElec_Energy_Col_GeV,                   "fScatElec_Energy_Col_GeV/D");
  t1.Branch("ScatElec_MomZ_Col_GeV",                     &fScatElec_MomZ_Col_GeV,                     "fScatElec_MomZ_Col_GeV/D");
  t1.Branch("ScatElec_MomX_Col_GeV",                     &fScatElec_MomX_Col_GeV,                     "fScatElec_MomX_Col_GeV/D");
  t1.Branch("ScatElec_MomY_Col_GeV",                     &fScatElec_MomY_Col_GeV,                     "fScatElec_MomY_Col_GeV/D");
  t1.Branch("ScatElec_Targ_Bremss_Loss",                 &fScatElec_Targ_Bremss_Loss,                 "fScatElec_Targ_Bremss_Loss/D");
  t1.Branch("ScatElec_Targ_Ion_Loss",                    &fScatElec_Targ_Ion_Loss,                    "fScatElec_Targ_Ion_Loss/D");
  t1.Branch("ScatElec_Air_Bremss_Loss",                  &fScatElec_Air_Bremss_Loss,                  "fScatElec_Air_Bremss_Loss/D");
  t1.Branch("ScatElec_Air_Ion_Loss",                     &fScatElec_Air_Ion_Loss,                     "fScatElec_Air_Ion_Loss/D");
  t1.Branch("ScatElec_Corrected_Energy_Col",             &fScatElec_Corrected_Energy_Col,             "fScatElec_Corrected_Energy_Col/D");
  t1.Branch("ScatElec_Corrected_Mom_Col",                &fScatElec_Corrected_Mom_Col,                "fScatElec_Corrected_Mom_Col/D");
  t1.Branch("ScatElec_Corrected_MomX_Col",               &fScatElec_Corrected_MomX_Col,               "fScatElec_Corrected_MomX_Col/D");
  t1.Branch("ScatElec_Corrected_MomY_Col",               &fScatElec_Corrected_MomY_Col,               "fScatElec_Corrected_MomY_Col/D");
  t1.Branch("ScatElec_Corrected_MomZ_Col",               &fScatElec_Corrected_MomZ_Col,               "fScatElec_Corrected_MomZ_Col/D");
  t1.Branch("ScatElec_Corrected_Theta_Col",              &fScatElec_Corrected_Theta_Col,              "fScatElec_Corrected_Theta_Col/D");
  t1.Branch("ScatElec_Corrected_Phi_Col",                &fScatElec_Corrected_Phi_Col,                "fScatElec_Corrected_Phi_Col/D");
  t1.Branch("ScatElec_Delta_Mom_Col",                    &fScatElec_Delta_Mom_Col,                    "fScatElec_Delta_Mom_Col/D");
  t1.Branch("ScatElec_Corrected_Energy_Col_GeV",         &fScatElec_Corrected_Energy_Col_GeV,         "fScatElec_Corrected_Energy_Col_GeV/D");
  t1.Branch("ScatElec_Corrected_Mom_Col_GeV",            &fScatElec_Corrected_Mom_Col_GeV,            "fScatElec_Corrected_Mom_Col_GeV/D");
  t1.Branch("ScatElec_Corrected_MomX_Col_GeV",           &fScatElec_Corrected_MomX_Col_GeV,           "fScatElec_Corrected_MomX_Col_GeV/D");
  t1.Branch("ScatElec_Corrected_MomY_Col_GeV",           &fScatElec_Corrected_MomY_Col_GeV,           "fScatElec_Corrected_MomY_Col_GeV/D");
  t1.Branch("ScatElec_Corrected_MomZ_Col_GeV",           &fScatElec_Corrected_MomZ_Col_GeV,           "fScatElec_Corrected_MomZ_Col_GeV/D");
  t1.Branch("ScatElec_Delta_Mom_Col_GeV",                &fScatElec_Delta_Mom_Col_GeV,                "fScatElec_Delta_Mom_Col_GeV/D");

  t1.Branch("Pion_Theta_Col",                            &fPion_Theta_Col,                            "fPion_Theta_Col/D");
  t1.Branch("Pion_Phi_Col",                              &fPion_Phi_Col,                              "fPion_Phi_Col/D");
  t1.Branch("Pion_Mom_Col",                              &fPion_Mom_Col,                              "fPion_Mom_Col/D");
  t1.Branch("Pion_Energy_Col",                           &fPion_Energy_Col,                           "fPion_Energy_Col/D");
  t1.Branch("Pion_MomZ_Col",                             &fPion_MomZ_Col,                             "fPion_MomZ_Col/D");
  t1.Branch("Pion_MomX_Col",                             &fPion_MomX_Col,                             "fPion_MomX_Col/D");
  t1.Branch("Pion_MomY_Col",                             &fPion_MomY_Col,                             "fPion_MomY_Col/D");
  t1.Branch("Pion_Energy_Col_GeV",                       &fPion_Energy_Col_GeV,                       "fPion_Energy_Col_GeV/D");
  t1.Branch("Pion_MomZ_Col_GeV",                         &fPion_MomZ_Col_GeV,                         "fPion_MomZ_Col_GeV/D");
  t1.Branch("Pion_MomX_Col_GeV",                         &fPion_MomX_Col_GeV,                         "fPion_MomX_Col_GeV/D");
  t1.Branch("Pion_MomY_Col_GeV",                         &fPion_MomY_Col_GeV,                         "fPion_MomY_Col_GeV/D");
  t1.Branch("Pion_Targ_Bremss_Loss",                     &fPion_Targ_Bremss_Loss,                     "fPion_Targ_Bremss_Loss/D");
  t1.Branch("Pion_Targ_Ion_Loss",                        &fPion_Targ_Ion_Loss,                        "fPion_Targ_Ion_Loss/D");
  t1.Branch("Pion_Air_Bremss_Loss",                      &fPion_Air_Bremss_Loss,                      "fPion_Air_Bremss_Loss/D");
  t1.Branch("Pion_Air_Ion_Loss",                         &fPion_Air_Ion_Loss,                         "fPion_Air_Ion_Loss/D");
  t1.Branch("Pion_Corrected_Theta_Col",                  &fPion_Corrected_Theta_Col,                  "fPion_Corrected_Theta_Col/D");
  t1.Branch("Pion_Corrected_Phi_Col",                    &fPion_Corrected_Phi_Col,                    "fPion_Corrected_Phi_Col/D");
  t1.Branch("Pion_Corrected_Energy_Col",                 &fPion_Corrected_Energy_Col,                 "fPion_Corrected_Energy_Col/D");
  t1.Branch("Pion_Corrected_Mom_Col",                    &fPion_Corrected_Mom_Col,                    "fPion_Corrected_Mom_Col/D");
  t1.Branch("Pion_Corrected_MomX_Col",                   &fPion_Corrected_MomX_Col,                   "fPion_Corrected_MomX_Col/D");
  t1.Branch("Pion_Corrected_MomY_Col",                   &fPion_Corrected_MomY_Col,                   "fPion_Corrected_MomY_Col/D");
  t1.Branch("Pion_Corrected_MomZ_Col",                   &fPion_Corrected_MomZ_Col,                   "fPion_Corrected_MomZ_Col/D");
  t1.Branch("Pion_Delta_Mom_Col",                        &fPion_Delta_Mom_Col,                        "fPion_Delta_Mom_Col/D");
  t1.Branch("Pion_Corrected_Energy_Col_GeV",             &fPion_Corrected_Energy_Col_GeV,             "fPion_Corrected_Energy_Col_GeV/D");
  t1.Branch("Pion_Corrected_Mom_Col_GeV",                &fPion_Corrected_Mom_Col_GeV,                "fPion_Corrected_Mom_Col_GeV/D");
  t1.Branch("Pion_Corrected_MomX_Col_GeV",               &fPion_Corrected_MomX_Col_GeV,               "fPion_Corrected_MomX_Col_GeV/D");
  t1.Branch("Pion_Corrected_MomY_Col_GeV",               &fPion_Corrected_MomY_Col_GeV,               "fPion_Corrected_MomY_Col_GeV/D");
  t1.Branch("Pion_Corrected_MomZ_Col_GeV",               &fPion_Corrected_MomZ_Col_GeV,               "fPion_Corrected_MomZ_Col_GeV/D");
  t1.Branch("Pion_Delta_Mom_Col_GeV",                    &fPion_Delta_Mom_Col_GeV,                    "fPion_Delta_Mom_Col_GeV/D");

  t1.Branch("Neutron_Theta_Col",                         &fNeutron_Theta_Col,                         "fNeutron_Theta_Col/D");
  t1.Branch("Neutron_Phi_Col",                           &fNeutron_Phi_Col,                           "fNeutron_Phi_Col/D");
  t1.Branch("Neutron_Mom_Col",                           &fNeutron_Mom_Col,                           "fNeutron_Mom_Col/D");
  t1.Branch("Neutron_Energy_Col",                        &fNeutron_Energy_Col,                        "fNeutron_Energy_Col/D");
  t1.Branch("Neutron_MomZ_Col",                          &fNeutron_MomZ_Col,                          "fNeutron_MomZ_Col/D");
  t1.Branch("Neutron_MomX_Col",                          &fNeutron_MomX_Col,                          "fNeutron_MomX_Col/D");
  t1.Branch("Neutron_MomY_Col",                          &fNeutron_MomY_Col,                          "fNeutron_MomY_Col/D");
  t1.Branch("Neutron_Energy_Col_GeV",                    &fNeutron_Energy_Col_GeV,                    "fNeutron_Energy_Col_GeV/D");
  t1.Branch("Neutron_MomZ_Col_GeV",                      &fNeutron_MomZ_Col_GeV,                      "fNeutron_MomZ_Col_GeV/D");
  t1.Branch("Neutron_MomX_Col_GeV",                      &fNeutron_MomX_Col_GeV,                      "fNeutron_MomX_Col_GeV/D");
  t1.Branch("Neutron_MomY_Col_GeV",                      &fNeutron_MomY_Col_GeV,                      "fNeutron_MomY_Col_GeV/D");
  t1.Branch("Neutron_Targ_Bremss_Loss",                  &fNeutron_Targ_Bremss_Loss,                  "fNeutron_Targ_Bremss_Loss/D");
  t1.Branch("Neutron_Targ_Ion_Loss",                     &fNeutron_Targ_Ion_Loss,                     "fNeutron_Targ_Ion_Loss/D");
  t1.Branch("Neutron_Air_Bremss_Loss",                   &fNeutron_Air_Bremss_Loss,                   "fNeutron_Air_Bremss_Loss/D");
  t1.Branch("Neutron_Air_Ion_Loss",                      &fNeutron_Air_Ion_Loss,                      "fNeutron_Air_Ion_Loss/D");
  t1.Branch("Neutron_Corrected_Theta_Col",               &fNeutron_Corrected_Theta_Col,               "fNeutron_Corrected_Theta_Col/D");
  t1.Branch("Neutron_Corrected_Phi_Col",                 &fNeutron_Corrected_Phi_Col,                 "fNeutron_Corrected_Phi_Col/D");
  t1.Branch("Neutron_Corrected_Energy_Col",              &fNeutron_Corrected_Energy_Col,              "fNeutron_Corrected_Energy_Col/D");
  t1.Branch("Neutron_Corrected_Mom_Col",                 &fNeutron_Corrected_Mom_Col,                 "fNeutron_Corrected_Mom_Col/D");
  t1.Branch("Neutron_Corrected_MomX_Col",                &fNeutron_Corrected_MomX_Col,                "fNeutron_Corrected_MomX_Col/D");
  t1.Branch("Neutron_Corrected_MomY_Col",                &fNeutron_Corrected_MomY_Col,                "fNeutron_Corrected_MomY_Col/D");
  t1.Branch("Neutron_Corrected_MomZ_Col",                &fNeutron_Corrected_MomZ_Col,                "fNeutron_Corrected_MomZ_Col/D");
  t1.Branch("Neutron_Delta_Mom_Col",                     &fNeutron_Delta_Mom_Col,                     "fNeutron_Delta_Mom_Col/D");
  t1.Branch("Neutron_Corrected_Energy_Col_GeV",          &fNeutron_Corrected_Energy_Col_GeV,          "fNeutron_Corrected_Energy_Col_GeV/D");
  t1.Branch("Neutron_Corrected_Mom_Col_GeV",             &fNeutron_Corrected_Mom_Col_GeV,             "fNeutron_Corrected_Mom_Col_GeV/D");
  t1.Branch("Neutron_Corrected_MomX_Col_GeV",            &fNeutron_Corrected_MomX_Col_GeV,            "fNeutron_Corrected_MomX_Col_GeV/D");
  t1.Branch("Neutron_Corrected_MomY_Col_GeV",            &fNeutron_Corrected_MomY_Col_GeV,            "fNeutron_Corrected_MomY_Col_GeV/D");
  t1.Branch("Neutron_Corrected_MomZ_Col_GeV",            &fNeutron_Corrected_MomZ_Col_GeV,            "fNeutron_Corrected_MomZ_Col_GeV/D");
  t1.Branch("Neutron_Delta_Mom_Col_GeV",                 &fNeutron_Delta_Mom_Col_GeV,                 "fNeutron_Delta_Mom_Col_GeV/D");

  t1.Branch("RecoilProton_Theta_Col",                    &fRecoilProton_Theta_Col,                    "fRecoilProton_Theta_Col/D");
  t1.Branch("RecoilProton_Phi_Col",                      &fRecoilProton_Phi_Col,                      "fRecoilProton_Phi_Col/D");
  t1.Branch("RecoilProton_Mom_Col",                      &fRecoilProton_Mom_Col,                      "fRecoilProton_Mom_Col/D");
  t1.Branch("RecoilProton_Energy_Col",                   &fRecoilProton_Energy_Col,                   "fRecoilProton_Energy_Col/D");
  t1.Branch("RecoilProton_MomZ_Col",                     &fRecoilProton_MomZ_Col,                     "fRecoilProton_MomZ_Col/D");
  t1.Branch("RecoilProton_MomX_Col",                     &fRecoilProton_MomX_Col,                     "fRecoilProton_MomX_Col/D");
  t1.Branch("RecoilProton_MomY_Col",                     &fRecoilProton_MomY_Col,                     "fRecoilProton_MomY_Col/D");
  t1.Branch("RecoilProton_Energy_Col_GeV",               &fRecoilProton_Energy_Col_GeV,               "fRecoilProton_Energy_Col_GeV/D");
  t1.Branch("RecoilProton_MomZ_Col_GeV",                 &fRecoilProton_MomZ_Col_GeV,                 "fRecoilProton_MomZ_Col_GeV/D");
  t1.Branch("RecoilProton_MomX_Col_GeV",                 &fRecoilProton_MomX_Col_GeV,                 "fRecoilProton_MomX_Col_GeV/D");
  t1.Branch("RecoilProton_MomY_Col_GeV",                 &fRecoilProton_MomY_Col_GeV,                 "fRecoilProton_MomY_Col_GeV/D");
  t1.Branch("RecoilProton_Targ_Bremss_Loss",             &fRecoilProton_Targ_Bremss_Loss,             "fRecoilProton_Targ_Bremss_Loss/D");
  t1.Branch("RecoilProton_Targ_Ion_Loss",                &fRecoilProton_Targ_Ion_Loss,                "fRecoilProton_Targ_Ion_Loss/D");
  t1.Branch("RecoilProton_Air_Bremss_Loss",              &fRecoilProton_Air_Bremss_Loss,              "fRecoilProton_Air_Bremss_Loss/D");
  t1.Branch("RecoilProton_Air_Ion_Loss",                 &fRecoilProton_Air_Ion_Loss,                 "fRecoilProton_Air_Ion_Loss/D");
  t1.Branch("RecoilProton_Corrected_Theta_Col",          &fRecoilProton_Corrected_Theta_Col,          "fRecoilProton_Corrected_Theta_Col/D");
  t1.Branch("RecoilProton_Corrected_Phi_Col",            &fRecoilProton_Corrected_Phi_Col,            "fRecoilProton_Corrected_Phi_Col/D");
  t1.Branch("RecoilProton_Corrected_Energy_Col",         &fRecoilProton_Corrected_Energy_Col,         "fRecoilProton_Corrected_Energy_Col/D");
  t1.Branch("RecoilProton_Corrected_Mom_Col",            &fRecoilProton_Corrected_Mom_Col,            "fRecoilProton_Corrected_Mom_Col/D");
  t1.Branch("RecoilProton_Corrected_MomX_Col",           &fRecoilProton_Corrected_MomX_Col,           "fRecoilProton_Corrected_MomX_Col/D");
  t1.Branch("RecoilProton_Corrected_MomY_Col",           &fRecoilProton_Corrected_MomY_Col,           "fRecoilProton_Corrected_MomY_Col/D");
  t1.Branch("RecoilProton_Corrected_MomZ_Col",           &fRecoilProton_Corrected_MomZ_Col,           "fRecoilProton_Corrected_MomZ_Col/D");
  t1.Branch("RecoilProton_Delta_Mom_Col",                &fRecoilProton_Delta_Mom_Col,                "fRecoilProton_Delta_Mom_Col/D");
  t1.Branch("RecoilProton_Corrected_Energy_Col_GeV",     &fRecoilProton_Corrected_Energy_Col_GeV,     "fRecoilProton_Corrected_Energy_Col_GeV/D");
  t1.Branch("RecoilProton_Corrected_Mom_Col_GeV",        &fRecoilProton_Corrected_Mom_Col_GeV,        "fRecoilProton_Corrected_Mom_Col_GeV/D");
  t1.Branch("RecoilProton_Corrected_MomX_Col_GeV",       &fRecoilProton_Corrected_MomX_Col_GeV,       "fRecoilProton_Corrected_MomX_Col_GeV/D");
  t1.Branch("RecoilProton_Corrected_MomY_Col_GeV",       &fRecoilProton_Corrected_MomY_Col_GeV,       "fRecoilProton_Corrected_MomY_Col_GeV/D");
  t1.Branch("RecoilProton_Corrected_MomZ_Col_GeV",       &fRecoilProton_Corrected_MomZ_Col_GeV,       "fRecoilProton_Corrected_MomZ_Col_GeV/D");
  t1.Branch("RecoilProton_Delta_Mom_Col_GeV",            &fRecoilProton_Delta_Mom_Col_GeV,            "fRecoilProton_Delta_Mom_Col_GeV/D");

  // t1.Branch("W_GeV_Col",                                 &fW_GeV_Col,                                 "fW_GeV_Col/D");
  // t1.Branch("W_Col",                                     &fW_Col,                                     "fW_Col/D");

  t1.Branch("flux_Factor_RF",                            &fFlux_Factor_RF,                            "fFlux_Factor_RF/D");
  t1.Branch("Jacobian_CM",                               &fJacobian_CM,                               "fJacobian_CM/D");
  t1.Branch("Jacobian_CM_RF",                            &fJacobian_CM_RF,                            "fJacobian_CM_RF/D");
  t1.Branch("Jacobian_CM_Col",                           &fJacobian_CM_Col,                           "fJacobian_CM_Col/D");
  t1.Branch("ZASigmaPara",                               &fZASigmaPara,                               "fZASigmaPara/D");
  t1.Branch("ZASigmaLab",                                &fZASigmaLab,                                "fZASigmaLab/D");
  t1.Branch("WFactor",                                   &fWFactor,                                   "fWFactor/D");
  t1.Branch("A",                                         &fA,                                         "fA/D");
  t1.Branch("ZASig_T",                                   &fZASig_T,                                   "fZASig_T/D");
  t1.Branch("ZASig_L",                                   &fZASig_L,                                   "fZASig_L/D");
  t1.Branch("ZASig_LT",                                  &fZASig_LT,                                  "fZASig_LT/D");
  t1.Branch("ZASig_TT",                                  &fZASig_TT,                                  "fZASig_TT/D");
  t1.Branch("SSAsym",                                    &fSSAsym,                                    "fSSAsym/D");
  t1.Branch("Vertex_X",                                  &fVertex_X,                                  "fVertex_X/D");
  t1.Branch("Vertex_Y",                                  &fVertex_Y,                                  "fVertex_Y/D");
  t1.Branch("Vertex_Z",                                  &fVertex_Z,                                  "fVertex_Z/D");

  
  for ( int i = 0; i < fNEvents; i++ ) {
  // while ( fNRecorded < fNEvents ) {
    
    fNGenerated ++;
    
    fProton_Theta_Col                     = 0.0;
    fProton_Phi_Col                       = 0.0;
    fProton_Mom_Col                       = 1e-6;

    if  ( kCalcFermi ) {
      fProton_Mom_Col                     = myPim.fermiMomentum();      
      fProton_Theta_Col                   = ( 180.0 / fPi ) * TMath::ACos( fRandom->Uniform(-1.0, 1.0) );
      fProton_Phi_Col                     = fRandom->Uniform( 0 , 360 );       
    }

    fProton_Energy_Col                    = TMath::Sqrt( TMath::Power( fProton_Mom_Col , 2 ) + TMath::Power(fProton_Mass,2 ) ); 
    fProton_MomZ_Col                      = fProton_Mom_Col * TMath::Cos((fPi/180.0)*fProton_Theta_Col);    
    fProton_MomX_Col                      = fProton_Mom_Col * TMath::Sin((fPi/180.0)*fProton_Theta_Col) * 
                                                              TMath::Cos((fPi/180.0)*fProton_Phi_Col);
    fProton_MomY_Col                      = fProton_Mom_Col * TMath::Sin((fPi/180.0)*fProton_Theta_Col) * 
                                                              TMath::Sin((fPi/180.0)*fProton_Phi_Col);
    fBetaX_Col_RF                         = fProton_MomX_Col / fProton_Energy_Col;
    fBetaY_Col_RF                         = fProton_MomY_Col / fProton_Energy_Col;
    fBetaZ_Col_RF                         = fProton_MomZ_Col / fProton_Energy_Col;
    fBeta_Col_RF                          = TMath::Sqrt( TMath::Power( fBetaX_Col_RF , 2 ) + 
							 TMath::Power( fBetaY_Col_RF , 2 ) + 
							 TMath::Power( fBetaZ_Col_RF , 2 ) );
    fGamma_Col_RF                         = 1.0/TMath::Sqrt( 1 - TMath::Power(fBeta_Col_RF,2));

    fProton_Mom_Col_GeV                   = fProton_Mom_Col / 1000.0;    
    fProton_Energy_Col_GeV                = fProton_Energy_Col/1000.0;
    fProton_MomX_Col_GeV                  = fProton_MomX_Col / 1000.0;
    fProton_MomY_Col_GeV                  = fProton_MomY_Col / 1000.0;
    fProton_MomZ_Col_GeV                  = fProton_MomZ_Col / 1000.0;   
    // ----------------------------------------------------
    // Transformation to the Proton frame
    // ----------------------------------------------------
    fProton_MomX_RF                       = 0.0;
    fProton_MomY_RF                       = 0.0;
    fProton_MomZ_RF                       = 0.0;
    fProton_Mom_RF                        = 0.0;
    fProton_Energy_RF                     = fProton_Mass;
    fProton_MomX_RF_GeV                   = fProton_MomX_RF / 1000.0;
    fProton_MomY_RF_GeV                   = fProton_MomY_RF / 1000.0;
    fProton_MomZ_RF_GeV                   = fProton_MomZ_RF / 1000.0;
    fProton_Mom_RF_GeV                    = fProton_Mom_RF / 1000.0;
    fProton_Energy_RF_GeV                 = fProton_Energy_RF / 1000.0;

    // ----------------------------------------------------
    // Incoming Electron in lab (collider) frame
    // ----------------------------------------------------
    fElectron_Energy_Col                  = fElectron_Kin_Col; // fElectron_Kin_Col + fElectron_Mass ;

    // Incoming Electron's energy loss by Bremsstrahlung:
    fElectron_Targ_Thickness              = 20.0 * fHelium_Density; // fRandom->Uniform(0,40);
    fElectron_Targ_Thickness_RadLen       = ( fElectron_Targ_Thickness ) / X0( fHelium_Z , fHelium_A );
    fElectron_Targ_BT                     = fElectron_Targ_Thickness_RadLen * b( fHelium_Z );
    fElectron_Targ_Bremss_Loss            = Bremsstrahlung( fElectron_Energy_Col , fElectron_Targ_BT );
    fElectron_Targ_Ion_Loss               = IonLoss( fElectron_Energy_Col, fHelium_A, fHelium_Z, fHelium_Density, fElectron_Targ_Thickness );
    fElectron_Corrected_Energy_Col        = fElectron_Energy_Col - fElectron_Targ_Ion_Loss - fElectron_Targ_Bremss_Loss;
    fElectron_Corrected_Energy_Col_GeV    = fElectron_Corrected_Energy_Col / 1000.0;

    if ( kCalcBremss ) {
      fElectron_Energy_Col                = fElectron_Energy_Col - fElectron_Targ_Bremss_Loss;
    }
    
    if ( kCalcIon ) {
      fElectron_Energy_Col               = fElectron_Energy_Col - fElectron_Targ_Ion_Loss;
    }
    
    fElectron_Mom_Col                     = TMath::Sqrt( TMath::Power(fElectron_Energy_Col , 2) - TMath::Power(fElectron_Mass , 2) );
    fElectron_Theta_Col                   = 0.0;
    fElectron_Phi_Col                     = 0.0;
    fElectron_MomZ_Col                    = fElectron_Mom_Col * TMath::Cos((fPi/180.0)*fElectron_Theta_Col);  
    fElectron_MomX_Col                    = fElectron_Mom_Col * TMath::Sin((fPi/180.0)*fElectron_Theta_Col) * 
                                                                TMath::Cos((fPi/180.0)*fElectron_Phi_Col);
    fElectron_MomY_Col                    = fElectron_Mom_Col * TMath::Sin((fPi/180.0)*fElectron_Theta_Col) * 
                                                                TMath::Sin((fPi/180.0)*fElectron_Phi_Col);  
    
    fElectron_Energy_Col_GeV              = fElectron_Energy_Col / 1000.0;
    fElectron_Mom_Col_GeV                 = fElectron_Mom_Col / 1000.0;
    fElectron_MomX_Col_GeV                =  fElectron_MomX_Col / 1000.0;
    fElectron_MomY_Col_GeV                =  fElectron_MomY_Col / 1000.0;
    fElectron_MomZ_Col_GeV                =  fElectron_MomZ_Col / 1000.0;
    // ----------------------------------------------------

    // ----------------------------------------------------
    // Transform incoming Electron in Target Neutron(Proton) rest frame
    // ----------------------------------------------------
    fElectron_Energy_RF       = fGamma_Col_RF * fElectron_Energy_Col - 
                                fGamma_Col_RF * fBetaX_Col_RF * fElectron_MomX_Col - 
                                fGamma_Col_RF * fBetaY_Col_RF * fElectron_MomY_Col -
                                fGamma_Col_RF * fBetaZ_Col_RF * fElectron_MomZ_Col;
    
    fElectron_MomX_RF         = -fGamma_Col_RF * fBetaX_Col_RF * fElectron_Energy_Col + 
      ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaX_Col_RF,2)     / TMath::Power(fBeta_Col_RF,2) ) ) * fElectron_MomX_Col + 
      ( fGamma_Col_RF - 1 )       * ( ( fBetaX_Col_RF * fBetaY_Col_RF ) / TMath::Power(fBeta_Col_RF,2) )   * fElectron_MomY_Col + 
      ( fGamma_Col_RF - 1 )       * ( ( fBetaX_Col_RF * fBetaZ_Col_RF ) / TMath::Power(fBeta_Col_RF,2) )   * fElectron_MomZ_Col;
    
    fElectron_MomY_RF         = -fGamma_Col_RF * fBetaY_Col_RF * fElectron_Energy_Col + 
      ( fGamma_Col_RF - 1 )       * ( ( fBetaX_Col_RF * fBetaY_Col_RF ) / TMath::Power(fBeta_Col_RF,2) )   * fElectron_MomX_Col + 
      ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaY_Col_RF,2)     / TMath::Power(fBeta_Col_RF,2) ) ) * fElectron_MomY_Col + 
      ( fGamma_Col_RF - 1 )       * ( ( fBetaY_Col_RF * fBetaZ_Col_RF ) / TMath::Power(fBeta_Col_RF,2) )   * fElectron_MomZ_Col;
    
    fElectron_MomZ_RF         = -fGamma_Col_RF * fBetaZ_Col_RF * fElectron_Energy_Col + 
      ( fGamma_Col_RF - 1 )       * ( ( fBetaX_Col_RF * fBetaZ_Col_RF ) / TMath::Power(fBeta_Col_RF,2) )   * fElectron_MomX_Col + 
      ( fGamma_Col_RF - 1 )       * ( ( fBetaY_Col_RF * fBetaZ_Col_RF ) / TMath::Power(fBeta_Col_RF,2) )   * fElectron_MomY_Col +
      ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaZ_Col_RF,2)     / TMath::Power(fBeta_Col_RF,2) ) ) * fElectron_MomZ_Col; 
    
    fElectron_Mom_RF          = TMath::Sqrt( TMath::Power(fElectron_MomX_RF,2) + 
					     TMath::Power(fElectron_MomY_RF,2) + 
					     TMath::Power(fElectron_MomZ_RF,2));

    fElectron_Theta_RF        = (180/fPi) *  TMath::ATan( TMath::Sqrt( TMath::Power(fElectron_MomX_RF , 2) + 
								       TMath::Power(fElectron_MomY_RF , 2) ) / fElectron_MomZ_RF );
    fElectron_Phi_RF          = (180/fPi)*TMath::ATan2(fElectron_MomY_RF,fElectron_MomX_RF);

    if ( ( fElectron_Theta_RF < 0 ) && ( fElectron_Phi_RF <= 0 ) ) 
      { fElectron_Theta_RF = 180.0 + fElectron_Theta_RF; fElectron_Phi_RF = 360 + fElectron_Phi_RF;}
    if ( ( fElectron_Theta_RF > 0 ) && ( fElectron_Phi_RF < 0 )  ) 
      { fElectron_Theta_RF = fElectron_Theta_RF;         fElectron_Phi_RF = 360 + fElectron_Phi_RF;}
    if ( ( fElectron_Theta_RF < 0 ) && ( fElectron_Phi_RF > 0 )  ) 
      { fElectron_Theta_RF = 180.0 + fElectron_Theta_RF; fElectron_Phi_RF = fElectron_Phi_RF;}
    
    fElectron_Mom_RF_GeV      = fElectron_Mom_RF / 1000.0;
    fElectron_Energy_RF_GeV   = fElectron_Energy_RF / 1000.0;
    fElectron_MomX_RF_GeV     =  fElectron_MomX_RF / 1000.0;
    fElectron_MomY_RF_GeV     =  fElectron_MomY_RF / 1000.0;
    fElectron_MomZ_RF_GeV     =  fElectron_MomZ_RF / 1000.0;

    // ----------------------------------------------------
    // Specify the energy of scatterd electron in Proton's rest frame, 
    // then get the momentum of scattered electron in Proton's rest frame and then 
    // finally get the Qsq.
    // This mehod will give us the theta of scattered electron w.r.t to direction 
    // of the incoming electron in Proton's rest frame.
    // ----------------------------------------------------	
    // cos(3 deg)  = 0.99862953475 ,  cos(30 deg) = 0.86602540378
    // fElec_ScatElec_Theta_RF        = acos( 2.0 * fRandom->Uniform() - 1.0 );
    // fElec_ScatElec_Theta_RF       = ( 180.0 / fPi ) * TMath::ACos( fRandom->Uniform( 0.82 , 1.0 ) );
    fElec_ScatElec_Theta_RF       = ( 180.0 / fPi ) * TMath::ACos( fRandom->Uniform( 0.0 , 1.0 ) );
    fScatElec_Cone_Phi_RF          = fRandom->Uniform(0,360);
    fScatElec_Mom_RF               = fRandom->Uniform(0.1 *fElectron_Mom_RF , 0.9 * fElectron_Mom_RF);
    fScatElec_Energy_RF            = TMath::Sqrt( TMath::Power( fScatElec_Mom_RF,2) + 
						  TMath::Power( fElectron_Mass , 2) );
    fScatElec_Mom_RF_GeV           = fScatElec_Mom_RF / 1000.0;
    fScatElec_Energy_RF_GeV        = fScatElec_Energy_RF/1000.0;

    // ----------------------------------------------------
    // Qsq, Energy and magnitude of Momentum of Virtual Photon in Proton's rest frame
    // ----------------------------------------------------    
    fPhoton_Energy_RF_GeV          = fElectron_Energy_RF_GeV - fScatElec_Energy_RF_GeV;
    fPhoton_Energy_RF              = fPhoton_Energy_RF_GeV * 1000.0;    
    fPhoton_Mom_RF_GeV             = TMath::Sqrt( std::abs( TMath::Power( fElectron_Mom_RF_GeV , 2 ) + 
							    TMath::Power( fScatElec_Mom_RF_GeV , 2 ) - 
							    2.0 * fElectron_Mom_RF_GeV * fScatElec_Mom_RF_GeV * 
							    TMath::Cos( ( fPi / 180.0 ) * ( fElec_ScatElec_Theta_RF ) ) ) );    
    fPhoton_Mom_RF                 = fPhoton_Mom_RF_GeV * 1000.0;    
    fQsq_GeV                       = TMath::Power( fPhoton_Mom_RF_GeV ,2 ) -  TMath::Power( fPhoton_Energy_RF_GeV ,2 );    
    fQsq                           = fQsq_GeV * 1000000.0;
    
    
    // ----------------------------------------------------
    // Scattering angle of scattered Electron w.r.t direction of incoming Electron  286.0
    // ----------------------------------------------------
    fScatElec_Angle    = ( TMath::Power( fElectron_Mom_RF , 2 ) + TMath::Power( fScatElec_Mom_RF , 2 ) - 
			   TMath::Power( fPhoton_Mom_RF , 2 ) ) / (2.0*fElectron_Mom_RF*fScatElec_Mom_RF);
        
    fScatElec_Alpha_RF = fScatElec_Mom_RF * ( TMath::Cos((fPi/180.0)*(fElec_ScatElec_Theta_RF)) * 
					      TMath::Sin((fPi/180.0)*(fElectron_Theta_RF)) +
					      TMath::Sin((fPi/180.0)*(fElec_ScatElec_Theta_RF)) * 
					      TMath::Cos((fPi/180.0)*(fElectron_Theta_RF)) * 
					      TMath::Cos((fPi/180.0)*(fScatElec_Cone_Phi_RF)) );
    
    fScatElec_Beta_RF  = fScatElec_Mom_RF * TMath::Sin((fPi/180.0)*(fElec_ScatElec_Theta_RF)) * 
                                            TMath::Sin((fPi/180.0)*(fScatElec_Cone_Phi_RF));

    fScatElec_MomX_RF  = fScatElec_Alpha_RF * TMath::Cos( ( fPi / 180.0 ) * ( fElectron_Phi_RF ) ) + 
                         fScatElec_Beta_RF  * TMath::Sin( ( fPi / 180.0 ) * ( fElectron_Phi_RF ) );
    fScatElec_MomY_RF  = fScatElec_Alpha_RF * TMath::Sin( ( fPi / 180.0 ) * ( fElectron_Phi_RF ) ) - 
                         fScatElec_Beta_RF  * TMath::Cos( ( fPi / 180.0 ) * ( fElectron_Phi_RF ) );
    
    fScatElec_MomZ_RF  = fScatElec_Mom_RF * ( TMath::Cos((fPi/180.0)*(fElec_ScatElec_Theta_RF)) * 
					      TMath::Cos((fPi/180.0)*(fElectron_Theta_RF)) -
					      TMath::Sin((fPi/180.0)*(fElec_ScatElec_Theta_RF)) * 
					      TMath::Sin((fPi/180.0)*(fElectron_Theta_RF)) * 
					      TMath::Cos((fPi/180.0)*(fScatElec_Cone_Phi_RF)) );
        
    fScatElec_Theta_RF = (180/fPi) * TMath::ATan( TMath::Sqrt( TMath::Power(fScatElec_MomX_RF , 2) + 
							       TMath::Power(fScatElec_MomY_RF , 2) ) / fScatElec_MomZ_RF );    
    fScatElec_Phi_RF   = (180/fPi)*TMath::ATan2(fScatElec_MomY_RF,fScatElec_MomX_RF);

    if ( ( fScatElec_Theta_RF < 0 ) && ( fScatElec_Phi_RF <= 0 ) ) 
      { fScatElec_Theta_RF = 180.0 + fScatElec_Theta_RF;  fScatElec_Phi_RF = 360 + fScatElec_Phi_RF;}
    if ( ( fScatElec_Theta_RF > 0 ) && ( fScatElec_Phi_RF < 0  ) ) 
      { fScatElec_Theta_RF = fScatElec_Theta_RF;          fScatElec_Phi_RF = 360 + fScatElec_Phi_RF;}
    if ( ( fScatElec_Theta_RF < 0 ) && ( fScatElec_Phi_RF > 0 ) )  
      { fScatElec_Theta_RF = 180.0 + fScatElec_Theta_RF;  fScatElec_Phi_RF = fScatElec_Phi_RF;}    
    
    fScatElec_MomX_RF_GeV  = fScatElec_MomX_RF  / 1000.0;
    fScatElec_MomY_RF_GeV  = fScatElec_MomY_RF  / 1000.0;
    fScatElec_MomZ_RF_GeV  = fScatElec_MomZ_RF  / 1000.0;

    // ----------------------------------------------------
    // X, Y and Z compotnents of momentum of Virtual Photon in Proton rest frame
    // ----------------------------------------------------
    fPhoton_MomX_RF  =  fElectron_MomX_RF - fScatElec_MomX_RF;
    fPhoton_MomY_RF  =  fElectron_MomY_RF - fScatElec_MomY_RF;
    fPhoton_MomZ_RF  =  fElectron_MomZ_RF - fScatElec_MomZ_RF;

    fPhoton_Theta_RF = (180/fPi) * TMath::ATan( TMath::Sqrt( TMath::Power(fPhoton_MomX_RF , 2) + 
							     TMath::Power(fPhoton_MomY_RF , 2) ) / fPhoton_MomZ_RF );
    fPhoton_Phi_RF   = (180/fPi)*TMath::ATan2(fPhoton_MomY_RF,fPhoton_MomX_RF);

    if ( ( fPhoton_Theta_RF < 0 ) && ( fPhoton_Phi_RF <= 0 ) ) 
      { fPhoton_Theta_RF = 180.0 + fPhoton_Theta_RF;  fPhoton_Phi_RF = 360 + fPhoton_Phi_RF;}
    if ( ( fPhoton_Theta_RF > 0 ) && ( fPhoton_Phi_RF < 0  ) ) 
      { fPhoton_Theta_RF = fPhoton_Theta_RF;          fPhoton_Phi_RF = 360 + fPhoton_Phi_RF;}
    if ( ( fPhoton_Theta_RF < 0 ) && ( fPhoton_Phi_RF > 0  ) ) 
      { fPhoton_Theta_RF = 180.0 + fPhoton_Theta_RF;  fPhoton_Phi_RF = fPhoton_Phi_RF;}

    fPhoton_MomX_RF_GeV  = fPhoton_MomX_RF / 1000.0;
    fPhoton_MomY_RF_GeV  = fPhoton_MomY_RF / 1000.0;
    fPhoton_MomZ_RF_GeV  = fPhoton_MomZ_RF / 1000.0;

    // ----------------------------------------------------
    // Invariant Mass (P_g + P_p)^2
    // ----------------------------------------------------

    fWSq_GeV    = TMath::Power( fProton_Mass_GeV , 2 ) - fQsq_GeV + 
                  2.0 * ( fPhoton_Energy_RF_GeV * fProton_Energy_RF_GeV - 
			  fPhoton_MomX_RF_GeV   * fProton_MomX_RF_GeV - 
			  fPhoton_MomY_RF_GeV   * fProton_MomY_RF_GeV - 
			  fPhoton_MomZ_RF_GeV   * fProton_MomZ_RF_GeV );
    
    if ( fWSq_GeV < 0 ){
      if(print){ cout << "W square is negative = "<< fWSq_GeV << endl; }      
      fWSqNeg ++;
      // continue;
    }
    
    fWSq = fWSq_GeV * 1000000.0;


    fW_GeV    = TMath::Sqrt( TMath::Power(fProton_Mass_GeV,2) - fQsq_GeV + 
			     2.0 * ( fPhoton_Energy_RF_GeV * fProton_Energy_RF_GeV - 
				     fPhoton_MomX_RF_GeV   * fProton_MomX_RF_GeV - 
				     fPhoton_MomY_RF_GeV   * fProton_MomY_RF_GeV - 
				     fPhoton_MomZ_RF_GeV   * fProton_MomZ_RF_GeV ) );    

    if ( fW_GeV < 1.9 ){
      if(print){ cout << "W is less than 1.9. W = "<< fW_GeV << endl; }
      fWLess1P9 ++;
      // continue;
    }
    
    fW = fW_GeV * 1000.0;
    
    if (  fW < ( fProton_Mass + fPion_Mass ) ){
      if(print) { cout << "skipping: w is less than Mp + Mpi. On shell pion cannot be created." << endl; }
      fWLessShell ++;
      // continue;
    }

    // ----------------------------------------------------
    // Virtual photon (q-vector) in proton+photon cm frame
    // ----------------------------------------------------
    fProton_Energy_CM     = ( TMath::Power(fW,2) + fQsq + TMath::Power(fProton_Mass,2) ) / ( 2.0 * fW );    
    fProton_Energy_CM_GeV = fProton_Energy_CM / 1000.0;     
    fProton_Mom_CM        = TMath::Sqrt( TMath::Power( fProton_Energy_CM , 2) - 
					 TMath::Power( fProton_Mass , 2) );    
    fPhoton_Energy_CM     = TMath::Sqrt( TMath::Power( fProton_Mom_CM , 2) - fQsq);
    fPhoton_Mom_CM        = fProton_Mom_CM;
    fPhoton_Mom_CM_GeV    = fPhoton_Mom_CM / 1000.0;
    fPhoton_Energy_CM_GeV = fPhoton_Energy_CM / 1000.0;
    fProton_Mom_CM_GeV    = fProton_Mom_CM / 1000.0;
    
    // ----------------------------------------------------
    // Pion 4-Momentum in CM frame, theta = 161.0, phi =  350.0;
    // ----------------------------------------------------
    // Comment: If pion theta in cm is very small then fix the phi
    fPion_Theta_CM        = ( 180.0 / fPi ) * TMath::ACos( fRandom->Uniform( 0.0, 1.0 ) );
    fPion_Phi_CM          = fRandom->Uniform(0,360);

    fPion_Energy_CM       = ( TMath::Power( fW , 2) + TMath::Power(fPion_Mass , 2) - 
			      TMath::Power(fNeutron_Mass , 2) ) / ( 2.0 * fW);    

    fPion_Energy_CM_GeV   = fPion_Energy_CM / 1000.0;
    fPion_Mom_CM          = TMath::Sqrt( TMath::Power(fPion_Energy_CM , 2) - 
					 TMath::Power(fPion_Mass , 2));
    fPion_Mom_CM_GeV      = fPion_Mom_CM / 1000.0;

    // ----------------------------------------------------
    // Recoil Neutron in CM frame
    // ----------------------------------------------------

    fNeutron_Mom_CM        = fPion_Mom_CM;
    fNeutron_Mom_CM_GeV    = fNeutron_Mom_CM / 1000.0;
    fNeutron_Energy_CM     = TMath::Sqrt( TMath::Power( fNeutron_Mom_CM , 2) + TMath::Power( fNeutron_Mass , 2) );    
    fNeutron_Energy_CM_GeV = fNeutron_Energy_CM / 1000.0;    
    fNeutron_Theta_CM      = (180.0 - fPion_Theta_CM);
    fNeutron_Phi_CM        = (180.0 + fPion_Phi_CM);  
    if ( TMath::Abs(fNeutron_Phi_CM) > 360 )   
      fNeutron_Phi_CM = TMath::Abs(fNeutron_Phi_CM) - 360.0;
    
    Double_t fPion_Mom_Para_CM     = fPion_Mom_CM * TMath::Cos((fPi/180.0)*fPion_Theta_CM);
    Double_t fPion_Mom_Perp_CM     = fPion_Mom_CM * TMath::Sin((fPi/180.0)*fPion_Theta_CM);
    Double_t fNeutron_Mom_Para_CM  = fNeutron_Mom_CM * TMath::Cos((fPi/180.0)*fNeutron_Theta_CM);
    Double_t fNeutron_Mom_Perp_CM  = fNeutron_Mom_CM * TMath::Sin((fPi/180.0)*fNeutron_Theta_CM);
        
    // ----------------------------------------------------
    // Transform Pion from CM fram to rest frame of Proton  w.r.t q-vector. 
    // First give a Loerentz boost to Pion from CM frame to
    // Proton's rest frame. Second, rotate Pion coordinates w.r.t e- beam (in Proton's rest frame)
    // ----------------------------------------------------

    fBeta_CM_RF                = 1.0*(fPhoton_Mom_RF / ( fPhoton_Energy_RF + fProton_Mass));
    fGamma_CM_RF               = ( fPhoton_Energy_RF + fProton_Mass) / fW;

    fPion_Energy_RF            = fGamma_CM_RF * fPion_Energy_CM + 
                                 fGamma_CM_RF * fBeta_CM_RF * fPion_Mom_CM * TMath::Cos((fPi/180)*fPion_Theta_CM);     

    fPion_Mom_RF               = TMath::Sqrt( TMath::Power(fPion_Energy_RF , 2 ) - TMath::Power(fPion_Mass , 2 ) );
    fPiqVec_Theta_RF           = (180/fPi)* TMath::ASin( ( TMath::Sin((fPi/180) * (fPion_Theta_CM ) ) * 
							   fPion_Mom_CM ) / fPion_Mom_RF );
    fPion_Energy_RF_GeV        = fPion_Energy_RF / 1000.0;
    fPion_Mom_RF_GeV           = fPion_Mom_RF / 1000.0;


    // ----------------------------------------------------
    // rotate pion to co-ordinates wrt e- beam (in proton rest frame)
    // ----------------------------------------------------
    fPion_Alpha          = ( TMath::Cos((fPi/180)*fPiqVec_Theta_RF) * TMath::Sin((fPi/180)*fPhoton_Theta_RF) ) - 
                           ( TMath::Sin((fPi/180)*fPiqVec_Theta_RF) * TMath::Cos((fPi/180)*fPhoton_Theta_RF) * 
			     TMath::Cos((fPi/180)*fPion_Phi_CM));

    fPion_Beta           = TMath::Sin((fPi/180)*fPiqVec_Theta_RF) * TMath::Sin((fPi/180)*fPion_Phi_CM);

    fPion_MomX_RotRF     = fPion_Mom_RF * ( fPion_Alpha * TMath::Cos((fPi/180)*fPhoton_Phi_RF) - fPion_Beta  * TMath::Sin((fPi/180)*fPhoton_Phi_RF));
    fPion_MomY_RotRF     = fPion_Mom_RF * ( fPion_Alpha * TMath::Sin((fPi/180)*fPhoton_Phi_RF) + fPion_Beta  * TMath::Cos((fPi/180)*fPhoton_Phi_RF));

    fPion_MomZ_RotRF     = fPion_Mom_RF * ( TMath::Cos(((fPi/180)*fPiqVec_Theta_RF)) * TMath::Cos(((fPi/180)*fPhoton_Theta_RF)) +                       
			 		    TMath::Sin((fPi/180)*fPiqVec_Theta_RF)   * TMath::Sin((fPi/180)*fPhoton_Theta_RF) * TMath::Cos((fPi/180)*fPion_Phi_CM) );
    
    fPion_Mom_RotRF      = TMath::Sqrt( TMath::Power(fPion_MomX_RotRF,2) + 
					TMath::Power(fPion_MomY_RotRF,2) + 
					TMath::Power(fPion_MomZ_RotRF,2) );    
    fPion_Mom_RotRF_GeV  = fPion_Mom_RotRF / 1000.0;
    
    fPion_Theta_RotRF    = (180/fPi) * TMath::ATan( TMath::Sqrt( TMath::Power(fPion_MomX_RotRF , 2) + 
								 TMath::Power(fPion_MomY_RotRF , 2) ) / fPion_MomZ_RotRF );
    fPion_Phi_RotRF      = (180/fPi)*TMath::ATan2(fPion_MomY_RotRF,fPion_MomX_RotRF);
    if ( ( fPion_Theta_RotRF < 0 ) && ( fPion_Phi_RotRF < 0 ) ) { fPion_Theta_RotRF = 180.0 + fPion_Theta_RotRF;  fPion_Phi_RotRF = 360 + fPion_Phi_RotRF;}
    if ( ( fPion_Theta_RotRF > 0 ) && ( fPion_Phi_RotRF < 0 ) ) { fPion_Theta_RotRF = fPion_Theta_RotRF;          fPion_Phi_RotRF = 360 + fPion_Phi_RotRF;}
    if ( ( fPion_Theta_RotRF < 0 ) && ( fPion_Phi_RotRF > 0 ) ) { fPion_Theta_RotRF = 180.0 + fPion_Theta_RotRF;  fPion_Phi_RotRF = fPion_Phi_RotRF;}

    fPion_MomX_RotRF_GeV = fPion_MomX_RotRF / 1000.0;
    fPion_MomY_RotRF_GeV = fPion_MomY_RotRF / 1000.0;
    fPion_MomZ_RotRF_GeV = fPion_MomZ_RotRF / 1000.0;

    // this equation is valid for parallel kinematics only!
    fT_Para = TMath::Power((fPhoton_Mom_RF - fPion_Mom_RF),2) - TMath::Power((fPhoton_Energy_RF - fPion_Energy_RF),2);
    fT_Para_GeV = fT_Para/1000000.0;
    
    // ----------------------------------------------------
    // general equation for t for non-parallel kinematics
    // ----------------------------------------------------
    fT = TMath::Power( ( fPhoton_MomX_RF - fPion_MomX_RotRF  ) , 2 ) + 
         TMath::Power( ( fPhoton_MomY_RF - fPion_MomY_RotRF  ) , 2 ) + 
         TMath::Power( ( fPhoton_MomZ_RF - fPion_MomZ_RotRF  ) , 2 ) - 
         TMath::Power( ( fPhoton_Energy_RF - fPion_Energy_RF ) , 2 );
    
    fT_GeV = fT / 1000000.0;
    
    // if ( fT_GeV > 1.1 ){ 
    //   // cout << "-t > 1.1: -t = " << fT_GeV << endl;
    //   continue;
    // }
    
    fEpsilon = 1.0 / ( 1.0 + 2.0 * ( TMath::Power(fPhoton_Mom_RF_GeV,2)/fQsq_GeV ) * 
		       TMath::Power( TMath::Tan( (fPi/180.0)*(fScatElec_Theta_RF)/2) ,2 ) );
    
    fx = fQsq_GeV/( 2.0 * fProton_Mass_GeV * fPhoton_Energy_RF_GeV );
    fz = fPion_Energy_RF/fPhoton_Energy_RF;  
    fy = fQsq / ( fx * ( TMath::Power(( fProton_Energy_Col+fElectron_Energy_Col ),2) - 
			 TMath::Power(( fProton_Mom_Col - fElectron_Mom_Col ),2 ) ) - 
		  TMath::Power(fProton_Mass,2) ) ;


    // ----------------------------------------------------
    // Transfrom recoil neutron quantities into rotated rest frame of Proton
    // ----------------------------------------------------  
    fNeutron_Energy_RotRF     = fGamma_CM_RF * fNeutron_Energy_CM + 
                                fGamma_CM_RF * fBeta_CM_RF * fNeutron_Mom_CM * 
                                TMath::Cos((fPi/180.0)*fNeutron_Theta_CM);    
    fNeutron_Energy_RotRF_GeV = fNeutron_Energy_RotRF / 1000.0;        
    fNeutron_Mom_RotRF        = TMath::Sqrt(TMath::Power( fNeutron_Energy_RotRF , 2 ) - 
					    TMath::Power( fNeutron_Mass , 2 ) );    
    fNeutron_Mom_RotRF_GeV    = fNeutron_Mom_RotRF / 1000.0;    
    fNeutron_qVec_Theta_RF    = (180.0/fPi)* TMath::ASin( TMath::Sin( (fPi/180.0) * fNeutron_Theta_CM ) * 
							  fNeutron_Mom_CM / fNeutron_Mom_RotRF );
    Double_t fNeutron_Alpha   = ( TMath::Cos((fPi/180.0) * fNeutron_qVec_Theta_RF ) * 
				  TMath::Sin((fPi/180.0) * fPhoton_Theta_RF ) ) - 
                                ( TMath::Sin((fPi/180.0) * fNeutron_qVec_Theta_RF ) * 
				  TMath::Cos((fPi/180.0) * fPhoton_Theta_RF ) * 
				  TMath::Cos((fPi/180.0) * fNeutron_Phi_CM  ) ) ;

    Double_t fNeutron_Beta    = TMath::Sin((fPi/180.0) * fNeutron_qVec_Theta_RF ) * 
                                TMath::Sin((fPi/180.0) * fNeutron_Phi_CM  );
    
    fNeutron_MomX_RotRF       = fNeutron_Mom_RotRF * ( fNeutron_Alpha * TMath::Cos((fPi/180)*fPhoton_Phi_RF) - 
						       fNeutron_Beta  * TMath::Sin((fPi/180)*fPhoton_Phi_RF));    
    fNeutron_MomY_RotRF       = fNeutron_Mom_RotRF * ( fNeutron_Alpha * TMath::Sin((fPi/180)*fPhoton_Phi_RF) + 
						       fNeutron_Beta  * TMath::Cos((fPi/180)*fPhoton_Phi_RF));	

    fNeutron_MomZ_RotRF       = fNeutron_Mom_RotRF * ( ( TMath::Cos((fPi/180.0) * fNeutron_qVec_Theta_RF ) * 
							 TMath::Cos((fPi/180.0) * fPhoton_Theta_RF ) ) + 
						       ( TMath::Sin((fPi/180.0) * fNeutron_qVec_Theta_RF ) * 
							 TMath::Sin((fPi/180.0) * fPhoton_Theta_RF ) * 
							 TMath::Cos((fPi/180.0) * fNeutron_Phi_CM  ) ) ) ;

    fNeutron_Theta_RotRF = (180/fPi) * TMath::ATan( TMath::Sqrt( TMath::Power(fNeutron_MomX_RotRF , 2) + 
								 TMath::Power(fNeutron_MomY_RotRF , 2) ) / fNeutron_MomZ_RotRF );
    fNeutron_Phi_RotRF = (180/fPi)*TMath::ATan2(fNeutron_MomY_RotRF,fNeutron_MomX_RotRF);

    if ( ( fNeutron_Theta_RotRF < 0 ) && ( fNeutron_Phi_RotRF < 0 ) ) 
      { fNeutron_Theta_RotRF = 180.0 + fNeutron_Theta_RotRF;  fNeutron_Phi_RotRF = 360 + fNeutron_Phi_RotRF;}
    if ( ( fNeutron_Theta_RotRF > 0 ) && ( fNeutron_Phi_RotRF < 0 ) ) 
      { fNeutron_Theta_RotRF = fNeutron_Theta_RotRF;          fNeutron_Phi_RotRF = 360 + fNeutron_Phi_RotRF;}
    if ( ( fNeutron_Theta_RotRF < 0 ) && ( fNeutron_Phi_RotRF > 0 ) ) 
      { fNeutron_Theta_RotRF = 180.0 + fNeutron_Theta_RotRF;  fNeutron_Phi_RotRF = fNeutron_Phi_RotRF;}

    fNeutron_MomX_RotRF_GeV  =  fNeutron_MomX_RotRF  / 1000.0;
    fNeutron_MomY_RotRF_GeV  =  fNeutron_MomY_RotRF  / 1000.0;
    fNeutron_MomZ_RotRF_GeV  =  fNeutron_MomZ_RotRF  / 1000.0; 

    // -----------------------------------------------------------------------------------------------------
    // Transformation to the collider frame.
    // Now transform all of these quantities to the  collider frame.
    // z of collider frame is along electron+proton beam  axis. z of proton rest frame 
    // is along incident electron direction, so these two frames should be parallel to 
    // each other in the z-direction
    // -----------------------------------------------------------------------------------------------------
    
    // -----------------------------------------------------------------------------------------------------
    // Virtual Photon
    // -----------------------------------------------------------------------------------------------------
    
    fPhoton_MomX_Col        = fGamma_Col_RF * fBetaX_Col_RF * fPhoton_Energy_RF +
                              ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaX_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fPhoton_MomX_RF +
                              ( fGamma_Col_RF - 1 ) *       ( fBetaX_Col_RF * fBetaY_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPhoton_MomY_RF +
                              ( fGamma_Col_RF - 1 ) *       ( fBetaX_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPhoton_MomZ_RF;

    fPhoton_MomY_Col        = fGamma_Col_RF * fBetaY_Col_RF * fPhoton_Energy_RF +
                              ( fGamma_Col_RF - 1 ) *       ( fBetaX_Col_RF * fBetaY_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPhoton_MomX_RF +
                              ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaY_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fPhoton_MomY_RF +
                              ( fGamma_Col_RF - 1 ) *       ( fBetaY_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPhoton_MomZ_RF;

    fPhoton_MomZ_Col        = fGamma_Col_RF * fBetaZ_Col_RF * fPhoton_Energy_RF +
                              ( fGamma_Col_RF - 1 )       * ( fBetaX_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPhoton_MomX_RF +
                              ( fGamma_Col_RF - 1 )       * ( fBetaY_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPhoton_MomY_RF +
                              ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaZ_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fPhoton_MomZ_RF;

    fPhoton_Mom_Col         = TMath::Sqrt( TMath::Power(fPhoton_MomZ_Col,2) + TMath::Power(fPhoton_MomX_Col,2) + TMath::Power(fPhoton_MomY_Col,2) );

    fPhoton_Energy_Col      = fGamma_Col_RF * fPhoton_Energy_RF + fGamma_Col_RF * fBetaX_Col_RF * fPhoton_MomX_RF + 
                                                                  fGamma_Col_RF * fBetaY_Col_RF * fPhoton_MomY_RF + 
                                                                  fGamma_Col_RF * fBetaZ_Col_RF * fPhoton_MomZ_RF;
    
    fPhoton_Theta_Col       = (180.0/fPi)*TMath::ATan( TMath::Sqrt( TMath::Power(fPhoton_MomX_Col,2) + TMath::Power(fPhoton_MomY_Col,2))/ fPhoton_MomZ_Col);    
    fPhoton_Phi_Col         = (180/fPi)*TMath::ATan2(fPhoton_MomY_Col,fPhoton_MomX_Col);
    
    if ( ( fPhoton_Theta_Col < 0 ) && ( fPhoton_Phi_Col <= 0 ) ) { fPhoton_Theta_Col = 180.0 + fPhoton_Theta_Col;  fPhoton_Phi_Col = 360 + fPhoton_Phi_Col;}    
    if ( ( fPhoton_Theta_Col > 0 ) && ( fPhoton_Phi_Col < 0  ) ) { fPhoton_Theta_Col = fPhoton_Theta_Col;          fPhoton_Phi_Col = 360 + fPhoton_Phi_Col;}    
    if ( ( fPhoton_Theta_Col < 0 ) && ( fPhoton_Phi_Col > 0  ) ) { fPhoton_Theta_Col = 180.0 + fPhoton_Theta_Col;  fPhoton_Phi_Col = fPhoton_Phi_Col;}

    fPhoton_Mom_Col_GeV     = fPhoton_Mom_Col    / 1000.0;    
    fPhoton_Energy_Col_GeV  = fPhoton_Energy_Col / 1000.0;
    fPhoton_MomX_Col_GeV    = fPhoton_MomX_Col   / 1000.0;
    fPhoton_MomY_Col_GeV    = fPhoton_MomY_Col   / 1000.0;
    fPhoton_MomZ_Col_GeV    = fPhoton_MomZ_Col   / 1000.0;

    // ----------------------------------------------------
    // Scattered Electron
    // ----------------------------------------------------    
    fScatElec_Energy_Col = fGamma_Col_RF * fScatElec_Energy_RF + fGamma_Col_RF * fBetaX_Col_RF * fScatElec_MomX_RF + 
                                                                 fGamma_Col_RF * fBetaY_Col_RF * fScatElec_MomY_RF + 
                                                                 fGamma_Col_RF * fBetaZ_Col_RF * fScatElec_MomZ_RF;

    fScatElec_MomX_Col  = fGamma_Col_RF * fBetaX_Col_RF * fScatElec_Energy_RF +
                          ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaX_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fScatElec_MomX_RF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaX_Col_RF * fBetaY_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fScatElec_MomY_RF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaX_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fScatElec_MomZ_RF;

    fScatElec_MomY_Col  = fGamma_Col_RF * fBetaY_Col_RF * fScatElec_Energy_RF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaX_Col_RF * fBetaY_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fScatElec_MomX_RF +
                          ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaY_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fScatElec_MomY_RF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaY_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fScatElec_MomZ_RF;

    fScatElec_MomZ_Col  = fGamma_Col_RF * fBetaZ_Col_RF * fScatElec_Energy_RF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaX_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fScatElec_MomX_RF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaY_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fScatElec_MomY_RF +
                          ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaZ_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fScatElec_MomZ_RF;

    fScatElec_Theta_Col = (180/fPi)* TMath::ATan( TMath::Sqrt( TMath::Power(fScatElec_MomX_Col,2) + 
							       TMath::Power(fScatElec_MomY_Col,2) ) / fScatElec_MomZ_Col );
    fScatElec_Phi_Col   = (180/fPi)*TMath::ATan2(fScatElec_MomY_Col,fScatElec_MomX_Col);
    
    if ( ( fScatElec_Theta_Col < 0 ) && ( fScatElec_Phi_Col <= 0 ) ) 
      { fScatElec_Theta_Col = 180.0 + fScatElec_Theta_Col;  fScatElec_Phi_Col = 360 + fScatElec_Phi_Col;} 
    if ( ( fScatElec_Theta_Col > 0 ) && ( fScatElec_Phi_Col < 0  ) ) 
      { fScatElec_Theta_Col = fScatElec_Theta_Col;          fScatElec_Phi_Col = 360 + fScatElec_Phi_Col;}
    if ( ( fScatElec_Theta_Col < 0 ) && ( fScatElec_Phi_Col > 0 ) )  
      { fScatElec_Theta_Col = 180.0 + fScatElec_Theta_Col;  fScatElec_Phi_Col = fScatElec_Phi_Col;}
    
    
    fScatElec_Mom_Col = TMath::Sqrt( TMath::Power(fScatElec_MomX_Col,2) + TMath::Power(fScatElec_MomY_Col,2) + TMath::Power(fScatElec_MomZ_Col,2) );

    // --------------------------------- Energy Corrections for Scattered Electron ----------------------------------------------

    // Incoming ScatElec's energy loss by Bremsstrahlung:
    // Here calcuate the Bremsstrahlung of scattered electron, 
    // then substract the Bremsstrahlung energy from scattered electron's energy
    // then recalcualte the momentum of scattered electron and three components of momentum

    fScatElec_Corrected_Theta_Col     = fScatElec_Theta_Col;
    fScatElec_Corrected_Phi_Col       = fScatElec_Phi_Col;
    fScatElec_Corrected_Energy_Col    = fScatElec_Energy_Col;
    fScatElec_Corrected_Mom_Col       = fScatElec_Mom_Col;
    fScatElec_Corrected_MomX_Col      = fScatElec_MomX_Col;
    fScatElec_Corrected_MomY_Col      = fScatElec_MomY_Col;
    fScatElec_Corrected_MomZ_Col      = fScatElec_MomZ_Col;
    fScatElec_Delta_Mom_Col           = 0;

    if ( kCalcBremss || kCalcIon ) {

      fScatElec_Targ_Thickness          = 20.0 * fHelium_Density; // 40.0 - fElectron_Thickness;
      fScatElec_Targ_Thickness_RadLen   = ( fScatElec_Targ_Thickness ) / X0( fHelium_Z , fHelium_A );
      fScatElec_Targ_BT                 = fScatElec_Targ_Thickness_RadLen * b( fHelium_Z );
      fScatElec_Targ_Bremss_Loss        = Bremsstrahlung( fScatElec_Energy_Col , fScatElec_Targ_BT );
      fScatElec_Air_Thickness           = 450.0 * fAir_Density; 
      if ( fScatElec_Theta_Col < 16 ) {
	fScatElec_Air_Thickness         = 950.0 * fAir_Density;
      }    
      fRadiation_Lenght_Air             = ( X0( 7, 14.007) * X0( 8, 16 ) ) / ( 0.766 * X0( 8, 15.999 ) + 0.233 * X0( 7, 14.007) );
      fScatElec_Air_Thickness_RadLen    = fScatElec_Air_Thickness / fRadiation_Lenght_Air;
      fScatElec_Air_BT                  = fScatElec_Air_Thickness_RadLen * b( fAir_Z );
      fScatElec_Air_Bremss_Loss         = Bremsstrahlung( fScatElec_Energy_Col , fScatElec_Air_BT );
      fScatElec_Targ_Ion_Loss           = IonLoss( fScatElec_Energy_Col, fHelium_A, fHelium_Z, fHelium_Density, fScatElec_Targ_Thickness );
      fScatElec_Air_Ion_Loss            = IonLoss( fScatElec_Energy_Col, fAir_A, fAir_Z, fAir_Density, fScatElec_Air_Thickness );

      if ( kCalcBremss && kCalcIon ) {
	fScatElec_Corrected_Energy_Col    = fScatElec_Energy_Col - fScatElec_Targ_Bremss_Loss - fScatElec_Air_Bremss_Loss - 
	  fScatElec_Targ_Ion_Loss -    fScatElec_Air_Ion_Loss;
      }

      // if ( kCalcBremss && !kCalcIon ) {
      //   fScatElec_Corrected_Energy_Col    = fScatElec_Energy_Col - fScatElec_Targ_Bremss_Loss - fScatElec_Air_Bremss_Loss;
      // }
    
      // if ( kCalcIon && !kCalcBremss ) {
      //   fScatElec_Corrected_Energy_Col    = fScatElec_Energy_Col - fScatElec_Targ_Ion_Loss - fScatElec_Air_Ion_Loss;
      // }    
      
      fScatElec_Corrected_Mom_Col       = TMath::Sqrt( TMath::Power( fScatElec_Corrected_Energy_Col , 2 ) - TMath::Power( fElectron_Mass , 2 ) );
      fScatElec_Delta_Mom_Col           = ( fScatElec_Mom_Col - fScatElec_Corrected_Mom_Col );
      fScatElec_Corrected_MomX_Col      = fScatElec_MomX_Col - fScatElec_Delta_Mom_Col * 
	TMath::Sin((fPi/180.0) * fScatElec_Theta_Col ) * TMath::Cos((fPi/180.0) * fScatElec_Phi_Col );
      fScatElec_Corrected_MomY_Col      = fScatElec_MomY_Col - fScatElec_Delta_Mom_Col * 
	TMath::Sin((fPi/180.0) * fScatElec_Theta_Col ) * TMath::Sin((fPi/180.0) * fScatElec_Phi_Col );
      fScatElec_Corrected_MomZ_Col      = fScatElec_MomZ_Col - fScatElec_Delta_Mom_Col * 
	TMath::Cos((fPi/180.0) * fScatElec_Theta_Col );
      fScatElec_Corrected_Theta_Col     = (180/fPi)* TMath::ATan( TMath::Sqrt( TMath::Power(fScatElec_Corrected_MomX_Col,2) + 
									       TMath::Power(fScatElec_Corrected_MomY_Col,2) ) / fScatElec_Corrected_MomZ_Col );
      
      fScatElec_Corrected_Phi_Col   = (180/fPi)*TMath::ATan2(fScatElec_Corrected_MomY_Col,fScatElec_Corrected_MomX_Col);
      
      if ( ( fScatElec_Corrected_Theta_Col < 0 ) && ( fScatElec_Corrected_Phi_Col <= 0 ) ) 
	{ fScatElec_Corrected_Theta_Col = 180.0 + fScatElec_Corrected_Theta_Col;  fScatElec_Corrected_Phi_Col = 360 + fScatElec_Corrected_Phi_Col;} 
      if ( ( fScatElec_Corrected_Theta_Col > 0 ) && ( fScatElec_Corrected_Phi_Col < 0  ) ) 
	{ fScatElec_Corrected_Theta_Col = fScatElec_Corrected_Theta_Col;          fScatElec_Corrected_Phi_Col = 360 + fScatElec_Corrected_Phi_Col;}
      if ( ( fScatElec_Corrected_Theta_Col < 0 ) && ( fScatElec_Corrected_Phi_Col > 0 ) )  
	{ fScatElec_Corrected_Theta_Col = 180.0 + fScatElec_Corrected_Theta_Col;  fScatElec_Corrected_Phi_Col = fScatElec_Corrected_Phi_Col;}
      
    }

    fScatElec_Corrected_Energy_Col_GeV    = fScatElec_Corrected_Energy_Col / 1000.0;
    fScatElec_Corrected_Mom_Col_GeV       = fScatElec_Corrected_Mom_Col / 1000.0;
    fScatElec_Delta_Mom_Col_GeV           = fScatElec_Delta_Mom_Col / 1000.0;
    fScatElec_Corrected_MomX_Col_GeV      = fScatElec_Corrected_MomX_Col / 1000.0;
    fScatElec_Corrected_MomY_Col_GeV      = fScatElec_Corrected_MomY_Col / 1000.0;
    fScatElec_Corrected_MomZ_Col_GeV      = fScatElec_Corrected_MomZ_Col / 1000.0;
    fScatElec_Energy_Col_GeV              = fScatElec_Energy_Col / 1000.0;
    fScatElec_Mom_Col_GeV                 = fScatElec_Mom_Col / 1000.0;
    fScatElec_MomX_Col_GeV                = fScatElec_MomX_Col / 1000.0;
    fScatElec_MomY_Col_GeV                = fScatElec_MomY_Col / 1000.0;
    fScatElec_MomZ_Col_GeV                = fScatElec_MomZ_Col / 1000.0;

    // --------------------------------- Energy Corrections for Scattered Electron ----------------------------------------------

    // ----------------------------------------------------
    // Transform Pion from Proton's rest frame to the lab frame
    // ----------------------------------------------------	

    fPion_MomX_Col = fGamma_Col_RF * fBetaX_Col_RF * fPion_Energy_RF + 
      ( 1 + ( fGamma_Col_RF - 1 )  * ( TMath::Power(fBetaX_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fPion_MomX_RotRF +
      ( fGamma_Col_RF - 1 )        * ( fBetaX_Col_RF * fBetaY_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPion_MomY_RotRF +
      ( fGamma_Col_RF - 1 )        * ( fBetaX_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPion_MomZ_RotRF;

    fPion_MomY_Col = fGamma_Col_RF * fBetaY_Col_RF * fPion_Energy_RF + 
      ( fGamma_Col_RF - 1 )        * ( fBetaX_Col_RF * fBetaY_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPion_MomX_RotRF +
      ( 1 + ( fGamma_Col_RF - 1 )  * ( TMath::Power(fBetaY_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fPion_MomY_RotRF +
      ( fGamma_Col_RF - 1 )        * ( fBetaY_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPion_MomZ_RotRF;

    fPion_MomZ_Col = fGamma_Col_RF * fBetaZ_Col_RF * fPion_Energy_RF +
      ( fGamma_Col_RF - 1 )        * ( fBetaX_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPion_MomX_RotRF + 
      ( fGamma_Col_RF - 1 )        * ( fBetaY_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fPion_MomY_RotRF + 
      ( 1 + ( fGamma_Col_RF - 1 )  * ( TMath::Power(fBetaZ_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fPion_MomZ_RotRF;
        
    fPion_Mom_Col = TMath::Sqrt( TMath::Power(fPion_MomX_Col,2) + TMath::Power(fPion_MomY_Col,2) + TMath::Power(fPion_MomZ_Col,2) );

    fPion_Mom_Col_GeV = fPion_Mom_Col / 1000.0;

    fPion_Energy_Col = fGamma_Col_RF * fPion_Energy_RF + fGamma_Col_RF * fBetaX_Col_RF * fPion_MomX_RotRF + 
                                                         fGamma_Col_RF * fBetaY_Col_RF * fPion_MomY_RotRF + 
                                                         fGamma_Col_RF * fBetaZ_Col_RF * fPion_MomZ_RotRF;

    fPion_Theta_Col = (180/fPi)*TMath::ATan( TMath::Sqrt( TMath::Power(fPion_MomX_Col,2) + TMath::Power(fPion_MomY_Col,2) ) / fPion_MomZ_Col );
    
    fPion_Phi_Col = (180/fPi)*TMath::ATan2(fPion_MomY_Col,fPion_MomX_Col);
    
    if ( ( fPion_Theta_Col < 0 ) && ( fPion_Phi_Col <= 0 ) ) { fPion_Theta_Col = 180.0 + fPion_Theta_Col;  fPion_Phi_Col = 360 + fPion_Phi_Col;}    
    if ( ( fPion_Theta_Col > 0 ) && ( fPion_Phi_Col < 0 ) )  { fPion_Theta_Col = fPion_Theta_Col;          fPion_Phi_Col = 360 + fPion_Phi_Col;}    
    if ( ( fPion_Theta_Col < 0 ) && ( fPion_Phi_Col > 0 ) )  { fPion_Theta_Col = 180.0 + fPion_Theta_Col;  fPion_Phi_Col = fPion_Phi_Col;}

    // --------------------------------- Energy Corrections for Pion ----------------------------------------------

    // Here calcuate the Bremsstrahlung of Pion, 
    // then substract the Bremsstrahlung energy from Pion's energy
    // then recalcualte the momentum of Pion and three components of momentum
    
    fPion_Corrected_Theta_Col     =     fPion_Theta_Col;
    fPion_Corrected_Phi_Col       =     fPion_Phi_Col;
    fPion_Corrected_Energy_Col    =     fPion_Energy_Col;
    fPion_Corrected_Mom_Col       =     fPion_Mom_Col;
    fPion_Corrected_MomX_Col      =     fPion_MomX_Col;
    fPion_Corrected_MomY_Col      =     fPion_MomY_Col;
    fPion_Corrected_MomZ_Col      =     fPion_MomZ_Col;
    fPion_Delta_Mom_Col           =     0;

    if ( kCalcBremss || kCalcIon ) {
    
      fPion_Targ_Thickness          = 20.0 * fHelium_Density; // 40.0 - fElectron_Thickness;
      fPion_Targ_Thickness_RadLen   = ( fPion_Targ_Thickness ) / X0( fHelium_Z , fHelium_A );
      fPion_Targ_BT                 = fPion_Targ_Thickness_RadLen * b( fHelium_Z );
      fPion_Targ_Bremss_Loss        = Bremsstrahlung( fPion_Energy_Col , fPion_Targ_BT );
      fPion_Air_Thickness           = 450.0 * fAir_Density; 
      if ( fPion_Theta_Col < 16 ) {
	fPion_Air_Thickness         = 950.0 * fAir_Density;
      }    
      fRadiation_Lenght_Air         = ( X0( 7, 14.007) * X0( 8, 16 ) ) / ( 0.766 * X0( 8, 15.999 ) + 0.233 * X0( 7, 14.007) );
      fPion_Air_Thickness_RadLen    = fPion_Air_Thickness / fRadiation_Lenght_Air;
      fPion_Air_BT                  = fPion_Air_Thickness_RadLen * b( fAir_Z );
      fPion_Air_Bremss_Loss         = Bremsstrahlung( fPion_Energy_Col , fPion_Air_BT );
      fPion_Targ_Ion_Loss           = IonLoss( fPion_Energy_Col, fHelium_A, fHelium_Z, fHelium_Density, fPion_Targ_Thickness );
      fPion_Air_Ion_Loss            = IonLoss( fPion_Energy_Col, fAir_A, fAir_Z, fAir_Density, fPion_Air_Thickness );


      if ( kCalcBremss && kCalcIon ) {
	fPion_Corrected_Energy_Col    = fPion_Energy_Col - fPion_Targ_Bremss_Loss - fPion_Air_Bremss_Loss - fPion_Targ_Ion_Loss - fPion_Air_Ion_Loss;
      }

      // if ( kCalcBremss && !kCalcIon ) {
      //   fPion_Corrected_Energy_Col    = fPion_Energy_Col - fPion_Targ_Bremss_Loss - fPion_Air_Bremss_Loss;
      // }
    
      // if ( kCalcIon && !kCalcBremss ) {
      //       fPion_Corrected_Energy_Col    = fPion_Energy_Col - fPion_Targ_Ion_Loss - fPion_Air_Ion_Loss;
      // }
    
      fPion_Corrected_Mom_Col       = TMath::Sqrt( TMath::Power( fPion_Corrected_Energy_Col , 2 ) - TMath::Power( fPion_Mass , 2 ) );
      fPion_Delta_Mom_Col           = ( fPion_Mom_Col - fPion_Corrected_Mom_Col );
      fPion_Corrected_MomX_Col      = fPion_MomX_Col - fPion_Delta_Mom_Col * TMath::Sin((fPi/180.0) * fPion_Theta_Col ) *  TMath::Cos((fPi/180.0) * fPion_Phi_Col );
      fPion_Corrected_MomY_Col      = fPion_MomY_Col - fPion_Delta_Mom_Col * TMath::Sin((fPi/180.0) * fPion_Theta_Col ) *  TMath::Sin((fPi/180.0) * fPion_Phi_Col );
      fPion_Corrected_MomZ_Col      = fPion_MomZ_Col - fPion_Delta_Mom_Col * TMath::Cos((fPi/180.0) * fPion_Theta_Col );
      fPion_Corrected_Theta_Col     = (180/fPi)* TMath::ATan( TMath::Sqrt( TMath::Power(fPion_Corrected_MomX_Col,2) + 
									   TMath::Power(fPion_Corrected_MomY_Col,2) ) / fPion_Corrected_MomZ_Col );

      fPion_Corrected_Theta_Col     = (180/fPi)* TMath::ATan( TMath::Sqrt( TMath::Power(fPion_Corrected_MomX_Col,2) + 
									   TMath::Power(fPion_Corrected_MomY_Col,2) ) / fPion_Corrected_MomZ_Col );
      
      fPion_Corrected_Phi_Col   = (180/fPi)*TMath::ATan2(fPion_Corrected_MomY_Col,fPion_Corrected_MomX_Col);
      
      if ( ( fPion_Corrected_Theta_Col < 0 ) && ( fPion_Corrected_Phi_Col <= 0 ) ) 
	{ fPion_Corrected_Theta_Col = 180.0 + fPion_Corrected_Theta_Col;  fPion_Corrected_Phi_Col = 360 + fPion_Corrected_Phi_Col;} 
      if ( ( fPion_Corrected_Theta_Col > 0 ) && ( fPion_Corrected_Phi_Col < 0  ) ) 
	{ fPion_Corrected_Theta_Col = fPion_Corrected_Theta_Col;          fPion_Corrected_Phi_Col = 360 + fPion_Corrected_Phi_Col;}
      if ( ( fPion_Corrected_Theta_Col < 0 ) && ( fPion_Corrected_Phi_Col > 0 ) )  
	{ fPion_Corrected_Theta_Col = 180.0 + fPion_Corrected_Theta_Col;  fPion_Corrected_Phi_Col = fPion_Corrected_Phi_Col;}

    }

    fPion_Corrected_Energy_Col_GeV    = fPion_Corrected_Energy_Col / 1000.0;
    fPion_Corrected_Mom_Col_GeV       = fPion_Corrected_Mom_Col / 1000.0;
    fPion_Delta_Mom_Col_GeV           = fPion_Delta_Mom_Col / 1000.0;
    fPion_Corrected_MomX_Col_GeV      = fPion_Corrected_MomX_Col / 1000.0;
    fPion_Corrected_MomY_Col_GeV      = fPion_Corrected_MomY_Col / 1000.0;
    fPion_Corrected_MomZ_Col_GeV      = fPion_Corrected_MomZ_Col / 1000.0;
    fPion_Energy_Col_GeV              = fPion_Energy_Col / 1000.0;
    fPion_Mom_Col_GeV                 = fPion_Mom_Col / 1000.0;
    fPion_MomX_Col_GeV                = fPion_MomX_Col / 1000.0;
    fPion_MomY_Col_GeV                = fPion_MomY_Col / 1000.0;
    fPion_MomZ_Col_GeV                = fPion_MomZ_Col / 1000.0;


    // -------------------------------------------------------------------
    // Transform recoil Neutron from Proton's rest frame to collider frame  
    // -------------------------------------------------------------------
    fNeutron_MomX_Col   = fGamma_Col_RF * fBetaX_Col_RF * fNeutron_Energy_RotRF +
                          ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaX_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fNeutron_MomX_RotRF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaX_Col_RF * fBetaY_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fNeutron_MomY_RotRF + 
                          ( fGamma_Col_RF - 1 )       * ( fBetaX_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fNeutron_MomZ_RotRF;

    fNeutron_MomY_Col   = fGamma_Col_RF * fBetaY_Col_RF * fNeutron_Energy_RotRF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaX_Col_RF * fBetaY_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fNeutron_MomX_RotRF + 
                          ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaY_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fNeutron_MomY_RotRF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaY_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fNeutron_MomZ_RotRF;

    fNeutron_MomZ_Col   = fGamma_Col_RF * fBetaZ_Col_RF * fNeutron_Energy_RotRF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaX_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fNeutron_MomX_RotRF +
                          ( fGamma_Col_RF - 1 )       * ( fBetaY_Col_RF * fBetaZ_Col_RF / TMath::Power(fBeta_Col_RF,2) )   * fNeutron_MomY_RotRF +
                          ( 1 + ( fGamma_Col_RF - 1 ) * ( TMath::Power(fBetaZ_Col_RF,2) / TMath::Power(fBeta_Col_RF,2) ) ) * fNeutron_MomZ_RotRF;
    
    fNeutron_Mom_Col    = TMath::Sqrt( TMath::Power(fNeutron_MomX_Col,2) + TMath::Power(fNeutron_MomY_Col,2) + TMath::Power(fNeutron_MomZ_Col,2) );
    fNeutron_Mom_Col_GeV = fNeutron_Mom_Col/1000.0;

    fNeutron_Energy_Col = TMath::Sqrt( TMath::Power(fNeutron_Mom_Col,2) + TMath::Power(fNeutron_Mass,2));
    fNeutron_Theta_Col  = (180/fPi)*TMath::ATan( TMath::Sqrt( TMath::Power(fNeutron_MomX_Col,2) + TMath::Power(fNeutron_MomY_Col,2) ) / fNeutron_MomZ_Col );
    fNeutron_Phi_Col    = (180/fPi)*TMath::ATan2(fNeutron_MomY_Col,fNeutron_MomX_Col); 

    if ( ( fNeutron_Theta_Col < 0 ) && ( fNeutron_Phi_Col <= 0 ) ) { fNeutron_Theta_Col = 180.0 + fNeutron_Theta_Col;  fNeutron_Phi_Col = 360 + fNeutron_Phi_Col;}    
    if ( ( fNeutron_Theta_Col > 0 ) && ( fNeutron_Phi_Col < 0  ) ) { fNeutron_Theta_Col = fNeutron_Theta_Col;          fNeutron_Phi_Col = 360 + fNeutron_Phi_Col;}    
    if ( ( fNeutron_Theta_Col < 0 ) && ( fNeutron_Phi_Col > 0  ) ) { fNeutron_Theta_Col = 180.0 + fNeutron_Theta_Col;  fNeutron_Phi_Col = fNeutron_Phi_Col;}

    // --------------------------------- Energy Corrections for Recoil Proton ----------------------------------------------

    // Here calcuate the Bremsstrahlung of Pion, 
    // then substract the Bremsstrahlung energy from Pion's energy
    // then recalcualte the momentum of Pion and three components of momentum
        
    fNeutron_Corrected_Theta_Col     =     fNeutron_Theta_Col;
    fNeutron_Corrected_Phi_Col       =     fNeutron_Phi_Col;
    fNeutron_Corrected_Energy_Col    =     fNeutron_Energy_Col;
    fNeutron_Corrected_Mom_Col       =     fNeutron_Mom_Col;
    fNeutron_Corrected_MomX_Col      =     fNeutron_MomX_Col;
    fNeutron_Corrected_MomY_Col      =     fNeutron_MomY_Col;
    fNeutron_Corrected_MomZ_Col      =     fNeutron_MomZ_Col;
    fNeutron_Delta_Mom_Col           =     0;

    if ( kCalcBremss || kCalcIon ) {

      fNeutron_Targ_Thickness          = 20.0 * fHelium_Density; // 40.0 - fElectron_Thickness;
      fNeutron_Targ_Thickness_RadLen   = ( fNeutron_Targ_Thickness ) / X0( fHelium_Z , fHelium_A );
      fNeutron_Targ_BT                 = fNeutron_Targ_Thickness_RadLen * b( fHelium_Z );
      fNeutron_Targ_Bremss_Loss        = Bremsstrahlung( fNeutron_Energy_Col , fNeutron_Targ_BT );
      fNeutron_Air_Thickness           = 450.0 * fAir_Density; 
      if ( fNeutron_Theta_Col < 16 ) {
	fNeutron_Air_Thickness         = 950.0 * fAir_Density;
      }    
      fRadiation_Lenght_Air            = ( X0( 7, 14.007) * X0( 8, 16 ) ) / ( 0.766 * X0( 8, 15.999 ) + 0.233 * X0( 7, 14.007) );
      fNeutron_Air_Thickness_RadLen    = fNeutron_Air_Thickness / fRadiation_Lenght_Air;
      fNeutron_Air_BT                  = fNeutron_Air_Thickness_RadLen * b( fAir_Z );
      fNeutron_Air_Bremss_Loss         = Bremsstrahlung( fNeutron_Energy_Col , fNeutron_Air_BT );
      fNeutron_Targ_Ion_Loss           = IonLoss( fNeutron_Energy_Col, fHelium_A, fHelium_Z, fHelium_Density, fNeutron_Targ_Thickness );
      fNeutron_Air_Ion_Loss            = IonLoss( fNeutron_Energy_Col, fAir_A, fAir_Z, fAir_Density, fNeutron_Air_Thickness );


      if ( kCalcBremss && kCalcIon ) {
	fNeutron_Corrected_Energy_Col    = fNeutron_Energy_Col - fNeutron_Targ_Bremss_Loss - fNeutron_Air_Bremss_Loss - 
	  fNeutron_Targ_Ion_Loss -    fNeutron_Air_Ion_Loss;
      }

      // if ( kCalcBremss && !kCalcIon ) {
      //   fNeutron_Corrected_Energy_Col    = fNeutron_Energy_Col - fNeutron_Targ_Bremss_Loss - fNeutron_Air_Bremss_Loss;
      // }
    
      // if ( kCalcIon && !kCalcBremss ) {
      //   fNeutron_Corrected_Energy_Col    = fNeutron_Energy_Col - fNeutron_Targ_Ion_Loss - fNeutron_Air_Ion_Loss;
      // }

      fNeutron_Corrected_Mom_Col       = TMath::Sqrt( TMath::Power( fNeutron_Corrected_Energy_Col , 2 ) - TMath::Power( fNeutron_Mass , 2 ) );
      fNeutron_Delta_Mom_Col           = ( fNeutron_Mom_Col - fNeutron_Corrected_Mom_Col );
      fNeutron_Corrected_MomX_Col      = fNeutron_MomX_Col - fNeutron_Delta_Mom_Col * TMath::Sin((fPi/180.0) * fNeutron_Theta_Col ) *  
	TMath::Cos((fPi/180.0) * fNeutron_Phi_Col );
      fNeutron_Corrected_MomY_Col      = fNeutron_MomY_Col - fNeutron_Delta_Mom_Col * TMath::Sin((fPi/180.0) * fNeutron_Theta_Col ) *  
	TMath::Sin((fPi/180.0) * fNeutron_Phi_Col );
      fNeutron_Corrected_MomZ_Col      = fNeutron_MomZ_Col - fNeutron_Delta_Mom_Col * TMath::Cos((fPi/180.0) * fNeutron_Theta_Col );
      fNeutron_Corrected_Theta_Col     = (180/fPi)* TMath::ATan( TMath::Sqrt( TMath::Power(fNeutron_Corrected_MomX_Col,2) + 
									      TMath::Power(fNeutron_Corrected_MomY_Col,2) ) / fNeutron_Corrected_MomZ_Col );

      fNeutron_Corrected_Theta_Col     = (180/fPi)* TMath::ATan( TMath::Sqrt( TMath::Power(fNeutron_Corrected_MomX_Col,2) + 
									      TMath::Power(fNeutron_Corrected_MomY_Col,2) ) / fNeutron_Corrected_MomZ_Col );
      
      fNeutron_Corrected_Phi_Col   = (180/fPi)*TMath::ATan2(fNeutron_Corrected_MomY_Col,fNeutron_Corrected_MomX_Col);
      
      if ( ( fNeutron_Corrected_Theta_Col < 0 ) && ( fNeutron_Corrected_Phi_Col <= 0 ) ) 
	{ fNeutron_Corrected_Theta_Col = 180.0 + fNeutron_Corrected_Theta_Col;  fNeutron_Corrected_Phi_Col = 360 + fNeutron_Corrected_Phi_Col;} 
      if ( ( fNeutron_Corrected_Theta_Col > 0 ) && ( fNeutron_Corrected_Phi_Col < 0  ) ) 
	{ fNeutron_Corrected_Theta_Col = fNeutron_Corrected_Theta_Col;          fNeutron_Corrected_Phi_Col = 360 + fNeutron_Corrected_Phi_Col;}
      if ( ( fNeutron_Corrected_Theta_Col < 0 ) && ( fNeutron_Corrected_Phi_Col > 0 ) )  
	{ fNeutron_Corrected_Theta_Col = 180.0 + fNeutron_Corrected_Theta_Col;  fNeutron_Corrected_Phi_Col = fNeutron_Corrected_Phi_Col;}

    }

    fNeutron_Corrected_Energy_Col_GeV             = fNeutron_Corrected_Energy_Col / 1000.0;
    fNeutron_Corrected_Mom_Col_GeV                = fNeutron_Corrected_Mom_Col / 1000.0;
    fNeutron_Delta_Mom_Col_GeV                    = fNeutron_Delta_Mom_Col / 1000.0;
    fNeutron_Corrected_MomX_Col_GeV               = fNeutron_Corrected_MomX_Col / 1000.0;
    fNeutron_Corrected_MomY_Col_GeV               = fNeutron_Corrected_MomY_Col / 1000.0;
    fNeutron_Corrected_MomZ_Col_GeV               = fNeutron_Corrected_MomZ_Col / 1000.0;
    fNeutron_Energy_Col_GeV                       = fNeutron_Energy_Col / 1000.0;
    fNeutron_Mom_Col_GeV                          = fNeutron_Mom_Col / 1000.0;
    fNeutron_MomX_Col_GeV                         = fNeutron_MomX_Col / 1000.0;
    fNeutron_MomY_Col_GeV                         = fNeutron_MomY_Col / 1000.0;
    fNeutron_MomZ_Col_GeV                         = fNeutron_MomZ_Col / 1000.0;

    fRecoilProton_Targ_Thickness                  = fNeutron_Targ_Thickness;
    fRecoilProton_Targ_Thickness_RadLen           = fNeutron_Targ_Thickness_RadLen;
    fRecoilProton_Targ_BT                         = fNeutron_Targ_BT;
    fRecoilProton_Targ_Bremss_Loss                = fNeutron_Targ_Bremss_Loss;
    fRecoilProton_Targ_Ion_Loss                   = fNeutron_Targ_Ion_Loss;
    fRecoilProton_Air_Thickness                   = fNeutron_Air_Thickness;
    fRecoilProton_Air_Thickness_RadLen            = fNeutron_Air_Thickness_RadLen;
    fRecoilProton_Air_BT                          = fNeutron_Air_BT;
    fRecoilProton_Air_Bremss_Loss                 = fNeutron_Air_Bremss_Loss;
    fRecoilProton_Air_Ion_Loss                    = fNeutron_Air_Ion_Loss;
    fRecoilProton_Theta_Col                       = fNeutron_Theta_Col;
    fRecoilProton_Phi_Col                         = fNeutron_Phi_Col;
    fRecoilProton_Energy_Col                      = fNeutron_Energy_Col;
    fRecoilProton_Mom_Col                         = fNeutron_Mom_Col;
    fRecoilProton_MomX_Col                        = fNeutron_MomX_Col;
    fRecoilProton_MomY_Col                        = fNeutron_MomY_Col;
    fRecoilProton_MomZ_Col                        = fNeutron_MomZ_Col;
    fRecoilProton_Corrected_Energy_Col            = fNeutron_Corrected_Energy_Col;
    fRecoilProton_Corrected_Mom_Col               = fNeutron_Corrected_Mom_Col;
    fRecoilProton_Corrected_MomX_Col              = fNeutron_Corrected_MomX_Col;
    fRecoilProton_Corrected_MomY_Col              = fNeutron_Corrected_MomY_Col;
    fRecoilProton_Corrected_MomZ_Col              = fNeutron_Corrected_MomZ_Col;
    fRecoilProton_Corrected_Theta_Col             = fNeutron_Corrected_Theta_Col;
    fRecoilProton_Corrected_Phi_Col               = fNeutron_Corrected_Phi_Col;
    fRecoilProton_Delta_Mom_Col                   = fNeutron_Delta_Mom_Col;

    fRecoilProton_Energy_Col_GeV                  = fRecoilProton_Energy_Col / 1000.0;
    fRecoilProton_Mom_Col_GeV                     = fRecoilProton_Mom_Col / 1000.0;
    fRecoilProton_MomX_Col_GeV                    = fRecoilProton_MomX_Col / 1000.0;
    fRecoilProton_MomY_Col_GeV                    = fRecoilProton_MomY_Col / 1000.0;
    fRecoilProton_MomZ_Col_GeV                    = fRecoilProton_MomZ_Col / 1000.0;
    fRecoilProton_Corrected_Energy_Col_GeV        = fRecoilProton_Corrected_Energy_Col / 1000.0;
    fRecoilProton_Corrected_Mom_Col_GeV           = fRecoilProton_Corrected_Mom_Col / 1000.0;
    fRecoilProton_Corrected_MomX_Col_GeV          = fRecoilProton_Corrected_MomX_Col / 1000.0;
    fRecoilProton_Corrected_MomY_Col_GeV          = fRecoilProton_Corrected_MomY_Col / 1000.0;
    fRecoilProton_Corrected_MomZ_Col_GeV          = fRecoilProton_Corrected_MomZ_Col / 1000.0;
    fRecoilProton_Delta_Mom_Col_GeV               = fRecoilProton_Delta_Mom_Col / 1000.0;

    // --------------------------------------------------------------------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------------------------------------------------------------------

    fS_I_Col = fElectron_Mass * fElectron_Mass + fProton_Mass * fProton_Mass + 2 * ( fElectron_Energy_Col * fProton_Energy_Col - 
	       fElectron_MomX_Col * fProton_MomX_Col - fElectron_MomY_Col * fProton_MomY_Col - fElectron_MomZ_Col * fProton_MomZ_Col );
    fS_F_Col =        fElectron_Mass * fElectron_Mass +  
      fNeutron_Mass * fNeutron_Mass + 
      fPion_Mass * fPion_Mass + 
      2 * ( fScatElec_Energy_Col * fNeutron_Energy_Col - 
	    fScatElec_MomX_Col * fNeutron_MomX_Col - 
	    fScatElec_MomY_Col * fNeutron_MomY_Col -
	    fScatElec_MomZ_Col * fNeutron_MomZ_Col ) + 
      2 * ( fScatElec_Energy_Col * fPion_Energy_Col - 
	    fScatElec_MomX_Col * fPion_MomX_Col - 
	    fScatElec_MomY_Col * fPion_MomY_Col -
	    fScatElec_MomZ_Col * fPion_MomZ_Col ) + 
      2 * ( fNeutron_Energy_Col * fPion_Energy_Col - 
	    fNeutron_MomX_Col * fPion_MomX_Col - 
	    fNeutron_MomY_Col * fPion_MomY_Col -
	    fNeutron_MomZ_Col * fPion_MomZ_Col ) ;
    
    fS_I_Col_GeV = fS_I_Col / 1000000.0;
    fS_F_Col_GeV = fS_F_Col / 1000000.0;

    kSConserve = false;
    if ( std::abs( fS_I_Col_GeV - fS_F_Col_GeV ) < fDiff ) {
      //      fSDiff ++;
      kSConserve = true;
    }
    
    if ( print ) {
      cout << "s initial col = " << fS_I_Col_GeV 
	   << "\ns final col   = " << fS_F_Col_GeV 
	   << "\ns diff rf   = " << std::abs( fS_I_Col_GeV - fS_F_Col_GeV ) 
	   << endl;
      if(kSConserve) {
	cout << "s is conserved: " << kSConserve << endl;
      }
      if(!kSConserve) {
	cout << "s is not conserved: " << kSConserve << endl;	
      }
    }

    // --------------------------------------------------------------------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------------------------------------------------------------------
    
    // ------------------------------------------------------------------------------------
    //                          Zafar Ahmed Scattering Cross Section for SoLID
    // ------------------------------------------------------------------------------------
   
    fZASig_L = ( pow( ( pow( 3.0    , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
		 pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) * 
      ( exp( 1.482 + fQsq_GeV * -0.3781 + fT_GeV * ( -17.93 + fQsq_GeV * 1.746 ) ) + 
	exp( 2.02 + pow( fQsq_GeV , 1 ) * -1.271 + pow( fQsq_GeV , 2 ) * 0.08637 + 
	     fT_GeV * ( -11.54 + pow( fQsq_GeV , 1 ) * 3.007 + pow( fQsq_GeV , 2 ) * -0.2712 ) ) );
    
    fZASig_T = ( pow( ( pow( 3.0    , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
		 pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) * 
      ( exp( 0.4495 + fQsq_GeV * -0.7096 + fT_GeV * ( -1.629 + fQsq_GeV * 0.4363 ) ) ) / ( 1.0  + 5.0 * fT_GeV );
    
    
    if ( fQsq_GeV < 1.0 ){
      
      fZASig_LT = ( ( ( pow( ( pow( 3.0 , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
			pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) ) * 
		    ( (  pow( fT_GeV  , 0 ) * (  pow( fQsq_GeV , 0 ) * 0.4181 + 
						 pow( fQsq_GeV , 1 ) * 3.679  + 
						 pow( fQsq_GeV , 2 ) * -4.247 ) ) + 
		      (  pow( fT_GeV  , 1 ) * (  pow( fQsq_GeV , 0 ) * -9.051 + 
						 pow( fQsq_GeV , 1 ) * -29.85 + 
						 pow( fQsq_GeV , 2 ) * 42.92  + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 2 ) * (  pow( fQsq_GeV , 0 ) * 35.44  + 
						 pow( fQsq_GeV , 1 ) * 83.71  + 
						 pow( fQsq_GeV , 2 ) * -135.2 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 3 ) * (  pow( fQsq_GeV , 0 ) * -48.22 + 
						 pow( fQsq_GeV , 1 ) * -97.41 + 
						 pow( fQsq_GeV , 2 ) * 167.7  + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 4 ) * (  pow( fQsq_GeV , 0 ) * 21.54  + 
						 pow( fQsq_GeV , 1 ) * 39.91  + 
						 pow( fQsq_GeV , 2 ) * -71.33 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) ) ); 
      
      fZASig_TT = ( ( ( pow( ( pow( 3.0 , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
			pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) ) * 
		    ( (  pow( fT_GeV  , 0 ) * (  pow( fQsq_GeV , 0 ) * -1.256 + 
						 pow( fQsq_GeV , 1 ) * 1.401 + 
						 pow( fQsq_GeV , 2 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 1 ) * (  pow( fQsq_GeV , 0 ) * 13.33  + 
						 pow( fQsq_GeV , 1 ) * -39.84 + 
						 pow( fQsq_GeV , 2 ) * 25.25 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 2 ) * (  pow( fQsq_GeV , 0 ) * -36.77 + 
						 pow( fQsq_GeV , 1 ) * 127.9 + 
						 pow( fQsq_GeV , 2 ) * -85.06 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 3 ) * (  pow( fQsq_GeV , 0 ) * 41.23  + 
						 pow( fQsq_GeV , 1 ) * -155.6 + 
						 pow( fQsq_GeV , 2 ) * 105.5 + pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 4 ) * (  pow( fQsq_GeV , 0 ) * -16.31 + 
						 pow( fQsq_GeV , 1 ) * 64.8 + 
						 pow( fQsq_GeV , 2 ) * -44.38  + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) ) );
    }
    
    if ( fQsq_GeV >= 1.0 && fQsq_GeV < 2.0 ){
      
      fZASig_LT = ( ( ( pow( ( pow( 3.0 , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
			pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) ) * 
		    ( (  pow( fT_GeV  , 0 ) * (  pow( fQsq_GeV , 0 ) * 0.1437   + 
						 pow( fQsq_GeV , 1 ) * -0.07952 + 
						 pow( fQsq_GeV , 2 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 1 ) * (  pow( fQsq_GeV , 0 ) * -0.07833 + 
						 pow( fQsq_GeV , 1 ) * 1.95     + 
						 pow( fQsq_GeV , 2 ) * -0.6121 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 2 ) * (  pow( fQsq_GeV , 0 ) * -3.083   + 
						 pow( fQsq_GeV , 1 ) * -5.737   + 
						 pow( fQsq_GeV , 2 ) * 2.267   + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 3 ) * (  pow( fQsq_GeV , 0 ) * 6.477    + 
						 pow( fQsq_GeV , 1 ) * 6.091    + 
						 pow( fQsq_GeV , 2 ) * -2.835  + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 4 ) * (  pow( fQsq_GeV , 0 ) * -3.513   + 
						 pow( fQsq_GeV , 1 ) * -2.201   + 
						 pow( fQsq_GeV , 2 ) * 1.178   + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) ) );
      
      fZASig_TT = ( ( ( pow( ( pow( 3.0 , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
			pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) ) * 
		    ( (  pow( fT_GeV  , 0 ) * (  pow( fQsq_GeV , 0 ) * -0.09242 + 
						 pow( fQsq_GeV , 1 ) * 0.05782 + 
						 pow( fQsq_GeV , 2 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 1 ) * (  pow( fQsq_GeV , 0 ) * -3.379 + 
						 pow( fQsq_GeV , 1 ) * 1.313 + 
						 pow( fQsq_GeV , 2 ) * 0 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 2 ) * (  pow( fQsq_GeV , 0 ) * 15.03 + 
						 pow( fQsq_GeV , 1 ) * -6.204 + 
						 pow( fQsq_GeV , 2 ) * 0 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 3 ) * (  pow( fQsq_GeV , 0 ) * -21.07 + 
						 pow( fQsq_GeV , 1 ) * 8.889 + 
						 pow( fQsq_GeV , 2 ) * 0 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 4 ) * (  pow( fQsq_GeV , 0 ) * 9.517 + 
						 pow( fQsq_GeV , 1 ) * -4.065 + 
						 pow( fQsq_GeV , 2 ) * 0 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) ) );
    }
    
    if ( fQsq_GeV >= 2.0 && fQsq_GeV < 4.0 ){
      
      fZASig_LT = ( ( ( pow( ( pow( 3.0    , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
			pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) ) * 
		    ( (  pow( fT_GeV  , 0 ) * (  pow( fQsq_GeV , 0 ) * 0.1432 + 
						 pow( fQsq_GeV , 1 ) * -0.104 + 
						 pow( fQsq_GeV , 2 ) * 0.01257 ) ) + 
		      (  pow( fT_GeV  , 1 ) * (  pow( fQsq_GeV , 0 ) * 2.171 + 
						 pow( fQsq_GeV , 1 ) * -0.4429 + 
						 pow( fQsq_GeV , 2 ) * 0.02899 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 2 ) * (  pow( fQsq_GeV , 0 ) * -11.57 + 
						 pow( fQsq_GeV , 1 ) * 3.718  + 
						 pow( fQsq_GeV , 2 ) * -0.3641 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 3 ) * (  pow( fQsq_GeV , 0 ) * 17.17 + 
						 pow( fQsq_GeV , 1 ) * -6.149  + 
						 pow( fQsq_GeV , 2 ) * 0.6431 + 
						 pow( fQsq_GeV , 3 ) * 0  + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 4 ) * (  pow( fQsq_GeV , 0 ) * -7.973 + 
						 pow( fQsq_GeV , 1 ) * 3.006  + 
						 pow( fQsq_GeV , 2 ) * -0.324 + 
						 pow( fQsq_GeV , 3 ) * 0  + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) ) );  
      
      fZASig_TT = ( ( ( pow( ( pow( 3.0    , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
			pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) ) * 
		    ( (  pow( fT_GeV  , 0 ) * (  pow( fQsq_GeV , 0 ) * -0.4663 + 
						 pow( fQsq_GeV , 1 ) * 0.2752 + 
						 pow( fQsq_GeV , 2 ) * -0.03895 ) ) + 
		      (  pow( fT_GeV  , 1 ) * (  pow( fQsq_GeV , 0 ) * 1.878 + 
						 pow( fQsq_GeV , 1 ) * -1.328   + 
						 pow( fQsq_GeV , 2 ) * 0.2049 + 
						 pow( fQsq_GeV , 3 ) * 0  + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 2 ) * (  pow( fQsq_GeV , 0 ) * -3.495 + 
						 pow( fQsq_GeV , 1 ) * 2.847   + 
						 pow( fQsq_GeV , 2 ) * -0.4648 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 3 ) * (  pow( fQsq_GeV , 0 ) * 3.128 + 
						 pow( fQsq_GeV , 1 ) * -2.822   + 
						 pow( fQsq_GeV , 2 ) * 0.4778 + 
						 pow( fQsq_GeV , 3 ) * 0  + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 4 ) * (  pow( fQsq_GeV , 0 ) * -1.075 + 
						 pow( fQsq_GeV , 1 ) * 1.041   + 
						 pow( fQsq_GeV , 2 ) * -0.1805 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) ) );      
    }
    
    if ( fQsq_GeV >= 4.0 && fQsq_GeV < 5.0 ){
	    
      fZASig_LT = ( ( ( pow( ( pow( 3.0    , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
			pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) ) * 
		    ( (  pow( fT_GeV  , 0 ) * (  pow( fQsq_GeV , 0 ) * 0.007935 + 
						 pow( fQsq_GeV , 1 ) * -0.03055 + 
						 pow( fQsq_GeV , 2 ) * 0.002606 ) ) + 
		      (  pow( fT_GeV  , 1 ) * (  pow( fQsq_GeV , 0 ) * 2.199 + 
						 pow( fQsq_GeV , 1 ) * -0.4759 + 
						 pow( fQsq_GeV , 2 ) * 0.03572 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 2 ) * (  pow( fQsq_GeV , 0 ) * -8.935 + 
						 pow( fQsq_GeV , 1 ) * 2.353  + 
						 pow( fQsq_GeV , 2 ) * -0.1867 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 3 ) * (  pow( fQsq_GeV , 0 ) * 11.86 + 
						 pow( fQsq_GeV , 1 ) * -3.342  + 
						 pow( fQsq_GeV , 2 ) * 0.2713  + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 4 ) * (  pow( fQsq_GeV , 0 ) * -5.156 + 
						 pow( fQsq_GeV , 1 ) * 1.507  + 
						 pow( fQsq_GeV , 2 ) * -0.124  + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) ) );
      
      fZASig_TT = ( ( ( pow( ( pow( 3.0    , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
			pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) ) * 
		    ( (  pow( fT_GeV  , 0 ) * (  pow( fQsq_GeV , 0 ) * 0.0361 + 
						 pow( fQsq_GeV , 1 ) * -0.005255 + 
						 pow( fQsq_GeV , 2 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 1 ) * (  pow( fQsq_GeV , 0 ) * -0.5167 + 
						 pow( fQsq_GeV , 1 ) * 0.08681  + 
						 pow( fQsq_GeV , 2 ) * 0 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 2 ) * (  pow( fQsq_GeV , 0 ) * 1.554 + 
						 pow( fQsq_GeV , 1 ) * -0.2691    + 
						 pow( fQsq_GeV , 2 ) * 0 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 3 ) * (  pow( fQsq_GeV , 0 ) * -1.799 + 
						 pow( fQsq_GeV , 1 ) * 0.3167    + 
						 pow( fQsq_GeV , 2 ) * 0 + 
						 pow( fQsq_GeV , 3 ) * 0 + pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 4 ) * (  pow( fQsq_GeV , 0 ) * 0.7183 + 
						 pow( fQsq_GeV , 1 ) * -0.1279   + 
						 pow( fQsq_GeV , 2 ) * 0 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) ) );
    }
	  
    if ( fQsq_GeV >= 5.0 && fQsq_GeV <= 6.0 ){
	    
      fZASig_LT = ( ( ( pow( ( pow( 3.0    , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
			pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) ) * 
		    ( (  pow( fT_GeV  , 0 ) * (  pow( fQsq_GeV , 0 ) * -0.05227 + 
						 pow( fQsq_GeV , 1 ) * -0.00627 + 
						 pow( fQsq_GeV , 2 ) * 0.000155 ) ) + 
		      (  pow( fT_GeV  , 1 ) * (  pow( fQsq_GeV , 0 ) * 1.977 + 
						 pow( fQsq_GeV , 1 ) * -0.3867 + 
						 pow( fQsq_GeV , 2 ) * 0.02673 + 
						 pow( fQsq_GeV , 3 ) * 0  + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 2 ) * (  pow( fQsq_GeV , 0 ) * -7.053 + 
						 pow( fQsq_GeV , 1 ) * 1.593 + 
						 pow( fQsq_GeV , 2 ) * -0.11 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 3 ) * (  pow( fQsq_GeV , 0 ) * 8.797 + 
						 pow( fQsq_GeV , 1 ) * -2.106 + 
						 pow( fQsq_GeV , 2 ) * 0.1463 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) + 
		      (  pow( fT_GeV  , 4 ) * (  pow( fQsq_GeV , 0 ) * -3.681 + 
						 pow( fQsq_GeV , 1 ) * 0.9106 + 
						 pow( fQsq_GeV , 2 ) * -0.06368 + 
						 pow( fQsq_GeV , 3 ) * 0 + 
						 pow( fQsq_GeV , 4 ) * 0 ) ) ) );
      
      fZASig_TT  = ( ( ( pow( ( pow( 3.0    , 2 ) - pow( 0.938 , 2 ) ) , 2 ) / 
			 pow( ( pow( fW_GeV , 2 ) - pow( 0.938 , 2 ) ) , 2 ) ) ) * 
		     ( (  pow( fT_GeV  , 0 ) * (  pow( fQsq_GeV , 0 ) * 0.00975 + 
						  pow( fQsq_GeV , 1 ) * -0.00128 + 
						  pow( fQsq_GeV , 2 ) * 0 ) ) + 
		       (  pow( fT_GeV  , 1 ) * (  pow( fQsq_GeV , 0 ) * -0.1026 + 
						  pow( fQsq_GeV , 1 ) * 0.01493  + 
						  pow( fQsq_GeV , 2 ) * 0 + 
						  pow( fQsq_GeV , 3 ) * 0 + 
						  pow( fQsq_GeV , 4 ) * 0 ) ) + 
		       (  pow( fT_GeV  , 2 ) * (  pow( fQsq_GeV , 0 ) * 0.1861 + 
						  pow( fQsq_GeV , 1 ) * -0.0275 + 
						  pow( fQsq_GeV , 2 ) * 0 + 
						  pow( fQsq_GeV , 3 ) * 0 + 
						  pow( fQsq_GeV , 4 ) * 0 ) ) + 
		       (  pow( fT_GeV  , 3 ) * (  pow( fQsq_GeV , 0 ) * -0.09933 + 
						  pow( fQsq_GeV , 1 ) * 0.01476 + 
						  pow( fQsq_GeV , 2 ) * 0 + 
						  pow( fQsq_GeV , 3 ) * 0 + 
						  pow( fQsq_GeV , 4 ) * 0 ) ) + 
		       (  pow( fT_GeV  , 4 ) * (  pow( fQsq_GeV , 0 ) * 0 + 
						  pow( fQsq_GeV , 1 ) * 0 + 
						  pow( fQsq_GeV , 2 ) * 0 + 
						  pow( fQsq_GeV , 3 ) * 0 + 
						  pow( fQsq_GeV , 4 ) * 0 ) ) ) );
    }
    
    if ( fQsq_GeV > 6.0 ){
      
      fZASig_LT = 0.0;
      fZASig_TT = 0.0;
      
    }	  
        
    fZASigmaPara = fZASig_T + fEpsilon * fZASig_L;        
    fZASigma = fZASig_T + fEpsilon * fZASig_L + fEpsilon * TMath::Cos( ( fPi / 180.0 ) * 2.0 * fPion_Phi_CM ) * fZASig_TT + 
      TMath::Sqrt( 0.5 * fEpsilon * ( 1.0 + fEpsilon ) ) * 2.0 * TMath::Cos( ( fPi / 180.0 ) * fPion_Phi_CM ) * fZASig_LT;
    
    fRR = fZASig_T / fZASig_L;

    // ----------------------------------------------------
    // Virtual Photon flux factor in units of 1/(GeV*Sr)
    // ----------------------------------------------------
    fFlux_Factor_Col = (fAlpha/(2.0*TMath::Power(fPi,2))) * (fScatElec_Energy_Col_GeV / fElectron_Energy_Col_GeV) * 
                       ( TMath::Power(fW_GeV,2) - TMath::Power(fProton_Mass_GeV,2) ) / (2.0*fProton_Mass_GeV*fQsq_GeV*(1.0 - fEpsilon));

    if ( kCalcBremss || kCalcIon ) {      
      fFlux_Factor_Col = (fAlpha/(2.0*TMath::Power(fPi,2))) * (fScatElec_Corrected_Energy_Col_GeV / fElectron_Corrected_Energy_Col_GeV) * 
	( TMath::Power(fW_GeV,2) - TMath::Power(fProton_Mass_GeV,2) ) / (2.0*fProton_Mass_GeV*fQsq_GeV*(1.0 - fEpsilon));

    }
        
    fFlux_Factor_RF = ( fAlpha / ( 2.0 * TMath::Power( fPi , 2 ) ) ) *
                      ( fScatElec_Energy_RF_GeV / fElectron_Energy_RF_GeV ) *
                      ( TMath::Power( fW_GeV , 2 ) - TMath::Power( fProton_Mass_GeV , 2 ) ) /
                      ( 2.0 * fProton_Mass_GeV * fQsq_GeV * ( 1.0 - fEpsilon ) );
    
    // ----------------------------------------------------
    //  Jacobian  dt/dcos(theta*)dphi in units of GeV2/sr
    // ----------------------------------------------------
    fJacobian_CM = ( fPhoton_Mom_RF_GeV - fBeta_CM_RF * fPhoton_Energy_RF_GeV ) / 
                   ( fGamma_CM_RF * ( 1.0 - TMath::Power(fBeta_CM_RF,2) ) );

    fA           = fJacobian_CM * fPion_Mom_CM_GeV / fPi;
    fZASigmaLab  = fZASigma     * fFlux_Factor_Col * fA;
    fZASigmaPara = fZASigmaPara * fFlux_Factor_Col * fA;

    // ----------------------------------------------------
    // Jacobian dOmega*/dOmega dimensionless
    // ----------------------------------------------------
    fJacobian_CM_RF = ( TMath::Power(fPion_Mom_RF,2)*fW) / 
                      ( fPion_Mom_CM * TMath::Abs( ( fProton_Mass + fPhoton_Energy_RF) * fPion_Mom_RF - 
						   ( fPion_Energy_RF * fPhoton_Mom_RF * TMath::Cos((fPi/180)*fPion_Theta_RotRF ) ) ) );

    fJacobian_CM_Col = ( TMath::Power(fPion_Mom_Col,2)*fW) / 
      ( fPion_Mom_CM * TMath::Abs( ( fProton_Mass + fPhoton_Energy_Col ) * fPion_Mom_Col - 
				   ( fPion_Energy_Col * fPhoton_Mom_Col * TMath::Cos((fPi/180)*fPion_Theta_Col ) ) ) );

    if ( kCalcBremss || kCalcIon ) {      
      fJacobian_CM_Col = ( TMath::Power(fPion_Corrected_Mom_Col,2)*fW) / 
	( fPion_Mom_CM * TMath::Abs( ( fProton_Mass + fPhoton_Energy_Col ) * fPion_Corrected_Mom_Col - 
				     ( fPion_Corrected_Energy_Col * fPhoton_Mom_Col * TMath::Cos((fPi/180)*fPion_Corrected_Theta_Col ) ) ) );      
    }
    
    fZASigmaLab    = fZASigmaLab  * fJacobian_CM_Col;
    fZASigmaPara   = fZASigmaPara * fJacobian_CM_Col;
    
    // --------------------------------------------------------------------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------------------------------------------------------------------

    fS_I_RF =   fElectron_Mass * fElectron_Mass + fProton_Mass * fProton_Mass + 
      2 * ( fElectron_Energy_Col * fProton_Energy_Col - 
	    fElectron_MomX_Col * fProton_MomX_Col - 
	    fElectron_MomY_Col * fProton_MomY_Col - 
	    fElectron_MomZ_Col * fProton_MomZ_Col );
    
    fS_F_RF =  fElectron_Mass * fElectron_Mass + 
      fNeutron_Mass * fNeutron_Mass + 
      fPion_Mass * fPion_Mass + 
      2 * ( fScatElec_Energy_RF * fNeutron_Energy_RotRF - 
	    fScatElec_MomX_RF * fNeutron_MomX_RotRF - 
	    fScatElec_MomY_RF * fNeutron_MomY_RotRF - 
	    fScatElec_MomZ_RF * fNeutron_MomZ_RotRF ) + 
      2 * ( fScatElec_Energy_RF * fPion_Energy_RF   - 
	    fScatElec_MomX_RF * fPion_MomX_RotRF    - 
	    fScatElec_MomY_RF * fPion_MomY_RotRF    - 
	    fScatElec_MomZ_RF * fPion_MomZ_RotRF ) + 
      2 * ( fNeutron_Energy_RotRF * fPion_Energy_RF - 
	    fNeutron_MomX_RotRF * fPion_MomX_RotRF  - 
	    fNeutron_MomY_RotRF * fPion_MomY_RotRF  - 
	    fNeutron_MomZ_RotRF * fPion_MomZ_RotRF );
    
    fS_I_RF_GeV = fS_I_RF / 1000000.0;
    fS_F_RF_GeV = fS_F_RF / 1000000.0;
    
    // --------------------------------------------------------------------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------------------------------------------------------------------

    if ( fT_GeV >= fT_Para_GeV )
      fSSAsym = 0.5468 * ( 1 - TMath::Exp( -1.0 * 30.62 * ( fT_GeV - fT_Para_GeV ) ) );
    if ( fT_GeV < fT_Para_GeV )
      fSSAsym = 0.0;

    // --------------------------------------------------------------------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------------------------------------------------------------------

    // if ( kSConserve && fWSq_GeV > 3.61 ) {
    if ( kSConserve && ( fT_GeV < 1 ) && ( fWSq_GeV > 3.61 ) ) {
          
      ppiOut << "3" << " \t " << fZASigmaPara << " \t " << fZASigmaLab  << " \t " << fSSAsym  << " \t " << "0" << " \t "  
	     << "0" << " \t " << "0" << " \t " << fW_GeV << " \t " << fQsq_GeV  << " \t " << "0" << endl;
    
      // Pion -
      ppiOut << setw(10) << "1" 
	     << setw(10) << "1" 
	     << setw(10) << "1" 
	     << setw(10) << "211" 
	     << setw(10) << "0" 
	     << setw(10) << "0" 
	     << setw(16) << fPion_MomX_Col_GeV    
	     << setw(16) << fPion_MomY_Col_GeV   
	     << setw(16) << fPion_MomZ_Col_GeV  
	     << setw(16) << fPion_Energy_Col_GeV
	     << setw(10) << fPion_Mass_GeV
	     << setw(10) << fVertex_X
	     << setw(10) << fVertex_Y
	     << setw(10) << fVertex_Z
	     << endl;
    
      // Scattered Electron
      ppiOut << setw(10) << "2" 
	     << setw(10) << "-1" 
	     << setw(10) << "1" 
	     << setw(10) << "11" 
	     << setw(10) << "0" 
	     << setw(10) << "0" 
	     << setw(16) << fScatElec_MomX_Col_GeV  
	     << setw(16) << fScatElec_MomY_Col_GeV   
	     << setw(16) << fScatElec_MomZ_Col_GeV  
	     << setw(16) << fScatElec_Energy_Col_GeV
	     << setw(10) << fElectron_Mass_GeV
	     << setw(10) << fVertex_X
	     << setw(10) << fVertex_Y
	     << setw(10) << fVertex_Z
	     << endl;
	  
      // Recoil Proton
      ppiOut << setw(10) << "3" 
	     << setw(10) << "0" 
	     << setw(10) << "1" 
	     << setw(10) << "2212" 
	     << setw(10) << "0" 
	     << setw(10) << "0" 
	     << setw(16) << fRecoilProton_MomX_Col_GeV    
	     << setw(16) << fRecoilProton_MomY_Col_GeV   
	     << setw(16) << fRecoilProton_MomZ_Col_GeV  
	     << setw(16) << fRecoilProton_Energy_Col_GeV
	     << setw(10) << fRecoilProton_Mass_GeV
	     << setw(10) << fVertex_X
	     << setw(10) << fVertex_Y
	     << setw(10) << fVertex_Z
	     << endl;
    
    }

    // --------------------------------------------------------------------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------------------------------------------------------------------

    // if( print && ( std::abs( fS_I_RF_GeV - fS_F_RF_GeV ) > fDiff ) ) {
    //    if( ( std::abs( fS_I_RF_GeV - fS_F_RF_GeV ) > fDiff ) && ( std::abs( fS_I_Col_GeV - fS_F_Col_GeV ) > fDiff ) ) {
    if( print ) {
      
      cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << "-----------------------------------------------------    Event: " << fNRecorded << "  ----------------------------------------------------" << endl;
      cout << "----------------------------------------------------- Proton's Rest Frame --------------------------------------------------------------" << endl;
      cout << setw(24) << "Particle"
	   << setw(14) << "Energy"         
	   << setw(14) << "|mom|"          
	   << setw(14) << "mom X"              
	   << setw(14) << "mom Y"              
	   << setw(14) << "mom Z"              
	   << setw(14) << "theta"           
	   << setw(14) << "phi"            
	   << setw(14) << "sqrt mom sq"         
	   << endl;
      cout << setw(24) << "Rest Frame:    Electron" 
	   << setw(14) << fElectron_Energy_RF_GeV
	   << setw(14) << fElectron_Mom_RF_GeV
	   << setw(14) << fElectron_MomX_RF_GeV 
	   << setw(14) << fElectron_MomY_RF_GeV 
	   << setw(14) << fElectron_MomZ_RF_GeV  
	   << setw(14) << fElectron_Theta_RF
	   << setw(14) << fElectron_Phi_RF
	   << setw(14) << TMath::Sqrt( fElectron_Energy_RF_GeV * fElectron_Energy_RF_GeV -  
				       fElectron_MomX_RF_GeV   * fElectron_MomX_RF_GeV - 
				       fElectron_MomY_RF_GeV   * fElectron_MomY_RF_GeV - 
				       fElectron_MomZ_RF_GeV   * fElectron_MomZ_RF_GeV ) 
	   << endl;

      cout << setw(24) << "Scatttered Electron" 
	   << setw(14) << fScatElec_Energy_RF_GeV
	   << setw(14) << fScatElec_Mom_RF_GeV
	   << setw(14) << fScatElec_MomX_RF_GeV 
	   << setw(14) << fScatElec_MomY_RF_GeV 
	   << setw(14) << fScatElec_MomZ_RF_GeV  
	   << setw(14) << fScatElec_Theta_RF
	   << setw(14) << fScatElec_Phi_RF
	   << setw(14) << TMath::Sqrt( fScatElec_Energy_RF_GeV * fScatElec_Energy_RF_GeV -  
				       fScatElec_MomX_RF_GeV   * fScatElec_MomX_RF_GeV - 
				       fScatElec_MomY_RF_GeV   * fScatElec_MomY_RF_GeV - 
				       fScatElec_MomZ_RF_GeV   * fScatElec_MomZ_RF_GeV ) 
	   << endl;

      cout << setw(24) << "Photon" 
	   << setw(14) << fPhoton_Energy_RF_GeV
	   << setw(14) << fPhoton_Mom_RF_GeV
	   << setw(14) << fPhoton_MomX_RF_GeV 
	   << setw(14) << fPhoton_MomY_RF_GeV 
	   << setw(14) << fPhoton_MomZ_RF_GeV  
	   << setw(14) << fPhoton_Theta_RF
	   << setw(14) << fPhoton_Phi_RF
	   << setw(14) << TMath::Sqrt( std::abs(fPhoton_Energy_RF_GeV * fPhoton_Energy_RF_GeV -  
						fPhoton_MomX_RF_GeV   * fPhoton_MomX_RF_GeV - 
						fPhoton_MomY_RF_GeV   * fPhoton_MomY_RF_GeV - 
						fPhoton_MomZ_RF_GeV   * fPhoton_MomZ_RF_GeV) ) 
	   << endl;
      
      cout << setw(24) << "Pion"  
	   << setw(14) << fPion_Energy_RF_GeV
	   << setw(14) << fPion_Mom_RotRF_GeV
	   << setw(14) << fPion_MomX_RotRF_GeV
	   << setw(14) << fPion_MomY_RotRF_GeV
	   << setw(14) << fPion_MomZ_RotRF_GeV
	   << setw(14) << fPion_Theta_RotRF
	   << setw(14) << fPion_Phi_RotRF
	   << setw(14) << TMath::Sqrt( fPion_Energy_RF_GeV  * fPion_Energy_RF_GeV -  
				       fPion_MomX_RotRF_GeV * fPion_MomX_RotRF_GeV - 
				       fPion_MomY_RotRF_GeV * fPion_MomY_RotRF_GeV - 
				       fPion_MomZ_RotRF_GeV * fPion_MomZ_RotRF_GeV ) 
	   << endl;

      cout << setw(24) << "Proton (Recoil)"  
	   << setw(14) << fNeutron_Energy_RotRF_GeV
	   << setw(14) << fNeutron_Mom_RotRF_GeV
	   << setw(14) << fNeutron_MomX_RotRF_GeV 
	   << setw(14) << fNeutron_MomY_RotRF_GeV 
	   << setw(14) << fNeutron_MomZ_RotRF_GeV  
	   << setw(14) << fNeutron_Theta_RotRF
	   << setw(14) << fNeutron_Phi_RotRF
	   << setw(14) << TMath::Sqrt( fNeutron_Energy_RotRF_GeV * fNeutron_Energy_RotRF_GeV -  
				       fNeutron_MomX_RotRF_GeV   * fNeutron_MomX_RotRF_GeV - 
				       fNeutron_MomY_RotRF_GeV   * fNeutron_MomY_RotRF_GeV - 
				       fNeutron_MomZ_RotRF_GeV   * fNeutron_MomZ_RotRF_GeV ) 
	   << endl;
      cout << setw(24) << "Conservation of momentum"
	   << setw(42) << -fElectron_MomX_RF_GeV + fPion_MomX_RotRF_GeV + fNeutron_MomX_RotRF_GeV + fScatElec_MomX_RF_GeV 
	   << setw(14) << -fElectron_MomY_RF_GeV + fPion_MomY_RotRF_GeV + fNeutron_MomY_RotRF_GeV + fScatElec_MomY_RF_GeV 
	   << setw(14) << -fElectron_MomZ_RF_GeV + fPion_MomZ_RotRF_GeV + fNeutron_MomZ_RotRF_GeV + fScatElec_MomZ_RF_GeV
	   << endl;
      cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

      cout << endl;
      cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << "---------------------------------------------------- Proton Photon Center of Mass Frame ------------------------------------------------" << endl;
      cout << setw(24) << "Particle"
	   << setw(14) << "Energy"         
	   << setw(14) << "|mom|"          
	   << setw(14) << "mom X"              
	   << setw(14) << "mom Y"              
	   << setw(14) << "mom Z"              
	   << setw(14) << "theta"           
	   << setw(14) << "phi"            
	   << setw(14) << "sqrt mom sq"         
	   << endl;
      
      cout << setw(24) << "Neutron (Target)" 
	   << setw(14) << fProton_Energy_CM_GeV
	   << setw(14) << fProton_Mom_CM_GeV
	   << setw(84) << TMath::Sqrt( fProton_Energy_CM_GeV * fProton_Energy_CM_GeV -  
	    			       fProton_Mom_CM_GeV    * fProton_Mom_CM_GeV ) 
	   << endl;


      cout << setw(24) << "Photon" 
	   << setw(14) << fPhoton_Energy_CM_GeV
	   << setw(14) << fPhoton_Mom_CM_GeV
	   << setw(84) << TMath::Sqrt( std::abs(fPhoton_Energy_CM_GeV * fPhoton_Energy_CM_GeV -  
						fPhoton_Mom_CM_GeV    * fPhoton_Mom_CM_GeV ) )
	   << endl;

      cout << setw(24) << "Conservation of momentum"  << setw(28) << fProton_Mom_CM_GeV - fPhoton_Mom_CM_GeV  
	   << endl;

      cout << setw(24) << "Pion"  
	   << setw(14) << fPion_Energy_CM_GeV
	   << setw(14) << fPion_Mom_CM_GeV
	   << setw(56) << fPion_Theta_CM
	   << setw(14) << fPion_Phi_CM
	   << setw(14) << TMath::Sqrt( fPion_Energy_CM_GeV * fPion_Energy_CM_GeV -  
	    			       fPion_Mom_CM_GeV    * fPion_Mom_CM_GeV ) 
	   << endl;
      cout << setw(24) << "Proton (Recoil)"  
	   << setw(14) << fNeutron_Energy_CM_GeV
	   << setw(14) << fNeutron_Mom_CM_GeV
	   << setw(56) << fNeutron_Theta_CM
	   << setw(14) << fNeutron_Phi_CM
	   << setw(14) << TMath::Sqrt( fNeutron_Energy_CM_GeV * fNeutron_Energy_CM_GeV -  
	    			       fNeutron_Mom_CM_GeV    * fNeutron_Mom_CM_GeV )
	   << endl;
      cout << setw(24) << "Conservation of momentum"  << setw(28) << fNeutron_Mom_CM_GeV - fPion_Mom_CM_GeV  
	   << setw(42) << "Conservation of thetas and phis"    << setw(14) << fPion_Theta_CM + fNeutron_Theta_CM
	   << setw(14) << std::abs(fPion_Phi_CM - fNeutron_Phi_CM)
	   << endl;
      cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

      cout << endl;
      cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << "---------------------------------------------------------- Collider Frame --------------------------------------------------------------" << endl;
      cout << setw(24) << "Particle"
	   << setw(14) << "Energy"         
	   << setw(14) << "|mom|"          
	   << setw(14) << "mom X"              
	   << setw(14) << "mom Y"              
	   << setw(14) << "mom Z"              
	   << setw(14) << "theta"           
	   << setw(14) << "phi"            
	   << setw(14) << "sqrt mom sq"         
	   << endl;
      
      cout << setw(24) << "Neutron (Target)" 
	   << setw(14) << fProton_Energy_Col_GeV
	   << setw(14) << fProton_Mom_Col_GeV
	   << setw(14) << fProton_MomX_Col_GeV 
	   << setw(14) << fProton_MomY_Col_GeV 
	   << setw(14) << fProton_MomZ_Col_GeV  
	   << setw(14) << fProton_Theta_Col
	   << setw(14) << fProton_Phi_Col
	   << setw(14) << TMath::Sqrt( fProton_Energy_Col_GeV * fProton_Energy_Col_GeV -  
				       fProton_MomX_Col_GeV   * fProton_MomX_Col_GeV - 
				       fProton_MomY_Col_GeV   * fProton_MomY_Col_GeV - 
				       fProton_MomZ_Col_GeV   * fProton_MomZ_Col_GeV  ) 
	   << endl;

      cout << setw(24) << "Electron" 
	   << setw(14) << fElectron_Energy_Col_GeV
	   << setw(14) << fElectron_Mom_Col_GeV
	   << setw(14) << fElectron_MomX_Col_GeV 
	   << setw(14) << fElectron_MomY_Col_GeV 
	   << setw(14) << fElectron_MomZ_Col_GeV  
	   << setw(14) << fElectron_Theta_Col
	   << setw(14) << fElectron_Phi_Col
	   << setw(14) << TMath::Sqrt( fElectron_Energy_Col_GeV * fElectron_Energy_Col_GeV -  
				       fElectron_MomX_Col_GeV   * fElectron_MomX_Col_GeV - 
				       fElectron_MomY_Col_GeV   * fElectron_MomY_Col_GeV - 
				       fElectron_MomZ_Col_GeV   * fElectron_MomZ_Col_GeV ) 
	   << endl;

      cout << setw(24) << "Scattered Electron" 
      	   << setw(14) << fScatElec_Energy_Col_GeV
      	   << setw(14) << fScatElec_Mom_Col_GeV
      	   << setw(14) << fScatElec_MomX_Col_GeV 
      	   << setw(14) << fScatElec_MomY_Col_GeV 
      	   << setw(14) << fScatElec_MomZ_Col_GeV  
      	   << setw(14) << fScatElec_Theta_Col
      	   << setw(14) << fScatElec_Phi_Col
      	   << setw(14) << TMath::Sqrt( std::abs( fScatElec_Energy_Col_GeV * fScatElec_Energy_Col_GeV -  
      	    			       fScatElec_MomX_Col_GeV    * fScatElec_MomX_Col_GeV - 
      	    			       fScatElec_MomY_Col_GeV    * fScatElec_MomY_Col_GeV - 
      	    			       fScatElec_MomZ_Col_GeV    * fScatElec_MomZ_Col_GeV ) ) 
      	   << endl;

      cout << setw(24) << "Photon" 
      	   << setw(14) << fPhoton_Energy_Col_GeV
      	   << setw(14) << fPhoton_Mom_Col_GeV
      	   << setw(14) << fPhoton_MomX_Col_GeV 
      	   << setw(14) << fPhoton_MomY_Col_GeV 
      	   << setw(14) << fPhoton_MomZ_Col_GeV  
      	   << setw(14) << fPhoton_Theta_Col
      	   << setw(14) << fPhoton_Phi_Col
      	   << setw(14) << TMath::Sqrt( std::abs(fPhoton_Energy_Col_GeV * fPhoton_Energy_Col_GeV -  
      						fPhoton_MomX_Col_GeV   * fPhoton_MomX_Col_GeV - 
      						fPhoton_MomY_Col_GeV   * fPhoton_MomY_Col_GeV - 
      						fPhoton_MomZ_Col_GeV   * fPhoton_MomZ_Col_GeV ) )
      	   << endl;

      cout << setw(24) << "Pion"  
      	   << setw(14) << fPion_Energy_Col_GeV
      	   << setw(14) << fPion_Mom_Col_GeV
      	   << setw(14) << fPion_MomX_Col_GeV 
      	   << setw(14) << fPion_MomY_Col_GeV
      	   << setw(14) << fPion_MomZ_Col_GeV
      	   << setw(14) << fPion_Theta_Col
      	   << setw(14) << fPion_Phi_Col
      	   << setw(14) << TMath::Sqrt( fPion_Energy_Col_GeV * fPion_Energy_Col_GeV -  
      				       fPion_MomX_Col_GeV   * fPion_MomX_Col_GeV - 
      				       fPion_MomY_Col_GeV   * fPion_MomY_Col_GeV - 
      				       fPion_MomZ_Col_GeV   * fPion_MomZ_Col_GeV ) 
      	   << endl;
      cout << setw(24) << "Proton (Recoil)"  
      	   << setw(14) << fNeutron_Energy_Col_GeV
      	   << setw(14) << fNeutron_Mom_Col_GeV
      	   << setw(14) << fNeutron_MomX_Col_GeV 
      	   << setw(14) << fNeutron_MomY_Col_GeV
      	   << setw(14) << fNeutron_MomZ_Col_GeV
      	   << setw(14) << fNeutron_Theta_Col
      	   << setw(14) << fNeutron_Phi_Col
      	   << setw(14) << TMath::Sqrt( fNeutron_Energy_Col_GeV * fNeutron_Energy_Col_GeV -  
      				       fNeutron_MomX_Col_GeV   * fNeutron_MomX_Col_GeV - 
      				       fNeutron_MomY_Col_GeV   * fNeutron_MomY_Col_GeV - 
      				       fNeutron_MomZ_Col_GeV   * fNeutron_MomZ_Col_GeV ) 
      	   << endl;
      cout << setw(24) << "Conservation of momentum"
      	   << setw(42) << fElectron_MomX_Col_GeV + fProton_MomX_Col_GeV - fPion_MomX_Col_GeV - fNeutron_MomX_Col_GeV - fScatElec_MomX_Col_GeV
      	   << setw(14) << fElectron_MomY_Col_GeV + fProton_MomY_Col_GeV - fPion_MomY_Col_GeV - fNeutron_MomY_Col_GeV - fScatElec_MomY_Col_GeV
      	   << setw(14) << fElectron_MomZ_Col_GeV + fProton_MomZ_Col_GeV - fPion_MomZ_Col_GeV - fNeutron_MomZ_Col_GeV - fScatElec_MomZ_Col_GeV
      	   << endl;
      cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;


      cout << "w = " << fW_GeV 
	   << "   Q-sq = " << fQsq_GeV 
	   << "   sqrt Q-sq = " << TMath::Sqrt(fQsq_GeV) 
	   << "   -t = " << fT_GeV
	   << "\ns initial rf = " << fS_I_RF_GeV 
	   << "\ns final rf   = " << fS_F_RF_GeV 
	   << "\ns diff rf   = " << std::abs( fS_I_RF_GeV - fS_F_RF_GeV )
	   << endl;  
      cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

      return 0;
    }

    // --------------------------------------------------------------------------------------------------------------------------------------------------------
    // --------------------------------------------------------------------------------------------------------------------------------------------------------

    fNRecorded ++;
    fRatio = fNRecorded / fNGenerated;
    fRand = myPim.test(); // This is a test variable.
    t1.Fill();

  } // This is the loop over total events.

  ppiOut.close();
  t1.Write();
  tTime.Stop();

  cout << setw(60) << "Total generted events " << setw(10) << fNGenerated << endl;
  cout << setw(60) << "Total recorded events "
       << setw(10) << fNRecorded << setw(4) << " % " << setw(4) << ( 1.*fNRecorded / (1.*fNGenerated) ) * 100.0
       << endl;
  cout << setw(60) << "Events with W square is negative "
       << setw(10) << fWSqNeg << setw(4) << " % " << setw(4) << ( 1.*fWSqNeg / (1.*fNGenerated) ) * 100.0
       << endl;
  cout << setw(60) << "Events with W less than 1.9 GeV: "
       << setw(10) << fWLess1P9 << setw(4) << " % " << setw(4) << ( 1.*fWLess1P9 / (1.*fNGenerated) ) * 100.0
       << endl;
  cout << setw(60) << "Events with s not conserved: "
       << setw(10) << fSDiff << setw(4) << " % " << setw(4) << ( 1.*fSDiff / (1.*fNGenerated) ) * 100.0
       << endl;
  cout << setw(60) << "Events with W less than sum of nmasses of Proton and Pion: "
       << setw(10) << fWLessShell << setw(4) << " % " << setw(4) << ( 1.*fWLessShell / (1.*fNGenerated) ) * 100.0
       << endl;
  cout << setw(60) << "Total time "; cout << "   "; tTime.Print();
  cout << endl;
 
 return 0;
}
# endif
//---------------------------------------------------------
