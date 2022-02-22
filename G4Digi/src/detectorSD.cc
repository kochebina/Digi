#include "detectorSD.hh"


TestSensitiveDetector::TestSensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{
	collectionName.insert(name);
	//collectionName.insert("testHitCollection2");
	collectionID = -1;
	collectionID2 = -1;

}

/*TestSensitiveDetector::TestSensitiveDetector(G4String name, G4int ID)
{
	collectionName.insert(name);
	//collectionName.insert("testHitCollection2");
	collectionID = -1;
	collectionID2 = -1;

}
*/

TestSensitiveDetector::~TestSensitiveDetector()
{

}

/*void TestSensitiveDetector::TestSensitiveDetector(const G4String& name, const G4String& hitsCollectionName) : G4VSensitiveDetector(name), fHitsCollection(0)
{
	collectionName.insert(hitsCollectionName);
}
*/

void TestSensitiveDetector::Initialize(G4HCofThisEvent* HCE)
{

	G4SDManager *SDMan=G4SDManager::GetSDMpointer();

	//G4cout<<"SD init"<<SDMan->FindSensitiveDetector ("", G4bool warning=true)  <<G4endl;

	//G4cout<<"TestSensitiveDetector collectionName size "<<collectionName.size() <<G4endl;

	if(collectionID==-1)
	{
		fHitsCollection = new TestHitsCollection("SensitiveDetector",collectionName[0]);
	}

	if(collectionID2==-1)
		{
			fHitsCollection2 = new TestHitsCollection("SensitiveDetector2",collectionName[0]);
		}

	if (collectionID > 0)
	{
		collectionID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection);
	}

	HCE->AddHitsCollection(collectionID, fHitsCollection);

	//G4cout<<collectionName[0]<<" "<<collectionName[1]<<G4endl;

	//fHitsCollection2 = new TestHitsCollection("SensitiveDetector2",collectionName[1]);

		if (collectionID2 > 0)
		{
			collectionID2 = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection2);
		}

	HCE->AddHitsCollection(collectionID2, fHitsCollection2);

	//G4cout<<"SD init fin"<<G4endl;


}




