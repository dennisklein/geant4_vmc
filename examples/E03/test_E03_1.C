// $Id$

//------------------------------------------------
// The Virtual Monte Carlo examples
// Copyright (C) 2007, 2008 Ivana Hrivnacova
// All rights reserved.
//
// For the licensing terms see geant4_vmc/LICENSE.
// Contact: vmc@pcroot.cern.ch
//-------------------------------------------------

/// \ingroup Tests
/// \file test_E03_1.C
/// \brief Example E03 Test macro 1
///
/// Running Example03

void test_E03_1(const TString& configMacro, Bool_t oldGeometry)
{
/// Macro function for testing example E03 
/// \param configMacro  configuration macro loaded in initialization 
/// \param oldGeometry  if true - geometry is defined via VMC, otherwise 
///                     via TGeo
/// 
/// Run 5 events with 20 primaries and print the calorimeter hits.

  // Load basic libraries
  gROOT->LoadMacro("../macro/basiclibs.C");
  basiclibs();

  // Load MC libraries
  TString mc = configMacro(0, 2);
  if ( mc == "g3" ) {
    // Geant3 libraries
    gROOT->LoadMacro("../macro/g3libs.C");
    g3libs();
  }
  else if ( mc == "g4" ) {  
    // Geant4 libraries
    gROOT->LoadMacro("../macro/g4libs.C");
    g4libs();
  }  
  else if ( mc == "fl" ) {  
    // Fluka libraries
    gROOT->LoadMacro("../macro/fllibs.C");
    fllibs();
    
    // Prepare Fluka working directory
    gSystem->Exec("../macro/run_fluka.sh");

    // Enter in Fluka working directory
    gSystem->cd("fluka_out");
  }  

  // Load this example library
  gSystem->Load("libexample03");
 
  // MC application
  Ex03MCApplication* appl 
    =  new Ex03MCApplication("Example03", "The example03 MC application");
  appl->GetPrimaryGenerator()->SetNofPrimaries(20);
  appl->SetPrintModulo(1);

  // Set geometry defined via VMC
  appl->SetOldGeometry(oldGeometry);  

  appl->InitMC(configMacro);

  // visualization setting
  // gROOT->LoadMacro("set_vis.C");
  // set_vis();

  appl->RunMC(5);

  delete appl;
}  