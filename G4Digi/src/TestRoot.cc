//#include "run.hh"
//#include "contruction.hh"
#include "TestRoot.hh"
#include "TestHitAttribute.hh"

TestRoot::TestRoot()
{
	G4cout<<"TestRoot: constructor"<<G4endl;
	//fHitAttribute= new TestHitAttribute();
}

TestRoot::~TestRoot()
{
	//delete fHitAttribute;

}


void TestRoot::CreateNtuple(G4String name, TestHitAttribute * att)
{
	fHitAttribute=att;
	//fHitAttribute->ReadFile();

	G4cout<<"CreateNTuple"<<G4endl;

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->OpenFile("output.root");
  
	man->CreateNtuple(name, name);

	//add some essential attributes
	man->CreateNtupleSColumn("SDname"); //0
	man->CreateNtupleIColumn("eventID"); //1
	//man->CreateNtupleDColumn("time");

	//G4int newEntriesCount=1; // as already 2 entries by default
	///add users attributes
	for(unsigned int i=0;i< att->fHitAttributeVector.size() ;i++)
	{

		//G4cout<<"something"<<G4endl;

		G4String attName=att->fHitAttributeVector[i].first;
		char attType=att->fHitAttributeVector[i].second;

		G4cout<<attName<<" "<< attType<<G4endl;

		if (attType=='I')
			man->CreateNtupleIColumn(attName);
		if (attType=='D')
			man->CreateNtupleDColumn(attName);
		if (attType=='S')
			man->CreateNtupleSColumn(attName);


	}

	man->FinishNtuple(0);
  
}



void TestRoot::FillNtuple(G4String attName, G4String attValue)
{


	/*//man->FillNtupleIColumn(0, id, attValue);
	G4AnalysisManager *man = G4AnalysisManager::Instance();

	for(unsigned int i=0;i< fHitAttribute->fHitAttributeVector.size() ;i++)
		{

			//G4cout<<"something"<<G4endl;

			//G4String attName=;
			char attType=fHitAttribute->fHitAttributeVector[i].second;

			//G4cout<<attName<<" "<< attType<<G4endl;
/*
			if (attType=='I')
				man->FillNtupleIColumn(0, i, (int)attValue);
			if (attType=='D')
				man->FillNtupleDColumn(0, i, (double)attValue);
			if (attType=='S')
				man->FillNtupleSColumn(0, i, attValue);
	  	  }
*/

}



void TestRoot::WriteAndClose()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->Write();
	man->CloseFile();

}





