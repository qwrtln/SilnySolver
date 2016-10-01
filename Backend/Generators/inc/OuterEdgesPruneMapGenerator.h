#include "PruneMapsGeneratorI.h"
#include <vector>

class OuterEdgesPruneMapGenerator: public PruneMapsGeneratorI
{
public:

private:
	std::vector<std::vector<int>> getPieceMap();
}; 
