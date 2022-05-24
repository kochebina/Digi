#include "contruction.hh"
#include "constructionMessenger.hh"

#include "G4VisAttributes.hh"

TestDetectorConstruction::TestDetectorConstruction(): G4VUserDetectorConstruction(),
fCheckOverlaps(true)
{
	//G4cout<<"TestDetectorConstruction:: constructor"<<G4endl;

	fDetectorMessenger = new TestDetectorConstructionMessenger(this);
	//fDetectorMessenger->
		//Initialize variables. The following variables can be changed via the run.mac file.
	sMaterial= "LYSO";
}

TestDetectorConstruction::~TestDetectorConstruction()
{
	delete fDetectorMessenger;
}

G4VPhysicalVolume *TestDetectorConstruction::Construct()
{
 G4NistManager *nist = G4NistManager::Instance();


 G4double energy[2] = {1.239841939*eV/0.2, 1.239841939*eV/0.9};
 G4double rindexLYSO[2] = {1.8, 1.8};
 G4double rindexWorld[2] = {1., 1.};
 if(sMaterial == "LYSO")
 	 {
	 DetectionMaterial = new G4Material("LYSO", 7.36*g/cm3,4);
	 DetectionMaterial->AddElement(nist->FindOrBuildElement("Lu"), 71.4467891*perCent);
	 DetectionMaterial->AddElement(nist->FindOrBuildElement("Y"), 4.033805*perCent);
	 DetectionMaterial->AddElement(nist->FindOrBuildElement("Si"), 6.3714272*perCent);
	 DetectionMaterial->AddElement(nist->FindOrBuildElement("O"), 18.1479788*perCent );



	  G4MaterialPropertiesTable *mptLYSO = new G4MaterialPropertiesTable();
	  mptLYSO->AddProperty("RINDEX", energy, rindexLYSO, 2);
	  DetectionMaterial->SetMaterialPropertiesTable(mptLYSO);
 	 }
 else if (sMaterial == "WATER")
 	 {
	 DetectionMaterial = new G4Material("WATER", 1*g/cm3,2);
	 DetectionMaterial->AddElement(nist->FindOrBuildElement("H"), 2);
	 DetectionMaterial->AddElement(nist->FindOrBuildElement("O"), 1);
 	 }
 else
 	 {
	 DetectionMaterial=nist->FindOrBuildMaterial("G4_AIR");
 	 }

 G4Material* water = new G4Material("WATER", 1*g/cm3,2);
 water->AddElement(nist->FindOrBuildElement("H"), 2);
 water->AddElement(nist->FindOrBuildElement("O"), 1);

 //G4cout<<"-------------------------------------------Detector Material "<<DetectionMaterial <<G4endl;


  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
  G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
  mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);
  worldMat->SetMaterialPropertiesTable(mptWorld);

  G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

  G4Box *solidDetector = new G4Box("solidDetector", 0.4*m, 0.4*m, 0.05*m);
  logicDetector = new G4LogicalVolume(solidDetector, water, "logicRadiator");
  G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.25*m), logicDetector, "physDetector", logicWorld, false, 0, true);

  logicDetector->SetVisAttributes(new G4VisAttributes (G4Colour::Green()));

  G4Box *solidDetector2 = new G4Box("solidDetector2", 0.4*m, 0.4*m, 0.05*m);
  logicDetector2 = new G4LogicalVolume(solidDetector2, DetectionMaterial, "logicRadiator2");
  G4VPhysicalVolume *physDetector2 = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.35*m), logicDetector2, "physDetector2", logicWorld, false, 0, true);


  /*
  G4Box *solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.1*m);
  logicRadiator = new G4LogicalVolume(solidRadiator, Detector, "logicRadiator");
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

	m_SDName= TestSensitiveDetector::GetCrystalCollectionName();
	TestSensitiveDetector *sensDet = new TestSensitiveDetector(m_SDName);
	//TestSensitiveDetector *sensDet2 = new TestSensitiveDetector("SensitiveDetector2");

	G4SDManager *SDMan=G4SDManager::GetSDMpointer();
	SDMan->AddNewDetector(sensDet);
	//SDMan->AddNewDetector(sensDet2);

	logicDetector->SetSensitiveDetector(sensDet);
	//logicDetector2->SetSensitiveDetector(sensDet2);




}

void TestDetectorConstruction::ChangeMaterial(G4String NewMaterial)
{
	sMaterial = NewMaterial;
}

