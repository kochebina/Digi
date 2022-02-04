#include "G4DigiManager.hh"
#include "G4SDManager.hh"

#include "event.hh"
#include "TestHit.hh"
#include "TestDigi.hh"
#include "TestDigitizer.hh" //InitializationModule.hh"
//#include "TestAdder.hh"
//#include "TestReadout.hh"

TestEventAction::TestEventAction(TestRunAction*) : HitsCollectionID(-1)
{


	//digitizer=new TestDigitizer();

	//digitizer = new TestDigitizer();
	digitizer->Initilize();


	/*TestDigitizerInitializationModule * myDM = new TestDigitizerInitializationModule( "TestDigitizerInitializationModule" );
	G4DigiManager::GetDMpointer()->AddNewModule(myDM);

	TestAdder * myAdder = new TestAdder( "TestAdder" );
	G4DigiManager::GetDMpointer()->AddNewModule(myAdder);

	TestReadout * myReadout = new TestReadout( "TestReadout" );
	G4DigiManager::GetDMpointer()->AddNewModule(myReadout);
	*/

}

TestEventAction::~TestEventAction()
{
	delete digitizer;
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

	digitizer->RunDigitizer();

  //	G4cout<<" TestEventAction::EndOfEventAction"<<G4endl;
/*
	 G4int event_id = evt->GetEventID();

	 ///////////////////////////////////
	 //Hits and HitsCollections
	 ///////////////////////////
	 
	 G4HCofThisEvent* HCE = evt->GetHCofThisEvent();



	 G4cout<<"Hits Collection: "<< HCE->GetHC(HitsCollectionID)->GetName()<< G4endl;

	 TestHitsCollection* THC = 0;//(TestHitsCollection*)(HCE->GetHC(HitsCollectionID));;


	 if (HCE)
	 {
		 THC = (TestHitsCollection*)(HCE->GetHC(HitsCollectionID));
		 //G4cout<<"entries "<< THC->entries ()<< G4endl;

		 if (THC)
		 {
		G4cout<<"Hits "<< THC->entries ()<< G4endl;
		   int n_hit = THC->entries();
			 G4double Edep=0;
			 G4double TotEdep=0;

			 // This is a cycle on all the hits of this event

			 for (int i=0;i<n_hit;i++)
			 {
				 G4cout<<(*THC)[i]->GetEdep()<< G4endl;
				 Edep = (*THC)[i]->GetEdep();
				// TotEdep += Edep;
			 }

			/* G4AnalysisManager *man = G4AnalysisManager::Instance();
			 man ->FillNtupleIColumn(1,0,event_id);
			 man ->FillNtupleDColumn(1,1,TotEdep);

			 man->AddNtupleRow(1);
			 */
/*		 }
*/ //}

	 ////////////////////////////
	 //Digits and DigiCollections
	 ///////////////////////////



	/* //TestDigiManager* DigiMan = TestDigiManager::GetDMpointer();
	G4DigiManager * fDM = G4DigiManager::GetDMpointer();
	 //TestDigiManager* fDM = 0;
	// fDM = (TestDigiManager*)(fDM->GetDMpointer());


	fDM->List();

	//	initialiosation
	//fDM->Initialize();

	//	loop over digitizer modules

	for (int i=0; i< fDM->GetModuleCapacity();i++)
	{
		 G4cout<<"capacity "<<fDM->GetModuleCapacity()<<G4endl;


	}



	 fDM->Digitize("TestDigitizerInitializationModule");
	 fDM->Digitize("TestAdder");
	 fDM->Digitize("TestReadout");

	//G4cout<<"Event::Digitize"<<G4endl;
	//TestDigitizer * myDM = (TestDigitizer*)fDM->FindDigitizerModule( "TestDigitizer" );
	//myDM->Digitize();

	// G4cout<<"capacity "<<fDM->GetModuleCapacity()<<G4endl;

	 G4int myDigiCollID = fDM->GetDigiCollectionID("TestDigitizerInitializationModule/DigitsCollection");
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

