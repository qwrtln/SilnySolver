/*
 * CrazyCube.h
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#ifndef CRAZYCUBE_H_
#define CRAZYCUBE_H_
#include "ConstDefs.h"

class CrazyCube
{
private:
	unsigned long long cubeState;

public:
	CrazyCube();
	virtual ~CrazyCube();
	bool checkIfSolved(unsigned long long cubeState);
	void setCubeState(unsigned long long cubeState);
	unsigned long long getCubeState();

	void setCentre(bool);
	void setEdges(edgeNames edges[NUM_OF_EDGES]);
	void setCorners(cornerNames corners[NUM_OF_CORNERS]);

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

	void move(unsigned int move);
};

#endif /* CRAZYCUBE_H_ */
