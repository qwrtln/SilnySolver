#include "InnerCornersPruneMapGenerator.h"

std::vector<std::vector<int>> InnerCornersPruneMapGenerator:: getPieceMap()
{
	return this->crazyCubeCachePtr->getInnerCornersMap();
}
