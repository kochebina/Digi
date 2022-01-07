#include "run.hh"

TestRunAction::TestRunAction()
{
}

TestRunAction::~TestRunAction()
{
}


void TestRunAction::BeginOfRunAction(const G4Run* aRun)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->OpenFile("output.root");
  
  man->CreateNtuple("Hits","Hits");
  man->CreateNtupleIColumn("EventID");
  man->CreateNtupleDColumn("edep");
  man->CreateNtupleDColumn("time");
  
  man->FinishNtuple(0);
  
  

	/*man->CreateNtupleDColumn("posX");
	man->CreateNtupleDColumn("posY");
	man->CreateNtupleDColumn("posZ");

	man->FinishNtuple(0);
	*/
	man->CreateNtuple("Singles","Singles");
	man->CreateNtupleIColumn("EventID");
	man->CreateNtupleDColumn("energy");

	man->FinishNtuple(1);


	/*man->CreateNtuple("Digits","Digits");
	man->CreateNtupleIColumn("EventID");
	man->CreateNtupleIColumn("hitID");
	man->CreateNtupleDColumn("TimePulse");

	man->FinishNtuple(2);
*/

}
void TestRunAction::EndOfRunAction(const G4Run* aRun)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->Write();
	man->CloseFile();
	
}
