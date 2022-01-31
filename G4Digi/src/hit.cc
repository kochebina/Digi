#include "hit.hh"

#include "G4VVisManager.hh"

G4Allocator<TestHit> TestHitAllocator;

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

