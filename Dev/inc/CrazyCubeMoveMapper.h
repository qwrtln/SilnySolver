/*
 * CrazyCubeMoveMapper.h
 *
 * Created on: May 29, 2016
 *      Author: qwrtln
 */

#ifndef CRAZYCUBEMOVEMAPPER_H_
#define CRAZYCUBEMOVEMAPPER_H_
#include "CrazyCubeAbstract.h"
#include "CrazyCube.h"
#include <vector>

////////////////////////////////
// 
// This class generates basic  and 
// necessary move maps, which are stored 
// in CrazyCubeCache.
//
///////////////////////////////

class CrazyCubeMoveMapper: public CrazyCubeAbstract
{
        // Cube to operate on
		CrazyCube cube;

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

        ///////////////////////////////
        // Utilites used by converters:
        ///////////////////////////////
        //
		// Single outer pieces extractor
		// base = 28 for edges
		// base = 56 for corners
		int extractOuterPiece(int base, int index, unsigned long long cubeState);
		// Single inner pieces extractor
		// base = 28 for edges
		// base = 56 for corners
		int extractInnerPiece(int base, int index, unsigned long long cubeState);
        //
        // Useful array
        static int temporaryPieceContainer[NUM_OF_EDGES];

        // Generic function - using pointers to methods so as not to implemend the same functionality five times
        std::vector<std::vector<int>> generatePieceMap(const int, unsigned long long (CrazyCubeMoveMapper::*convertingToIntFunction)(int), int (CrazyCubeMoveMapper::*convertingToPiecesFunction)(unsigned long long));


    public:
        std::vector<std::vector<int>> generateOuterCornersMap();
        std::vector<std::vector<int>> generateOuterEdgesMap();
        std::vector<std::vector<int>> generateInnerCornersMap();
        std::vector<std::vector<int>> generateInnerEdgesMap();
        std::vector<std::vector<int>> generateCentreMap();
};


#endif /* CRAZYCUBEMOVEMAPPER_H_ */

