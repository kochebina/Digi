//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
//
// 
// ------------------------------------------------------------
//      GEANT 4 class header file
//      CERN Geneva Switzerland
//
//
//      ------------ TestDigitizerMessenger  ------
//           by F.Longo, G.Santin & R.Giannitrapani (29 nov 2001) 
//
// ************************************************************

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef TestDigitizerMessenger_h
#define TestDigitizerMessenger_h 1

#include "G4UImessenger.hh"
//#include "G4UIcmdWithAString.hh"
#include "globals.hh"

//#include "TestDigitizer.hh"


class TestDigitizer;
class G4UIdirectory;
class G4UIcmdWithAString;
//class G4UIcmdWithADoubleAndUnit;
//class G4UIcmdWithAString;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class TestDigitizerMessenger: public G4UImessenger
{
public:
  TestDigitizerMessenger(TestDigitizer*);
  ~TestDigitizerMessenger();
  
  void SetNewValue(G4UIcommand*, G4String);
  
  //G4bool CheckNameConflict(const G4String& name); //??

  private:
    //! Dumps the list of modules that the user can insert into the chain
   // virtual const G4String& DumpMap();

    //! Inserts a new module into the pulse-processor chain



private:
  TestDigitizer* m_digitizer;

  G4UIdirectory           *Dir;
 // G4UIcmdWithADoubleAndUnit*  ThresholdCmd;
  G4UIcmdWithAString*         SetModuleNameCmd;

//private:
//   G4String  	      	m_newInsertionBaseName;

};

#endif


