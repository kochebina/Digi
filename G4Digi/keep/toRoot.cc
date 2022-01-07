#include "toRoot.hh"

//#include <TH1D.h>
#include <TFile.h>
#include <TTree.h>
#include <CLHEP/Units/SystemOfUnits.h>

#include "G4UnitsTable.hh"

TesttoRoot::TesttoRoot() : fRootFile(0), fNtupleHits(0), fNtupleSignles(0)
{
//	fNtupleHits = 0;
//	fNtupleSignles = 0;
}

TesttoRoot::~TesttoRoot()
{
	//if (fRootFile) delete fRootFile;
}


void TesttoRoot::Book()
{
/*
	G4String fileName = "Test2ROOT.root";
	  fRootFile = new TFile(fileName,"RECREATE");
	  if (! fRootFile) {
	    G4cout << " HistoManager::Book :"
	           << " problem creating the ROOT TFile "
	           << G4endl;
	    return;
	  }

	  fNtupleHits = new TTree("NtupleHits", "NtupleHits");


	  /*Branch("edep",           &buffer.edep,"edep/F");
	  Branch("stepLength",     &buffer.stepLength,"stepLength/F");

	  fNtuple1->Branch("Eabs", &fEabs, "Eabs/D");
	  fNtuple1->Branch("Egap", &fEgap, "Egap/D");

	    // create 2nd ntuple
	  fNtuple2 = new TTree("Ntuple2", "TrackL");
	  fNtuple2->Branch("Labs", &fLabs, "Labs/D");
	  fNtuple2->Branch("Lgap", &fLgap, "Lgap/D");
*/

}
void TesttoRoot::Save()
{

}

void TesttoRoot::FillNtuple()
{

}

