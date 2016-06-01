#include "MoveMapsGeneratorI.h"

int MoveMapsGeneratorI::temporaryPieceContainer[NUM_OF_EDGES] = {0, 1, 2, 3, 4, 5, 6, 7};

int MoveMapsGeneratorI:: extractOuterPiece(int base, int index, unsigned long long cubeState)
{
	return (    (cubeState & (0xEULL << (base-index*4))) >> (base-index*4 + 1)    );
}

int MoveMapsGeneratorI:: extractInnerPiece(int base, int index, unsigned long long cubeState)
{
	return (    (cubeState & (0x1ULL << (base-index*4))) >> (base-index*4)    );
}

