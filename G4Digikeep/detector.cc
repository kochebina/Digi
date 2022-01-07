#include "detector.hh"


TestSensitiveDetector::TestSensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{
}

TestSensitiveDetector::~TestSensitiveDetector()
{
}

void TestSensitiveDetector::Initialize(G4HCofThisEvent*)
{
 // HitsCollection = new TestHitsCollection(SensitiveDetectorName,collectionName[0]);

}

G4bool TestSensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROHits)
{

	G4cout<<"Lets process hits !!!!!!!!!!!!!!!!!!!!! "<<G4endl;

	G4double edep = 0.;
	edep = aStep->GetTotalEnergyDeposit();
	if (edep == 0.) return false;



	G4int	evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0, 0,evt);
	man->FillNtupleDColumn(0, 1, edep);


	TestHit* testHit = new TestHit;
	testHit->AddEnergy(edep);


	//HitsCollection->insert(testHit);


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
	man->AddNtupleRow(0);

	return true; //added by me
}

void TestSensitiveDetector::EndOfEvent(G4HCofThisEvent* HCE)
{
 // HitsCollection = new TestHitsCollection(SensitiveDetectorName,collectionName[0]);

}


