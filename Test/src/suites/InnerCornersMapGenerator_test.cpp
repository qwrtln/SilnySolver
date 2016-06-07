/*
 * InnerCornersMapGenerator_test.cpp
 *
 *  Created on: Jun 7, 2016
 *      Author: qwrtln
 */

#include "TestExecuter.h"
#include "CrazyCube.h"
#include "InnerCornersMapGenerator.h"
#include <cmath>

class InnerCornersMapGeneratorTest: public BaseTest
{
public:
	InnerCornersMapGeneratorTest(string testCase, string testName)
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
  static InnerCornersMapGenerator ICmapper;
};

InnerCornersMapGenerator InnerCornersMapGeneratorTest::ICmapper;

// For backward compatibility:
#define FIVE_MOVES 5
#define SIX_MOVES 6

#ifdef MEMORY_CHECK
TEST_F(InnerCornersMapGeneratorTest, findingMemoryLeaks)
{
	unsigned long long cubeState = 0x102469BD02469BDF;

    /* ~~Inner Corners ~~ */
    ICmapper.convertIntToPieces(4);
    ICmapper.convertPiecesToInt(cubeState);
    ICmapper.generateMoveMap();
}
#else

TEST_F(InnerCornersMapGeneratorTest, TestconvertPiecesToIntSolvedCube)
{
    int expectedSum = 7; // result after bin2dec operation
    int actualOutput = ICmapper.convertPiecesToInt(ICmapper.solvedCube); 
	ASSERT_EQ(actualOutput, expectedSum);
}

TEST_F(InnerCornersMapGeneratorTest, TestconvertPiecesToIntRandomCube)
{
    rotation randomMoves[SIX_MOVES] = {rotation::MIDDLE_VERTICAL_FRONT_ROTATION, rotation::UP_2, rotation::MIDDLE_HORIZONTAL, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION, rotation::LEFT, rotation::FRONT};

    CrazyCube cube;

    for (int i = 0; i < SIX_MOVES; ++i)
        cube.move(randomMoves[i]);

    int expectedSum = 0b110100; // result of dec2bin operation
    int actualOutput =ICmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ_BIN(actualOutput, expectedSum);

    // double checking
    cube.resetCube();
    rotation randomMoves2[SIX_MOVES] = {rotation::FRONT, rotation::LEFT, rotation::FRONT, rotation::MIDDLE_VERTICAL, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION, rotation::MIDDLE_VERTICAL};
    
    for (int i = 0; i < SIX_MOVES; ++i)
    {
        cube.move(randomMoves2[i]);
    }

    expectedSum = 0b0000111; 
    actualOutput =ICmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ_BIN(expectedSum, actualOutput);
    
    // triple check - let's be thorough this time :)
    cube.resetCube();
    rotation randomMoves3[SIX_MOVES] = {rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, rotation::MIDDLE_VERTICAL_FRONT_ROTATION, rotation::UP_2, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION, rotation::UP_INVERTED, rotation::FRONT};
    
    for (int i = 0; i < SIX_MOVES; ++i)
    {
        cube.move(randomMoves3[i]);
    }

    expectedSum = 0b1100001; 
    actualOutput =ICmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ_BIN(expectedSum, actualOutput);
}

TEST_F(InnerCornersMapGeneratorTest, TestconvertIntToPiecesSolvedCube)
{
	//unsigned long long int cubeState = 0x1 02469BD 02469BDF;
	int innerCornersInt = 0x7;
	unsigned long long int innerCornersExpected = 0x0000011100000000;
	ASSERT_EQ_HEX(innerCornersExpected,ICmapper.convertIntToPieces(innerCornersInt));
}

TEST_F(InnerCornersMapGeneratorTest, TestconvertIntToPiecesRandomCube)
{
	//unsigned long long int cubeState = 0x1 DB96420 02469BDF;
	int innerCornersInt = 0x70;
	unsigned long long int innerCornersExpected = 0x0111000000000000;
	ASSERT_EQ_HEX(innerCornersExpected,ICmapper.convertIntToPieces(innerCornersInt));
	
	innerCornersInt = 0x61;
	innerCornersExpected = 0x0110000100000000;
	ASSERT_EQ_HEX(innerCornersExpected,ICmapper.convertIntToPieces(innerCornersInt));
	
	innerCornersInt = 0x54;
	innerCornersExpected = 0x0101010000000000;
	ASSERT_EQ_HEX(innerCornersExpected,ICmapper.convertIntToPieces(innerCornersInt));
}

#endif
