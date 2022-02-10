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
//      ------------ TestDigitizer  ------
//           by   F.Longo, R.Giannitrapani & G.Santin (13 nov 2000)
//
// ************************************************************

#include <vector>

#include "TestDigitizer.hh"
#include "TestDigi.hh"
#include "TestDigitizerMessenger.hh"

#include "TestHit.hh"


#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4DigiManager.hh"
#include "G4ios.hh"

#include "TestDigitizerInitializationModule.hh"
#include "TestAdder.hh"
#include "TestReadout.hh"

TestDigitizer* TestDigitizer::theDigitizer=0;

//-----------------------------------------------------------------
TestDigitizer* TestDigitizer::GetInstance()
{
  if (!theDigitizer)
    theDigitizer = new TestDigitizer;
  return theDigitizer;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestDigitizer::TestDigitizer()
{
	G4cout<<"TestDigitizer:: constructor"<<G4endl;

//create a messenger for this class
 fMessenger = new TestDigitizerMessenger(this);
 m_moduleName = "TestDigitizerInitializationModule";


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestDigitizer::~TestDigitizer()
{
 delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void TestDigitizer::Initilize()
{
		TestDigitizerInitializationModule * myDM = new TestDigitizerInitializationModule( "TestDigitizerInitializationModule" );
		G4DigiManager::GetDMpointer()->AddNewModule(myDM);

		TestAdder * myAdder = new TestAdder( "TestAdder" );
		G4DigiManager::GetDMpointer()->AddNewModule(myAdder);

		TestReadout * myReadout = new TestReadout( "TestReadout" );
		G4DigiManager::GetDMpointer()->AddNewModule(myReadout);




}

void TestDigitizer::RunDigitizer()
{


	G4cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! "<<m_moduleName<<G4endl;

	G4DigiManager * fDM = G4DigiManager::GetDMpointer();


	//fDM->List();

	//	initialiosation
	//fDM->Initialize();

	//	loop over digitizer modules

	std::vector <G4String> v_modules;
	v_modules.push_back("TestDigitizerInitializationModule");
	v_modules.push_back("TestAdder");
	v_modules.push_back("TestReadout");

	/*fDM->Digitize("TestDigitizerInitializationModule");
		 fDM->Digitize("TestAdder");
		 fDM->Digitize("TestReadout");
*/

	/*for (G4int i=0; i< fDM->GetModuleCapacity();i++)
	{
		 G4cout<<"capacity "<<fDM->GetModuleCapacity()<<G4endl;

		// G4VDigitizerModule *DigiModule = (G4VDigitizerModule *) (fDM->FindDigitizerModule (v_modules[i]));


		 fDM->Digitize(v_modules[i]);

		// G4int myDigiCollID = fDM->GetDigiCollectionID("TestDigitizerInitializationModule/DigitsCollection");
		// TestDigitsCollection * DC = (TestDigitsCollection*)fDM->GetDigiCollection(i);
		// DC

		// G4cout<<"Digi Collection "<< DC->entries () <<G4endl;
		 //"TestDigitizerInitializationModule/DigitsCollection");

	}

*/



	//G4cout<<"Event::Digitize"<<G4endl;
	//TestDigitizer * myDM = (TestDigitizer*)fDM->FindDigitizerModule( "TestDigitizer" );
	//myDM->Digitize();

	// G4cout<<"capacity "<<fDM->GetModuleCapacity()<<G4endl;

	/* G4int myDigiCollID = fDM->GetDigiCollectionID("TestDigitizerInitializationModule/DigitsCollection");
	 TestDigitsCollection * DC = (TestDigitsCollection*)fDM->GetDigiCollection( myDigiCollID );


	 if (DC)
	    {
	      G4int n_digi = DC->entries();
	      G4cout<<"Digits "<< DC->entries()<<G4endl;
	      for (G4int i=0;i<n_digi;i++)
	      {

	    	  G4cout<< (*DC)[i]->m_edep<<G4endl;
	      }
	    }

	// G4cout<<"Event::Adder"<<G4endl;
	 //TestAdder * myAdder = (TestAdder*)fDM->FindDigitizerModule( "TestAdder" );
	 //myAdder->Digitize();

	 G4int myAdderCollID = fDM->GetDigiCollectionID("TestAdder/DigitsCollection");
	 TestDigitsCollection * DCAdder = (TestDigitsCollection*)fDM->GetDigiCollection( myAdderCollID );


	 if (DCAdder)
	    {
	      G4int n_digi = DCAdder->entries();
	      G4cout<<"Adder "<< DCAdder->entries()<<G4endl;
	      for (G4int i=0;i<n_digi;i++)
	      {

	    	  G4cout<< (*DCAdder)[i]->m_edep<<G4endl;
	      }
	    }


	 G4cout<<"Event::Readout"<<G4endl;

	// TestReadout * myRO = (TestReadout*)fDM->FindDigitizerModule( "TestReadout" );
	// 	myRO->Digitize();

	 	G4int myReadoutCollID = fDM->GetDigiCollectionID("TestReadout/DigitsCollection");
	 TestDigitsCollection * DCRO = (TestDigitsCollection*)fDM->GetDigiCollection( myReadoutCollID );
	 if (DCRO)
	    {
	      G4int n_digi = DCRO->entries();
	      G4cout<<"Readout "<< DCRO->entries()<<G4endl;
	      for (G4int i=0;i<n_digi;i++)
	      {

	    	  G4cout<< (*DCRO)[i]->m_edep<<G4endl;
	      }
	    }




	 //	 DigiMan->List();

	/* G4cout<< "Digitizer " << G4endl;

	 TestDigiManager * fDM = TestDigiManager::GetDMpointer();

	 TestDigitizer * myDM = (TestDigitizer*)fDM->FindDigitizerModule( "testDigitizer" );
	 myDM->Digitize();
	//G4cout<< "Energy " << fEdep <<G4endl;



	/*G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleDColumn(0, 2, fEdep);
	man->AddNtupleRow(0);
*/
}


void TestDigitizer::AddNewDigitizerModule(G4String name)
{
	m_moduleName = name;
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....










