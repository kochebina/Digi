#include "event.hh"

TestEventAction::TestEventAction(TestRunAction*)
{
	fEdep = 0. ;
}

TestEventAction::~TestEventAction()
{
}


void TestEventAction::BeginOfEventAction(const G4Event*)
{
	fEdep = 0. ;



}
void TestEventAction::EndOfEventAction(const G4Event*)
{
	/*G4cout<< "Energy " << fEdep <<G4endl;

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man ->FillNtupleDColumn(1,0,fEdep);
	man->AddNtupleRow(1); //1 or 2??
*/
}
