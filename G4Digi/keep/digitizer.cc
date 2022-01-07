#include "G4DigiManager.hh"
#include "CLHEP/Random/RandGauss.h"

#include "digitizer.hh"
#include "hit.hh"

TestDigitizer::TestDigitizer(G4String name) : G4VDigitizerModule(name)
{
	G4String colName = "DigiCollection";
	collectionName.push_back(colName);

	//	Energy_Threshold = 120.*keV;
}

TestDigitizer::~TestDigitizer()
{
}


void TestDigitizer::Digitize()
{
	G4cout<<"TestDigitizer::Digitize"<<G4endl;

	DigiCollection = new TestDigiCollection ("testDigitizer","DigiCollection"); // to create the Digi Collection

	G4DigiManager* DigiMan = G4DigiManager::GetDMpointer();

	G4int HitsCollectionID;
	HitsCollectionID = DigiMan->GetHitsCollectionID("testHitCollection");

	TestHitsCollection* THC = 0;
	THC = (TestHitsCollection*)(DigiMan->GetHitsCollection(HitsCollectionID)); // get our hit collection


	G4AnalysisManager *man = G4AnalysisManager::Instance();

	if (THC)
	{
		int n_hit = THC->entries();
		G4cout << "Number of tracker hits in this event =  " << n_hit << G4endl;
		G4double Edep=0;
		G4double Time=0;

		G4int nbins=100;

		G4double TimePulse;//[nbins];

		G4int	evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

		//G4int NStrip, NPlane, IsX;

		// This is a cycle on all the hits of this event

		for (int i=0;i<n_hit;i++)
		{
			Edep = (*THC)[i]->GetEdep();
			Time = (*THC)[i]->GetTime();

			//CLHEP::RandLandau::shootArray(100, TimePulse*);


		//	for (int j=0; j<nbins; j++)
		//	{
			//	TimePulse = CLHEP::RandGauss::shoot( Time, Time*0.1 );
				//man ->FillNtupleDColumn(2,0,TimePulse);

		//	}

		/*	man ->FillNtupleDColumn(2,0, evt);
			man ->FillNtupleDColumn(2,1,n_hit);

			//man ->FillNtupleDColumn(2,2,TimePulse);
			man->AddNtupleRow(2);
*/
		}

		//G4cout<< "Total energy = "<< TotEdep<< G4endl;
		/*G4AnalysisManager *man = G4AnalysisManager::Instance();
		man ->FillNtupleDColumn(1,0,TotEdep);
		man->AddNtupleRow(1);
	*/
	}








	 //TesttsCollection = new TestDigitsCollection
	  //	("TestDigitizer","TesttsCollection"); // to create the Test Collection

}

