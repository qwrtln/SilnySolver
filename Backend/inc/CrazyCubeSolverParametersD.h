#ifndef CRAZYCUBESOLVERPARAMETERS_H_
#define CRAZYCUBESOLVERPARAMETERS_H_

#include <vector>
using namespace std;
struct CrazyCubeSolverParametersD
{
	unsigned short int maxDepth;
	unsigned short int minDepth;
	vector<bool> enabledMoves;
	unsigned short int numberOfSolutions;
	unsigned long long int solvedMask;
};

#endif /* CRAZYCUBESOLVERPARAMETERS_H_ */
