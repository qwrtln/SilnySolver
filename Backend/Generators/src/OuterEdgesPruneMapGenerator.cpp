#include "OuterEdgesPruneMapGenerator.h"

std::vector<std::vector<int>> OuterEdgesPruneMapGenerator:: getPieceMap()
{
	return this->crazyCubeCachePtr->getOuterEdgesMap();
}
