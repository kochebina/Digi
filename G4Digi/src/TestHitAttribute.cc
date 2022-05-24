#include "TestHitAttribute.hh"
#include "TestHitAttributeMessenger.hh"

#include "TestHit.hh"

#include <fstream>

TestHitAttribute* TestHitAttribute::theHitAttribute=0;

TestHitAttribute* TestHitAttribute::GetInstance()
{
  if (!theHitAttribute)
    theHitAttribute = new TestHitAttribute;
  return theHitAttribute;
}


//#define GET_VARIABLE_NAME(Variable) (#Variable)


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

	/*if(file.is_open())
	{
		G4String line;
		while(std::getline(file,line))
		{
			HitAttributeVector.push_back(line);
		}
	}
	*/
	G4String temp_name;
	char temp_type;

	while (1) {
			file >>  temp_name >>temp_type;
			//in >>  temp_name;
		    	if (!file.good()) break;
		    	fHitAttributeVector.push_back(std::pair<G4String,char>(temp_name,temp_type));
		    	//fHitAttributeVector.push_back(temp_name);
		  	  }

	file.close();


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
	 /* 	 for (unsigned int i=0; i<fHitAttributeVector.size();i++)
	  	  {
	  		  G4cout<< fHitAttributeVector[i].first<<" "<< fHitAttributeVector[i].second<<G4endl;


	  	  }
*/
	  	//Check if we have this attribute in Hits, if yes, get type

	 /* 	TestHit* aHit=new TestHit();
	  	G4double edep=aHit->m_edep;

	  	char* var_name= GET_VARIABLE_NAME(aHit->m_edep);
	  	G4cout<<"!!!!! "<<var_name<<G4endl;
*/

}

/*
void TestHitAttribute::IntilizeAllAttributesMaps()
{
	TestHit* aHit=new TestHit();

	AddToMapI("PDGEncoding",&(aHit->m_PDGEncoding));
	AddToMapI("trackID",&(aHit->m_trackID));

	//G4cout<<GET_VARIABLE_NAME(m_PDGEncoding)<<G4endl;
		//AddToMapD("edep",&m_edep);
		//AddToMapD("trackID",&m_trackID);


}
*/


void TestHitAttribute::AddToMapI(G4String name, G4int* varPtr)
{
	//mapHitAttributesI.insert( std::pair<G4String, G4int*>(name,varPtr));
	mapHitAttributesI.push_back( std::pair<G4String, G4int*>(name,varPtr));
}


void TestHitAttribute::AddToMapD(G4String name, G4double* varPtr)
{
	//mapHitAttributesD.insert( std::pair<G4String, G4double*>(name,varPtr));
	mapHitAttributesD.push_back( std::pair<G4String, G4double*>(name,varPtr));
}

