#include "G4DigiManager.hh"
#include "G4SDManager.hh"

#include "event.hh"
#include "hit.hh"
//#include "digi.hh"
//#include "digitizer.hh"

TestEventAction::TestEventAction(TestRunAction*) : HitsCollectionID(-1)
{


	/*TestDigitizer * myDM = new TestDigitizer( "testDigitizer" );
	G4DigiManager::GetDMpointer()->AddNewModule(myDM);
*/

}

TestEventAction::~TestEventAction()
{
}


void TestEventAction::BeginOfEventAction(const G4Event* evt)
{
  G4SDManager * SDman = G4SDManager::GetSDMpointer();

  if ( HitsCollectionID ==-1) {
    HitsCollectionID = SDman->GetCollectionID("testHitCollection"); //defined in constructor of SD
  }
  
}
void TestEventAction::EndOfEventAction(const G4Event* evt)
{

  //	G4cout<<" TestEventAction::EndOfEventAction"<<G4endl;

	 G4int event_id = evt->GetEventID();

	 ///////////////////////////////////
	 //Hits and HitsCollections
	 ///////////////////////////
	 
	 G4HCofThisEvent* HCE = evt->GetHCofThisEvent();

	 //G4cout<< HCE->GetHC(HitsCollectionID)->GetName()<< G4endl;

	 TestHitsCollection* THC = 0;//(TestHitsCollection*)(HCE->GetHC(HitsCollectionID));;


	 if (HCE)
	 {
		 THC = (TestHitsCollection*)(HCE->GetHC(HitsCollectionID));
		 if (THC)
		 {
		   int n_hit = THC->entries();
			 G4double Edep=0;
			 G4double TotEdep=0;

			 // This is a cycle on all the hits of this event

			 for (int i=0;i<n_hit;i++)
			 {
				 Edep = (*THC)[i]->GetEdep();
				 TotEdep += Edep;
			 }

			 G4AnalysisManager *man = G4AnalysisManager::Instance();
			 man ->FillNtupleIColumn(1,0,event_id);
			 man ->FillNtupleDColumn(1,1,TotEdep);

			 man->AddNtupleRow(1);
		 }
	 }

	 ////////////////////////////
	 //Digits and DigiCollections
	 ///////////////////////////

	/* G4cout<< "Digitizer " << G4endl;

	 G4DigiManager * fDM = G4DigiManager::GetDMpointer();

	 TestDigitizer * myDM = (TestDigitizer*)fDM->FindDigitizerModule( "testDigitizer" );
	 myDM->Digitize();
	//G4cout<< "Energy " << fEdep <<G4endl;



	/*G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleDColumn(0, 2, fEdep);
	man->AddNtupleRow(0);
*/

}

