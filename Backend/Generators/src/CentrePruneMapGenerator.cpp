#include "CentrePruneMapGenerator.h"

std::vector<std::vector<int>> CentrePruneMapGenerator:: getPieceMap()
{
	return this->crazyCubeCachePtr->getCentreMap();
}
