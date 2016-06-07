/*
 * InnerCornersMapGenerator.h
 *
 * Created on: Jun 7, 2016
 *      Author: qwrtln
 */
#ifndef INNER_CORNERS_MOVE_MAP_GENERATOR_H
#define INNER_CORNERS_MOVE_MAP_GENERATOR_H
#include "MoveMapsGeneratorI.h"

class InnerCornersMapGenerator: public MoveMapsGeneratorI
{
#if defined(TESTING) || defined(MEMORY_CHECK)
  public:
#endif
    int convertPiecesToInt(unsigned long long);
    unsigned long long convertIntToPieces(int);
    int getMapLength();
};

#endif /* INNER_CORNERS_MOVE_MAP_GENERATOR_H */

