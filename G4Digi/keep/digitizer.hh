#ifndef DIGITIZER_HH
#define DIGITIZER_HH

#include "G4VDigitizerModule.hh"
#include "G4RunManager.hh"
#include "g4root.hh"


#include "digi.hh"



class TestDigitizer : public G4VDigitizerModule
{
public:
	TestDigitizer(G4String name);
	~TestDigitizer();

	virtual void Digitize();

private:
	TestDigiCollection*  DigiCollection;
	 // G4double TotalEnergy; // for CAL analysis


};

#endif
