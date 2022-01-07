#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"

#include "g4root.hh"

#include "hit.hh"

class TestSensitiveDetector : public G4VSensitiveDetector
{
public:
	TestSensitiveDetector(G4String);
	~TestSensitiveDetector();

	void Initialize(G4HCofThisEvent*);
	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
	void EndOfEvent(G4HCofThisEvent*);

private:
	TestHitsCollection*  HitsCollection;
  
};



#endif
