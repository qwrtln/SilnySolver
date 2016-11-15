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
#if defined(TESTING) || defined(MEMORY_CHECK)
  public:
#else
    private:
#endif
        const static int edgeArrayLimit;
        const static int cornerArrayLimit;
        const static int centreArrayLimit;
        std::vector<int> pruneMap;
        int maxDepth; // How deep do you want the Pruner to delve?


		void swapMapElementValue(int width, std::vector<int>& vect, short int oldValue, short int newValue);
        std::vector<int> generateInitialVector(int length);

        int generatePruneMapIter(int depth, int& pieces, short int prevMove);

        // Wrapper for getting specific maps for specific pieces
        virtual std::vector<std::vector<int>> getPieceMap() = 0;
	protected:
		CrazyCubeCache* crazyCubeCachePtr;

		unsigned int mapSize;
    public:
		PruneMapsGeneratorI();
		std::vector<int> generatePruneMap(int length);
};

#endif /* PRUNEMAPSGENERATORI_H_ */
