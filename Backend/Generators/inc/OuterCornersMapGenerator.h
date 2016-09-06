/*
 * OuterCornersMapGenerator.h
 *
 * Created on: Jun 1, 2016
 *      Author: qwrtln
 */
#ifndef OUTER_CORNERS_MOVE_MAP_GENERATOR_H
#define OUTER_CORNERS_MOVE_MAP_GENERATOR_H
#include "MoveMapsGeneratorI.h"

class OuterCornersMapGenerator: public MoveMapsGeneratorI
{
  public:
    int convertPiecesToInt(unsigned long long);
    unsigned long long convertIntToPieces(int);
    int getMapLength();
};

#endif /* OUTER_CORNERS_MOVE_MAP_GENERATOR_H */

