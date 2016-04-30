#include "CrazyCubeCache.h"

CrazyCubeCache* CrazyCubeCache::instance = nullptr;

CrazyCubeCache* CrazyCubeCache::getInstance()
{
  if(!instance) 
  {
    instance = new CrazyCubeCache();
  } 
  return instance;
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
    delete instance;
    instance = nullptr;
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

