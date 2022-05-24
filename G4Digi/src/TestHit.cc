#include "TestHit.hh"

#include "G4VVisManager.hh"
#include "G4AttDefStore.hh"
#include "G4AttDef.hh"
#include "G4AttValue.hh"
#include "G4UIcommand.hh"
#include "G4UnitsTable.hh"
G4Allocator<TestHit> TestHitAllocator;

#define GET_VARIABLE_NAME(Variable) (#Variable)


TestHit::TestHit()
: m_edep(0),
  m_stepLength(0),
  m_time(0.),
  m_PDGEncoding(0),
  m_trackID(0),
  m_parentID(0),
 // m_systemID(-1),
  m_sourceEnergy(-1),
  m_sourcePDG(0),
  m_nCrystalConv(0)
{

	testHA=TestHitAttribute::GetInstance();
}


TestHit::~TestHit()
{

}

void TestHit::Draw()
{
  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
  if(pVVisManager)
  {
    /*G4Circle circle(m_pos);
    circle.SetScreenSize(0.04);
    circle.SetFillStyle(G4Circle::filled);
    G4Colour colour(1.,0.,0.);
    G4VisAttributes attribs(colour);
    circle.SetVisAttributes(attribs);
    pVVisManager->Draw(circle);
    */
  }
}
//---------------------------------------------------------------------


//---------------------------------------------------------------------
void TestHit::Print()
{
  G4cout << this;
  G4cout << G4endl;
}
//---------------------------------------------------------------------


/*
const std::map<G4String,G4AttDef>* TestHit::GetAttDefs() const
{
  G4bool isNew;
  std::map<G4String,G4AttDef>* store
    = G4AttDefStore::GetInstance("Hit",isNew);
  if (isNew) {

	  G4String trackid("trackID");
    (*store)[trackid] = G4AttDef(trackid,"Track ID","Physics","","G4int");

    G4String processName("processName");
    (*store)[processName] = G4AttDef(processName,"Process Name","Physics","","G4String");

    G4String energy("energy");
    (*store)[energy] = G4AttDef(energy,"Energy","Physics","G4BestUnit","G4double");


    G4String iPos("pos");
    (*store)[iPos] = G4AttDef(iPos, "Position",
                              "Physics","G4BestUnit","G4ThreeVector");

  }

  return store;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
std::vector<G4AttValue>* TestHit::CreateAttValues() const
{
  std::vector<G4AttValue>* values = new std::vector<G4AttValue>;

  values->push_back
    (G4AttValue("trackID",G4UIcommand::ConvertToString(m_trackID),""));

  values->push_back(G4AttValue("processName",m_process,""));

  values->push_back
    (G4AttValue("energy",G4UIcommand::ConvertToString(m_edep),""));

  values->push_back
    (G4AttValue("pos",G4BestUnit(m_pos,"Position"),""));

#ifdef G4ATTDEBUG
  G4cout << G4AttCheck(values,GetAttDefs());
#endif

  return values;
}
*/
