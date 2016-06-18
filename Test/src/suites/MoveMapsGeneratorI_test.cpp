/*
 * MoveMapsGeneratorI_test.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: qwrtln
 */

#include "MoveMapsGeneratorI.h"
#include "MoveMapsGeneratorI_mock.h"
#include "TestExecuter.h"
#include "CrazyCubeAbstract.h"
#include "CrazyCube.h"
#include <cmath>

class MoveMapsGeneratorITest: public BaseTest
{
public:
	MoveMapsGeneratorITest(string testCase, string testName)
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
	static MoveMapsGeneratorI_mock generator;
};

MoveMapsGeneratorI_mock MoveMapsGeneratorITest::generator;

// For backward compatibility:
#define FIVE_MOVES 5
#define SIX_MOVES 6

#ifdef MEMORY_CHECK
TEST_F(MoveMapsGeneratorITest, findingMemoryLeaks)
{
	unsigned long long cubeState = 0x102469BD02469BDF;

    generator.extractInnerPiece(1,2,cubeState);
    generator.extractOuterPiece(3,4,cubeState);
}
#else
TEST_F(MoveMapsGeneratorITest, TestExtractOuterPieceGeneralSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int outerPiecesExpected[16] = {0, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 7};
	for(unsigned int i = 0; i < 16; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], generator.extractOuterPiece(CENTRE_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractOuterPieceGeneralRandomCube)
{
	unsigned long long cubeState = 0x0DB2046920964BFD;
	int outerPiecesExpected[16] = {0,    6, 5, 1, 0, 2, 3, 4,    1, 0, 4, 3, 2, 5, 7, 6};
	for(unsigned int i = 0; i < 16; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], generator.extractOuterPiece(CENTRE_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractOuterPieceCornersSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int outerPiecesExpected[NUM_OF_CORNERS] = {0, 1, 2, 3, 4, 5, 6};
	for(unsigned int i = 0; i < NUM_OF_CORNERS; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], generator.extractOuterPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractOuterPieceCornersRandomCube)
{
	unsigned long long cubeState = 0x0DB204962964BFD0;
	int outerPiecesExpected[NUM_OF_CORNERS] = {6, 5, 1, 0, 2, 4, 3};
	for(unsigned int i = 0; i < NUM_OF_CORNERS; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], generator.extractOuterPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractOuterPieceEdgesSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int outerPiecesExpected[NUM_OF_EDGES] = {0, 1, 2, 3, 4, 5, 6, 7};
	for(unsigned int i = 0; i < NUM_OF_EDGES; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], generator.extractOuterPiece(EDGES_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractOuterPieceEdgesRandomCube)
{
	unsigned long long cubeState = 0x0DB20469964BFD20;
	int outerPiecesExpected[NUM_OF_EDGES] = {4, 3, 2, 5, 7, 6, 1, 0};
	for(unsigned int i = 0; i < NUM_OF_EDGES; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], generator.extractOuterPiece(EDGES_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractInnerPieceGeneralSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int innerPiecesExpected[16] = {1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1};
	for(unsigned int i = 0; i < 16; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], generator.extractInnerPiece(CENTRE_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractInnerPieceGeneralRandomCube)
{
	unsigned long long cubeState = 0x0DB2046920964BFD;
	int innerPiecesExpected[16] = {0,    1, 1, 0, 0, 0, 0, 1,    0, 0, 1, 0, 0, 1, 1, 1};
	for(unsigned int i = 0; i < 16; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], generator.extractInnerPiece(CENTRE_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractInnerPieceCornersSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int innerPiecesExpected[NUM_OF_CORNERS] = {0, 0, 0, 0, 1, 1, 1};
	for(unsigned int i = 0; i < NUM_OF_CORNERS; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], generator.extractInnerPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractInnerPieceCornersRandomCube)
{
	unsigned long long cubeState = 0x0DB204962964BFD0;
	int innerPiecesExpected[NUM_OF_CORNERS] = {1, 1, 0, 0, 0, 1, 0};
	for(unsigned int i = 0; i < NUM_OF_CORNERS; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], generator.extractInnerPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractInnerPieceEdgesSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int innerPiecesExpected[NUM_OF_EDGES] = {0, 0, 0, 0, 1, 1, 1, 1};
	for(unsigned int i = 0; i < NUM_OF_EDGES; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], generator.extractInnerPiece(EDGES_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(MoveMapsGeneratorITest, TestExtractInnerPieceEdgesRandomCube)
{
	unsigned long long cubeState = 0x0DB20469964BFD20;
	int innerPiecesExpected[NUM_OF_EDGES] = {1, 0, 0, 1, 1, 1, 0, 0};
	for(unsigned int i = 0; i < NUM_OF_EDGES; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], generator.extractInnerPiece(EDGES_MOST_SIGNIFICANT, i, cubeState));
	}
}

#endif
