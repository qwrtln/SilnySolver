#include "InnerEdgesMapGenerator.h"

int InnerEdgesMapGenerator::convertPiecesToInt(unsigned long long cubeState)
{
	int sum = 0;
	for(int i = 0; i < NUM_OF_EDGES; i++)
	{
		sum+= extractInnerPiece(EDGES_MOST_SIGNIFICANT, i, cubeState) * pow2toX[NUM_OF_EDGES - 1 - i];
	}
	return sum;
}

unsigned long long InnerEdgesMapGenerator::convertIntToPieces(int innerEdges)
{
	unsigned long long result = 0;
	for(int i = 0; i < NUM_OF_EDGES; i++)
	{
		result |= ((unsigned long long)(innerEdges & 1)  <<  (i*4));
		innerEdges /= 2;
	}
	return result;
}

int InnerEdgesMapGenerator::getMapLength()
{
    return pow2toX[NUM_OF_EDGES];
}
