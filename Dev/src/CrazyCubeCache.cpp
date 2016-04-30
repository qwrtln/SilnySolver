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
    CrazyCubeMapper mapper;

    outerCornersMap = mapper.generateOuterCornersMap();
    innerCornersMap = mapper.generateInnerCornersMap();
    outerEdgesMap = mapper.generateOuterEdgesMap();
    innerEdgesMap = mapper.generateInnerEdgesMap();
    centreMap = mapper.generateCentreMap();
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

