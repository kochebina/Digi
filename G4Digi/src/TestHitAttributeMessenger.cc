
#include "TestHitAttributeMessenger.hh"
#include "TestHitAttribute.hh"


#include "G4SystemOfUnits.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIdirectory.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....


TestHitAttributeMessenger::TestHitAttributeMessenger (TestHitAttribute* hitAtt): m_HitAtt(hitAtt)
{

	G4cout<<"TestHitAttributeMessenger::constructor"<<G4endl;
	Dir = new G4UIdirectory("/hitAttribute/");
	Dir->SetGuidance("Hit directory");

	/*SetModuleNameCmd = new G4UIcmdWithAString("/digitizer/insert",this);
	SetModuleNameCmd->SetGuidance("Module to insert");
	SetModuleNameCmd->SetParameterName("choice",false);
	SetModuleNameCmd->AvailableForStates(G4State_PreInit);
	G4cout<<"TestHitAttributeMessenger::TestHitAttributeMessenger"<<G4endl;
	*/
	G4String cmdName;

	cmdName = Dir->GetCommandPath () + "file";
	SetInputAttributeFileCmd = new G4UIcmdWithAString(cmdName,this);



}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestHitAttributeMessenger::~TestHitAttributeMessenger()
{
	delete Dir;
	delete SetInputAttributeFileCmd;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void TestHitAttributeMessenger::SetNewValue(G4UIcommand * command,G4String newValue)
{
G4cout<<"Messenger::SetNewValue"<<G4endl;
	//G4VDigitizerModule* myDM=0;
	//G4DigiManager * fDM = G4DigiManager::GetDMpointer();

	if( command == SetInputAttributeFileCmd )
	    {
		m_HitAtt->SetInputAttributeFile(newValue);

	    }


}
