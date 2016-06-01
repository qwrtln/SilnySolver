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

std::vector<std::vector<int>> MoveMapsGeneratorI::generateMoveMap()
{
    cube.resetCube();

    std::vector<std::vector<int>> pieceMap = std::vector<std::vector<int>>(this->setMapLength());

    // Each itration generates one row of movements
    for (int i = 0; i < this->setMapLength(); ++i)
    {
        cube.setCubeState(this->convertPiecesToInt(i));
        pieceMap[i] =  std::vector<int>(NUM_OF_MOVES);
        for (int j = 0; j < NUM_OF_MOVES; ++j)
        {
            cube.move(static_cast<rotation>(j));
            // Here's where we remember cube state in the array:
            pieceMap[i][j] = this->convertPiecesToInt(cube.getCubeState());
            cube.undoMove(static_cast<rotation>(j));
        }

    }

    return pieceMap;
}
