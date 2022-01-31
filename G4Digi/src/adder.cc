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

#include <vector>

#include "adder.hh"
#include "digi.hh"
//#include "AdderMessenger.hh"

#include "hit.hh"


#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4DigiManager.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestAdder::TestAdder(G4String name)
  :G4VDigitizerModule(name)
{


  G4String colName = "AdderCollection";
  collectionName.push_back(colName);
  Energy = 0;

//create a messenger for this class
  //digiMessenger = new TestAdderMessenger(this);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestAdder::~TestAdder()
{
 // delete digiMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void TestAdder::Digitize()
{

	G4cout<<"Adder::Digitize()"<<G4endl;
  AdderCollection = new TestDigitsCollection("TestAdder","AdderCollection"); // to create the Digi Collection
  
  G4DigiManager* DigiMan = G4DigiManager::GetDMpointer();
  

  G4int HCID; // HitCollection

  //G4int THCID; // TrackerCollection
  //G4int CHCID; // CalorimeterCollection
  //G4int AHCID; // AnticoincidenceCollection

 //TotalEnergy = 0.; // at each event
  
  // TKR Hits collection
  
 // G4cout<<"From HitsCollection"<<G4endl;
  //HCID = DigiMan->GetHitsCollectionID("testHitCollection");
 HCID = DigiMan->GetDigiCollectionID("TestDigitizer/DigitsCollection");
  TestHitsCollection* THC = 0;
  THC = (TestHitsCollection*) (DigiMan->GetHitsCollection(HCID));

  TestDigi* Digi = new TestDigi();

  if (THC)
     {
	  G4int n_hit = THC->entries();
	  Energy=0;
	  for (G4int i=0;i<n_hit;i++)
	  {


		  Energy+=(*THC)[i]->m_edep;
	  }
	  Digi->SetEdep(Energy);

	  AdderCollection->insert(Digi);
     }

  
  StoreDigiCollection(AdderCollection);

  G4int DCID = -1;
  if(DCID<0)
    { 
      //	  DigiMan->List();
      DCID = DigiMan->GetDigiCollectionID("TestAdder/AdderCollection");
    }
  

}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....










