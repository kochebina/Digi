#ifndef DIGIT_HH
#define DIGIT_HH

#include "G4VTest.hh"
#include "G4TTestCollection.hh"


class TestDigi : public G4VTest
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


typedef G4TTestCollection<TestDigi> TestDigitsCollection;

#endif
