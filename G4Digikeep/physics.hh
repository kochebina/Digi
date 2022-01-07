#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"

class TestPhysicsList : public G4VModularPhysicsList
{
public:
  TestPhysicsList();
  ~TestPhysicsList();
  


};


#endif
