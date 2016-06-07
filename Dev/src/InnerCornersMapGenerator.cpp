#include "InnerCornersMapGenerator.h"

int InnerCornersMapGenerator::convertPiecesToInt(unsigned long long cubeState)
{
	int sum = 0;
	for(int i = 0; i < NUM_OF_CORNERS; i++)
	{
		sum+= extractInnerPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState) * pow2toX[NUM_OF_CORNERS - 1 - i];
		
	}
	return sum;
}

unsigned long long InnerCornersMapGenerator::convertIntToPieces(int innerCorners)
{
	unsigned long long result = 0;
	for(int i = 0; i < NUM_OF_CORNERS; i++)
	{
		result |= ((unsigned long long)(innerCorners & 1)  <<  (i*4 + CORNERS_LEAST_SIGNIFICANT));
		innerCorners /= 2;
	}
	return result;
}

int InnerCornersMapGenerator::getMapLength()
{
    return pow2toX[NUM_OF_CORNERS];
}
