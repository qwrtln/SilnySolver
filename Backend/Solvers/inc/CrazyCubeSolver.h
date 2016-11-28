#ifndef CRAZYCUBESOLVER_H_
#define CRAZYCUBESOLVER_H_

#include "CrazyCube.h"
#include "CrazyCubeSolverParametersD.h"
#include "CubeInterface.h"
#include "SolverInterface.h"
#include <vector>
#include <memory>

class CrazyCubeSolver: public CrazyCubeAbstract, public virtual SolverInterface
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
	void setEnabledMoves(std::vector<bool> enabledMoves);
	std::vector<bool> getEnabledMoves();
	void setNumberOfSolutions(unsigned short int numberOfSolutions);
	unsigned short int getNumberOfSolutions();
	void setSolutions(std::vector<std::vector<unsigned short int> > solutions);	// For testing purpose
	std::vector<std::vector<unsigned short int> > getSolutions();
	void solve();
	void setCrazyCube(CubeInterface* crazyCube);
	CubeInterface* getCrazyCube();
	void setParameters(CrazyCubeSolverParametersD& parameters);
	CrazyCubeSolverParametersD getParameters();

protected:
	void setup();
	bool solveIteration(unsigned short int depth, unsigned short int prevMove);

	unsigned short int maxDepth;
	unsigned short int minDepth;
	std::vector<bool> enabledMoves;
	unsigned short int numberOfSolutions;
	unsigned short int solutionsFound;
	CubeInterface* crazyCube;
	unsigned long long int solvedMask;
	std::vector<std::vector<unsigned short int> > solutions;	
    std::unique_ptr<unsigned short int[]> currentPath;
	unsigned short int iDepth;
};

#endif /* CRAZYCUBESOLVER_H_ */
