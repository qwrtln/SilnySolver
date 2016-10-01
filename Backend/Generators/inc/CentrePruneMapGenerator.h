#include "PruneMapsGeneratorI.h"
#include <vector>

class CentrePruneMapGenerator: public PruneMapsGeneratorI
{
public:

private:
	std::vector<std::vector<int>> getPieceMap();
}; 
