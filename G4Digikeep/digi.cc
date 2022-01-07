#include "testt.hh"


TestDigi::TestDigi() : G4VTest()
{

}

TestDigi::~TestDigi()
{
}

TestDigi::TestDigi(const TestDigi& right)
  :G4VTest()
{

	 Energy= right.Energy;
}
