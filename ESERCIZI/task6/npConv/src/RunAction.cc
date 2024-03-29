// $Id: RunAction.cc 28 2010-01-12 10:24:06Z adotti $
/**
 * @file   RunAction.cc
 *
 * @date   17 Dec 2009
 * @author adotti
 *
 * @brief  Implements user class RunAction.
 */

#include "RunAction.hh"
#include "EventAction.hh"
#include "G4Run.hh"


RunAction::RunAction(EventAction* theEventAction ) 
  : eventAction(theEventAction)
{
  eventAction->SetRootSaver( &saver );
}

void RunAction::BeginOfRunAction(const G4Run* aRun )
{
	G4cout<<"Starting Run: "<<aRun->GetRunID()<<G4endl;
//        //For each run a new TTree is created, with default names
        
	G4cout << "!!!!!!!!!!!!!!!Creating ROOT TTree!!!!!!!!!!!!!" << G4endl;
	saver.CreateTree();

	out_root_f = new TFile("histoEnergy.root","RECREATE");
	hrun = new TH1F("EnDis","Energy Distribution",1000,0,1000);
	hrun->GetXaxis()->SetTitle("Deposited Energy (keV)");

	// G4cout << "Address of hrun in RunAction: " 
// 	       << static_cast<void*>(hrun) << G4endl;
	eventAction->AssignHisto(hrun);
}




void RunAction::EndOfRunAction( const G4Run* aRun )
{
	G4cout<<"Ending Run: "<<aRun->GetRunID()<<G4endl;
	G4cout<<"Number of events: "<<aRun->GetNumberOfEvent()<<G4endl;
	
	// G4cout << "Address of hrun in RunAction: " 
// 	       << static_cast<void*>(hrun) << G4endl;

	hrun->Write();
	out_root_f->Close();
	

	saver.CloseTree();
}
