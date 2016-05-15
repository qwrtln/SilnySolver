#include "CrazyCubeMapper.h"

const int CrazyCubeMapper::NumberOfkindsOfPieces = 5;
const int CrazyCubeMapper::edgeArrayLimit = 40320; // Facotiral of NUM_OF_EDGES
const int CrazyCubeMapper::cornerArrayLimit = 5040; // Factorial of NUM_OF_CORNERS 
const int CrazyCubeMapper::centreArrayLimit = 1; // Factorial of 1 :-)))
int CrazyCubeMapper::tmp[NUM_OF_EDGES] = {0, 1, 2, 3, 4, 5, 6, 7};

CrazyCubeMapper:: CrazyCubeMapper()
{
	crazyCubeCachePtr = CrazyCubeCache::getInstance();
}
/*	  C	CCCCCCC EEEEEEEE
 *  0x1 02469BD 02469BDF;
 * 	
 * 	000 0  000 0  000 0  000 0  000 0  000 0  000 0
 * 	Gets the value of n-th outer corner piece
 * 	CORNERS_BASE = 56
 * 	EDGES_BASE = 28
 *	(cubeState & (0xE << (56-n*4))) >> ((56-n*4))
 */

// Utilities
int CrazyCubeMapper:: extractOuterPiece(int base, int index, unsigned long long cubeState)
{
	return (    (cubeState & (0xEULL << (base-index*4))) >> (base-index*4 + 1)    );
}

int CrazyCubeMapper:: extractInnerPiece(int base, int index, unsigned long long cubeState)
{
	return (    (cubeState & (0x1ULL << (base-index*4))) >> (base-index*4)    );
}

// Cube -> int CrazyCubeMapper::converters
int CrazyCubeMapper::convertOuterCornersToInt(unsigned long long cubeState)
{
	int sum = 0;
	for(int i = NUM_OF_CORNERS - 1; i > 0; i--)
	{
		int cornersLeft = 0; // ile rogow na lewo od aktualnego ma od niego wieksza wartosc
		for(int j = i - 1; j >= 0; j--)
		{
			 if(extractOuterPiece(CORNERS_MOST_SIGNIFICANT, j, cubeState) > extractOuterPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState))
				 cornersLeft++;
		}
		sum+= cornersLeft * factorials[i];
	}
	return sum;
}
int CrazyCubeMapper::convertOuterEdgesToInt(unsigned long long cubeState)
{
	int sum = 0;
	for(int i = NUM_OF_EDGES - 1; i > 0; i--)
	{
		int edgesLeft = 0;
		for(int j = i - 1; j >= 0; j--)
		{
			if(extractOuterPiece(EDGES_MOST_SIGNIFICANT, j, cubeState) > extractOuterPiece(EDGES_MOST_SIGNIFICANT, i, cubeState))
				edgesLeft++;
		}
		sum+= edgesLeft * factorials[i];
	}
	return sum;
}
int CrazyCubeMapper::convertInnerCornersToInt(unsigned long long cubeState)
{
	int sum = 0;
	for(int i = 0; i < NUM_OF_CORNERS; i++)
	{
		sum+= extractInnerPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState) * pow2toX[NUM_OF_CORNERS - 1 - i];
		
	}
	return sum;
}
int CrazyCubeMapper::convertInnerEdgesToInt(unsigned long long cubeState)
{
	int sum = 0;
	for(int i = 0; i < NUM_OF_EDGES; i++)
	{
		sum+= extractInnerPiece(EDGES_MOST_SIGNIFICANT, i, cubeState) * pow2toX[NUM_OF_EDGES - 1 - i];
	}
	return sum;
}
int CrazyCubeMapper::convertCentreToInt(unsigned long long cubeState)
{
	return extractInnerPiece(CENTRE_MOST_SIGNIFICANT, 0, cubeState);
}


