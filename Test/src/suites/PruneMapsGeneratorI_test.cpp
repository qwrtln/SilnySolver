/*
 * PruneMapsGeneratorI_test.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: qwrtln
 */
#include "PruneMapsGeneratorI.h"
#include "PruneMapsGeneratorI_mock.h"
#include "TestExecuter.h"
#include "CrazyCubeAbstract.h"
#include <vector>

class PruneMapsGeneratorITest: public BaseTest
{
public:
	PruneMapsGeneratorITest(string testCase, string testName)
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
	static PruneMapsGeneratorI_mock generator;
};

PruneMapsGeneratorI_mock PruneMapsGeneratorITest::generator;

#ifdef MEMORY_CHECK
TEST_F(PruneMapsGeneratorITest, findingMemoryLeaks)
{
    std::vector<int> singleVect(17);

    generator.swapMapElementValue(3, singleVect, 4, 5);
    generator.generateInitialVector(42);
    generator.getPieceMap();
    generator.generatePruneMap(4);
}
#else
TEST_F(PruneMapsGeneratorITest, GenericVisibilityTest)
{
    ASSERT_EQ(1,0);
}

#endif
TEST_F(PruneMapsGeneratorITest, SwapElementValueTest)
{
	std::vector<int> testVect {0, 1, 2, 3, 4, 5, 6, 7}; 
	std::vector<int> testVect2 = testVect;
	testVect2[4] = 9;
	generator.swapMapElementValue(testVect.size(), testVect, 4, 9);
	bool areVectsEq = (testVect == testVect2);
	ASSERT_EQ(areVectsEq, 1);
							
}
