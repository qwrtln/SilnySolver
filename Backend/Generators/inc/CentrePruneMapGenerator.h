#include "PruneMapsGeneratorI.h"
#include <vector>

class CentrePruneMapGenerator: public PruneMapsGeneratorI
{
public:
	CentrePruneMapGenerator();
private:
	std::vector<std::vector<int>> getPieceMap();
}; 
