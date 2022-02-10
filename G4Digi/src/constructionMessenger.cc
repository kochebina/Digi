

#include "constructionMessenger.hh"
#include "contruction.hh"

#include "G4SystemOfUnits.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIdirectory.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestDetectorConstructionMessenger::TestDetectorConstructionMessenger (TestDetectorConstruction* det): Detector(det)
{ 

	G4cout<<"TestDetectorConstructionMessenger::constructor"<<G4endl;

	Dir = new G4UIdirectory("/DetectorConstruction/");
	Dir->SetGuidance("DetectorConstruction directory");

	SetMaterialCmd = new G4UIcmdWithAString("/DetectorConstruction/insert",this);
	SetMaterialCmd->SetGuidance("Module to insert");
	SetMaterialCmd->SetParameterName("choice",false);
	SetMaterialCmd->AvailableForStates(G4State_PreInit);
	G4cout<<"TestDetectorConstructionMessenger::TestDetectorConstructionMessenger"<<G4endl;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestDetectorConstructionMessenger::~TestDetectorConstructionMessenger()
{
	delete Dir;
	delete SetMaterialCmd;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void TestDetectorConstructionMessenger::SetNewValue(G4UIcommand * command,G4String newValue)
{ 

	//G4VDetectorConstructionModule* myDM=0;

	if( command == SetMaterialCmd )
	    {
		Detector->ChangeMaterial(newValue);
		//myDM = new TestDetectorConstructionInitializationModule( "TestDetectorConstructionInitializationModule" );
		//	  G4DigiManager::GetDMpointer()->AddNewModule(myDM);
			//  m_DetectorConstruction->SetThreshold(DefineModuleNameCmd->GetNewStringValue(newValue));

		G4cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! "<<newValue<<G4endl;
	    }

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....












