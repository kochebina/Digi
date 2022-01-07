#include "detector.hh"


TestSensitiveDetector::TestSensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{
	collectionName.insert("testHitCollection");
	collectionID = -1;


}

TestSensitiveDetector::~TestSensitiveDetector()
{
  // delete fHitsCollection;

}

/*void TestSensitiveDetector::TestSensitiveDetector(const G4String& name, const G4String& hitsCollectionName) : G4VSensitiveDetector(name), fHitsCollection(0)
{
	collectionName.insert(hitsCollectionName);
}
*/

void TestSensitiveDetector::Initialize(G4HCofThisEvent* HCE)
{
  
	fHitsCollection = new TestHitsCollection(SensitiveDetectorName,collectionName[0]);

	if (collectionID > 0)
	{
		collectionID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection);
	}

	HCE->AddHitsCollection(collectionID, fHitsCollection);

	//iHit = 0;
	
}

G4bool TestSensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROHits)
{

	//G4cout<<"Lets process hits !!!!!!!!!!!!!!!!!!!!! "<<G4endl;

	G4double edep = aStep->GetTotalEnergyDeposit();
	

	if (edep == 0.) return false;

	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

	G4double time= preStepPoint->GetGlobalTime();
 
	/*	const G4VTouchable *touchablePre = aStep->GetPreStepPoint()->GetTouchable();
	//const G4VTouchable *touchablePost = aStep->GetPreStepPoint()->GetTouchable();


	G4VPhysicalVolume *physVolPre = touchablePre->GetVolume();
	//G4VPhysicalVolume *physVolPost = touchablePre->GetVolume();

	G4cout<<physVolPre->GetName ()<<G4endl;
	//G4cout<<physVolPost->GetName ()<<G4endl;

	//G4int copyNo = touchable->GetCopyNumber();

	*/


	///do something with hit here

	TestHit* aHit = new TestHit();
	aHit->SetEdep(edep);
	aHit->SetTime(time);
	fHitsCollection->insert(aHit);

	/*
	if(iHit == 0)
	{
		aHit->SetEdep(edep);
		aHit->SetTotalEdep(0.);
		aHit->AddTotalEdep(edep);

		fHitsCollection->insert(aHit);



	}
	else
	{
		aHit->SetEdep(edep);
		aHit->AddTotalEdep(edep);

		fHitsCollection->insert(aHit);
	}
*/
	//fill root file with step/hits info

	//G4cout<<"Filling histo "<<G4endl;
	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0, 0, evt);
	man->FillNtupleDColumn(0, 1, edep);
	man->FillNtupleDColumn(0, 2, time);

	man->AddNtupleRow(0);



   /* G4Track *track = aStep->GetTrack();

    track->SetTrackStatus(fStopAndKill);

	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

	G4ThreeVector posPhoton = preStepPoint->GetPosition();

	//G4cout<< ""<< G4endl;
	//G4cout<<"Position"<< posPhoton <<G4endl;

	const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

	G4int copyNo = touchable->GetCopyNumber();

	//G4cout << "Copy no: "<< copyNo << G4endl;

	G4VPhysicalVolume *physVol = touchable->GetVolume();
	G4ThreeVector posDetector = physVol->GetTranslation();

	G4cout << "Pos: "<<  posDetector<< G4endl;

	G4int	evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0, 0,evt);
	man->FillNtupleDColumn(0, 1,posDetector[0]);
	man->FillNtupleDColumn(0, 2,posDetector[1]);
	man->FillNtupleDColumn(0, 3,posDetector[2]);
*/

	return true; //added by me
}

void TestSensitiveDetector::EndOfEvent(G4HCofThisEvent* HCE)
{

	//G4cout<<" TestSensitiveDetector::EndOfEvent"<<G4endl;

	static G4int HCID = -1;
	  if(HCID<0)
	    {
	      HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
	    }
	  HCE->AddHitsCollection(HCID,fHitsCollection); //to use later in EndEventAction

	  /*
	//G4cout<< HCE->GetHC(0)->GetName()<< G4endl;


	//here we can process hitcollection of this event

	//TestHit *aHit=(*fHitsCollection)[0];


	/*TestHit *aHit= new TestHit();

	//G4double totalEnergy=0;
	aHit->SetTotalEdep(0.);

	G4cout<<"Here "<< aHit->GetTotalEdep()<<G4endl;

	for (G4int i = 0; i<fHitsCollection->entries(); i++ )
	{

		aHit = (*fHitsCollection)[i];

	//	totalEnergy += aHit->GetEdep();
		G4cout<<aHit->GetEdep() << G4endl;
		G4double en = aHit->GetEdep() ;

		aHit->AddTotalEdep(en);

		G4cout << aHit->GetTotalEdep() << G4endl;
	}
	G4cout << aHit->GetTotalEdep() << G4endl;

/*	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0, 0, evt);
	man->FillNtupleDColumn(0, 1, edep);
*/

}


