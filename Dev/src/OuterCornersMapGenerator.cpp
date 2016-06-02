#include "OuterCornersMapGenerator.h"

int OuterCornersMapGenerator::getMapLength()
{
    return factorials[NUM_OF_EDGES]; 
}

int OuterCornersMapGenerator::convertPiecesToInt(unsigned long long cubeState)
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

unsigned long long OuterCornersMapGenerator::convertIntToPieces(int outerCorners)
{
	unsigned long long crazyCubeState = 0;
	for(int i = 0; i < NUM_OF_CORNERS; i++)
	{
		temporaryPieceContainer[i] = i;
	}
	int rem = 0;
	int quot = 0;
	for(int i = NUM_OF_CORNERS - 1; i >= 0; i--)
	{
		rem = outerCorners % factorials[i];
		quot = outerCorners / factorials[i];
		int k = 0;
		for(int j = NUM_OF_CORNERS - 1; j >= 0; j--)
		{
			if(temporaryPieceContainer[j] < 0)
				continue;
			k++;
			if(k > quot)
			{
				crazyCubeState |= ((unsigned long long)(temporaryPieceContainer[j])    <<    (CORNERS_MOST_SIGNIFICANT + 1 - i*4));
				temporaryPieceContainer[j] = -1;
				break;
			}
		}
		outerCorners = rem;
	}

	return crazyCubeState;
}


