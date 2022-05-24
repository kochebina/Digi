#ifndef TESTHITATTRIBUTE_HH
#define TESTHITATTRIBUTE_HH

#include "TestHitAttributeMessenger.hh"
#include "globals.hh"

class TestHitAttributeMessenger;

class TestHitAttribute
{
public:
	static TestHitAttribute* GetInstance();

//protected:
	TestHitAttribute();
public:
	~TestHitAttribute();

    void SetInputAttributeFile(G4String name){fInputAttributeFile=name;};

    void ReadFile();

    void IntilizeAllAttributesMaps();

    std::vector<std::pair<G4String,char>> GetHitAttributeVector(){ return fHitAttributeVector;};

    void AddToMapI(G4String, G4int*);
    void AddToMapD(G4String, G4double*);
    void AddToMapS(G4String, G4String*);


private:

     G4String fInputAttributeFile;
     TestHitAttributeMessenger *fMessenger;
     static TestHitAttribute*  theHitAttribute;
public:
     std::vector<std::pair<G4String,char>> fHitAttributeVector;
     //std::vector<std::pair<G4String,char>> fHitALLAttributeVector;
public:
     std::vector<std::pair<G4String,G4int*>> mapHitAttributesI;
     std::vector< std::pair<G4String,G4double*>> mapHitAttributesD;
     std::vector<std::pair<G4String,G4String*>> mapHitAttributesS;


};

#endif