// int CrazyCubeMapper::-> Cube converters
unsigned long long CrazyCubeMapper::convertIntToOuterCorners(int corners)
{
	unsigned long long crazyCubeState = 0;
	for(int i = 0; i < NUM_OF_CORNERS; i++)
	{
		tmp[i] = i;
	}
	int rem = 0;
	int quot = 0;
	for(int i = NUM_OF_CORNERS - 1; i >= 0; i--)
	{
		rem = corners % factorials[i];
		quot = corners / factorials[i];
		int k = 0;
		for(int j = NUM_OF_CORNERS - 1; j >= 0; j--)
		{
			if(tmp[j] < 0)
				continue;
			k++;
			if(k > quot)
			{
				crazyCubeState |= ((unsigned long long)(tmp[j])    <<    (CORNERS_MOST_SIGNIFICANT + 1 - i*4));
				tmp[j] = -1;
				break;
			}
		}
		corners = rem;
	}

	return crazyCubeState;
}
unsigned long long CrazyCubeMapper::convertIntToOuterEdges(int edges)
{
	unsigned long long crazyCubeState = 0;
	for(int i = 0; i < NUM_OF_EDGES; i++)
	{
		tmp[i] = i;
	}
	int rem = 0;
	int quot = 0;
	for(int i = NUM_OF_EDGES - 1; i >= 0; i--)
	{
		rem = edges % factorials[i];
		quot = edges / factorials[i];
		int k = 0;
		for(int j = NUM_OF_EDGES - 1; j >= 0; j--)
		{
			if(tmp[j] < 0)
				continue;
			k++;
			if(k > quot)
			{
				crazyCubeState |= ((unsigned long long)(tmp[j])    <<    (EDGES_MOST_SIGNIFICANT + 1 - i*4));
				tmp[j] = -1;
				break;
			}
		}
		edges = rem;
	}
	return crazyCubeState;
}
 
unsigned long long CrazyCubeMapper::convertIntToInnerCorners(int innerCorners)
{
	unsigned long long result = 0;
	for(int i = 0; i < NUM_OF_CORNERS; i++)
	{
		result |= ((unsigned long long)(innerCorners & 1)  <<  (i*4 + CORNERS_LEAST_SIGNIFICANT));
		innerCorners /= 2;
	}
	return result;
}
unsigned long long CrazyCubeMapper::convertIntToInnerEdges(int innerEdges)
{
	unsigned long long result = 0;
	for(int i = 0; i < NUM_OF_EDGES; i++)
	{
		result |= ((unsigned long long)(innerEdges & 1)  <<  (i*4));
		innerEdges /= 2;
	}
	return result;
}

unsigned long long CrazyCubeMapper::convertIntToCentre(int centre)
{
	return ((unsigned long long)centre << CENTRE_MOST_SIGNIFICANT);
}


///////////////////////////////////////////
//
// Functions to be used by end-user
//
//////////////////////////////////////////

std::vector<std::vector<int>> CrazyCubeMapper::generateOuterCornersMap()
{
    return generatePieceMap(factorials[NUM_OF_CORNERS],&CrazyCubeMapper::convertIntToOuterCorners,&CrazyCubeMapper::convertOuterCornersToInt);
}

std::vector<std::vector<int>> CrazyCubeMapper::generateOuterEdgesMap()
{
	return generatePieceMap(factorials[NUM_OF_EDGES],&CrazyCubeMapper::convertIntToOuterEdges,&CrazyCubeMapper::convertOuterEdgesToInt);
}

std::vector<std::vector<int>> CrazyCubeMapper::generateInnerCornersMap()
{
    return generatePieceMap(pow2toX[NUM_OF_CORNERS], &CrazyCubeMapper::convertIntToInnerCorners,&CrazyCubeMapper::convertInnerCornersToInt);
}

std::vector<std::vector<int>> CrazyCubeMapper::generateInnerEdgesMap()
{
	return generatePieceMap(pow2toX[NUM_OF_EDGES],&CrazyCubeMapper::convertIntToInnerEdges,&CrazyCubeMapper::convertInnerEdgesToInt);
}

