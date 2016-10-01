/*
 * PruneMapsGeneratorI.h
 *
 * Created on: Oct 1, 2016
 *      Author: qwrtln
 */
#ifndef PRUNEMAPSGENERATORI_H_
#define PRUNEMAPSGENERATORI_H_
#include "CrazyCube.h"
#include "CrazyCubeAbstract.h"
#include "CrazyCubeCache.h"
#include <cmath>
#include <vector>

class PruneMapsGeneratorI: public CrazyCubeAbstract
{
    private:
        const static int edgeArrayLimit;
        const static int cornerArrayLimit;
        const static int centreArrayLimit;

		CrazyCubeCache* crazyCubeCachePtr;

		PruneMapGenerator();

		void swapMapElementValue(int width, std::vector<int>& vect, short int oldValue, short int newValue);
        std::vector<int> generateInitialVector(int length);

		virtual int generatePruneMapIter(int depth, int maxDepth, int& pieces, std::vector<int>& piecesPruneMap, short int prevMove) = 0;


    public:
		virtual std::vector<int> generatePruneMap(int length, int maxMoves);
};

#endif /* PRUNEMAPSGENERATORI_H_ */
