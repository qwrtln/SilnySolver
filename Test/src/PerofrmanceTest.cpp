/*
 * PerformanceTest.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: qwrtln
 */
#include "CrazyCubeBase.h"
#include "CrazyCube.h"
#include "CrazyCubeImproved.h"
#include "CrazyCubeSolver.h"
#include "TestExecuter.h"
#include "CrazyCubeAbstract.h"
#include <cmath>

class PerformanceTest: public BaseTest
{
public:
	PerformanceTest(string testCase, string testName)
		:BaseTest(testCase, testName)
	{
		SetUp();
	}

    CrazyCubeBase* cubeToTest;

protected:
	void SetUp()
	{

	}
	void TearDown()
	{

	}

	void TestMove(unsigned int depth, bool showTime = true)
	{
		if(showTime)
		{
			cout << "Test of depth " << depth << "(" << (unsigned int)pow((double)NUM_OF_MOVES, (double)depth + 1) << " moves): ";
			cout.flush();
		}
		time_t start;
		if(showTime)
		{
			start = clock();
		}
		unsigned int max = (unsigned int)pow((double)NUM_OF_MOVES, (double)depth);

		for(unsigned int i = 0; i < max; i++) 
		{
			for(unsigned short int j = 0; j < NUM_OF_MOVES; j++)
			{			
				cubeToTest->move(j);
			}		
		}
		if(showTime)
		{
			cout << ((float)(clock() - start))/CLOCKS_PER_SEC << "s\n";
		}
	}

	void TestMoveAverage(unsigned int depth, unsigned int averageOf)
	{
		cout << "Test of depth " << depth << "(" << (unsigned int)pow((double)NUM_OF_MOVES, (double)depth + 1) << " moves): ";
		cout.flush();
		time_t start = clock();		
		for(unsigned short int i = 1; i <= averageOf; i++)
		{
			TestMove(depth, false);
		}
		cout << (((float)(clock() - start)) / (double)averageOf)/CLOCKS_PER_SEC << "s (avg of " << averageOf << " trials) \n";
	}

    void passCubeToTester(CrazyCubeBase* cubeToPass)
    {
        this->cubeToTest = cubeToPass;
    }


protected:
	static CrazyCube cube;
    static CrazyCubeImproved cubeImproved;
};

CrazyCube PerformanceTest::cube;
CrazyCubeImproved PerformanceTest::cubeImproved;

TEST_F(PerformanceTest, CrazyCubeAvgTest)
{
	cube.resetCube(); 

    passCubeToTester(&cube);
	#ifndef PREF_DEPTH
	for(unsigned short int i = 0; i <= 6; i++)
	{
		TestMoveAverage(i, 5);
	}
	#else
	for(unsigned short int i = 0; i <= PREF_DEPTH; i++)
	{
		TestMoveAverage(i, 5);
	}
	#endif
}

TEST_F(PerformanceTest, CrazyCubeImprovedAvgTest)
{
	passCubeToTester(&cubeImproved);
    #ifndef PREF_DEPTH
	for(unsigned short int i = 0; i <= 6; i++)
	{
		TestMoveAverage(i, 5);
	}
	#else
	for(unsigned short int i = 0; i <= PREF_DEPTH; i++)
	{
		TestMoveAverage(i, 5);
	}
	#endif
}
