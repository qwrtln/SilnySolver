#include "CrazyCubePruner.h"

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
  
  int length = 8; // just a temporary setting

  outerCornersPruneMap = OCmapper.generatePruneMap(length);
  innerCornersPruneMap = ICmapper.generatePruneMap(length);
  outerEdgesPruneMap = OEmapper.generatePruneMap(length);
  innerEdgesPruneMap = IEmapper.generatePruneMap(length);
  centrePruneMap = Cmapper.generatePruneMap(length);
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
