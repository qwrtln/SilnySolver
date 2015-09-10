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
}
void CrazyCubeSolver:: SetCrazyCube(CrazyCube* crazyCube)
{
	this->crazyCube = crazyCube;
}
CrazyCube* CrazyCubeSolver:: GetCrazyCube()
{
	return this->crazyCube;
}
void CrazyCubeSolver:: SetParameters(CrazyCubeSolverParametersD parameters)
{
	// przepakowac parametry ze struktury do atrybutow
}
CrazyCubeSolverParametersD CrazyCubeSolver:: GetParameters()
{
	// przepakowac parametry z atrybutow do struktury i zwrocic ja
}
void CrazyCubeSolver:: SetUp()
{
}
void CrazyCubeSolver:: CleanUp()
{
}
bool CrazyCubeSolver:: SolveIteration(unsigned short int depth, unsigned short int prevMove)
{
	return 0;
}
