#include "CrazyCubePruner.h"


short int* CrazyCubePruner::generateOuterCornersPruneMap(int maxMoves)
{
    short int* OuterCornersPruneMap = new short int[factorials[NUM_OF_EDGES]];

    for (int i = 0; i < factorials[NUM_OF_EDGES]; ++i)
    {
        OuterCornersPruneMap[i] = 100; // Safe boundary - this prunes nothing
    }

    return OuterCornersPruneMap;
}
