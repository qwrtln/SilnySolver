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
	// Clean the arrays created using CrazyCubeMapper
	for(int i = 0; i < factorials[NUM_OF_CORNERS]; i++)
	{
		delete[] outerCornersMap[i];
	}
	for(int i = 0; i < pow2toX[NUM_OF_CORNERS]; i++)
	{
		delete[] innerCornersMap[i];
	}
	delete[] innerCornersMap;
	delete[] outerCornersMap;
	
	for(int i = 0; i < factorials[NUM_OF_EDGES]; i++)
	{
		delete[] outerEdgesMap[i];
	}
	for(int i = 0; i < pow2toX[NUM_OF_EDGES]; i++)
	{
		delete[] innerEdgesMap[i];
	}
	delete[] innerEdgesMap;
	delete[] outerEdgesMap;
	
	for(int i = 0; i < factorials[2]; i++) // Magic 2 because 1! = 1 and we need 2 states for centre
	{
		delete[] centreMap[i];
	}
	delete[] centreMap;
}

void CrazyCubeCache:: cleanup()
{
    delete instance;
    instance = nullptr;
}

int** CrazyCubeCache:: getOuterCornersMap()
{
	return this->outerCornersMap;
}

int** CrazyCubeCache:: getInnerCornersMap()
{
	return this->innerCornersMap;
}

int** CrazyCubeCache:: getOuterEdgesMap()
{
	return this->outerEdgesMap;
}

int** CrazyCubeCache:: getInnerEdgesMap()
{
	return this->innerEdgesMap;
}

int** CrazyCubeCache:: getCentreMap()
{
	return this->centreMap;
}

void CrazyCubeCache::  setOuterCornersMap(int** outerCornersMap)
{
	this->outerCornersMap = outerCornersMap;
}

void CrazyCubeCache::  setInnerCornersMap(int** innerCornersMap)
{
	this->innerCornersMap = innerCornersMap;
}

void CrazyCubeCache::  setOuterEdgesMap(int** outerEdgesMap)
{
	this->outerEdgesMap = outerEdgesMap;
}

void CrazyCubeCache::  setInnerEdgesMap(int** innerEdgesMap)
{
	this->innerEdgesMap = innerEdgesMap;
}

void CrazyCubeCache::  setCentreMap(int** centreMap)
{
	this->centreMap = centreMap;
}
