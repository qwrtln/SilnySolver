#ifndef PRUNEMAPGENERATOR_H_
#define PRUNEMAPGENERATOR_H_

#include "CrazyCube.h"
#include "CrazyCubeAbstract.h"
#include "CrazyCubeCache.h"
#include <cmath>
#include <vector>

class CrazyCubeCache;
class PruneMapGenerator: public CrazyCubeAbstract
{
    private:
        const static int NumberOfkindsOfPieces;
        const static int edgeArrayLimit;
        const static int cornerArrayLimit;
        const static int centreArrayLimit;


        // Array in turn: Corners, Edges, corners, edges, Centre
        int* piecesState;

	CrazyCubeCache* crazyCubeCachePtr;

#if defined(TESTING) || defined(MEMORY_CHECK)
    public:
#endif
		// helpful methods
		void swapMapElementValue(int width, std::vector<int>& vect, short int oldValue, short int newValue);
        std::vector<int> generateInitialVector(int length);

	public:

		PruneMapGenerator();
		// pruning maps
		std::vector<int> generateOuterCornersPruneMap(int length, int maxMoves);
		std::vector<int> generateOuterEdgesPruneMap(int length, int maxMoves);
		std::vector<int> generateInnerCornersPruneMap(int length, int maxMoves);
		std::vector<int> generateInnerEdgesPruneMap(int length, int maxMoves);
		std::vector<int> generateCentrePruneMap(int length, int maxMoves);

		int generateOuterCornersPruneMapIter(int depth, int maxDepth, int& outerCorners, std::vector<int>& outerCornersPruneMap, short int prevMove);
		int generateOuterEdgesPruneMapIter(int depth, int maxDepth, int& outerEdges, std::vector<int>& outerEdgesPruneMap, short int prevMove);
		int generateInnerCornersPruneMapIter(int depth, int maxDepth, int& innerCorners, std::vector<int>& innerCornersPruneMap, short int prevMove);
		int generateInnerEdgesPruneMapIter(int depth, int maxDepth, int& innerEdges, std::vector<int>& innerEdgesPruneMap, short int prevMove);
		int generateCentrePruneMapIter(int depth, int maxDepth, int& centre, std::vector<int>& centrePruneMap, short int prevMove);

        unsigned long long convertIntArrayToCubeState(int,int,int,int,int);
};

#endif /* PRUNEMAPGENERATOR_H_ */
