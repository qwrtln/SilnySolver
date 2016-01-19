/*
 * CrazyCubeSolver_test.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: SecT
 */

#include "TestExecuter.h"
#include "FileWriter.h"
#include <cmath>


class FileWriterTest: public BaseTest
{
public:
	FileWriterTest(string testCase, string testName)
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
	static FileWriter fileWriter;
};

///CrazyCubeSolver CrazyCubeSolverTest:: solver;


TEST_F(FileWriterTest, initTest)
{
//	unsigned short int minDepth = 123;
//	solver.setMinDepth(minDepth);
//	ASSERT_EQ(solver.getMinDepth(), minDepth);
}


