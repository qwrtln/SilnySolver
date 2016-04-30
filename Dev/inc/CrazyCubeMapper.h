#ifndef CRAZYCUBEMAPPER_H_
#define CRAZYCUBEMAPPER_H_

#include "CrazyCube.h"
#include "CrazyCubeAbstract.h"
#include <cmath>
#include <vector>

class CrazyCubeMapper: public CrazyCubeAbstract
{
    private:
        const static int NumberOfkindsOfPieces;
        const static int edgeArrayLimit;
        const static int cornerArrayLimit;
        const static int centreArrayLimit;
        

        // Array in turn: Corners, Edges, corners, edges, Centre
        int* piecesState;
        
        // Useful tmp array
        static int tmp[NUM_OF_EDGES];
        
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
		
		// Single outer pieces extractor
		// base = 28 for edges
		// base = 56 for corners
		int extractOuterPiece(int base, int index, unsigned long long cubeState);
		// Single inner pieces extractor
		// base = 28 for edges
		// base = 56 for corners
		int extractInnerPiece(int base, int index, unsigned long long cubeState);
		
        // Cube -> Int converters
        int convertOuterCornersToInt(unsigned long long);
        int convertOuterEdgesToInt(unsigned long long);
        int convertInnerCornersToInt(unsigned long long);
        int convertInnerEdgesToInt(unsigned long long);
        int convertCentreToInt(unsigned long long);

        // Int -> Cube converters
        unsigned long long convertIntToOuterCorners(int);
        unsigned long long convertIntToOuterEdges(int);
        unsigned long long convertIntToInnerCorners(int);
        unsigned long long convertIntToInnerEdges(int);
        unsigned long long convertIntToCentre(int);

        std::vector<std::vector<int>> generatePieceMap(const int, unsigned long long (CrazyCubeMapper::*convertingToIntFunction)(int), int (CrazyCubeMapper::*convertingToPiecesFunction)(unsigned long long));

        CrazyCube cube;

        std::vector<std::vector<int>> generateOuterCornersMap();
        std::vector<std::vector<int>> generateOuterEdgesMap();
        std::vector<std::vector<int>> generateInnerCornersMap();
        std::vector<std::vector<int>> generateInnerEdgesMap();
        std::vector<std::vector<int>> generateCentreMap();

        unsigned long long convertIntArrayToCubeState(int,int,int,int,int);
};

#endif /* CRAZYCUBEMAPPER_H_ */
