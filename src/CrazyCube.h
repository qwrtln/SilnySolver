/*
 * CrazyCube.h
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#ifndef CRAZYCUBE_H_
#define CRAZYCUBE_H_
#include "ConstDefs.h"

class CrazyCube: public CrazyCubeAbstract
{
private:
	unsigned long long cubeState;
	void(CrazyCube::*moveTab[NUM_OF_MOVES])();
	void(CrazyCube::*undoMoveTab[NUM_OF_MOVES])();
	unsigned long long initialMask;
	unsigned long long edgeOneMask;
	unsigned long long edgeTwoMask;
	unsigned long long edgeOne;
	unsigned long long edgeTwo;
	unsigned long long cornerOneMask;
	unsigned long long cornerTwoMask;
	unsigned long long cornerOne;
	unsigned long long cornerTwo;

public:
	CrazyCube();
	virtual ~CrazyCube();
	bool checkIfSolved();
	void setCubeState(unsigned long long cubeState);
	unsigned long long getCubeState();

	void setCentre(bool);
	void setEdges(edgeNames edges[NUM_OF_EDGES]);
	void setCorners(cornerNames corners[NUM_OF_CORNERS]);

	void setWholeCube(bool, edgeNames edges[NUM_OF_EDGES], cornerNames corners[NUM_OF_CORNERS]);

	// valid moves
	void L();
	void F();
	void U();
	void Ui();
	void U2();
	void Mv();
	void Mh();
	void MhRr();
	void MhLr();
	void MvFr();
	void MvBr();

	void move(unsigned short int);
	void undoMove(unsigned short int);

	void swapEdges(unsigned short int, unsigned short int, bool);
	void swapCorners(unsigned short int, unsigned short int, bool);
	void cycleCorners(unsigned short int, unsigned short int, unsigned short int, unsigned short int);
	void cycleEdges(unsigned short int, unsigned short int, unsigned short int, unsigned short int);
	void toggleCentre();

	void resetCube();
};

#endif /* CRAZYCUBE_H_ */
