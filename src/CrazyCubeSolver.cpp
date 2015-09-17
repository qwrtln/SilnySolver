#include "CrazyCubeSolver.h"

CrazyCubeSolver:: CrazyCubeSolver():
				maxDepth(0),
				minDepth(0),
				numberOfSolutions(0),
				solutionsFound(0),
				crazyCube(0),
				solvedMask(0xFFFFFFFFFFFFFFFF),
				currentPath(0),
				iDepth(0)
{
	// TODO - to jest przyklad z piramidki. Domyslnie ustawiamy wszystkie mozliwe ruchy na dozwolone
	/*		
	for(int i = 0; i < NUMBER_OF_MOVES * NUMBER_OF_FACES; i++)
	{
		enabledMoves.push_back(true);
	}
	*/
	solutions.clear();
}
CrazyCubeSolver:: ~CrazyCubeSolver()
{
}
void CrazyCubeSolver:: setSolvedMask(unsigned long long int solvedMask)
{
	this->solvedMask = solvedMask;
}
unsigned long long int CrazyCubeSolver:: getSolvedMask()
{
	return this->solvedMask;
}
void CrazyCubeSolver:: setMinDepth(unsigned short int minDepth)
{
	this->minDepth = minDepth;
}
unsigned short int CrazyCubeSolver:: getMinDepth()
{
	return this->minDepth;
}
void CrazyCubeSolver:: setMaxDepth(unsigned short int maxDepth)
{
	this->maxDepth = maxDepth;
}
unsigned short int CrazyCubeSolver:: getMaxDepth()
{
	return this->maxDepth;
}
void CrazyCubeSolver:: setEnabledMoves(vector<bool> enabledMoves)
{
	this->enabledMoves = enabledMoves;
}
vector<bool> CrazyCubeSolver:: getEnabledMoves()
{
	return this->enabledMoves;
}
void CrazyCubeSolver:: setNumberOfSolutions(unsigned short int numberOfSolutions)
{
	this->numberOfSolutions = numberOfSolutions;
}
unsigned short int CrazyCubeSolver:: getNumberOfSolutions()
{
	return this->numberOfSolutions;
}
void CrazyCubeSolver:: setSolutions(vector<vector<unsigned short int> > solutions)
{
	this->solutions = solutions;
}
vector<vector<unsigned short int> > CrazyCubeSolver:: getSolutions()
{
	return this->solutions;
}
void CrazyCubeSolver:: solve()
{
	setup();
	for(iDepth = minDepth; iDepth <= maxDepth; iDepth++)
	{
		currentPath = new unsigned short int[iDepth];
		solveIteration(iDepth, -1);
		delete[] currentPath;
	}
}
void CrazyCubeSolver:: setCrazyCube(CrazyCube* crazyCube)
{
	this->crazyCube = crazyCube;
}
CrazyCube* CrazyCubeSolver:: getCrazyCube()
{
	return this->crazyCube;
}
void CrazyCubeSolver:: setParameters(CrazyCubeSolverParametersD& parameters)
{
	this->maxDepth = parameters.maxDepth;
	this->minDepth = parameters.minDepth;
	this->enabledMoves = parameters.enabledMoves;
	this->numberOfSolutions = parameters.numberOfSolutions;
	this->solvedMask = parameters.solvedMask;
}
CrazyCubeSolverParametersD CrazyCubeSolver:: getParameters()
{
	CrazyCubeSolverParametersD parameters;
	parameters.maxDepth = this->maxDepth;
	parameters.minDepth = this->minDepth;
	parameters.enabledMoves = this->enabledMoves;
	parameters.numberOfSolutions = this->numberOfSolutions;
	parameters.solvedMask = this->solvedMask;
	return parameters;
}
void CrazyCubeSolver:: setup()
{
	solutions.clear();
	solutionsFound = 0;
}
void CrazyCubeSolver:: cleanup()
{
	// TODO
}
bool CrazyCubeSolver:: solveIteration(unsigned short int depth, unsigned short int prevMove)
{
	if (solutionsFound == numberOfSolutions)
	{
		return false;
	}

	if ( (depth == 0) && crazyCube->checkIfSolved(solvedMask))
	{
		return true;
	}
	else if ( (depth > 0) && crazyCube->checkIfSolved(solvedMask))
	{
		for (int move = L; move < NUM_OF_MOVES; ++move)
		{
			if (prevMove == move)
			{
				continue;
			}

			crazyCube->move(move);
			currentPath[iDepth - depth] = move;
			if (solveIteration(depth - 1,move))
			{
				++solutionsFound;
				vector<unsigned short int>solubleVector(currentPath,currentPath + iDepth);
				solutions.push_back(solubleVector);
			}
			crazyCube->undoMove(move);
		}
	}

	return false;
}
