#ifndef CRAZYCUBEIMPROVED_H_
#define CRAZYCUBEIMPROVED_H_

#include "CrazyCubeBase.h"
#include "CrazyCubeCache.h"
#include "OuterCornersMapGenerator.h"
#include "CubeInterface.h"
#include <iostream>
using namespace std;

class CrazyCubeImproved: public CubeInterface 
{
private:
	CrazyCubeCache* cache;
	int outerCorners;
	int innerCorners;
	int outerEdges;
	int innerEdges;
	int centre;
	
	unsigned short int movesInversions[NUM_OF_MOVES];

public:

// checki co ulozone

    /**
     * Basic constructor.
     */
	CrazyCubeImproved();
    /**
     * Virtual destructor.
     */
	virtual ~CrazyCubeImproved();
	
    /**
     * Setters.
     * 
     * @param x part of the cube to be set
     */
	void setOuterCorners(int outerCorners);
	void setInnerCorners(int innerCorners);
	void setOuterEdges(int outerEdges);
	void setInnerEdges(int innerEdges);
	void setCentre(int centers);
	void setCube(int outerCorners, int innerCorners, int outerEdges, int innerEdges, int centers);
	// void setCrazyCubeCache(CrazyCubeCache cache);
	
    /**
     * Getters.
     * 
     * @return particular part of the cube
     */
    unsigned long long getCubeState();

	int getOuterCorners();
	int getInnerCorners();
	int getOuterEdges();
	int getInnerEdges();
	int getCentre();
	// CrazyCubeCache* getCrazyCubeCache();

    /**
     * CrazyCube move implementation using move index
     *
     * @param m index of move to be done
     */
	void move(rotation m);
	/**
     * Inversion of a provided move
     *
     * @param m index of move to be undone
     */
	void undoMove(rotation m);
	/**
     * Cube is solved again with no effort :)
     */
	void resetCube();
    /**
     * Prints cube state using std::cout
     */
    void printCubeState();

    bool isSolved();
};


#endif /* CRAZYCUBEIMPROVED_H_ */
