/*
 * CentreMapGenerator.h
 *
 * Created on: Jun 12, 2016
 *      Author: qwrtln
 */
#ifndef CENTRE_MOVE_MAP_GENERATOR_H
#define CENTRE_MOVE_MAP_GENERATOR_H
#include "MoveMapsGeneratorI.h"

class CentreMapGenerator: public MoveMapsGeneratorI
{
#if defined(TESTING) || defined(MEMORY_CHECK)
  public:
#endif
    int convertPiecesToInt(unsigned long long);
    unsigned long long convertIntToPieces(int);
    int getMapLength();
};

#endif /* CENTRE_MOVE_MAP_GENERATOR_H */


