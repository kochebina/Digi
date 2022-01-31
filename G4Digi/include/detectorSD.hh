#ifndef DETECTORSD_HH
#define DETECTORSD_HH

#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"

#include "g4root.hh"

#include "hit.hh"



class TestSensitiveDetector : public G4VSensitiveDetector
{
public:
	TestSensitiveDetector(G4String);
	~TestSensitiveDetector();
	//void TestSensitiveDetector(const G4String, const G4String);

	virtual void Initialize(G4HCofThisEvent*);
	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
	virtual void EndOfEvent(G4HCofThisEvent*);

private:
  TestHitsCollection*  fHitsCollection;
  G4int collectionID;
  
};



#endif
