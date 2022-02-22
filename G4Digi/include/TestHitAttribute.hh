#ifndef TESTHITATTRIBUTE_HH
#define TESTHITATTRIBUTE_HH

#include "TestHitAttributeMessenger.hh"
#include "globals.hh"

class TestHitAttributeMessenger;

class TestHitAttribute
{
//public:
//	static TestHitAttribute* GetInstance();

public:
	TestHitAttribute();
	~TestHitAttribute();

    void SetInputAttributeFile(G4String name){fInputAttributeFile=name;};

    void ReadFile();


private:

     G4String fInputAttributeFile;
     TestHitAttributeMessenger *fMessenger;
public:
     std::vector<G4String> fHitAttributeVector;




};

#endif
