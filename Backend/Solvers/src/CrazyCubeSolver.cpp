#include "CrazyCubeSolver.h"
#include "Tracer.h"

CrazyCubeSolver:: CrazyCubeSolver():
				maxDepth(0),
				minDepth(0),
				numberOfSolutions(0),
				solutionsFound(0),
				crazyCube(0),
                solvedMask(0xFFFFFFFFFFFFFFFF),
				iDepth(0)
{
    TRACE( TRACE_ALL, 0, "Constructor CrazyCubeSolver" );

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
    TRACE( TRACE_ALL, 0, "Destructor CrazyCubeSolver");
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
        currentPath.reset(new unsigned short int[iDepth]);
		solveIteration(iDepth, -1);		
	}
}
void CrazyCubeSolver:: setCrazyCube(CubeInterface* crazyCube)
{
	this->crazyCube = crazyCube;
}
CubeInterface* CrazyCubeSolver:: getCrazyCube()
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
bool CrazyCubeSolver:: solveIteration(unsigned short int depth, unsigned short int prevMove)
{
	// Check if you already have as many solutions as you wish
	if (solutionsFound == numberOfSolutions)
	{
		// If so, quit - this will terminate further iterations of the branch
		return false;
	}

	// Check if you've reached final depth and if the cube is solved
	if ( (depth == 0) && crazyCube->isSolved())
	{
		// If so, there's no point in going any deeper
		return true;
	}
	// Otherwise, keep searching but discontinue, if the cube is already solved
	else if ( depth > 0 && !crazyCube->isSolved())
	{
		// Iterate through each move
		for (int move = static_cast<int>(rotation::LEFT); move < NUM_OF_MOVES; ++move)
		{
			// This rules out repetitions
			if (prevMove == move)
			{
				continue;
			}

			// Do the move
			crazyCube->move(static_cast<rotation>(move));

			// Remember it in the array
			currentPath[iDepth - depth] = move;

			// Step into the snippet, if your branch has a solution
			if (solveIteration(depth - 1,move))
			{
				++solutionsFound;

				// Create a vector with our solutions
				// iDepth - current depth of the iteration in "solve" method
                vector<unsigned short int>solubleVector(currentPath.get(),currentPath.get() + iDepth);

				// Place found solution in the vector
				solutions.push_back(solubleVector);
			}

			// Move done? Go back in order to check every possibility of this depth
			crazyCube->undoMove(static_cast<rotation>(move));
		}
	}

	// Nothing found here, go deeper (or terminate if it's the last iteration)
	return false;
}
