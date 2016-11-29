/*
 * PruneMapsGeneratorI.cpp
 *
 * Created on: Oct 1, 2016
 *      Author: qwrtln
 */
#include "PruneMapsGeneratorI.h"

const int PruneMapsGeneratorI::edgeArrayLimit = 40320; // Facotiral of NUM_OF_EDGES
const int PruneMapsGeneratorI::cornerArrayLimit = 5040; // Factorial of NUM_OF_CORNERS
const int PruneMapsGeneratorI::centreArrayLimit = 1; // Factorial of 1 :-)))

PruneMapsGeneratorI:: PruneMapsGeneratorI()
{
	crazyCubeCachePtr = CrazyCubeCache::getInstance();
}

void PruneMapsGeneratorI::swapMapElementValue(int width, std::vector<int>& vect, short int oldValue, short int newValue)
{
	for(int i = 0; i < width; i++)
	{
		if(vect[i] == oldValue)
		{
			vect[i] = newValue;
		}
	}
}

std::vector<int> PruneMapsGeneratorI::generateInitialVector(int length)
{
    std::vector<int> pruneMap(length);
    int safeBound = 100;    // This is the depth, which we'll definitely not cross, sine we do not know the exact number (for standard cube it's 20)
    std::fill(pruneMap.begin()+1,pruneMap.end(),safeBound);

    return pruneMap;
}

std::vector<int> PruneMapsGeneratorI::generatePruneMap(int length)
{
    pruneMap = generateInitialVector(mapSize);
    int pieces = 0;
	this->maxDepth = length;
	generatePruneMapIter(1, pieces, -1);
	swapMapElementValue(mapSize, pruneMap, 100, -1);
	return pruneMap;
}

int PruneMapsGeneratorI::generatePruneMapIter(int depth, int& pieces, short int prevMove)
{
	if(depth <= this->maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}

            if(depth < pruneMap[getPieceMap()[pieces][i]])
            {
				pruneMap[getPieceMap()[pieces][i]] = depth;
            }
			generatePruneMapIter(depth + 1, getPieceMap()[pieces][i], i);
		}
	}
	return 0;
}
