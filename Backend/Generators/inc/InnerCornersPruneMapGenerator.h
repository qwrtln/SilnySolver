#include "PruneMapsGeneratorI.h"
#include <vector>

class InnerCornersPruneMapGenerator: public PruneMapsGeneratorI
{
public:
	InnerCornersPruneMapGenerator();
private:
	std::vector<std::vector<int>> getPieceMap();
}; 
