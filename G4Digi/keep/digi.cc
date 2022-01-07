#include "digi.hh"


TestDigi::TestDigi() : G4VDigi()
{

}

TestDigi::~TestDigi()
{
}

TestDigi::TestDigi(const TestDigi& right)
  :G4VDigi()
{

	// Energy= right.Energy;
}
