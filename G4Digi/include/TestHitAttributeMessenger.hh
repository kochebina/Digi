#ifndef TestHitAttributeMessenger_HH
#define TestHitAttributeMessenger_HH

#include "G4UImessenger.hh"
//#include "TestDigi.hh"
#include "globals.hh"

class TestHitAttribute;
class G4UIcmdWithAString;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class TestHitAttributeMessenger : public G4UImessenger
{
public:
 TestHitAttributeMessenger();
  TestHitAttributeMessenger(TestHitAttribute*);
  ~TestHitAttributeMessenger();

  void SetNewValue(G4UIcommand*, G4String);


private:
  TestHitAttribute* m_HitAtt;
  G4UIdirectory           *Dir;
  G4UIcmdWithAString*         SetInputAttributeFileCmd;


};
#endif
