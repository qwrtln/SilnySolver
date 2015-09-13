/*
 * CrazyCubeSolver_test.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: piotoor
 */
#include "CrazyCubeSolver.h"
#include "TestExecuter.h"
#include "ConstDefs.h"
#include <cmath>

extern TestExecuter testExecuter;
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
	enabledMoves.pop_back();
	enabledMoves.push_back(1);
	ASSERT_EQ_STL_CONTAINER(solver.getEnabledMoves(), enabledMoves);
}
