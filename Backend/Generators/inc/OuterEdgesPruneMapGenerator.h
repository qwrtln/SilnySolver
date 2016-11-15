#include "PruneMapsGeneratorI.h"
#include <vector>

class OuterEdgesPruneMapGenerator: public PruneMapsGeneratorI
{
public:
	OuterEdgesPruneMapGenerator();
private:
	std::vector<std::vector<int>> getPieceMap();
}; 
