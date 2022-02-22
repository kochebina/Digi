#include <vector>

#include "TestDigitizer.hh"
#include "TestDigi.hh"
#include "TestDigitizerMessenger.hh"

#include "TestHit.hh"


#include "G4SystemOfUnits.hh"
//#include "G4EventManager.hh"
//#include "G4Event.hh"
//#include "G4SDManager.hh"
#include "G4DigiManager.hh"
//#include "G4ios.hh"

#include "TestDigitizerInitializationModule.hh"
#include "TestAdder.hh"
#include "TestReadout.hh"

TestDigitizer* TestDigitizer::theDigitizer=0;

//-----------------------------------------------------------------
TestDigitizer* TestDigitizer::GetInstance()
{
  if (!theDigitizer)
    theDigitizer = new TestDigitizer;
  return theDigitizer;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestDigitizer::TestDigitizer()
{
	G4cout<<"TestDigitizer:: constructor"<<G4endl;

	//create a messenger for this class
	fMessenger = new TestDigitizerMessenger(this);



}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TestDigitizer::~TestDigitizer()
{
 delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void TestDigitizer::Initilize()
{

	G4cout<<"TestDigitizer::Initilize"<<G4endl;


	TestDigitizerInitializationModule * myDM = new TestDigitizerInitializationModule( "TestDigitizerInitializationModule" );
	G4DigiManager::GetDMpointer()->AddNewModule(myDM);



}


void TestDigitizer::RunDigitizer()
{


	G4cout<<"TestDigitizer::RunDigitizer"<<G4endl;

	G4DigiManager * fDM = G4DigiManager::GetDMpointer();

	//fDM->GetHC

	//fDM->List();

//	G4cout<<"capacity "<<fDM->GetModuleCapacity()<<G4endl;


	//G4cout<<"test!!!!!!!  "<<fDM->GetDCtable () -> GetDMname (1)<<G4endl;
	//G4cout<<"moduleNameList "<<m_moduleNameList.size()<<G4endl;
	for (G4int i=0; i<(fDM->GetModuleCapacity());i++)
	{
		fDM->Digitize(fDM->GetDCtable()->GetDMname(i));
	}



}




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....










