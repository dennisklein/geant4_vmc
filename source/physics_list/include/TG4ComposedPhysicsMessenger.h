#ifndef TG4_COMPOSED_PHYSICS_MESSENGER_H
#define TG4_COMPOSED_PHYSICS_MESSENGER_H 

// $Id$

//------------------------------------------------
// The Geant4 Virtual Monte Carlo package
// Copyright (C) 2007, 2008 Ivana Hrivnacova
// All rights reserved.
//
// For the licensing terms see geant4_vmc/LICENSE.
// Contact: vmc@pcroot.cern.ch
//-------------------------------------------------

/// \file TG4ComposedPhysicsMessenger.h 
/// \brief Definition of the TG4ComposedPhysicsMessenger class 
///
/// \author I. Hrivnacova; IPN Orsay

#include <G4UImessenger.hh>
#include <globals.hh>

class TG4ComposedPhysicsList;

class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithoutParameter;
class G4UIcmdWithAString;

/// \ingroup physics_list
/// \brief Messenger class that defines commands for Geant4 VMC composed 
///        physics list and related classes
///
/// Implements commands:
/// - /mcPhysics/rangeCutForElectron 
/// - /mcPhysics/rangeCutForPositron
/// - /mcPhysics/rangeCutForGamma
/// - /mcPhysics/rangeCuts
/// - /mcPhysics/printProcessMCMap
/// - /mcPhysics/printProcessControlMap
/// - /mcPhysics/printVolumeLimits [volName]
/// - /mcPhysics/printGlobalCuts
/// - /mcPhysics/printGlobalControls
///
/// \author I. Hrivnacova; IPN Orsay

class TG4ComposedPhysicsMessenger : public G4UImessenger
{
  public:
    TG4ComposedPhysicsMessenger(TG4ComposedPhysicsList* physicsList); 
    virtual ~TG4ComposedPhysicsMessenger();
   
    // methods 
    virtual void SetNewValue(G4UIcommand* command, G4String string);
    
  private:
    /// Not implemented
    TG4ComposedPhysicsMessenger();  
    /// Not implemented
    TG4ComposedPhysicsMessenger(const TG4ComposedPhysicsMessenger& right);
    /// Not implemented
    TG4ComposedPhysicsMessenger& operator=(const TG4ComposedPhysicsMessenger& right);

    //
    // data members
    
    /// associated class
    TG4ComposedPhysicsList*     fPhysicsList; 
    
    /// command directory
    G4UIdirectory*              fDirectory; 

    /// rangeCutForGamma command
    G4UIcmdWithADoubleAndUnit*  fRangeGammaCutCmd;

    /// rangeCutForElectron command
    G4UIcmdWithADoubleAndUnit*  fRangeElectronCutCmd;

    /// rangeCutForPositron command
    G4UIcmdWithADoubleAndUnit*  fRangePositronCutCmd;

    /// rangeCuts command
    G4UIcmdWithADoubleAndUnit*  fRangeAllCutCmd;
    
    /// printAllProcess command 
    G4UIcmdWithoutParameter*    fPrintAllProcessesCmd;

    /// dumpAllProcess command      
    G4UIcmdWithoutParameter*    fDumpAllProcessesCmd;

    /// printProcessMCMap command                   
    G4UIcmdWithoutParameter*    fPrintProcessMCMapCmd;

    /// printProcessControlsMap command
    G4UIcmdWithoutParameter*    fPrintProcessControlMapCmd;

    /// printVolumeLimits command
    G4UIcmdWithAString*         fPrintVolumeLimitsCmd;

    /// printGeneralCuts command
    G4UIcmdWithoutParameter*    fPrintGlobalCutsCmd;

    /// printGeneralControls command
    G4UIcmdWithoutParameter*    fPrintGlobalControlsCmd;
};     

#endif //TG4_COMPOSED_PHYSICS_MESSENGER_H