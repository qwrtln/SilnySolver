#include "OuterCornersPruneMapGenerator.h"

std::vector<std::vector<int>> OuterCornersPruneMapGenerator:: getPieceMap()
{
	return this->crazyCubeCachePtr->getOuterCornersMap();
}
