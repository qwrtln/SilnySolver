#ifndef CRAZYCUBESOLVER_H_
#define CRAZYCUBESOLVER_H_

#include "CrazyCube.h"
#include "CrazyCubeSolverParametersD.h"
#include <vector>
using namespace std;

class CrazyCubeSolver
{
public:
	CrazyCubeSolver();
	~CrazyCubeSolver();
	void SetSolvedMask(unsigned long long int solvedMask);
	unsigned long long int GetSolvedMask();
	void SetMinDepth(unsigned short int minDepth);
	unsigned short int GetMinDepth();
	void SetMaxDepth(unsigned short int maxDepth);
	unsigned short int GetMaxDepth();
	void SetEnabledMoves(vector<bool> enabledMoves);
	vector<bool> GetEnabledMoves();
	void SetNumberOfSolutions(unsigned short int numberOfSolutions);
	unsigned short int GetNumberOfSolutions();
	void SetSolutions(vector<vector<unsigned short int> > solutions);	// For testing purpose
	vector<vector<unsigned short int> > GetSolutions();
	void Solve();
	void SetCrazyCube(CrazyCube* crazyCube);
	CrazyCube* GetCrazyCube();
	void SetParameters(CrazyCubeSolverParametersD parameters);
	CrazyCubeSolverParametersD GetParameters();

protected:
	void SetUp();
	void CleanUp();
	bool SolveIteration(unsigned short int depth, unsigned short int prevMove);

protected:
	unsigned short int maxDepth;
	unsigned short int minDepth;
	vector<bool> enabledMoves;
	unsigned short int numberOfSolutions;
	unsigned short int solutionsFound;
	CrazyCube* crazyCube;
	unsigned long long int solvedMask;
	vector<vector<unsigned short int> > solutions;
	unsigned short int* currentPath;
	unsigned short int iDepth;
};

#endif /* CRAZYCUBESOLVER_H_ */
