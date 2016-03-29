/*
 * CrazyCubePruner.h
 *
 *  Created on: Mar 16, 2016
 *      Author: qwrtln
 */
#ifndef CRAZYCUBEPRUNER_H_
#define CRAZYCUBEPRUNER_H_

//#include "CrazyCube.h"
#include "CrazyCubeAbstract.h"

class CrazyCubePruner: public CrazyCubeAbstract
{
    short int* OuterCornersPruneMap;

    public:
        void generateOuterCornersPruneMapIter(int depth, int maxDepth, int& outerCorners, short int* outerCornersPruneMap, int prevMove);
        short int* generateOuterCornersPruneMap(int);

};

#endif /* CRAZYCUBEPRUNER_H_ */
