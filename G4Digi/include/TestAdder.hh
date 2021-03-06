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
// ------------------------------------------------------------
//      GEANT 4 class header file
//      CERN Geneva Switzerland
//
//
//      ------------ TestAdder ------
//
//           by F.Longo, R.Giannitrapani & G.Santin (24 oct 2001)
//
// ************************************************************

#ifndef TestAdder_h
#define TestAdder_h 1

#include "G4VDigitizerModule.hh"
#include "TestDigi.hh"
#include "globals.hh"

#include "TestAdderMessenger.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class TestAdder : public G4VDigitizerModule
{
public:
  
  TestAdder(G4String name);
  ~TestAdder();
  
  void Digitize();

  void SetPolitics(G4String name){m_politics=name;}
  
private:
  G4String m_politics;

  TestAdderMessenger *fMessenger;

   //static TestDigitizer*  theDigitizer;

   TestDigitsCollection*  DigitsCollection;
    G4double Energy;


};

#endif








