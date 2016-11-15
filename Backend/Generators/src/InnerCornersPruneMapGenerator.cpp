#include "InnerCornersPruneMapGenerator.h"

InnerCornersPruneMapGenerator:: InnerCornersPruneMapGenerator()
{
	mapSize = pow2toX[NUM_OF_CORNERS];
}

std::vector<std::vector<int>> InnerCornersPruneMapGenerator:: getPieceMap()
{
	return this->crazyCubeCachePtr->getInnerCornersMap();
}
