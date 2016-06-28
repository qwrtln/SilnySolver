#include "CentreMapGenerator.h"

int CentreMapGenerator::convertPiecesToInt(unsigned long long cubeState)
{
	return extractInnerPiece(CENTRE_MOST_SIGNIFICANT, 0, cubeState);
}


unsigned long long CentreMapGenerator::convertIntToPieces(int centre)
{
	return ((unsigned long long)centre << CENTRE_MOST_SIGNIFICANT);
}

int CentreMapGenerator::getMapLength()
{
    return factorials[2];
}
