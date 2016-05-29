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

// For backward compatibility:
#define FIVE_MOVES 5
#define SIX_MOVES 6

#ifdef MEMORY_CHECK
TEST_F(CrazyCubeMapperTest, findingMemoryLeaks)
{
    // Tests to be written!!!
    ASSERT_EQ(true,false);
}
#else
TEST_F(CrazyCubeMapperTest, TestSwapMapElementValue)
{
    // Tests to be written!!!
    ASSERT_EQ(true,false);
}

#endif
