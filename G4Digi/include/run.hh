#ifndef RUN_HH
#define RUN_HH


#include "G4UserRunAction.hh"
#include "g4root.hh"
#include "globals.hh"

class TestDetectorConstruction;
class TestDigitizer;
class TestHitAttribute;

class TestRunAction : public G4UserRunAction
{
public:
  TestRunAction();
  ~TestRunAction();


  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);
  
protected:
  TestDigitizer *digitizer;
  TestHitAttribute *fHitAttribute;
//  G4AnalysisManager *man;
//  G4AnalysisManager *man2;

};



#endif
