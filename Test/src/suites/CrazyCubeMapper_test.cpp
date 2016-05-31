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
    for (int i = 0; i < 40321; ++i)
    {
        testingVector[i] = i;
    }

    // int testingRef = 0;
    
    //mapper.generateCentrePruneMap(6,7);
    //mapper.generateCentrePruneMapIter(8, 9, testingRef, testingVector, 1);
    //mapper.generateInnerCornersPruneMap(3,4);
    //mapper.generateInnerCornersPruneMapIter(5, 6, testingRef, testingVector, 8);
    //mapper.generateInnerEdgesPruneMap(9, 2);
    //mapper.generateInnerEdgesPruneMapIter(1, 2, testingRef, testingVector, 4);
    //mapper.generateOuterCornersPruneMap(5, 6);
    //mapper.generateOuterCornersPruneMapIter(7, 8, testingRef, testingVector, 8);
    //mapper.generateOuterEdgesPruneMap(7, 6);
    //mapper.generateOuterEdgesPruneMapIter(5, 4, testingRef, testingVector, 2);
    //mapper.swapMapElementValue(1, testingVector, 0, 1);
}
#else
TEST_F(CrazyCubeMapperTest, GenericVisibilityTest)
{
    // Tests to be written!!!
    ASSERT_EQ(true,false);
}

#endif
