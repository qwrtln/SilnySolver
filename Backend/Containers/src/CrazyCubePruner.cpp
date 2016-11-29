#include "CrazyCubePruner.h"
#include <iostream>

std::unique_ptr<CrazyCubePruner> CrazyCubePruner::instance;

CrazyCubePruner* CrazyCubePruner::getInstance()
{
  if(!instance) 
  {
    instance.reset(new CrazyCubePruner());
  } 
  return instance.get();
}

CrazyCubePruner::CrazyCubePruner() {
  OuterCornersPruneMapGenerator OCmapper;
  InnerCornersPruneMapGenerator ICmapper;
  OuterEdgesPruneMapGenerator OEmapper;
  InnerEdgesPruneMapGenerator IEmapper;
  CentrePruneMapGenerator Cmapper;
  
  int length = 4; // just a temporary setting
  using namespace std;

  cout << "Generuje prune mapy" << endl;
  cout << "Generuje OC... " << endl;
  outerCornersPruneMap = OCmapper.generatePruneMap(length);
  cout << "Generuje IC... " << endl;
  innerCornersPruneMap = ICmapper.generatePruneMap(length);
  cout << "Generuje OE... " << endl;
  outerEdgesPruneMap = OEmapper.generatePruneMap(length);
  cout << "Generuje IE... " << endl;
  innerEdgesPruneMap = IEmapper.generatePruneMap(length);
  cout << "Generuje C... " << endl;
  centrePruneMap = Cmapper.generatePruneMap(length);
  cout << "Skoczylem generowac prune mapy" << endl;
}

CrazyCubePruner::~CrazyCubePruner() {

}

void CrazyCubePruner:: cleanup()
{
    instance.release();
}

std::vector<int>& CrazyCubePruner:: getOuterCornersPruneMap()
{
	return this->outerCornersPruneMap;
}

std::vector<int>& CrazyCubePruner:: getInnerCornersPruneMap()
{
	return this->innerCornersPruneMap;
}

std::vector<int>& CrazyCubePruner:: getOuterEdgesPruneMap()
{
	return this->outerEdgesPruneMap;
}

std::vector<int>& CrazyCubePruner:: getInnerEdgesPruneMap()
{
	return this->innerEdgesPruneMap;
}

std::vector<int>& CrazyCubePruner:: getCentrePruneMap()
{
	return this->centrePruneMap;
}
