

#ifndef TestDetectorConstructionMessenger_h
#define TestDetectorConstructionMessenger_h 1

#include "G4UImessenger.hh"
//#include "G4UIcmdWithAString.hh"
#include "globals.hh"
#include "G4UIdirectory.hh"

//#include "TestDetectorConstruction.hh"


class TestDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithAString;
//class G4UIcmdWithADoubleAndUnit;
//class G4UIcmdWithAString;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class TestDetectorConstructionMessenger: public G4UImessenger
{
public:
  TestDetectorConstructionMessenger(TestDetectorConstruction*);
  ~TestDetectorConstructionMessenger();
  
  inline void SetNewValue(G4UIcommand*, G4String);
  
  //G4bool CheckNameConflict(const G4String& name); //??




private:
  TestDetectorConstruction* Detector;

  G4UIdirectory           *Dir;

  G4UIcmdWithAString*         SetMaterialCmd;


};

#endif


