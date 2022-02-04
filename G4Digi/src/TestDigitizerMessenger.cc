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
//      ------------ TestDigitizerMessenger  ------
//           by F.Longo, G.Santin & R.Giannitrapani (27 nov 2001)
//
// ************************************************************

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#include "TestDigitizerMessenger.hh"
#include "TestDigitizer.hh"

#include "G4SystemOfUnits.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIdirectory.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestDigitizerMessenger::TestDigitizerMessenger (TestDigitizer* digitizer): m_digitizer(digitizer)
{ 
	Dir = new G4UIdirectory("/digitizer/");
	Dir->SetGuidance("Digitizer directory");

	/* pInsertCmd->SetCandidates(DumpMap());

	  G4String cmdName;

	  cmdName = GetDirectoryName()+"setInputName";
	  SetInputNameCmd = new G4UIcmdWithAString(cmdName,this);
	  SetInputNameCmd->SetGuidance("Set the name of the input pulse channel");
	  SetInputNameCmd->SetParameterName("Name",false);
*/

	SetModuleNameCmd = new G4UIcmdWithAString("/digitizer/insert",this);
	SetModuleNameCmd->SetGuidance("Module to insert");
	SetModuleNameCmd->SetParameterName("choice",false);
	SetModuleNameCmd->AvailableForStates(G4State_PreInit);
	G4cout<<"TestDigitizerMessenger::TestDigitizerMessenger"<<G4endl;

  //DefineModuleNameCmd->SetDefaultValue("adder");
  //dDefineModuleNameCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestDigitizerMessenger::~TestDigitizerMessenger()
{
	delete Dir;
	delete SetModuleNameCmd;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void TestDigitizerMessenger::SetNewValue(G4UIcommand * command,G4String newValue)
{ 

	//G4VDigitizerModule* myDM=0;

	if( command == SetModuleNameCmd )
	    {

		//myDM = new TestDigitizerInitializationModule( "TestDigitizerInitializationModule" );
		//	  G4DigiManager::GetDMpointer()->AddNewModule(myDM);
			//  m_digitizer->SetThreshold(DefineModuleNameCmd->GetNewStringValue(newValue));

		G4cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! "<<newValue<<G4endl;
	    }

}
/*
{
	GateVPulseProcessor* newProcessor=0;

	  G4String newInsertionName = GetProcessorChain()->MakeElementName(GetNewInsertionBaseName());

	  if (childTypeName=="readout")
	    newProcessor = new GateReadout(GetProcessorChain(),newInsertionName);
	  else if (childTypeName=="pileup")
	    newProcessor = new GatePileup(GetProcessorChain(),newInsertionName);

	if( command ==  )
    { 
	  G4V * myDM = new TestDigitizerInitializationModule( "TestDigitizerInitializationModule" );
	  G4DigiManager::GetDMpointer()->AddNewModule(myDM);
    }



}
*/
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....












