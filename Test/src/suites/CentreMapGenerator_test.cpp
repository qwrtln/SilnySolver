/*
 * CentreMapGenerator_test.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: qwrtln
 */

#include "TestExecuter.h"
#include "CrazyCube.h"
#include "CentreMapGenerator.h"
#include <cmath>

class CentreMapGeneratorTest: public BaseTest
{
public:
	CentreMapGeneratorTest(string testCase, string testName)
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
  static CentreMapGenerator Cmapper;
};

CentreMapGenerator CentreMapGeneratorTest::Cmapper;

// For backward compatibility:
#define FIVE_MOVES 5
#define SIX_MOVES 6

#ifdef MEMORY_CHECK
TEST_F(CentreMapGeneratorTest, findingMemoryLeaks)
{
	unsigned long long cubeState = 0x102469BD02469BDF;

    /* ~~ Centre ~~ */
    Cmapper.convertIntToPieces(4);
    Cmapper.convertPiecesToInt(cubeState);
    Cmapper.generateMoveMap();
}
#else

TEST_F(CentreMapGeneratorTest, TestconvertPiecesToIntSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int intCentreExpected = 1;
	ASSERT_EQ(intCentreExpected, Cmapper.convertPiecesToInt(cubeState));
}

TEST_F(CentreMapGeneratorTest, TestconvertPiecesToIntRandomCube)
{
    // TODO: 2 more cases

	unsigned long long cubeState = 0x0DB204962964BFD0;
	int intCentreExpected = 0;
	ASSERT_EQ(intCentreExpected, Cmapper.convertPiecesToInt(cubeState));
}

TEST_F(CentreMapGeneratorTest, TestConvertIntToPiecesSolvedCube)
{
	int centre = 1;
	unsigned long long int centreExpected = 0x1000000000000000;
	ASSERT_EQ_HEX(centreExpected, Cmapper.convertIntToPieces(centre));
}

TEST_F(CentreMapGeneratorTest, TestConvertIntToPiecesRandomCube)
{
	int centre = 0;
	unsigned long long int centreExpected = 0x0000000000000000;
	ASSERT_EQ_HEX(centreExpected, Cmapper.convertIntToPieces(centre));
}

#endif
