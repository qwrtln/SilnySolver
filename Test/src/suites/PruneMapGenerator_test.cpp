/*
 * PruneMapGenerator_test.cpp
 *
 *  Created on: Sept 20, 2016
 *      Author: qwrtln
 */
#include "PruneMapGenerator.h"
#include "TestExecuter.h"
#include "CrazyCubeAbstract.h"
#include "CrazyCube.h"
#include <cmath>
#include <iostream>
using namespace std;


class PruneMapGeneratorTest: public BaseTest
{
public:
	PruneMapGeneratorTest(string testCase, string testName)
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
	static PruneMapGenerator generator;
};

PruneMapGenerator PruneMapGeneratorTest::generator;

#ifdef MEMORY_CHECK
TEST_F(PruneMapGeneratorTest, findingMemoryLeaks)
{
    std::vector<int> testingVector;
    for (int i = 0; i < 100; ++i)
    {
        testingVector.push_back(69);
    }

    generator.generateCentrePruneMap(2,7);
    generator.generateInnerCornersPruneMap(pow2toX[NUM_OF_CORNERS],4);
    generator.generateInnerEdgesPruneMap(pow2toX[NUM_OF_EDGES], 2);
    generator.generateOuterCornersPruneMap(factorials[NUM_OF_CORNERS], 6);
    generator.generateOuterEdgesPruneMap(factorials[NUM_OF_EDGES], 6);
    generator.swapMapElementValue(100, testingVector, 69, 96);
}
#else
TEST_F(PruneMapGeneratorTest, generateInnerCornersPruneMapTest)
{

}

TEST_F(PruneMapGeneratorTest, GenericVisibilityTest)
{
    // Tests to be written!!!
    ASSERT_EQ(true,false);
}

#endif

