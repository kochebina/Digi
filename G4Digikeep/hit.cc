#include "hit.hh"


TestHit::TestHit() : G4VHit()
{
	Edep = 0.;
}

TestHit::~TestHit()
{
}

TestHit::TestHit(const TestHit& right)
  :G4VHit()
{
  Edep = right.Edep;

}
