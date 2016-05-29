#ifndef CRAZYCUBEMAPPER_H_
#define CRAZYCUBEMAPPER_H_

#include "CrazyCube.h"
#include "CrazyCubeAbstract.h"
#include "CrazyCubeCache.h"
#include <cmath>
#include <vector>

using namespace std;
class CrazyCubeCache;
class CrazyCubeMapper: public CrazyCubeAbstract
{
    private:
        const static int NumberOfkindsOfPieces;
        const static int edgeArrayLimit;
        const static int cornerArrayLimit;
        const static int centreArrayLimit;
        

        // Array in turn: Corners, Edges, corners, edges, Centre
        int* piecesState;
        
		CrazyCubeCache* crazyCubeCachePtr;
    /* If we want the methods defined below to be private, but want to be able to test them we can use the following:
     * 
     * #ifdef TEST
     * public:
     * #else 
     * private
     * #endif
     * 
     * And add the -D TEST option to the compiler, when compiling our tests
     */
	public:
		
		CrazyCubeMapper();
		// helpful methods
		
		void swapMapElementValue(int width, vector<int>& vect, short int oldValue, short int newValue);
		// pruning maps
		vector<int> generateOuterCornersPruneMap(int length, int maxMoves);
		vector<int> generateOuterEdgesPruneMap(int length, int maxMoves);
		vector<int> generateInnerCornersPruneMap(int length, int maxMoves);
		vector<int> generateInnerEdgesPruneMap(int length, int maxMoves);
		vector<int> generateCentrePruneMap(int length, int maxMoves);

		int generateOuterCornersPruneMapIter(int depth, int maxDepth, int& outerCorners, vector<int>& outerCornersPruneMap, short int prevMove);
		int generateOuterEdgesPruneMapIter(int depth, int maxDepth, int& outerEdges, vector<int>& outerEdgesPruneMap, short int prevMove);
		int generateInnerCornersPruneMapIter(int depth, int maxDepth, int& innerCorners, vector<int>& innerCornersPruneMap, short int prevMove);
		int generateInnerEdgesPruneMapIter(int depth, int maxDepth, int& innerEdges, vector<int>& innerEdgesPruneMap, short int prevMove);
		int generateCentrePruneMapIter(int depth, int maxDepth, int& centre, vector<int>& centrePruneMap, short int prevMove);
		
        unsigned long long convertIntArrayToCubeState(int,int,int,int,int);
};

#endif /* CRAZYCUBEMAPPER_H_ */
