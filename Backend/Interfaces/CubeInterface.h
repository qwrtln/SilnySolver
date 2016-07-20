/*
 * CubeInterface.h
 *
 * Created on: Jul 20, 2016
 *      Author: qwrtln
 */
#ifndef CUBEINTERFACE_H_
#define CUBEINTERFACE_H_
#include "CrazyCubeBase.h"

class CubeInterface: public CrazyCubeBase
{
public:
	virtual unsigned long long int getCubeState() = 0;
};

#endif /* CUBEINTERFACE_H_ */
