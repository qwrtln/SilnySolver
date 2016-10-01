#include "PruneMapsGeneratorI.h"
#include <vector>

class InnerCornersPruneMapGenerator: public PruneMapsGeneratorI
{
public:

private:
	std::vector<std::vector<int>> getPieceMap();
}; 
