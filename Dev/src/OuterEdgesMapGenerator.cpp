#include "OuterEdgesMapGenerator.h"

int OuterEdgesMapGenerator::getMapLength() 
{
    return factorials[NUM_OF_EDGES]; 
}

int OuterEdgesMapGenerator::convertPiecesToInt(unsigned long long cubeState) 
{ 
  int sum = 0;
	for(int i = NUM_OF_EDGES - 1; i > 0; --i)
	{
    int edgesLeft = 0;
		for(int j = i - 1; j >= 0; --j) 
    {
			if(extractOuterPiece(EDGES_MOST_SIGNIFICANT, j, cubeState) > extractOuterPiece(EDGES_MOST_SIGNIFICANT, i, cubeState))
				++edgesLeft;
		}
		sum+= edgesLeft * factorials[i];
	}
	return sum;
}

unsigned long long OuterEdgesMapGenerator::convertIntToPieces(int edges) 
{
	unsigned long long crazyCubeState = 0;
	for(int i = 0; i < NUM_OF_EDGES; ++i) {
		temporaryPieceContainer[i] = i;
	}
	int rem = 0;
	int quot = 0;
	for(int i = NUM_OF_EDGES - 1; i >= 0; --i) {
		rem = edges % factorials[i];
		quot = edges / factorials[i];
		int k = 0;
		for(int j = NUM_OF_EDGES - 1; j >= 0; --j) {
			if(temporaryPieceContainer[j] < 0)
				continue;
			k++;
			if(k > quot) {
				crazyCubeState |= ((unsigned long long)(temporaryPieceContainer[j])    <<    (EDGES_MOST_SIGNIFICANT + 1 - i*4));
				temporaryPieceContainer[j] = -1;
				break;
			}
		}
		edges = rem;
	}
	return crazyCubeState;
}
