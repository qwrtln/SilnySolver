#include "OuterEdgesPruneMapGenerator.h"

OuterEdgesPruneMapGenerator:: OuterEdgesPruneMapGenerator()
{
	mapSize = factorials[NUM_OF_EDGES];
}

std::vector<std::vector<int>> OuterEdgesPruneMapGenerator:: getPieceMap()
{
	return this->crazyCubeCachePtr->getOuterEdgesMap();
}
