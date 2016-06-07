/*
 * MoveMapsGenerator_test.cpp
 *
 *  Created on: Jun 6, 2016
 *      Author: qwrtln
 */

#include "TestExecuter.h"
#include "CrazyCubeAbstract.h"
#include "CrazyCube.h"
#include "OuterCornersMapGenerator.h"
#include <cmath>

class OuterCornersMapGeneratorTest: public BaseTest
{
public:
	OuterCornersMapGeneratorTest(string testCase, string testName)
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
  static OuterCornersMapGenerator OCmapper;
};

OuterCornersMapGenerator OuterCornersMapGeneratorTest::OCmapper;

// For backward compatibility:
#define FIVE_MOVES 5
#define SIX_MOVES 6

#ifdef MEMORY_CHECK
TEST_F(OuterCornersMapGeneratorTest, findingMemoryLeaks)
{
	unsigned long long cubeState = 0x102469BD02469BDF;

    /* ~~Outer Corners ~~ */
    OCmapper.convertIntToPieces(4);
    OCmapper.convertPiecesToInt(cubeState);
    OCmapper.generateMoveMap();
}
#else
TEST_F(OuterCornersMapGeneratorTest, TestConvertPiecesToIntSolvedCube)
{
    // Actual output
    int output = OCmapper.convertPiecesToInt(OCmapper.solvedCorners);
   
    // Hardcoded Pkoz algorithm
    int sum = 0;
    for (int i = NUM_OF_CORNERS - 1; i > 0; --i)
    {
        int cornersLeft = 0;

        for (int j = i - 1; j >=0; --j)
        {
            if (OCmapper.extractOuterPiece(CORNERS_MOST_SIGNIFICANT, j, OCmapper.solvedCorners) > OCmapper.extractOuterPiece(CORNERS_MOST_SIGNIFICANT, i, OCmapper.solvedCorners) )
            {
               ++cornersLeft; 
        }
        
        sum += cornersLeft * OCmapper.factorials[i];

        }

        ASSERT_EQ(sum, output);
    }
}

TEST_F(OuterCornersMapGeneratorTest, TestConvertPiecesToIntRandomCube)
{
    CrazyCube cube;

    cube.move(rotation::LEFT);

    int expectedSum = 4142; // calculated in Octave
    int actualOutput = OCmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);
   
    // 2nd case
    cube.resetCube();
   rotation randomMoves[FIVE_MOVES] = {rotation::FRONT, rotation::MIDDLE_VERTICAL, rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, rotation::LEFT, rotation::UP_2};

    for (int i = 0; i < FIVE_MOVES; ++i)
        cube.move(randomMoves[i]);
    
    expectedSum = 2354;
    actualOutput = OCmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);

    // 3rd case
    cube.resetCube();
    rotation randomMoves2[FIVE_MOVES] = {rotation::UP, rotation::LEFT, rotation::FRONT, rotation::LEFT, rotation::MIDDLE_HORIZONTAL};

    for (int i = 0; i < FIVE_MOVES; ++i)
        cube.move(randomMoves2[i]);
   
    expectedSum = 1567;
    actualOutput = OCmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);
}

TEST_F(OuterCornersMapGeneratorTest, TestConvertIntToPiecesSolvedCube)
{
	unsigned long long cubeState = 0x002468AC00000000;
	int outerCornersInt = 0;

	ASSERT_EQ_HEX(cubeState, OCmapper.convertIntToPieces(outerCornersInt));
}

TEST_F(OuterCornersMapGeneratorTest, TestConvertIntToPiecesRandomCube)
{
    // TODO: 2 more cases

    rotation randomMoves[SIX_MOVES] = {rotation::LEFT, rotation::MIDDLE_VERTICAL_BACK_ROTATION, rotation::UP_2, rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, rotation::FRONT, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION};

    CrazyCube cube;

    for (int i = 0; i < SIX_MOVES; ++i)
        cube.move(randomMoves[i]);

    int intFromConversion = 3776; // calculated in Octave

    unsigned long long expectedCubeState = cube.getCubeState() & 0x0eeeeeee00000000ULL; // Murphy's law - stupid but working
    unsigned long long actualCube = OCmapper.convertIntToPieces(intFromConversion);
	ASSERT_EQ_HEX(expectedCubeState, actualCube);
}
#endif
