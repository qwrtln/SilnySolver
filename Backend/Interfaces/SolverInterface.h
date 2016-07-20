/*
 * SolverInterface.h
 *
 * Created on: Jul 20, 2016
 *      Author: qwrtln
 */

#ifndef SOLVERINTERFACE_H_
#define SOLVERINTERFACE_H_
#include <vector>
#include "CrazyCubeSolverParametersD.h"
#include "CubeInterface.h"

class SolverInterface
{
public:
	virtual void solve() = 0; 
	virtual void setParameters(CrazyCubeSolverParametersD&) = 0;
	virtual void setCrazyCube(CubeInterface*) = 0;
	virtual std::vector<std::vector<unsigned short int>> getSolutions() = 0;
	virtual CrazyCubeSolverParametersD getParameters() = 0;

private:
	std::vector<std::vector<unsigned short int>> solutions;
};

#endif /* SOLVERINTERFACE_H_ */