G4bool TestSensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROHits)
{

	G4cout<<"SD Process Hits"<<G4endl;

	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

	G4double time= preStepPoint->GetGlobalTime();
 
	/*	const G4VTouchable *touchablePre = aStep->GetPreStepPoint()->GetTouchable();
	//const G4VTouchable *touchablePost = aStep->GetPreStepPoint()->GetTouchable();


	G4VPhysicalVolume *physVolPre = touchablePre->GetVolume();
	//G4VPhysicalVolume *physVolPost = touchablePre->GetVolume();

	G4cout<<physVolPre->GetName ()<<G4endl;
	//G4cout<<physVolPost->GetName ()<<G4endl;

	//G4int copyNo = touchable->GetCopyNumber();

	*/

	// Get the track information
	  G4Track* aTrack       = aStep->GetTrack();
	  G4int    trackID      = aTrack->GetTrackID();
	  G4int    parentID     = aTrack->GetParentID();
	  // Seb Modif 5/4/2016
	  G4double trackLength  = aTrack->GetTrackLength();
	  G4double trackLocalTime = aTrack->GetLocalTime();

	  G4String partName     = aTrack->GetDefinition()->GetParticleName();
	  G4int    PDGEncoding  = aTrack->GetDefinition()->GetPDGEncoding();

	  //Get information about gamma ( generated by ExtendedVSource )
	  /*G4int source_type = static_cast<G4int>(GateEmittedGammaInformation::SourceKind::NotDefined);
	  G4int decay_type = static_cast<G4int>(GateEmittedGammaInformation::DecayModel::None);
	  G4int gamma_type = static_cast<G4int>(GateEmittedGammaInformation::GammaKind::Unknown);
	  G4PrimaryParticle* primary_particle = aTrack->GetDynamicParticle()->GetPrimaryParticle();
	 /* if( primary_particle != nullptr )
	  {
	   GateEmittedGammaInformation* info = dynamic_cast<GateEmittedGammaInformation*>( primary_particle->GetUserInformation() );
	   if ( info != nullptr )
	   {
	    source_type = static_cast<G4int>( info->GetSourceKind() );
	    decay_type = static_cast<G4int>( info->GetDecayModel() );
	    gamma_type = static_cast<G4int>( info->GetGammaKind() );
	   }
	  }
*/
	  // Get the step-points
	  G4StepPoint  *oldStepPoint = aStep->GetPreStepPoint(),
	      	       *newStepPoint = aStep->GetPostStepPoint();


	  //  Get the process name
	  const G4VProcess* process = newStepPoint->GetProcessDefinedStep();
	  G4String processName = ( (process != NULL) ? process->GetProcessName() : G4String() ) ;

	  //  For all processes except transportation, we select the PostStepPoint volume
	  //  For the transportation, we select the PreStepPoint volume
	  const G4TouchableHistory* touchable;
	  if ( processName == "Transportation" )
	      touchable = (const G4TouchableHistory*)(oldStepPoint->GetTouchable() );
	  else
	      touchable = (const G4TouchableHistory*)(newStepPoint->GetTouchable() );


	  //GateVolumeID volumeID(touchable);


	 // if (volumeID.IsInvalid())
	  //  G4Exception( "GateCrystalSD::ProcessHits", "ProcessHits", FatalException, "could not get the volume ID! Aborting!\n");

	  // Get the hit global position
	  //Modifs Seb 22-06-2011
	  //G4ThreeVector position = oldStepPoint->GetPosition();
	  G4ThreeVector position = newStepPoint->GetPosition();

	  // Get the hit momentumDirecton
	  G4ThreeVector momentumDirection = newStepPoint->GetMomentumDirection();

	  // Compute the hit local position
	  // (It will be in the reference frame of the PreStepPoint volume for a transportation hit)
	  //G4ThreeVector localPosition = volumeID.MoveToBottomVolumeFrame(position);


	  // Get the scanner position and rotation angle
	/*  GateSystemComponent* baseComponent = GetSystem()->GetBaseComponent();*/
	//  GateVSystem* system = FindSystem(volumeID);
	 // GateSystemComponent* baseComponent = system->GetBaseComponent();
	//  G4ThreeVector scannerPos = baseComponent->GetCurrentTranslation();
	 // G4double scannerRotAngle = 0;

/*
	  if ( baseComponent->FindRotationMove() )
	    scannerRotAngle = baseComponent->FindRotationMove()->GetCurrentAngle();
	  else if ( baseComponent->FindOrbitingMove() )
	    scannerRotAngle = baseComponent->FindOrbitingMove()->GetCurrentAngle();
	  else if ( baseComponent->FindEccentRotMove() )
	    scannerRotAngle = baseComponent->FindEccentRotMove()->GetCurrentAngle();
*/

	  // deposit energy in the current step
	  G4double edep = aStep->GetTotalEnergyDeposit();


	  // stepLength of the current step
	  G4double stepLength = aStep->GetStepLength();
	  // time of the current step
	  G4double aTime = newStepPoint->GetGlobalTime();


	  //GND
	  TestHit* aHit = new TestHit();

	  // Store the data already obtained into the hit
	  aHit->SetPDGEncoding( PDGEncoding );
	  aHit->SetEdep( edep );
	  aHit->SetStepLength( stepLength );
	  aHit->SetTime( aTime );
	  aHit->SetGlobalPos( position );
	  //aHit->SetLocalPos( localPosition );
	  aHit->SetProcess( processName );
	  aHit->SetTrackID( trackID );
	 // Seb Modif 5/4/2016
	  aHit->SetTrackLength( trackLength );
	  aHit->SetTrackLocalTime( trackLocalTime );
	  aHit->SetMomentumDir( momentumDirection );
	  aHit->SetParentID( parentID );
	 //aHit->SetVolumeID( volumeID );
	  //aHit->SetScannerPos( scannerPos );
	  //aHit->SetScannerRotAngle( scannerRotAngle );
	 // aHit->SetSystemID(system->GetItsNumber());
	  //aHit->SetSourceType( source_type );
	  //aHit->SetDecayType( decay_type );
	  //aHit->SetGammaType( gamma_type );

	  // Ask the system to compute the output volume ID and store it into the hit

	//Seb Modif 24/02/2009
	/*  GateOutputVolumeID outputVolumeID = GetSystem()->ComputeOutputVolumeID(aHit->GetVolumeID());*/
	 // GateOutputVolumeID outputVolumeIDGND = system->ComputeOutputVolumeID(aHit->GetVolumeID());
	 // aHit->SetOutputVolumeID(outputVolumeIDGND);

	  // Insert the new hit into the hit collection
	  fHitsCollection->insert( aHit );





	  ///do something with hit here

	/*TestHit* aHit = new TestHit();
	aHit->SetEdep(edep);
	aHit->SetTime(time);
	fHitsCollection->insert(aHit);
*/

	//fill root file with step/hits info

	//G4cout<<"Filling histo "<<G4endl;
	/*G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0, 0, evt);
	man->FillNtupleDColumn(0, 1, edep);
	man->FillNtupleDColumn(0, 2, time);

	man->AddNtupleRow(0);



   /* G4Track *track = aStep->GetTrack();

    track->SetTrackStatus(fStopAndKill);

	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

	G4ThreeVector posPhoton = preStepPoint->GetPosition();

	//G4cout<< ""<< G4endl;
	//G4cout<<"Position"<< posPhoton <<G4endl;

	const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

	G4int copyNo = touchable->GetCopyNumber();

	//G4cout << "Copy no: "<< copyNo << G4endl;

	G4VPhysicalVolume *physVol = touchable->GetVolume();
	G4ThreeVector posDetector = physVol->GetTranslation();

	G4cout << "Pos: "<<  posDetector<< G4endl;

	G4int	evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0, 0,evt);
	man->FillNtupleDColumn(0, 1,posDetector[0]);
	man->FillNtupleDColumn(0, 2,posDetector[1]);
	man->FillNtupleDColumn(0, 3,posDetector[2]);
*/

	return true; //added by me
}

void TestSensitiveDetector::EndOfEvent(G4HCofThisEvent* HCE)
{

	//G4cout<<" TestSensitiveDetector::EndOfEvent"<<G4endl;

	static G4int HCID = -1;
	  if(HCID<0)
	    {
	      HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
	    }
	  HCE->AddHitsCollection(HCID,fHitsCollection); //to use later in EndEventAction

	  //G4SDManager *SDMan=G4SDManager::GetSDMpointer();
	  //G4cout<<"!!!!!!!!!!!!!!! "<<SDMan->GetCollectionCapacity () <<G4endl;
	 // SDMan->ListTree ();


}


