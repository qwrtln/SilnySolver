/*
 * CrazyCubeSolver_test.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: piotoor
 */
#include "CrazyCubeSolver.h"
#include "TestExecuter.h"
#include "CrazyCubeAbstract.h"
#include <cmath>


class CrazyCubeSolverTest: public BaseTest
{
public:
	CrazyCubeSolverTest(string testCase, string testName)
		:BaseTest(testCase, testName)
	{
		SetUp();
	}
protected:
	void SetUp()
	{

	}
	void TearDown()
	{

	}
protected:
	static CrazyCubeSolver solver;
};

CrazyCubeSolver CrazyCubeSolverTest:: solver;

#ifdef MEMORY_CHECK
TEST_F(CrazyCubeSolverTest, findingMemoryLeaks)
{
    // Variables for memory check test functions arguments
	CrazyCube kosteczka;
    
    unsigned short int minDepth = 3;
    unsigned short int maxDepth = 30;
    unsigned short int numOfSolutions = 300;
    unsigned long long solvedMask = 0xBEDFEDFEDFCCDFED;

	vector<bool> enabledMoves;
	for(unsigned short int i = 0; i < 11; i++)
	{
		enabledMoves.push_back(i&1);
	}

	vector<vector<unsigned short int> > testSolutions;
	vector<unsigned short int> sol1;
	vector<unsigned short int> sol2;
	sol1.push_back(1);
	sol1.push_back(2);
	sol2.push_back(3);
	sol2.push_back(4);
	testSolutions.push_back(sol1);
	testSolutions.push_back(sol2);

	CrazyCubeSolverParametersD params;	
	params.maxDepth = maxDepth;
	params.minDepth = minDepth;
	params.enabledMoves = enabledMoves;
	params.numberOfSolutions = numOfSolutions;
	params.solvedMask = solvedMask;

    solver.getCrazyCube();
    solver.getEnabledMoves();
    solver.getMaxDepth();
    solver.getMinDepth();
    solver.getNumberOfSolutions();
    solver.getParameters();
    solver.getSolutions();
    solver.getSolvedMask();
    solver.setCrazyCube(&kosteczka);
	solver.setEnabledMoves(enabledMoves);;
    solver.setMaxDepth(maxDepth);
    solver.setMinDepth(minDepth);
    solver.setNumberOfSolutions(numOfSolutions);
    solver.setParameters(params);
    solver.setSolutions(testSolutions);
    solver.setSolvedMask(solvedMask);
    //solver.setup(); /* ~~Protected method~~ */
    // These below are unnecessary to test from the point of memory check
    //solver.solve();
    //solver.solveIteration(unsigned short int depth, unsigned short int prevMove);
}
#else
TEST_F(CrazyCubeSolverTest, SetSolvedMaskTest)
{
	unsigned long long int solvedMask = 0xBABC1A6665A7A4FA;
	solver.setSolvedMask(solvedMask);
	ASSERT_EQ(solver.getSolvedMask(), solvedMask);
}

TEST_F(CrazyCubeSolverTest, SetMinDepthTest)
{
	unsigned short int minDepth = 123;
	solver.setMinDepth(minDepth);
	ASSERT_EQ(solver.getMinDepth(), minDepth);
}

TEST_F(CrazyCubeSolverTest, SetMaxDepthTest)
{
	unsigned short int maxDepth = 1223;
	solver.setMaxDepth(maxDepth);
	ASSERT_EQ(solver.getMaxDepth(), maxDepth);
}

TEST_F(CrazyCubeSolverTest, SetEnabledMovesTest)
{
	vector<bool> enabledMoves;
	for(unsigned short int i = 0; i < 11; i++)
	{
		enabledMoves.push_back(i&1);
	}
	solver.setEnabledMoves(enabledMoves);
	ASSERT_EQ_STL_CONTAINER(solver.getEnabledMoves(), enabledMoves);
}

TEST_F(CrazyCubeSolverTest, SetNumberOfSolutionsTest)
{
	unsigned short int numOfSol = 666;
	solver.setNumberOfSolutions(numOfSol);
	ASSERT_EQ(solver.getNumberOfSolutions(), numOfSol);
}

TEST_F(CrazyCubeSolverTest, SetSolutionsTest)
{
	vector<vector<unsigned short int> > testSolutions;
	vector<unsigned short int> sol1;
	vector<unsigned short int> sol2;
	sol1.push_back(1);
	sol1.push_back(2);
	sol1.push_back(3);
	sol2.push_back(4);
	sol2.push_back(2);
	sol2.push_back(1);
	sol2.push_back(3);
	testSolutions.push_back(sol1);
	testSolutions.push_back(sol2);
	solver.setSolutions(testSolutions);
	vector<vector<unsigned short int> > testSolutions2 = solver.getSolutions();
	for(unsigned int i = 0; i < testSolutions.size(); i++)
	{
		sol1 = testSolutions[i];
		sol2 = testSolutions2[i];
		ASSERT_EQ_STL_CONTAINER(sol2, sol1);
	}	
}

TEST_F(CrazyCubeSolverTest, SetParametersTest)
{
	CrazyCubeSolverParametersD params, actual;	
	params.maxDepth = 5;
	params.minDepth = 2;
	vector<bool> enabledMoves;
	for(unsigned short int i = 0; i <= NUM_OF_MOVES; i++)
	{
		enabledMoves.push_back(1);
	}
	params.enabledMoves = enabledMoves;
	params.numberOfSolutions = 123;
	params.solvedMask = 0xBEDFEDFEDFCCDFED;
	solver.setParameters(params);
	actual = solver.getParameters();
	ASSERT_EQ(actual.maxDepth, params.maxDepth);
	ASSERT_EQ(actual.minDepth, params.minDepth);
	ASSERT_EQ_STL_CONTAINER(actual.enabledMoves, params.enabledMoves);
	ASSERT_EQ(actual.numberOfSolutions, params.numberOfSolutions);
	ASSERT_EQ(actual.solvedMask, params.solvedMask);
}

TEST_F(CrazyCubeSolverTest, CrazyCubeSolveTest)
{
	CrazyCube kosteczka;
	solver.setCrazyCube(&kosteczka);

	kosteczka.move((int)rotation::MVBR);
	kosteczka.move((int)rotation::L);
	kosteczka.move((int)rotation::F);
	kosteczka.move((int)rotation::MHRR);
	kosteczka.move((int)rotation::MV);

	solver.setMinDepth(4);
	solver.setMaxDepth(6);
	solver.setNumberOfSolutions(2);
	solver.setSolvedMask(solvedCube);
	solver.solve();

	vector<vector<unsigned short int> > rozwiazania;
	rozwiazania = solver.getSolutions();

	if (rozwiazania.size() == 0)
	{
		cout << "Nie umiem tego rozwiazac. Sory." << endl;
	}

	for (unsigned short int i = 0; i < rozwiazania.size(); ++i)
	{
		for (unsigned short int j = 0; j < rozwiazania[i].size(); ++j)
		{
			cout << rozwiazania[i][j] << " ";
		}
		cout << endl;
	}

}
#endif
