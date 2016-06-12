#include "CrazyCubeCache.h"

std::unique_ptr<CrazyCubeCache> CrazyCubeCache::instance;

CrazyCubeCache* CrazyCubeCache::getInstance()
{
  if(!instance) 
  {
    instance.reset(new CrazyCubeCache());
  } 
  return instance.get();
}

CrazyCubeCache:: CrazyCubeCache()
{
    CrazyCubeMoveMapper mapper;
    OuterCornersMapGenerator OCmapper;
    InnerCornersMapGenerator ICmapper;
    //OuterEdgesMapGenerator OEmapper;
    InnerEdgesMapGenerator IEmapper;
    CentreMapGenerator Cmapper;

    outerCornersMap = OCmapper.generateMoveMap();
    innerCornersMap = ICmapper.generateMoveMap();
    outerEdgesMap = mapper.generateOuterEdgesMap();
    innerEdgesMap = IEmapper.generateMoveMap();
    centreMap = Cmapper.generateMoveMap();
}

CrazyCubeCache:: ~CrazyCubeCache()
{

}

void CrazyCubeCache:: cleanup()
{
    instance.release();
}

std::vector<std::vector<int>>& CrazyCubeCache:: getOuterCornersMap()
{
	return this->outerCornersMap;
}

std::vector<std::vector<int>>& CrazyCubeCache:: getInnerCornersMap()
{
	return this->innerCornersMap;
}

std::vector<std::vector<int>>& CrazyCubeCache:: getOuterEdgesMap()
{
	return this->outerEdgesMap;
}

std::vector<std::vector<int>>& CrazyCubeCache:: getInnerEdgesMap()
{
	return this->innerEdgesMap;
}

std::vector<std::vector<int>>& CrazyCubeCache:: getCentreMap()
{
	return this->centreMap;
}
