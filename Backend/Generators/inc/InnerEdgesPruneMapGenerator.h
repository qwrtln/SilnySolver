#include "PruneMapsGeneratorI.h"
#include <vector>

class InnerEdgesPruneMapGenerator: public PruneMapsGeneratorI
{
public:

private:
	std::vector<std::vector<int>> getPieceMap();
}; 
