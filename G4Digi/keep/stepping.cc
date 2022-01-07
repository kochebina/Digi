#include "stepping.hh"

TestSteppingAction::TestSteppingAction(TestEventAction* eventAction)
{
	//fEventAction = eventAction;
}

TestSteppingAction::~TestSteppingAction()
{
}

void TestSteppingAction::UserSteppingAction(const G4Step* step)
{
	/*G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();


	const TestDetectorConstruction *detConst = static_cast<const TestDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

	G4LogicalVolume *fScoringVolume = detConst->GetScoringVolume();

	if (volume != fScoringVolume)
		return;
*/

/*

	G4double edep = step->GetTotalEnergyDeposit();
	fEventAction->AddEdep(edep);
	G4cout<<"edep "<<edep<<G4endl;
*/
}
