/*
 * InnerEdgesMapGenerator.h
 *
 * Created on: Jun 12, 2016
 *      Author: qwrtln
 */
#ifndef INNER_EDGES_MOVE_MAP_GENERATOR_H
#define INNER_EDGES_MOVE_MAP_GENERATOR_H
#include "MoveMapsGeneratorI.h"

class InnerEdgesMapGenerator: public MoveMapsGeneratorI
{
#if defined(TESTING) || defined(MEMORY_CHECK)
  public:
#endif
    int convertPiecesToInt(unsigned long long);
    unsigned long long convertIntToPieces(int);
    int getMapLength();
};

#endif /* INNER_EDGES_MOVE_MAP_GENERATOR_H */