std::vector<std::vector<int>> CrazyCubeMapper::generateCentreMap()
{
	return generatePieceMap(factorials[2],&CrazyCubeMapper::convertIntToCentre,&CrazyCubeMapper::convertCentreToInt);
}

// This is a generic map function called by the public ones
std::vector<std::vector<int>> CrazyCubeMapper::generatePieceMap(const int arrayLength,unsigned long long (CrazyCubeMapper::*convertingToPiecesFunction)(int), int (CrazyCubeMapper::*convertingToIntFunction)(unsigned long long) )
{
    cube.resetCube();

    std::vector<std::vector<int>> pieceMap = std::vector<std::vector<int>>(arrayLength);

    // Each itration generates one row of movements
    for (int i = 0; i < arrayLength; ++i)
    {
        cube.setCubeState( (this->*convertingToPiecesFunction)(i));
        pieceMap[i] =  std::vector<int>(NUM_OF_MOVES);
        for (int j = 0; j < NUM_OF_MOVES; ++j)
        {
            cube.move(static_cast<rotation>(j));
            // Here's where we remember cube state in the array:
            pieceMap[i][j] = (this->*convertingToIntFunction)(cube.getCubeState());
            cube.undoMove(static_cast<rotation>(j));
        }

    }

    return pieceMap;
}

unsigned long long CrazyCubeMapper::convertIntArrayToCubeState(int CP, int cp, int EP, int ep, int Centre)
{
    return convertIntToOuterCorners(CP) |
           convertIntToOuterEdges(EP)   |
           convertIntToInnerCorners(cp) |
           convertIntToInnerEdges(ep)   |
           convertIntToCentre(Centre);

}

void CrazyCubeMapper::swapMapElementValue(int width, vector<int>& vect, short int oldValue, short int newValue)
{
	for(int i = 0; i < width; i++)
	{
		if(vect[i] == oldValue)
		{
			vect[i] = newValue;
		}
	}
}

vector<int> CrazyCubeMapper::generateOuterCornersPruneMap(int length, int maxMoves)
{
	vector<int> outerCornersPruneMap = vector<int>(length); 
	for(int i = 0; i < length; i++)
	{
		outerCornersPruneMap[i] = 100;
	}
	int outerCorners = 0;
	generateOuterCornersPruneMapIter(1, maxMoves, outerCorners, outerCornersPruneMap, -1);
	swapMapElementValue(length, outerCornersPruneMap, 100, -1);
	return outerCornersPruneMap;
}

vector<int> CrazyCubeMapper::generateOuterEdgesPruneMap(int length, int maxMoves)
{
	vector<int> outerEdgesPruneMap = vector<int>(length); 
	for(int i = 0; i < length; i++)
	{
		outerEdgesPruneMap[i] = 100;
	}
	int outerEdges = 0;
	generateOuterEdgesPruneMapIter(1, maxMoves, outerEdges, outerEdgesPruneMap, -1);
	swapMapElementValue(length, outerEdgesPruneMap, 100, -1);
	return outerEdgesPruneMap;
}

vector<int> CrazyCubeMapper::generateInnerCornersPruneMap(int length, int maxMoves)
{
	vector<int> innerCornersPruneMap = vector<int>(length); 
	for(int i = 0; i < length; i++)
	{
		innerCornersPruneMap[i] = 100;
	}
	int innerCorners = 0;
	generateInnerCornersPruneMapIter(1, maxMoves, innerCorners, innerCornersPruneMap, -1);
	swapMapElementValue(length, innerCornersPruneMap, 100, -1);
	return innerCornersPruneMap;
}

vector<int> CrazyCubeMapper::generateInnerEdgesPruneMap(int length, int maxMoves)
{
	vector<int> innerEdgesPruneMap = vector<int>(length); 
	for(int i = 0; i < length; i++)
	{
		innerEdgesPruneMap[i] = 100;
	}
	int innerEdges = 0;
	generateInnerEdgesPruneMapIter(1, maxMoves, innerEdges, innerEdgesPruneMap, -1);
	swapMapElementValue(length, innerEdgesPruneMap, 100, -1);
	return innerEdgesPruneMap;
}

