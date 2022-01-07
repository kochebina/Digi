#ifndef TOROOT_HH
#define TOROOT_HH


#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "g4root.hh"
#include "globals.hh"




class TFile;
class TTree;
class TH1D;


class TesttoRoot
{
public:
  TesttoRoot();
  ~TesttoRoot();

  void Book();
  void Save();

  void FillNtuple ();


private:
  	  TFile*   fRootFile;
  	  TTree* fNtupleHits;
  	  TTree* fNtupleSignles;


};



#endif
