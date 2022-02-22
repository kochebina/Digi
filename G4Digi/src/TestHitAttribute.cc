#include "TestHitAttribute.hh"
#include "TestHitAttributeMessenger.hh"
#include <fstream>
//TestHitAttribute* TestHitAttribute::theHitAttribute=0;

/*TestHitAttribute* TestHitAttribute::GetInstance()
{
  if (!theHitAttribute)
    theHitAttribute = new TestHitAttribute;
  return theHitAttribute;
}
*/

TestHitAttribute::TestHitAttribute()
{
	G4cout<<"TestHitAttribute::constructor"<<G4endl;
	fMessenger = new TestHitAttributeMessenger(this);
}


TestHitAttribute::~TestHitAttribute()
{
		delete fMessenger;
}


void TestHitAttribute::ReadFile()
{
	G4cout<<"READFILE "<< fInputAttributeFile<<G4endl;

	std::ifstream file(fInputAttributeFile);

	if(file.is_open())
	{
		G4String line;
		while(std::getline(file,line))
		{
			fHitAttributeVector.push_back(line);
		}
	}

	file.close();

	G4double temp_name=0;
	//G4double temp_efficiency=0;
/*
	while (1) {
		//in >>  temp_energy >>temp_efficiency;
		in >>  temp_name;
	    	if (!in.good()) break;
	    	//fHitAttributeVector.push_back(std::pair<G4double,G4double>(temp_energy,temp_efficiency) );
	    	fHitAttributeVector.push_back(temp_name);
	  	  }
	  	  in.close();
*/
	  	  for (G4int i=0; i<fHitAttributeVector.size();i++)
	  	  {
	  		  G4cout<< fHitAttributeVector[i]<<G4endl;


	  	  }

}
