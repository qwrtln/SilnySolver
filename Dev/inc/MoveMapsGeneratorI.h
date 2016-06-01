/*
 * CrazyCubeMoveMapper.h
 *
 * Created on: Jun 1, 2016
 *      Author: qwrtln
 */

#ifndef MOVEMAPGENERATORI_H_
#define MOVEMAPGENERATORI_H_
#include "CrazyCubeAbstract.h"
#include <vector>

class MoveMapsGeneratorI: public CrazyCubeAbstract
{
        virtual int convertPiecesToInt(unsigned long long) = 0;

        virtual unsigned long long convertIntToPieces(int) = 0;

        int extractOuterPiece(int,int,unsigned long long);
        int extractInnerPiece(int,int,unsigned long long);

        static int temporaryPieceContainer[NUM_OF_EDGES];

    public:
        virtual std::vector<std::vector<int>> generateMoveMap() = 0;


};

#endif /* MOVEMAPGENERATORI_H_ */ 
