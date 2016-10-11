#ifndef PRUNINGSOLVER_H_
#define PRUNINGSOLVER_H_

#include "CrazyCubeSolver.h"
#include "CrazyCubePruner.h"
#include "CrazyCubeImproved.h"

class PruningSolver: public CrazyCubeSolver
{
public:

    PruningSolver();
    // void setCrazyCube(CrazyCubeImproved*);

protected:

    bool doWeFuckingHaveToPrune(int);
};


#endif /* PRUNINGSOLVER_H_ */
