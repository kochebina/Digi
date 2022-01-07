#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4SystemOfUnits.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"

#include "detector.hh"

class TestDetectorConstruction : public G4VUserDetectorConstruction
{

public:
  TestDetectorConstruction();
  ~TestDetectorConstruction();

 // G4LogicalVolume *GetScoringVolume() const {return fScoringVolume;}

  virtual G4VPhysicalVolume *Construct();

private:
 // G4LogicalVolume *logicDetector;
  G4LogicalVolume *logicRadiator;
  virtual void ConstructSDandField();

  //G4LogicalVolume *fScoringVolume;

};

#endif
