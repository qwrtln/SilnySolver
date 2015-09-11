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
};

TEST_F(CrazyCubeSolverTest, dupa)
{
	ASSERT_EQ(2, 2);
}
