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
};

#endif /* CRAZYCUBE_H_ */