vector<int> CrazyCubeMapper::generateCentrePruneMap(int length, int maxMoves)
{
	vector<int> centrePruneMap = vector<int>(length); 
	for(int i = 0; i < length; i++)
	{
		centrePruneMap[i] = 100;
	}
	int centre = 0;
	generateCentrePruneMapIter(1, maxMoves, centre, centrePruneMap, -1);
	swapMapElementValue(length, centrePruneMap, 100, -1);
	return centrePruneMap;
}


int CrazyCubeMapper::generateOuterCornersPruneMapIter(int depth, int maxDepth, int& outerCorners, vector<int>& outerCornersPruneMap, short int prevMove)
{
	if(depth <= maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}
			
			if(depth < outerCornersPruneMap[crazyCubeCachePtr->getOuterCornersMap()[outerCorners][i]])
				outerCornersPruneMap[crazyCubeCachePtr->getOuterCornersMap()[outerCorners][i]] = depth;
			generateOuterCornersPruneMapIter(depth + 1, maxDepth, crazyCubeCachePtr->getOuterCornersMap()[outerCorners][i], outerCornersPruneMap, prevMove);
		}
	}
	return 0;
}

int CrazyCubeMapper::generateOuterEdgesPruneMapIter(int depth, int maxDepth, int& outerEdges, vector<int>& outerEdgesPruneMap, short int prevMove)
{
	if(depth <= maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}
			
			if(depth < outerEdgesPruneMap[crazyCubeCachePtr->getOuterEdgesMap()[outerEdges][i]])
				outerEdgesPruneMap[crazyCubeCachePtr->getOuterEdgesMap()[outerEdges][i]] = depth;
			generateOuterEdgesPruneMapIter(depth + 1, maxDepth, crazyCubeCachePtr->getOuterEdgesMap()[outerEdges][i], outerEdgesPruneMap, prevMove);
		}
	}
	return 0;
}

int CrazyCubeMapper::generateInnerCornersPruneMapIter(int depth, int maxDepth, int& innerCorners, vector<int>& innerCornersPruneMap, short int prevMove)
{
	if(depth <= maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}
			
			if(depth < innerCornersPruneMap[crazyCubeCachePtr->getInnerCornersMap()[innerCorners][i]])
				innerCornersPruneMap[crazyCubeCachePtr->getInnerCornersMap()[innerCorners][i]] = depth;
			generateInnerCornersPruneMapIter(depth + 1, maxDepth, crazyCubeCachePtr->getInnerCornersMap()[innerCorners][i], innerCornersPruneMap, prevMove);
		}
	}
	return 0;
}

int CrazyCubeMapper::generateInnerEdgesPruneMapIter(int depth, int maxDepth, int& innerEdges, vector<int>& innerEdgesPruneMap, short int prevMove)
{
	if(depth <= maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}
			
			if(depth < innerEdgesPruneMap[crazyCubeCachePtr->getInnerEdgesMap()[innerEdges][i]])
				innerEdgesPruneMap[crazyCubeCachePtr->getInnerEdgesMap()[innerEdges][i]] = depth;
			generateInnerEdgesPruneMapIter(depth + 1, maxDepth, crazyCubeCachePtr->getInnerEdgesMap()[innerEdges][i], innerEdgesPruneMap, prevMove);
		}
	}
	return 0;
}

int CrazyCubeMapper::generateCentrePruneMapIter(int depth, int maxDepth, int& centre, vector<int>& centrePruneMap, short int prevMove)
{
	if(depth <= maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}
			
			if(depth < centrePruneMap[crazyCubeCachePtr->getCentreMap()[centre][i]])
				centrePruneMap[crazyCubeCachePtr->getCentreMap()[centre][i]] = depth;
			generateCentrePruneMapIter(depth + 1, maxDepth, crazyCubeCachePtr->getCentreMap()[centre][i], centrePruneMap, prevMove);
		}
	}
	return 0;
}

