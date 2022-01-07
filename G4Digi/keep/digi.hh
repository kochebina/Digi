#ifndef DIGIT_HH
#define DIGIT_HH

#include "G4VDigi.hh"
#include "G4TDigiCollection.hh"


class TestDigi : public G4VDigi
{
public:
	TestDigi();
	~TestDigi();
	TestDigi(const TestDigi&);

private:

	G4double Energy;

public:
	inline void SetEnergy(G4double Ene)  {Energy = Ene;};
	 inline G4double GetEnergy()  {return Energy;};

};


typedef G4TDigiCollection<TestDigi> TestDigiCollection;

#endif
