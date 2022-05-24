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


	G4cout<<"!!!! TestDigitizer::RunDigitizer"<<G4endl;

	G4DigiManager * fDM = G4DigiManager::GetDMpointer();

	//fDM->GetHC

	fDM->List();

//	G4cout<<"capacity "<<fDM->GetModuleCapacity()<<G4endl;


	//G4cout<<"test!!!!!!!  "<<fDM->GetDCtable () -> GetDMname (1)<<G4endl;
	//G4cout<<"moduleNameList "<<m_moduleNameList.size()<<G4endl;
	for (G4int i=0; i<(fDM->GetModuleCapacity());i++)
	{
		fDM->Digitize(fDM->GetDCtable()->GetDMname(i));
	}

	SaveDigits();


}

void TestDigitizer::SaveDigits()
{


	G4cout<<"TestDigitizer::SaveDigi"<<G4endl;

	G4DigiManager * fDM = G4DigiManager::GetDMpointer();
	 fDM->List();
	//TestDigitsCollection* singleDigiCollection = new TestDigitsCollection("CrystalSD","DigitsCollection");

	//G4cout<<singleDigiCollection->entries()<<G4endl;



	// G4int myDigiCollID = fDM->GetDigiCollectionID("TestAdder/DigitsCollection");
	 //G4cout<< myDigiCollID <<G4endl;

	 G4int lastDCID=fDM->GetDCtable()->entries() -1 ;
	 G4cout << "digi collecion " <<lastDCID << G4endl;

	 for (int i = 0; i< fDM->GetDCtable()->entries(); i++)
	 {
		 G4cout<<fDM->GetDCtable()->GetDMname(i)<<" "<< fDM->GetDCtable()->GetDCname(i)<<G4endl;
	 }
	TestDigitsCollection * DC = (TestDigitsCollection*)fDM->GetDigiCollection( lastDCID );

	  G4cout<<"DC = "<< DC->GetName()<<G4endl;

	  if(DC) {
		  G4cout << "Total Digits " << DC->entries() << G4endl;
		G4int n_digi =  DC->entries();
		//G4int NStrip, NPlane, IsX;
		for (G4int i=0;i<n_digi;i++) {
		  // Here we put the digi data in a an ASCII file for
		  // later analysis
			G4cout<<(*DC)[i]->GetEdep()<<G4endl; //GetStripNumber()


			/* NStrip = (*DC)[i]->GetStripNumber();
		  NPlane = (*DC)[i]->GetPlaneNumber();
		  IsX = (*DC)[i]->GetPlaneType();

		  (*outFile) << std::setw(7) << event_id << " " << NStrip <<
		   	" " << NPlane << " " << IsX << " " << G4endl;
		   	*/
		}
	      }

}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....










