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
void CrazyCubeSolver:: SetSolvedMask(unsigned long long int solvedMask)
{
	this->solvedMask = solvedMask;
}
unsigned long long int CrazyCubeSolver:: GetSolvedMask()
{
	return this->solvedMask;
}
void CrazyCubeSolver:: SetMinDepth(unsigned short int minDepth)
{
	this->minDepth = minDepth;
}
unsigned short int CrazyCubeSolver:: GetMinDepth()
{
	return this->minDepth;
}
void CrazyCubeSolver:: SetMaxDepth(unsigned short int maxDepth)
{
	this->maxDepth = maxDepth;
}
unsigned short int CrazyCubeSolver:: GetMaxDepth()
{
	return this->maxDepth;
}
void CrazyCubeSolver:: SetEnabledMoves(vector<bool> enabledMoves)
{
	this->enabledMoves = enabledMoves;
}
vector<bool> CrazyCubeSolver:: GetEnabledMoves()
{
	return this->enabledMoves;
}
void CrazyCubeSolver:: SetNumberOfSolutions(unsigned short int numberOfSolutions)
{
	this->numberOfSolutions = numberOfSolutions;
}
unsigned short int CrazyCubeSolver:: GetNumberOfSolutions()
{
	return this->numberOfSolutions;
}
void CrazyCubeSolver:: SetSolutions(vector<vector<unsigned short int> > solutions)
{
	this->solutions = solutions;
}
vector<vector<unsigned short int> > CrazyCubeSolver:: GetSolutions()
{
	return this->solutions;
}
void CrazyCubeSolver:: Solve()
{
	SetUp();
	for(iDepth = minDepth; iDepth <= maxDepth; iDepth++)
	{
		currentPath = new unsigned short int[iDepth];
		SolveIteration(iDepth, -1);
		delete[] currentPath;
	}
}
void CrazyCubeSolver:: SetCrazyCube(CrazyCube* crazyCube)
{
	this->crazyCube = crazyCube;
}
CrazyCube* CrazyCubeSolver:: GetCrazyCube()
{
	return this->crazyCube;
}
void CrazyCubeSolver:: SetParameters(CrazyCubeSolverParametersD& parameters)
{
	this->maxDepth = parameters.maxDepth;
	this->minDepth = parameters.minDepth;
	this->enabledMoves = parameters.enabledMoves;
	this->numberOfSolutions = parameters.numberOfSolutions;
	this->solvedMask = parameters.solvedMask;
}
CrazyCubeSolverParametersD CrazyCubeSolver:: GetParameters()
{
	CrazyCubeSolverParametersD parameters;
	parameters.maxDepth = this->maxDepth;
	parameters.minDepth = this->minDepth;
	parameters.enabledMoves = this->enabledMoves;
	parameters.numberOfSolutions = this->numberOfSolutions;
	parameters.solvedMask = this->solvedMask;
	return parameters;
}
void CrazyCubeSolver:: SetUp()
{
	solutions.clear();
	solutionsFound = 0;
}
void CrazyCubeSolver:: CleanUp()
{
	// TODO
}
bool CrazyCubeSolver:: SolveIteration(unsigned short int depth, unsigned short int prevMove)
{
	// TODO
	return 0;
}
