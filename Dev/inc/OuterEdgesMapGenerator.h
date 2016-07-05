/*
 * OuterEdgesMapGenerator.h
 *
 * Created on: Jun 13, 2016
 *      Author: OPTIMUS
 */
#ifndef OUTER_EDGES_MOVE_MAP_GENERATOR_H
#define OUTER_EDGES_MOVE_MAP_GENERATOR_H
#include "MoveMapsGeneratorI.h"

class OuterEdgesMapGenerator: public MoveMapsGeneratorI
{
#if defined(TESTING) || defined(MEMORY_CHECK)
  public:
#endif
    int convertPiecesToInt(unsigned long long);
    unsigned long long convertIntToPieces(int);
    int getMapLength();
};

#endif /* OUTER_EDGES_MOVE_MAP_GENERATOR_H */

