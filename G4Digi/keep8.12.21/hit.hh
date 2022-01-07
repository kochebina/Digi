#ifndef HIT_HH
#define HIT_HH

#include "G4VHit.hh"
#include "G4THitsCollection.hh"


class TestHit : public G4VHit
{
public:
	TestHit();
	~TestHit();


	//virtual void Draw();
	//virtual void Print();

private:
	G4double fEdep;
	G4double fTime;


	G4double fTotEdep;

public:
	inline void AddTotalEdep(G4double energy) {fTotEdep += energy; };
	G4double GetTotalEdep() {return fTotEdep;} ;
	void SetTotalEdep(G4double energy) {fTotEdep = energy;};


	void SetEdep(G4double edep) {fEdep = edep;} ;
	G4double GetEdep() const {return fEdep;};

	void SetTime(G4double time) {fTime = time;} ;
	G4double GetTime() const {return fTime;};


};


typedef G4THitsCollection<TestHit> TestHitsCollection;

#endif
