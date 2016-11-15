#include "InnerEdgesPruneMapGenerator.h"

InnerEdgesPruneMapGenerator:: InnerEdgesPruneMapGenerator()
{
	mapSize = pow2toX[NUM_OF_EDGES];
}

std::vector<std::vector<int>> InnerEdgesPruneMapGenerator:: getPieceMap()
{
	return this->crazyCubeCachePtr->getInnerEdgesMap();
}
