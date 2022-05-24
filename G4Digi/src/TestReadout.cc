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
//      ------------ TestReadout  ------
//           by   F.Longo, R.Giannitrapani & G.Santin (13 nov 2000)
//
// ************************************************************

#include <vector>

#include "TestReadout.hh"
#include "TestDigi.hh"
//#include "ReadoutMessenger.hh"


#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4DigiManager.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestReadout::TestReadout(G4String name)
  :G4VDigitizerModule(name)
{


  G4String colName = "DigitsCollection";
  collectionName.push_back(colName);
  Energy = 0;

//create a messenger for this class
  //digiMessenger = new TestReadoutMessenger(this);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestReadout::~TestReadout()
{
 // delete digiMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void TestReadout::Digitize()
{

	//G4cout<<"Readout::Digitize()"<<G4endl;
  DigitsCollection = new TestDigitsCollection("TestReadout","DigitsCollection"); // to create the Digi Collection
  
  G4DigiManager* DigiMan = G4DigiManager::GetDMpointer();
  /*TestDigiManager* DigiMan = 0;

   DigiMan = (TestDigiManager*)(DigiMan->GetDMpointer());
*/

  //DigiMan->List();

  G4int HCID; // HitCollection

 // G4cout<<"From HitsCollection"<<G4endl;
//  HCID = DigiMan->GetHitsCollectionID("testHitCollection");
  HCID = DigiMan->GetDigiCollectionID("TestReadout/DigitsCollection");
 // G4cout<<HCID<<G4endl;

  TestDigitsCollection* THC = 0;
  THC = (TestDigitsCollection*) (DigiMan->GetDigiCollection(HCID-1));

 // G4cout<<THC->entries()<<G4endl;

	TestDigi* Digi = new TestDigi();

  if (THC)
     {
	  G4int n_hit = THC->entries();
	  for (G4int i=0;i<n_hit;i++)
	  {


		  Energy=(*THC)[i]->m_edep*10;
	  }
	  Digi->SetEdep(Energy);

	  DigitsCollection->insert(Digi);
     }

  
  StoreDigiCollection(DigitsCollection);

}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....










