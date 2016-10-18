#include "PruningSolver.h"

PruningSolver:: PruningSolver()
{
	solutions.clear();
    this->pruner = CrazyCubePruner::getInstance();
}

void PruningSolver:: setCrazyCube(CubeInterface* crazyCube) 
{
    this->crazyCube = crazyCube;
    // We need this conversion for pruning - CubeImproved provides methods delivering indices for pruner.
    this->crazyCubeImproved = dynamic_cast<CrazyCubeImproved*>(crazyCube);
}

bool PruningSolver:: doWeFuckingHaveToPrune(int depth)
{
    return !((pruner->getOuterEdgesPruneMap()[crazyCubeImproved->getOuterEdges()] <= depth) && 
            (pruner->getOuterCornersPruneMap()[crazyCubeImproved->getOuterCorners()] <= depth) && 
            (pruner->getInnerCornersPruneMap()[crazyCubeImproved->getInnerCorners()] <= depth) &&
            (pruner->getInnerEdgesPruneMap()[crazyCubeImproved->getInnerEdges()] <= depth) &&
            (pruner->getCentrePruneMap()[crazyCubeImproved->getCentre()] <= depth)); 
}
