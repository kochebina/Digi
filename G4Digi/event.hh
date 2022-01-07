#ifndef EVENT_HH
#define EVENT_HH


#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "g4root.hh"

#include "run.hh"


class TestEventAction : public G4UserEventAction
{
public:
  TestEventAction(TestRunAction*);
  ~TestEventAction();


  virtual void BeginOfEventAction(const G4Event*);
  virtual void EndOfEventAction(const G4Event*);


private:
  
  G4int HitsCollectionID;

};



#endif
