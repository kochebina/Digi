#include "G4DigiManager.hh"
#include "G4SDManager.hh"

#include "event.hh"
#include "TestHit.hh"
#include "TestDigi.hh"
#include "TestDigitizer.hh" //InitializationModule.hh"
//#include "TestAdder.hh"
//#include "TestReadout.hh"

TestEventAction::TestEventAction(TestRunAction*) :
HitsCollectionID(-1), HitsCollectionID2(-1)
{

	G4cout<<"TestEventAction:: constr"<<G4endl;
	//digitizer=new TestDigitizer();

	//digitizer = new TestDigitizer();
	//digitizer->Initilize();


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
	//delete digitizer;
}


void TestEventAction::BeginOfEventAction(const G4Event* evt)
{


	G4cout<<"Begin of Event "<<evt->GetEventID () <<G4endl;
	G4SDManager * SDman = G4SDManager::GetSDMpointer();

	for (int i=0;i< SDman->GetHCtable () ->entries();i++)
		{
		G4cout<<"Entries "<< SDman->GetHCtable () ->GetHCname(i)<<G4endl;
		}

  if ( HitsCollectionID ==-1) {
    HitsCollectionID = SDman->GetCollectionID("SensitiveDetector"); //defined in constructor of SD

  }
  if ( HitsCollectionID2 ==-1) {
      HitsCollectionID2 = SDman->GetCollectionID("SensitiveDetector2"); //defined in constructor of SD

    }


  
}
void TestEventAction::EndOfEventAction(const G4Event* evt)
{
	G4cout<<"End of Event "<<evt->GetEventID () <<G4endl;


	G4cout<<"Hits Collection: "<< HitsCollectionID<< G4endl;
	G4cout<<"Hits Collection: "<< HitsCollectionID2<< G4endl;

	/*G4DigiManager* DigiMan = G4DigiManager::GetDMpointer();

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
*/







	TestDigitizer* testD=TestDigitizer::GetInstance();
	testD->RunDigitizer();





/*

	G4cout<<"Hits Collection: "<< HitsCollectionID<< G4endl;
	G4cout<<"Hits Collection: "<< HitsCollectionID2<< G4endl;


	G4HCofThisEvent* HCE = evt->GetHCofThisEvent();
	G4cout<<HCE->GetCapacity ()<< G4endl;
	//G4cout<<"Hits Collection: "<< HCE->GetHC(0)->GetName()<< G4endl;
	//G4cout<<"Hits Collection: "<< HCE->GetHC(1)->GetName()<< G4endl;

	TestHitsCollection* THC = static_cast<TestHitsCollection*>(HCE->GetHC(HitsCollectionID));




	G4cout<<"Hits Collection: "<< THC->GetName ()<< G4endl;

	TestHitsCollection* THC2 = static_cast<TestHitsCollection*>(HCE->GetHC(HitsCollectionID2));
	G4cout<<"Hits Collection2: "<< THC2->GetName ()<< G4endl;

/*digitizer->RunDigitizer();

	TestDigitizer* testD=TestDigitizer::GetInstance();
	testD->RunDigitizer();
*/

  //	G4cout<<" TestEventAction::EndOfEventAction"<<G4endl;
/*
	 G4int event_id = evt->GetEventID();

	 ///////////////////////////////////
	 //Hits and HitsCollections
	 ///////////////////////////
	 
	 G4HCofThisEvent* HCE = evt->GetHCofThisEvent();



	 G4cout<<"Hits Collection: "<< HCE
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

