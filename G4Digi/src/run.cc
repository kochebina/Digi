#include "run.hh"
#include "contruction.hh"
#include "TestDigitizer.hh"
#include "TestHitAttribute.hh"
#include "TestRoot.hh"

TestRunAction::TestRunAction()
{
	G4cout<<"TestRunAction: constructor"<<G4endl;

	//fHitAttribute= new TestHitAttribute();
	fHitAttribute=TestHitAttribute::GetInstance();
	digitizer = new TestDigitizer();
	digitizer->Initilize();
	fRoot=new TestRoot();


}

TestRunAction::~TestRunAction()
{
	delete digitizer;
	delete fHitAttribute;
	delete fRoot;
}


void TestRunAction::BeginOfRunAction(const G4Run* aRun)
{
	G4cout<<"Begin of run"<<G4endl;
	fHitAttribute->ReadFile();


	fRoot->CreateNtuple("Hits",fHitAttribute);


 /* G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->OpenFile("output.root");
  
  man->CreateNtuple("Hits","Hits");
*/

	/*

  for(G4int i=0;i<fHitAttribute->HitAttributeVector.size();i++)
  	  {
	  	  G4cout<<"something"<<G4endl;


  	  }
  /*man->CreateNtupleIColumn("EventID");
  man->CreateNtupleDColumn("edep");
  man->CreateNtupleDColumn("time");
  
  man->FinishNtuple(0);
  
  


	/*man->CreateNtupleDColumn("posX");
	man->CreateNtupleDColumn("posY");
	man->CreateNtupleDColumn("posZ");

	man->FinishNtuple(0);
	*/
/*	man->CreateNtuple("Singles","Singles");
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

	fRoot->WriteAndClose();
	

	/*G4AnalysisManager *man2 = G4AnalysisManager::Instance();
	man2->Write();
		man2->CloseFile();
	*/
}
