#ifndef DETECTORSD_HH
#define DETECTORSD_HH

#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"

#include "g4root.hh"

#include "TestHit.hh"
#include "TestHitAttribute.hh"


class TestSensitiveDetector : public G4VSensitiveDetector
{
public:
	TestSensitiveDetector(G4String);
	~TestSensitiveDetector();
	//void TestSensitiveDetector(const G4String, const G4String);

	 void Initialize(G4HCofThisEvent*) override;
	 G4bool ProcessHits(G4Step *, G4TouchableHistory *) override;
	 void EndOfEvent(G4HCofThisEvent*) override;

    //! Tool method returning the name of the hit-collection where the crystal hits are stored
    static inline const G4String& GetCrystalCollectionName()
    	  { return theCrystalCollectionName; }

private:
  TestHitsCollection*  fHitsCollection;
  TestHitsCollection*  fHitsCollection2;
  G4int collectionID;
  G4int collectionID2;
  TestHitAttribute *fHitAttribute;
  static const G4String theCrystalCollectionName; //! Name of the hit collection

  
};



#endif
