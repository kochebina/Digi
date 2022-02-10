#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4SystemOfUnits.hh"

#include "contruction.hh"
#include "physics.hh"
#include "action.hh"

#include "TestDigitizer.hh"

int main(int argc, char** argv)
{
  G4RunManager *runManager = new G4RunManager();

  runManager->SetUserInitialization(new TestDetectorConstruction());
  runManager->SetUserInitialization(new TestPhysicsList());
  runManager->SetUserInitialization(new TestActionInit());
  //runManager->SetUserInitialization(new TestDigitizer());
   runManager->Initialize();
  
   G4UIExecutive *ui = 0;// new G4UIExecutive(argc,argv);

   if(argc == 1)
  {
	  ui = new G4UIExecutive(argc,argv);

  }
  
  
  G4VisManager *visManager = new G4VisExecutive(); 
  visManager->Initialize();

  G4UImanager *UImanager = G4UImanager::GetUIpointer();

   if (!ui)
  	  {
	    
	    G4String command = "/control/execute ";
	    G4String filename = argv[1];
	    UImanager->ApplyCommand(command+filename);

      	  }
   else
     {
       UImanager->ApplyCommand("/control/execute ../vis.mac");
       ui->SessionStart();
       
       delete ui;
       
     }

   /*
  UImanager->ApplyCommand("/vis/open OGL");
  UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
  UImanager->ApplyCommand("/vis/drawVolume");
  UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
  UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
   */

   TestDigitizer* digitizer = TestDigitizer::GetInstance();

 
  delete visManager;
  delete runManager;
  
  return 0;
}
