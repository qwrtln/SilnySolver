#include "PruneMapGenerator.h"

const int PruneMapGenerator::NumberOfkindsOfPieces = 5;
const int PruneMapGenerator::edgeArrayLimit = 40320; // Facotiral of NUM_OF_EDGES
const int PruneMapGenerator::cornerArrayLimit = 5040; // Factorial of NUM_OF_CORNERS 
const int PruneMapGenerator::centreArrayLimit = 1; // Factorial of 1 :-)))

PruneMapGenerator:: PruneMapGenerator()
{
	crazyCubeCachePtr = CrazyCubeCache::getInstance();
}
/*	  C	CCCCCCC EEEEEEEE
 *  0x1 02469BD 02469BDF;
 * 	
 * 	000 0  000 0  000 0  000 0  000 0  000 0  000 0
 * 	Gets the value of n-th outer corner piece
 * 	CORNERS_BASE = 56
 * 	EDGES_BASE = 28
 *	(cubeState & (0xE << (56-n*4))) >> ((56-n*4))
 */

void PruneMapGenerator::swapMapElementValue(int width, vector<int>& vect, short int oldValue, short int newValue)
{
	for(int i = 0; i < width; i++)
	{
		if(vect[i] == oldValue)
		{
			vect[i] = newValue;
		}
	}
}

vector<int> PruneMapGenerator::generateOuterCornersPruneMap(int length, int maxMoves)
{
	vector<int> outerCornersPruneMap = vector<int>(length); 
	for(int i = 0; i < length; i++)
	{
		outerCornersPruneMap[i] = 100;
	}
	int outerCorners = 0;
	generateOuterCornersPruneMapIter(1, maxMoves, outerCorners, outerCornersPruneMap, -1);
	swapMapElementValue(length, outerCornersPruneMap, 100, -1);
	return outerCornersPruneMap;
}

vector<int> PruneMapGenerator::generateOuterEdgesPruneMap(int length, int maxMoves)
{
	vector<int> outerEdgesPruneMap = vector<int>(length); 
	for(int i = 0; i < length; i++)
	{
		outerEdgesPruneMap[i] = 100;
	}
	int outerEdges = 0;
	generateOuterEdgesPruneMapIter(1, maxMoves, outerEdges, outerEdgesPruneMap, -1);
	swapMapElementValue(length, outerEdgesPruneMap, 100, -1);
	return outerEdgesPruneMap;
}

vector<int> PruneMapGenerator::generateInnerCornersPruneMap(int length, int maxMoves)
{
	vector<int> innerCornersPruneMap = vector<int>(length); 
	for(int i = 0; i < length; i++)
	{
		innerCornersPruneMap[i] = 100;
	}
	int innerCorners = 0;
	generateInnerCornersPruneMapIter(1, maxMoves, innerCorners, innerCornersPruneMap, -1);
	swapMapElementValue(length, innerCornersPruneMap, 100, -1);
	return innerCornersPruneMap;
}

vector<int> PruneMapGenerator::generateInnerEdgesPruneMap(int length, int maxMoves)
{
	vector<int> innerEdgesPruneMap = vector<int>(length); 
	for(int i = 0; i < length; i++)
	{
		innerEdgesPruneMap[i] = 100;
	}
	int innerEdges = 0;
	generateInnerEdgesPruneMapIter(1, maxMoves, innerEdges, innerEdgesPruneMap, -1);
	swapMapElementValue(length, innerEdgesPruneMap, 100, -1);
	return innerEdgesPruneMap;
}

vector<int> PruneMapGenerator::generateCentrePruneMap(int length, int maxMoves)
{
	vector<int> centrePruneMap = vector<int>(length); 
	for(int i = 0; i < length; i++)
	{
		centrePruneMap[i] = 100;
	}
	int centre = 0;
	generateCentrePruneMapIter(1, maxMoves, centre, centrePruneMap, -1);
	swapMapElementValue(length, centrePruneMap, 100, -1);
	return centrePruneMap;
}


int PruneMapGenerator::generateOuterCornersPruneMapIter(int depth, int maxDepth, int& outerCorners, vector<int>& outerCornersPruneMap, short int prevMove)
{
	if(depth <= maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}
			
			if(depth < outerCornersPruneMap[crazyCubeCachePtr->getOuterCornersMap()[outerCorners][i]])
				outerCornersPruneMap[crazyCubeCachePtr->getOuterCornersMap()[outerCorners][i]] = depth;
			generateOuterCornersPruneMapIter(depth + 1, maxDepth, crazyCubeCachePtr->getOuterCornersMap()[outerCorners][i], outerCornersPruneMap, prevMove);
		}
	}
	return 0;
}

int PruneMapGenerator::generateOuterEdgesPruneMapIter(int depth, int maxDepth, int& outerEdges, vector<int>& outerEdgesPruneMap, short int prevMove)
{
	if(depth <= maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}
			
			if(depth < outerEdgesPruneMap[crazyCubeCachePtr->getOuterEdgesMap()[outerEdges][i]])
				outerEdgesPruneMap[crazyCubeCachePtr->getOuterEdgesMap()[outerEdges][i]] = depth;
			generateOuterEdgesPruneMapIter(depth + 1, maxDepth, crazyCubeCachePtr->getOuterEdgesMap()[outerEdges][i], outerEdgesPruneMap, prevMove);
		}
	}
	return 0;
}

int PruneMapGenerator::generateInnerCornersPruneMapIter(int depth, int maxDepth, int& innerCorners, vector<int>& innerCornersPruneMap, short int prevMove)
{
	if(depth <= maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}
			
			if(depth < innerCornersPruneMap[crazyCubeCachePtr->getInnerCornersMap()[innerCorners][i]])
				innerCornersPruneMap[crazyCubeCachePtr->getInnerCornersMap()[innerCorners][i]] = depth;
			generateInnerCornersPruneMapIter(depth + 1, maxDepth, crazyCubeCachePtr->getInnerCornersMap()[innerCorners][i], innerCornersPruneMap, prevMove);
		}
	}
	return 0;
}

int PruneMapGenerator::generateInnerEdgesPruneMapIter(int depth, int maxDepth, int& innerEdges, vector<int>& innerEdgesPruneMap, short int prevMove)
{
	if(depth <= maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}
			
			if(depth < innerEdgesPruneMap[crazyCubeCachePtr->getInnerEdgesMap()[innerEdges][i]])
				innerEdgesPruneMap[crazyCubeCachePtr->getInnerEdgesMap()[innerEdges][i]] = depth;
			generateInnerEdgesPruneMapIter(depth + 1, maxDepth, crazyCubeCachePtr->getInnerEdgesMap()[innerEdges][i], innerEdgesPruneMap, prevMove);
		}
	}
	return 0;
}

int PruneMapGenerator::generateCentrePruneMapIter(int depth, int maxDepth, int& centre, vector<int>& centrePruneMap, short int prevMove)
{
	if(depth <= maxDepth)
	{
		for(int i = 0; i < NUM_OF_MOVES; i++)
		{
			if(i == prevMove)
			{
				continue;
			}
			
			if(depth < centrePruneMap[crazyCubeCachePtr->getCentreMap()[centre][i]])
				centrePruneMap[crazyCubeCachePtr->getCentreMap()[centre][i]] = depth;
			generateCentrePruneMapIter(depth + 1, maxDepth, crazyCubeCachePtr->getCentreMap()[centre][i], centrePruneMap, prevMove);
		}
	}
	return 0;
}

