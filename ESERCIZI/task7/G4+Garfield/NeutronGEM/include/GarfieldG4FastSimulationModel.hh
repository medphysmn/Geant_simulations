/*
 * GarfieldModel.h
 *
 *  Created on: Apr 9, 2014
 *      Author: dpfeiffe
 */

#ifndef GARFIELDG4FASTSIMULATIONMODEL_H_
#define GARFIELDG4FASTSIMULATIONMODEL_H_

#include "G4VFastSimulationModel.hh"
#include "GarfieldPhysics.hh"

class G4VPhysicalVolume;

class GarfieldG4FastSimulationModel : public G4VFastSimulationModel
{
public:
  //-------------------------
  // Constructor, destructor
  //-------------------------
	GarfieldG4FastSimulationModel (G4String, G4Region*);
	GarfieldG4FastSimulationModel (G4String);
  ~GarfieldG4FastSimulationModel ();

  void SetPhysics(GarfieldPhysics* fGarfieldPhysics);
  void WriteGeometryToGDML(G4VPhysicalVolume* physicalVolume);

  virtual G4bool IsApplicable(const G4ParticleDefinition&);
  virtual G4bool ModelTrigger(const G4FastTrack &);
  virtual void DoIt(const G4FastTrack&, G4FastStep&);



private:

   GarfieldPhysics* fGarfieldPhysics;
};


#endif /* GARFIELDMODEL_H_ */
