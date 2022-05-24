#ifndef TestDigitizer_h
#define TestDigitizer_h 1

//#include "G4VDigitizerModule.hh"
#include "TestDigi.hh"
#include "globals.hh"

//#include "G4UImessenger.hh"
//#include "g4std/vector"

class TestDigitizerMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class TestDigitizer
{
public:
	static TestDigitizer* GetInstance();

public:
  
	TestDigitizer();
  ~TestDigitizer();
  
  void Initilize();

  void RunDigitizer();

  void SaveDigits();

  void SetNewModuleName(G4String name){m_moduleName=name;}


 // void Digitize();



private:

  G4String m_moduleName;

  TestDigitizerMessenger *fMessenger;
  
  static TestDigitizer*  theDigitizer;



};

#endif








