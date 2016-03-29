#include "CrazyCubePruner.h"
#include "CrazyCubeCache.h"


short int* CrazyCubePruner::generateOuterCornersPruneMap(int maxMoves)
{
	CrazyCubeCache::getInstance();
    short int* OuterCornersPruneMap = new short int[factorials[NUM_OF_EDGES]];

    for (int i = 0; i < factorials[NUM_OF_EDGES]; ++i)
    {
        OuterCornersPruneMap[i] = 100; // Safe boundary - this prunes nothing
    }

	int outerCorners = 0;
	
	generateOuterCornersPruneMapIter(1, maxMoves, outerCorners, OuterCornersPruneMap, -1);
    return OuterCornersPruneMap;
}
void CrazyCubePruner::generateOuterCornersPruneMapIter(int depth, int maxDepth, int& outerCorners, short int* outerCornersPruneMap, int prevMove)
{

}
