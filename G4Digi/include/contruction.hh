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
#include "G4SDManager.hh"

#include "detectorSD.hh"

class TestDetectorConstructionMessenger;
class G4Material;

class TestDetectorConstruction : public G4VUserDetectorConstruction
{

public:
  TestDetectorConstruction();
  virtual ~TestDetectorConstruction();

  G4LogicalVolume *GetSDVolume() const {return logicDetector;}
  G4LogicalVolume *GetSDVolume2() const {return logicDetector2;}

  virtual G4VPhysicalVolume *Construct();
  void ChangeMaterial(G4String choice);

private:
  TestDetectorConstructionMessenger* fDetectorMessenger;
  // G4LogicalVolume *logicDetector;
  //G4LogicalVolume *logicRadiator;
	G4bool  fCheckOverlaps;
	G4String sMaterial;

  G4LogicalVolume *logicDetector;
  G4LogicalVolume *logicDetector2;
  virtual void ConstructSDandField();

  //G4LogicalVolume *fScoringVolume;
  G4Material *DetectionMaterial;

public:
  G4String m_SDName;


};

#endif
