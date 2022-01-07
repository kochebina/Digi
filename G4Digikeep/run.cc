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
	man->CreateNtupleIColumn("Event");
	man->CreateNtupleDColumn("edep");

	man->FinishNtuple(0);

	/*man->CreateNtupleDColumn("posX");
	man->CreateNtupleDColumn("posY");
	man->CreateNtupleDColumn("posZ");

	man->FinishNtuple(0);
/*
	man->CreateNtuple("Scoring","Scoring");
	man->CreateNtupleDColumn("fEdep");

	man->FinishNtuple(1);
*/
}
void TestRunAction::EndOfRunAction(const G4Run* aRun)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->Write();
	man->CloseFile();
}
