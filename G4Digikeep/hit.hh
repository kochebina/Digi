#ifndef HIT_HH
#define HIT_HH

#include "G4VHit.hh"
#include "G4THitsCollection.hh"


class TestHit : public G4VHit
{
public:
	TestHit();
	~TestHit();
	TestHit(const TestHit&);

private:
	G4double Edep;

public:
	inline void AddEnergy(G4double energy) {Edep += energy;};

};


typedef G4THitsCollection<TestHit> TestHitsCollection;

#endif
