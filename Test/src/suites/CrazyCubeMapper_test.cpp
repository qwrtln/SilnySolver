/*
 * CrazyCubeMapper_test.cpp
 *
 *  Created on: Dec 16, 2015
 *      Author: qwrtln
 */
#include "CrazyCubeMapper.h"
#include "TestExecuter.h"
#include "CrazyCubeAbstract.h"
#include "CrazyCube.h"
#include <cmath>
#include <iostream>
using namespace std;


class CrazyCubeMapperTest: public BaseTest
{
public:
	CrazyCubeMapperTest(string testCase, string testName)
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
	static CrazyCubeMapper mapper;
};

CrazyCubeMapper CrazyCubeMapperTest::mapper;

#ifdef MEMORY_CHECK
TEST_F(CrazyCubeMapperTest, findingMemoryLeaks)
{
    std::vector<int> testingVector;
    for (int i = 0; i < 100; ++i)
    {
        testingVector.push_back(69);
    }

    mapper.generateCentrePruneMap(2,7);
    mapper.generateInnerCornersPruneMap(pow2toX[NUM_OF_CORNERS],4);
    mapper.generateInnerEdgesPruneMap(pow2toX[NUM_OF_EDGES], 2);
    mapper.generateOuterCornersPruneMap(factorials[NUM_OF_CORNERS], 6);
    mapper.generateOuterEdgesPruneMap(factorials[NUM_OF_EDGES], 6);
    mapper.swapMapElementValue(100, testingVector, 69, 96);
}
#else
TEST_F(CrazyCubeMapperTest, GenericVisibilityTest)
{
    // Tests to be written!!!
    ASSERT_EQ(true,false);
}

#endif
