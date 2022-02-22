//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// ------------------------------------------------------------
//      GEANT 4 class implementation file
//      CERN Geneva Switzerland
//
//
//      ------------ TestAdder  ------
//           by   F.Longo, R.Giannitrapani & G.Santin (13 nov 2000)
//
// ************************************************************

#include "TestAdderMessenger.hh"
#include "TestAdder.hh"


#include "G4SystemOfUnits.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIdirectory.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestAdderMessenger::TestAdderMessenger (TestAdder* adder): m_Adder(adder)
{

	G4cout<<"TestAdderMessenger::constructor"<<G4endl;
	Dir = new G4UIdirectory("/digitizer/adder/");
	Dir->SetGuidance("Digitizer directory");

	/*SetModuleNameCmd = new G4UIcmdWithAString("/digitizer/insert",this);
	SetModuleNameCmd->SetGuidance("Module to insert");
	SetModuleNameCmd->SetParameterName("choice",false);
	SetModuleNameCmd->AvailableForStates(G4State_PreInit);
	G4cout<<"TestAdderMessenger::TestAdderMessenger"<<G4endl;
	*/
	G4String cmdName;

	cmdName = Dir->GetCommandPath () + "politics";
	SetPoliticsCmd = new G4UIcmdWithAString(cmdName,this);



}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestAdderMessenger::~TestAdderMessenger()
{
	delete Dir;
	delete SetPoliticsCmd;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void TestAdderMessenger::SetNewValue(G4UIcommand * command,G4String newValue)
{
G4cout<<"TestAdderMessenger::SetNewValue"<<G4endl;
	//G4VDigitizerModule* myDM=0;
	//G4DigiManager * fDM = G4DigiManager::GetDMpointer();

	if( command == SetPoliticsCmd )
	    {
		m_Adder->SetPolitics(newValue);
		/*if(newValue=="adder")
			{
			TestAdder * myAdder = new TestAdder( "TestAdder" );
			G4DigiManager::GetDMpointer()->AddNewModule(myAdder);


			}
		//
		else if (newValue=="readout")
			{
			TestReadout * myReadout = new TestReadout( "TestReadout" );
			G4DigiManager::GetDMpointer()->AddNewModule(myReadout);

			}
*/
	    }
//	fDM->List();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....












