#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"
#include "generator.hh"
#include "run.hh"

class TestActionInit : public G4VUserActionInitialization
{
public:
  TestActionInit();
  ~TestActionInit();


  virtual void Build() const;

  
};



#endif
