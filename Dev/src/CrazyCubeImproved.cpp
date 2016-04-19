#include "CrazyCubeImproved.h"

CrazyCubeImproved:: CrazyCubeImproved()
{
    // Set cube as solved
    outerEdges = 0;
    outerCorners = 0;
    innerEdges = 0xF; // accordingly: 0 0 0 0 in top layer, 1 1 1 1 in bottom layer
    innerCorners = 0x7; // the same: 0 0 0 0, 1 1 1
    centre = 1;

    // Initialise moves array 
    for (int i = 0; i < NUM_OF_MOVES; ++i)
    {
        movesInversions[i] = i;
    }

    this->cache = CrazyCubeCache::getInstance();
}


CrazyCubeImproved:: ~CrazyCubeImproved()
{
}

void CrazyCubeImproved:: resetCube()
{
    outerEdges = 0;
    outerCorners = 0;
    innerEdges = 0xF;
    innerCorners = 0x7;
    centre = 1;
}

void CrazyCubeImproved:: setOuterCorners(int outerCorners)
{
	this->outerCorners = outerCorners;
}

void CrazyCubeImproved:: setInnerCorners(int innerCorners)
{
	this->innerCorners = innerCorners;
}

void CrazyCubeImproved:: setOuterEdges(int outerEdges)
{
	this->outerEdges = outerEdges;
}

void CrazyCubeImproved:: setInnerEdges(int innerEdges)
{
	this->innerEdges = innerEdges;
}

void CrazyCubeImproved:: setCentre(int centre)
{
	this->centre = centre;
}

void CrazyCubeImproved:: setCube(int outerCorners, int innerCorners, int outerEdges, int innerEdges, int centre)
{
	setOuterCorners(outerCorners);
	setInnerCorners(innerCorners);
	setOuterEdges(outerEdges);
	setInnerEdges(innerEdges);
	setCentre(centre);
}

int CrazyCubeImproved:: getOuterCorners()
{
	return outerCorners;
}

int CrazyCubeImproved:: getInnerCorners()
{
	return innerCorners;
}

int CrazyCubeImproved:: getOuterEdges()
{
	return outerEdges;
}

int CrazyCubeImproved:: getInnerEdges()
{
	return innerEdges;
}

int CrazyCubeImproved:: getCentre()
{
	return centre;
}


void CrazyCubeImproved:: move(rotation m)
{
  unsigned short mInt = static_cast<unsigned short>(m);
	outerCorners = cache->getOuterCornersMap()[outerCorners][mInt];
	innerCorners = cache->getInnerCornersMap()[innerCorners][mInt];
	outerEdges = cache->getOuterEdgesMap()[outerEdges][mInt];
	innerEdges = cache->getInnerEdgesMap()[innerEdges][mInt];
	centre = cache->getCentreMap()[centre][mInt];
}


void CrazyCubeImproved:: undoMove(rotation m)
{
  unsigned short mInt = static_cast<unsigned short>(m);
	outerCorners = cache->getOuterCornersMap()[outerCorners][movesInversions[mInt]];
	innerCorners = cache->getInnerCornersMap()[innerCorners][movesInversions[mInt]];
	outerEdges = cache->getOuterEdgesMap()[outerEdges][movesInversions[mInt]];
	innerEdges = cache->getInnerEdgesMap()[innerEdges][movesInversions[mInt]];
	centre = cache->getCentreMap()[centre][movesInversions[mInt]];
}


void CrazyCubeImproved:: printCubeState()
{
	cout << "outerCorners: " << outerCorners << endl;
	cout << "innerCorners: " << innerCorners << endl;
	cout << "outerEdges: " << outerEdges << endl;
	cout << "innerEdges: " << innerEdges << endl;
	cout << "centre: " << centre << endl;
}

bool CrazyCubeImproved:: isSolved()
{
    return (outerEdges == 0)    && 
           (outerCorners == 0)  &&
           (innerEdges == 0xF)  &&
           (innerCorners == 0x7)&&
           (centre == 1);

}

