#include "PruneMapsGeneratorI.h"
#include <vector>

class OuterCornersPruneMapGenerator: public PruneMapsGeneratorI
{
public:

private:
	std::vector<std::vector<int>> getPieceMap();
}; 
