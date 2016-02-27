/*
 * CrazyCubeBase.h
 *
 * Created on: Jan 23, 2016
 *      Author: qwrtln
 */

#ifndef CRAZYCUBEBASE_H_
#define CRAZYCUBEBASE_H_
#include "CrazyCubeAbstract.h"

////////////////////////////////
// 
// The purpose of this class is
// to provide a virtual base 
// interface holder for CrazyCubeSolver.
// Solver will take a pointer to an object
// inheriting from CrazyCubeBase class,
// which will make it able to handle
// any derivative cube.
//
///////////////////////////////

class CrazyCubeBase: public CrazyCubeAbstract
{
    public:
	virtual void move(unsigned short int) = 0;
	virtual void undoMove(unsigned short int) = 0;
    virtual void resetCube() = 0;
    virtual bool isSolved() = 0;
};


#endif /* CRAZYCUBEBASE_H_ */

