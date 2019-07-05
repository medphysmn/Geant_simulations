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

#ifndef NeutronGEMUserScoreWriter_h
#define NeutronGEMUserScoreWriter_h 1

#include "globals.hh"
#include "G4VScoreWriter.hh"

class NeutronGEMDataManager;
class TFile;
class TTree;
class TH2D;

// class description:
//
//  This class represents storing the scored quantity into a file.
//


class NeutronGEMUserScoreWriter : public G4VScoreWriter {

public:
	NeutronGEMUserScoreWriter(NeutronGEMDataManager* dataManager);
	virtual ~NeutronGEMUserScoreWriter();
	void DumpQuantityToFile(const G4String & psName, const G4String & fileName,  const G4String & option);
private:
	char fStartTime[50];
	char fEndTime[50];
	NeutronGEMDataManager* fDataManager;
};

#endif


