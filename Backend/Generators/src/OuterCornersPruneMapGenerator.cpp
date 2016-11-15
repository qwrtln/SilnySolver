#include "OuterCornersPruneMapGenerator.h"

OuterCornersPruneMapGenerator:: OuterCornersPruneMapGenerator()
{
	mapSize = factorials[NUM_OF_CORNERS];
}

std::vector<std::vector<int>> OuterCornersPruneMapGenerator:: getPieceMap()
{
	return this->crazyCubeCachePtr->getOuterCornersMap();
}
