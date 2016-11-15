#include "CentrePruneMapGenerator.h"

CentrePruneMapGenerator:: CentrePruneMapGenerator()
{
	mapSize = 2;
}

std::vector<std::vector<int>> CentrePruneMapGenerator:: getPieceMap()
{
	return this->crazyCubeCachePtr->getCentreMap();
}
