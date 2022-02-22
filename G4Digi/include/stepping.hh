#ifndef STEPPING_HH
#define STEPPING_HH


#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "contruction.hh"
#include "event.hh"

class TestSteppingAction : public G4UserSteppingAction
{
public:
	TestSteppingAction(TestEventAction* eventAction);
	~TestSteppingAction();

	virtual void UserSteppingAction(const G4Step*);

private:
	TestEventAction *fEventAction;

};

#endif
