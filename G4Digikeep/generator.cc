#include "generator.hh"


TestPrimaryGenerator::TestPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1);
}

TestPrimaryGenerator::~TestPrimaryGenerator()
{
	delete fParticleGun;
}


void TestPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	G4ParticleTable *particleTable =  G4ParticleTable::GetParticleTable();
	G4String particleName = "gamma";
	G4ParticleDefinition *particle = particleTable->FindParticle("gamma");

	G4ThreeVector pos(0., 0., 0.);
	G4ThreeVector mom(0., 0., 1.);

	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom);
	fParticleGun->SetParticleMomentum(511.*keV);
	fParticleGun->SetParticleDefinition(particle);

	fParticleGun->GeneratePrimaryVertex(anEvent);
}
