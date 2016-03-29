#include "CrazyCubeMapper.h"

const int CrazyCubeMapper::NumberOfkindsOfPieces = 5;
const int CrazyCubeMapper::edgeArrayLimit = 40320; // Facotiral of NUM_OF_EDGES
const int CrazyCubeMapper::cornerArrayLimit = 5040; // Factorial of NUM_OF_CORNERS 
const int CrazyCubeMapper::centreArrayLimit = 1; // Factorial of 1 :-)))
int CrazyCubeMapper::tmp[NUM_OF_EDGES] = {0, 1, 2, 3, 4, 5, 6, 7};


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

int** CrazyCubeMapper::generateOuterCornersMap()
{
    return generatePieceMap(factorials[NUM_OF_CORNERS],&CrazyCubeMapper::convertIntToOuterCorners,&CrazyCubeMapper::convertOuterCornersToInt);
}

int** CrazyCubeMapper::generateOuterEdgesMap()
{
	return generatePieceMap(factorials[NUM_OF_EDGES],&CrazyCubeMapper::convertIntToOuterEdges,&CrazyCubeMapper::convertOuterEdgesToInt);
}

int** CrazyCubeMapper::generateInnerCornersMap()
{
    return generatePieceMap(pow2toX[NUM_OF_CORNERS], &CrazyCubeMapper::convertIntToInnerCorners,&CrazyCubeMapper::convertInnerCornersToInt);
}

int** CrazyCubeMapper::generateInnerEdgesMap()
{
	return generatePieceMap(pow2toX[NUM_OF_EDGES],&CrazyCubeMapper::convertIntToInnerEdges,&CrazyCubeMapper::convertInnerEdgesToInt);
}

int** CrazyCubeMapper::generateCentreMap()
{
	return generatePieceMap(factorials[2],&CrazyCubeMapper::convertIntToCentre,&CrazyCubeMapper::convertCentreToInt);
}

// This is a generic map function called by the public ones
int** CrazyCubeMapper::generatePieceMap(const int arrayLength,unsigned long long (CrazyCubeMapper::*convertingToPiecesFunction)(int), int (CrazyCubeMapper::*convertingToIntFunction)(unsigned long long) )
{
    cube.resetCube();

    int** pieceMap;
    pieceMap = new int*[arrayLength];

    // Each itration generates one row of movements
    for (int i = 0; i < arrayLength; ++i)
    {
        cube.setCubeState( (this->*convertingToPiecesFunction)(i));
		pieceMap[i] = new int[NUM_OF_MOVES];
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

