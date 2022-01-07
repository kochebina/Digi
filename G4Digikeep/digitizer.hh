#ifndef DIGITIZER_HH
#define DIGITIZER_HH

#include "G4VTesttizerModule.hh"


class TestDigitizer : public G4VTesttizerModule
{
public:
	TestDigitizer(G4String name);
	~TestDigitizer();

	//virtual void Testtize();

private:
	//GammaRayTelTesttsCollection*  TesttsCollection;
	 // G4double TotalEnergy; // for CAL analysis


};

#endif
