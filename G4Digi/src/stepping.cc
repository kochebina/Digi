#include "stepping.hh"

TestSteppingAction::TestSteppingAction(TestEventAction* eventAction)
{
	fEventAction = eventAction;
}

TestSteppingAction::~TestSteppingAction()
{
}


void TestSteppingAction::UserSteppingAction(const G4Step* step)
{
	G4double edep = step -> GetTotalEnergyDeposit();

	G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

	const TestDetectorConstruction *detectorConstruction = static_cast<const TestDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

	G4LogicalVolume *fLogVolume= detectorConstruction->GetSDVolume();

	G4LogicalVolume *fLogVolume2= detectorConstruction->GetSDVolume2();

	if (volume!= fLogVolume)
		return;

	//fEventAction-> ..
	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

		G4AnalysisManager *man = G4AnalysisManager::Instance();
		man->FillNtupleIColumn(0, 0, evt);
		man->FillNtupleDColumn(0, 1, edep);
		man->FillNtupleDColumn(0, 2, time);

		man->AddNtupleRow(0);


}
