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
//      ------------ TestDigitizerInitializationModule  ------
//           by   F.Longo, R.Giannitrapani & G.Santin (13 nov 2000)
//
// ************************************************************

#include <vector>

#include "TestDigitizerInitializationModule.hh"
#include "TestDigi.hh"
//#include "digitizerMessenger.hh"

#include "TestHit.hh"


#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4DigiManager.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestDigitizerInitializationModule::TestDigitizerInitializationModule(G4String name)
  :G4VDigitizerModule(name)
{


  G4String colName = "DigitsCollection";
  collectionName.push_back(colName);
  Energy = 0;

//create a messenger for this class
 // digiMessenger = new TestDigitizerInitializationModuleMessenger(this);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestDigitizerInitializationModule::~TestDigitizerInitializationModule()
{
 // delete digiMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void TestDigitizerInitializationModule::Digitize()
{

	G4cout<<"DigitizerInitialization::Digitize()"<<G4endl;
	DigitsCollection = new TestDigitsCollection ("TestDigitizerInitializationModule","DigitsCollection"); // to create the Digi Collection
  

	G4DigiManager* DigiMan = G4DigiManager::GetDMpointer();
 /* TestDigiManager* DigiMan = 0;

   DigiMan = (TestDigiManager*)(DigiMan->GetDMpointer());
*/
  G4int HCID;
  
  HCID = DigiMan->GetHitsCollectionID("SensitiveDetector");
  G4cout<<HCID<<G4endl;
  TestHitsCollection* THC = 0;
  THC = (TestHitsCollection*) (DigiMan->GetHitsCollection(HCID));

  

  if (THC)
    {
      G4int n_hit = THC->entries();

      for (G4int i=0;i<n_hit;i++)
	{

    	  if((*THC)[i]->GetEdep() !=0 )
    	  {
    		 // G4cout<<"in Digitizer "<< (*THC)[i]->GetEdep()<<G4endl;
    		  TestDigi* Digi = new TestDigi();
    		  Digi->SetPDGEncoding( (*THC)[i]->GetPDGEncoding() );
    		  Digi->SetEdep( (*THC)[i]->m_edep );
    		  Digi->SetStepLength( (*THC)[i]->m_stepLength );
    		  Digi->SetTime( (*THC)[i]->m_time );
    		  Digi->SetGlobalPos( (*THC)[i]->m_pos );
    		  //Digi->SetLocalPos( localPosition );
    		  Digi->SetProcess( (*THC)[i]->m_process );
    		  Digi->SetTrackID( (*THC)[i]->m_trackID );
    		  // Seb Modif 5/4/2016
    		  Digi->SetTrackLength( (*THC)[i]->m_trackLength );
    		  Digi->SetTrackLocalTime( (*THC)[i]->m_trackLocalTime );
    		  Digi->SetMomentumDir( (*THC)[i]->m_momDir );
    		  Digi->SetParentID( (*THC)[i]->m_parentID );
    		  DigitsCollection->insert(Digi);

    	  }



		}
   }

  StoreDigiCollection(DigitsCollection);
  
  /*G4int DCID = -1;
  if(DCID<0)
    { 
      //	  DigiMan->List();
      DCID = DigiMan->GetDigiCollectionID("TestDigitizerInitializationModule/DigitsCollection");
    }
  */
  
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....










