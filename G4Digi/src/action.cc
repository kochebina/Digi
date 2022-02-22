#include "action.hh"
#include "run.hh"
#include "event.hh"
#include "stepping.hh"


TestActionInit::TestActionInit()
{
}

TestActionInit::~TestActionInit()
{
}


void TestActionInit::Build() const
{
	TestPrimaryGenerator *generator = new TestPrimaryGenerator();
	SetUserAction(generator);

	TestRunAction *runAction = new TestRunAction();
	SetUserAction(runAction);

	TestEventAction *eventAction = new TestEventAction(runAction);
	SetUserAction(eventAction);

	TestSteppingAction *steppingAction = new TestSteppingAction(eventAction);
	SetUserAction(steppingAction);

}
