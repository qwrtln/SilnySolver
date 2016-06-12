/*
 * CrazyCubeMoveMapper.h
 *
 * Created on: May 29, 2016
 *      Author: qwrtln
 */
#include "CrazyCubeMoveMapper.h"

int CrazyCubeMoveMapper::temporaryPieceContainer[NUM_OF_EDGES] = {0, 1, 2, 3, 4, 5, 6, 7};

// Utilities
int CrazyCubeMoveMapper:: extractOuterPiece(int base, int index, unsigned long long cubeState)
{
	return (    (cubeState & (0xEULL << (base-index*4))) >> (base-index*4 + 1)    );
}

int CrazyCubeMoveMapper:: extractInnerPiece(int base, int index, unsigned long long cubeState)
{
	return (    (cubeState & (0x1ULL << (base-index*4))) >> (base-index*4)    );
}

// Cube -> int CrazyCubeMoveMapper::converters
int CrazyCubeMoveMapper::convertOuterEdgesToInt(unsigned long long cubeState)
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

// int CrazyCubeMoveMapper::-> Cube converters
unsigned long long CrazyCubeMoveMapper::convertIntToOuterEdges(int edges)
{
	unsigned long long crazyCubeState = 0;
	for(int i = 0; i < NUM_OF_EDGES; i++)
	{
		temporaryPieceContainer[i] = i;
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
			if(temporaryPieceContainer[j] < 0)
				continue;
			k++;
			if(k > quot)
			{
				crazyCubeState |= ((unsigned long long)(temporaryPieceContainer[j])    <<    (EDGES_MOST_SIGNIFICANT + 1 - i*4));
				temporaryPieceContainer[j] = -1;
				break;
			}
		}
		edges = rem;
	}
	return crazyCubeState;
}
 


// This is the generic map function called by the public ones
std::vector<std::vector<int>> CrazyCubeMoveMapper::generatePieceMap(const int arrayLength,unsigned long long (CrazyCubeMoveMapper::*convertingToPiecesFunction)(int), int (CrazyCubeMoveMapper::*convertingToIntFunction)(unsigned long long) )
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

///////////////////////////////////////////
//
// Functions to be used by end-user
//
//////////////////////////////////////////


std::vector<std::vector<int>> CrazyCubeMoveMapper::generateOuterEdgesMap()
{
	return generatePieceMap(factorials[NUM_OF_EDGES],&CrazyCubeMoveMapper::convertIntToOuterEdges,&CrazyCubeMoveMapper::convertOuterEdgesToInt);
}

