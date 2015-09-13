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
	void setSolvedMask(unsigned long long int solvedMask);
	unsigned long long int getSolvedMask();
	void setMinDepth(unsigned short int minDepth);
	unsigned short int getMinDepth();
	void setMaxDepth(unsigned short int maxDepth);
	unsigned short int getMaxDepth();
	void setEnabledMoves(vector<bool> enabledMoves);
	vector<bool> getEnabledMoves();
	void setNumberOfSolutions(unsigned short int numberOfSolutions);
	unsigned short int getNumberOfSolutions();
	void setSolutions(vector<vector<unsigned short int> > solutions);	// For testing purpose
	vector<vector<unsigned short int> > getSolutions();
	void solve();
	void setCrazyCube(CrazyCube* crazyCube);
	CrazyCube* getCrazyCube();
	void setParameters(CrazyCubeSolverParametersD& parameters);
	CrazyCubeSolverParametersD getParameters();

protected:
	void setUp();
	void cleanUp();
	bool solveIteration(unsigned short int depth, unsigned short int prevMove);

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
