#include "InnerEdgesPruneMapGenerator.h"

std::vector<std::vector<int>> InnerEdgesPruneMapGenerator:: getPieceMap()
{
	return this->crazyCubeCachePtr->getInnerEdgesMap();
}
