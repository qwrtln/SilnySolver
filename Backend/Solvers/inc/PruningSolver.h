#ifndef PRUNINGSOLVER_H_
#define PRUNINGSOLVER_H_

#include "CrazyCubeSolver.h"
#include "CrazyCubePruner.h"
#include "CrazyCubeImproved.h"

class PruningSolver: public CrazyCubeSolver
{
public:

    PruningSolver();
    void setCrazyCube(CubeInterface*) override;

protected:

    bool doWeFuckingHaveToPrune(int);
    CrazyCubeImproved* crazyCubeImproved;    
    CrazyCubePruner* pruner;
};


#endif /* PRUNINGSOLVER_H_ */
