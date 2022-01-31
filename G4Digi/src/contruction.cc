#include "contruction.hh"

TestDetectorConstruction::TestDetectorConstruction()
{
}

TestDetectorConstruction::~TestDetectorConstruction()
{
}

G4VPhysicalVolume *TestDetectorConstruction::Construct()
{
 G4NistManager *nist = G4NistManager::Instance();

  G4Material *LYSO = new G4Material("LYSO", 7.36*g/cm3,4);
  LYSO->AddElement(nist->FindOrBuildElement("Lu"), 71.4467891*perCent);
  LYSO->AddElement(nist->FindOrBuildElement("Y"), 4.033805*perCent);
  LYSO->AddElement(nist->FindOrBuildElement("Si"), 6.3714272*perCent);
  LYSO->AddElement(nist->FindOrBuildElement("O"), 18.1479788*perCent );


  G4double energy[2] = {1.239841939*eV/0.2, 1.239841939*eV/0.9};
  G4double rindexLYSO[2] = {1.8, 1.8};
  G4double rindexWorld[2] = {1., 1.};

  G4MaterialPropertiesTable *mptLYSO = new G4MaterialPropertiesTable();
  mptLYSO->AddProperty("RINDEX", energy, rindexLYSO, 2);
  LYSO->SetMaterialPropertiesTable(mptLYSO);

  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
  G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
  mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);
  worldMat->SetMaterialPropertiesTable(mptWorld);

  G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

  G4Box *solidLYSO = new G4Box("solidLYSO", 0.4*m, 0.4*m, 0.1*m);
  logicLYSO = new G4LogicalVolume(solidLYSO, LYSO, "logicRadiator");
  G4VPhysicalVolume *physLYSO = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.25*m), logicLYSO, "physLYSO", logicWorld, false, 0, true);

  /*
  G4Box *solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.1*m);
  logicRadiator = new G4LogicalVolume(solidRadiator, LYSO, "logicRadiator");
  G4VPhysicalVolume *physRadiator = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.25*m), logicRadiator, "physRadiator", logicWorld, false, 0, true);
  */
// fScoringVolume = logicRadiator;


 //detector geometry
  /*G4Box *solidDetector = new G4Box("solidDetector", 0.05*m, 0.05*m, 0.01*m);
  logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetecor");
  //G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(0, 0, 0.49*m), logicDetector, "physDetector", logicWorld, false, 0, true);
  /*
  for(G4int i = 0; i<10; i++)
  {
	  for(G4int j = 0; j<10; j++)
	    {
		  G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i+0.5)*m/10, -0.5*m+(j+0.5)*m/10, 0.49*m), logicDetector, "physDetector", logicWorld, false, j+i*10, true);
		  //G4cout<< physDetector-> GetCopyNo () <<G4endl;
	    }
  }
  */
  return physWorld;
}


void TestDetectorConstruction::ConstructSDandField()
{
	TestSensitiveDetector *sensDet = new TestSensitiveDetector("SensitiveDetector");

	G4SDManager *SDMan=G4SDManager::GetSDMpointer();
	SDMan->AddNewDetector(sensDet);

	logicLYSO->SetSensitiveDetector(sensDet);

}


