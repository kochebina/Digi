#ifndef TestRoot_HH
#define TestRoot_HH


//#include "G4UserTestRootAction.hh"
#include "g4root.hh"
#include "globals.hh"

#include "TestHitAttribute.hh"

//class TestDetectorConstruction;
//class TestDigitizer;
//class TestHitAttribute;

class TestRoot
{
public:
  TestRoot();
  ~TestRoot();


  void CreateNtuple(G4String name, TestHitAttribute * att);
 // void FillNtuple();
  void FillNtuple(G4String attName, G4String attValue);
  void WriteAndClose();




protected:
  //fHitAttribute;
  TestHitAttribute * fHitAttribute;
};



#endif
