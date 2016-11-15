#include "PruneMapsGeneratorI.h"
#include <vector>

class OuterCornersPruneMapGenerator: public PruneMapsGeneratorI
{
public:
	OuterCornersPruneMapGenerator();
private:
	std::vector<std::vector<int>> getPieceMap();
}; 
