/*
 * InnerEdgesMapGenerator_test.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: qwrtln
 */

#include "TestExecuter.h"
#include "CrazyCube.h"
#include "InnerEdgesMapGenerator.h"
#include <cmath>

class InnerEdgesMapGeneratorTest: public BaseTest
{
public:
	InnerEdgesMapGeneratorTest(string testCase, string testName)
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
  static InnerEdgesMapGenerator IEmapper;
};

InnerEdgesMapGenerator InnerEdgesMapGeneratorTest::IEmapper;

// For backward compatibility:
#define FIVE_MOVES 5
#define SIX_MOVES 6

#ifdef MEMORY_CHECK
TEST_F(InnerEdgesMapGeneratorTest, findingMemoryLeaks)
{
	unsigned long long cubeState = 0x102469BD02469BDF;

    /* ~~Inner Corners ~~ */
    IEmapper.convertIntToPieces(4);
    IEmapper.convertPiecesToInt(cubeState);
    IEmapper.generateMoveMap();
}
#else

TEST_F(InnerEdgesMapGeneratorTest, TestConvertPiecesToIntSolvedCube)
{
    int expectedSum = 15; // just as above
    int actualOutput = IEmapper.convertPiecesToInt(IEmapper.solvedCube); 
	ASSERT_EQ(actualOutput, expectedSum);
}

TEST_F(InnerEdgesMapGeneratorTest, TestConvertPiecesToIntRandomCube)
{
    const int moves = 5;
    rotation randomMoves[moves] = {rotation::LEFT, rotation::UP, rotation::FRONT, rotation::UP_INVERTED, rotation::MIDDLE_VERTICAL};

    CrazyCube cube;

    for (int i = 0; i < moves; ++i)
        cube.move(randomMoves[i]);

    int expectedSum = 0b11000011; // still the same magic number
    int actualOutput = IEmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ_BIN(actualOutput, expectedSum);

    // double check just to be sure
    cube.resetCube();
    rotation randomMoves2[FIVE_MOVES] = {rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, rotation::LEFT, rotation::MIDDLE_HORIZONTAL, rotation::MIDDLE_VERTICAL_BACK_ROTATION, rotation::FRONT};
    
    for (int i = 0; i < FIVE_MOVES; ++i)
    {
        cube.move(randomMoves2[i]);
    }

    expectedSum = 0b10100101; 
    actualOutput = IEmapper.convertPiecesToInt(cube.getCubeState()); 
	ASSERT_EQ_BIN(actualOutput, expectedSum);
	//-------------------------------------------------------------------------
	
	unsigned long long cubeState = 0x102469BD12479BCE;
	int expectedEdgesInt = 0b10011100;
	actualOutput = IEmapper.convertPiecesToInt(cubeState);
	ASSERT_EQ_BIN(actualOutput, expectedEdgesInt);
	
	//-------------------------------------------------------------------------
	
	cubeState = 0x102469BD13578ACE;
	expectedEdgesInt = 0b11110000;
	actualOutput = IEmapper.convertPiecesToInt(cubeState);
	ASSERT_EQ_BIN(actualOutput, expectedEdgesInt);
}

TEST_F(InnerEdgesMapGeneratorTest, TestConvertIntToPiecesSolvedCube)
{
	//unsigned long long int cubeState = 0x1 02469BD 02469BDF;
	// innerEdgesInt = 2^0 + 2^1 + 2^2 + 2^3 = 0xF
	int innerEdgesInt = 0xF;
	unsigned long long int innerEdgesExpected = 0x0000000000001111;
	ASSERT_EQ_HEX(innerEdgesExpected, IEmapper.convertIntToPieces(innerEdgesInt));
}

TEST_F(InnerEdgesMapGeneratorTest, TestConvertIntToPiecesRandomCube)
{
	int innerEdgesInt = 0xF0;
	unsigned long long int innerEdgesExpected = 0x0000000011110000;
	ASSERT_EQ_HEX(innerEdgesExpected, IEmapper.convertIntToPieces(innerEdgesInt));
	
	innerEdgesInt = 0xC3;
	innerEdgesExpected = 0x0000000011000011;
	ASSERT_EQ_HEX(innerEdgesExpected, IEmapper.convertIntToPieces(innerEdgesInt));
	
	innerEdgesInt = 0xAA;
	innerEdgesExpected = 0x0000000010101010;
	ASSERT_EQ_HEX(innerEdgesExpected, IEmapper.convertIntToPieces(innerEdgesInt));
}

#endif
