/*
 * OuterEdgesMapGenerator_test.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: OPTIMUS
 */

#include "TestExecuter.h"
#include "CrazyCube.h"
#include "OuterEdgesMapGenerator.h"
#include <cmath>

class OuterEdgesMapGeneratorTest: public BaseTest
{
public:
	OuterEdgesMapGeneratorTest(string testCase, string testName)
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
  static OuterEdgesMapGenerator OEmapper;
};

OuterEdgesMapGenerator OuterEdgesMapGeneratorTest::OEmapper;

// For backward compatibility:
#define FIVE_MOVES 5
#define SIX_MOVES 6

#ifdef MEMORY_CHECK
TEST_F(OuterEdgesMapGeneratorTest, findingMemoryLeaks)
{
	unsigned long long cubeState = 0x102469BD02469BDF;

    /* ~~Outer Corners ~~ */
    OEmapper.convertIntToPieces(5);
    OEmapper.convertPiecesToInt(cubeState);
    OEmapper.generateMoveMap();
}
#else

TEST_F(OuterEdgesMapGeneratorTest, TestConvertPiecesToIntSolvedCube)
{
    int expectedSum = 0; 
    int actualOutput = OEmapper.convertPiecesToInt(OEmapper.solvedCube); 
	ASSERT_EQ(actualOutput, expectedSum);
}

TEST_F(OuterEdgesMapGeneratorTest, TestConvertPiecesToIntRandomCube)
{
    rotation randomMoves[SIX_MOVES] = {rotation::LEFT, rotation::MIDDLE_VERTICAL_BACK_ROTATION, rotation::UP_2, rotation::FRONT, rotation::UP_INVERTED, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION};

    CrazyCube cube;

    for (int i = 0; i < SIX_MOVES; ++i)
        cube.move(randomMoves[i]);

    int expectedSum = 3487; // calculated in Octave
    int actualOutput = OEmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);

    // 2nd case
    cube.resetCube();
    rotation randomMoves2[FIVE_MOVES] = {rotation::FRONT, rotation::MIDDLE_VERTICAL, rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, rotation::LEFT, rotation::UP_2};

    for (int i = 0; i < FIVE_MOVES; ++i)
        cube.move(randomMoves2[i]);
   
    expectedSum = 22888;
    actualOutput = OEmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);

    // 3rd case
    cube.resetCube();
    rotation randomMoves3[FIVE_MOVES] = {rotation::UP, rotation::LEFT, rotation::FRONT, rotation::LEFT, rotation::MIDDLE_HORIZONTAL};

    for (int i = 0; i < FIVE_MOVES; ++i)
        cube.move(randomMoves3[i]);
   
    expectedSum = 36562;
    actualOutput = OEmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);
}

TEST_F(OuterEdgesMapGeneratorTest, TestConvertIntToPiecesSolvedCube)
{
	unsigned long long cubeState = solvedCube & 0xEEEEEEEE;
	int outerEdgesInt = 0;
	ASSERT_EQ_HEX(cubeState, OEmapper.convertIntToPieces(outerEdgesInt));
}

TEST_F(OuterEdgesMapGeneratorTest, TestConvertIntToPiecesRandomCube)
{
    // TODO: 2 more cases

	//rotation randomMoves[moves] = {rotation::LEFT, rotation::MIDDLE_VERTICAL_BACK_ROTATION, rotation::UP_2, rotation::FRONT, rotation::UP_INVERTED, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION};

    int outerEdgesInt = 3487;
    unsigned long long int expectedOutput = 0x0000000062A8C04E;
    unsigned long long int actualOutput = OEmapper.convertIntToPieces(outerEdgesInt); 
	ASSERT_EQ_HEX(actualOutput, expectedOutput);
}

TEST_F(OuterEdgesMapGeneratorTest, TestconvertPiecesToIntSolvedCube)
{
    int expectedSum = 0; 
    int actualOutput = OEmapper.convertPiecesToInt(OEmapper.solvedCube); 
	ASSERT_EQ(actualOutput, expectedSum);
}

TEST_F(OuterEdgesMapGeneratorTest, TestconvertPiecesToIntRandomCube)
{
    rotation randomMoves[SIX_MOVES] = {rotation::LEFT, rotation::MIDDLE_VERTICAL_BACK_ROTATION, rotation::UP_2, rotation::FRONT, rotation::UP_INVERTED, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION};

    CrazyCube cube;

    for (int i = 0; i < SIX_MOVES; ++i)
        cube.move(randomMoves[i]);

    int expectedSum = 3487; // calculated in Octave
    int actualOutput = OEmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);

    // 2nd case
    cube.resetCube();
    rotation randomMoves2[FIVE_MOVES] = {rotation::FRONT, rotation::MIDDLE_VERTICAL, rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, rotation::LEFT, rotation::UP_2};

    for (int i = 0; i < FIVE_MOVES; ++i)
        cube.move(randomMoves2[i]);
   
    expectedSum = 22888;
    actualOutput = OEmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);

    // 3rd case
    cube.resetCube();
    rotation randomMoves3[FIVE_MOVES] = {rotation::UP, rotation::LEFT, rotation::FRONT, rotation::LEFT, rotation::MIDDLE_HORIZONTAL};

    for (int i = 0; i < FIVE_MOVES; ++i)
        cube.move(randomMoves3[i]);
   
    expectedSum = 36562;
    actualOutput = OEmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);
}



TEST_F(OuterEdgesMapGeneratorTest, TestconvertIntToPiecesSolvedCube)
{	
	unsigned long long cubeState = solvedCube & 0xEEEEEEEE;
	int outerEdgesInt = 0;
	ASSERT_EQ_HEX(cubeState, OEmapper.convertIntToPieces(outerEdgesInt));
}

TEST_F(OuterEdgesMapGeneratorTest, TestconvertIntToPiecesRandomCube)
{
    // TODO: 2 more cases

	//rotation randomMoves[moves] = {rotation::LEFT, rotation::MIDDLE_VERTICAL_BACK_ROTATION, rotation::UP_2, rotation::FRONT, rotation::UP_INVERTED, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION};

    int outerEdgesInt = 3487;
    unsigned long long int expectedOutput = 0x0000000062A8C04E;
    unsigned long long int actualOutput = OEmapper.convertIntToPieces(outerEdgesInt); 
	ASSERT_EQ_HEX(actualOutput, expectedOutput);
}

#endif
