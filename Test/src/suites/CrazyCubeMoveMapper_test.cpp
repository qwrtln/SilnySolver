/*
 * CrazyCubeMoveMapper_test.cpp
 *
 *  Created on: May 29, 2016
 *      Author: qwrtln
 */

#include "CrazyCubeMoveMapper.h"
#include "TestExecuter.h"
#include "CrazyCubeAbstract.h"
#include "CrazyCube.h"
#include <cmath>

class CrazyCubeMoveMapperTest: public BaseTest
{
public:
	CrazyCubeMoveMapperTest(string testCase, string testName)
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
	static CrazyCubeMoveMapper mapper;
};

CrazyCubeMoveMapper CrazyCubeMoveMapperTest::mapper;

// For backward compatibility:
#define FIVE_MOVES 5
#define SIX_MOVES 6

#ifdef MEMORY_CHECK
TEST_F(CrazyCubeMoveMapperTest, findingMemoryLeaks)
{
	unsigned long long cubeState = 0x102469BD02469BDF;

    mapper.convertIntToOuterEdges(5);
    mapper.convertOuterEdgesToInt(cubeState);
    mapper.extractInnerPiece(1,2,cubeState);
    mapper.extractOuterPiece(3,4,cubeState);
    mapper.generateOuterEdgesMap();
	mapper.generatePieceMap(factorials[NUM_OF_EDGES],&CrazyCubeMoveMapper::convertIntToOuterEdges,&CrazyCubeMoveMapper::convertOuterEdgesToInt);
}
#else
TEST_F(CrazyCubeMoveMapperTest, TestExtractOuterPieceGeneralSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int outerPiecesExpected[16] = {0, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 7};
	for(unsigned int i = 0; i < 16; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], mapper.extractOuterPiece(CENTRE_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractOuterPieceGeneralRandomCube)
{
	unsigned long long cubeState = 0x0DB2046920964BFD;
	int outerPiecesExpected[16] = {0,    6, 5, 1, 0, 2, 3, 4,    1, 0, 4, 3, 2, 5, 7, 6};
	for(unsigned int i = 0; i < 16; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], mapper.extractOuterPiece(CENTRE_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractOuterPieceCornersSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int outerPiecesExpected[NUM_OF_CORNERS] = {0, 1, 2, 3, 4, 5, 6};
	for(unsigned int i = 0; i < NUM_OF_CORNERS; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], mapper.extractOuterPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractOuterPieceCornersRandomCube)
{
	unsigned long long cubeState = 0x0DB204962964BFD0;
	int outerPiecesExpected[NUM_OF_CORNERS] = {6, 5, 1, 0, 2, 4, 3};
	for(unsigned int i = 0; i < NUM_OF_CORNERS; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], mapper.extractOuterPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractOuterPieceEdgesSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int outerPiecesExpected[NUM_OF_EDGES] = {0, 1, 2, 3, 4, 5, 6, 7};
	for(unsigned int i = 0; i < NUM_OF_EDGES; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], mapper.extractOuterPiece(EDGES_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractOuterPieceEdgesRandomCube)
{
	unsigned long long cubeState = 0x0DB20469964BFD20;
	int outerPiecesExpected[NUM_OF_EDGES] = {4, 3, 2, 5, 7, 6, 1, 0};
	for(unsigned int i = 0; i < NUM_OF_EDGES; i++)
	{	
		ASSERT_EQ(outerPiecesExpected[i], mapper.extractOuterPiece(EDGES_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractInnerPieceGeneralSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int innerPiecesExpected[16] = {1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1};
	for(unsigned int i = 0; i < 16; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], mapper.extractInnerPiece(CENTRE_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractInnerPieceGeneralRandomCube)
{
	unsigned long long cubeState = 0x0DB2046920964BFD;
	int innerPiecesExpected[16] = {0,    1, 1, 0, 0, 0, 0, 1,    0, 0, 1, 0, 0, 1, 1, 1};
	for(unsigned int i = 0; i < 16; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], mapper.extractInnerPiece(CENTRE_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractInnerPieceCornersSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int innerPiecesExpected[NUM_OF_CORNERS] = {0, 0, 0, 0, 1, 1, 1};
	for(unsigned int i = 0; i < NUM_OF_CORNERS; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], mapper.extractInnerPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractInnerPieceCornersRandomCube)
{
	unsigned long long cubeState = 0x0DB204962964BFD0;
	int innerPiecesExpected[NUM_OF_CORNERS] = {1, 1, 0, 0, 0, 1, 0};
	for(unsigned int i = 0; i < NUM_OF_CORNERS; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], mapper.extractInnerPiece(CORNERS_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractInnerPieceEdgesSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int innerPiecesExpected[NUM_OF_EDGES] = {0, 0, 0, 0, 1, 1, 1, 1};
	for(unsigned int i = 0; i < NUM_OF_EDGES; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], mapper.extractInnerPiece(EDGES_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestExtractInnerPieceEdgesRandomCube)
{
	unsigned long long cubeState = 0x0DB20469964BFD20;
	int innerPiecesExpected[NUM_OF_EDGES] = {1, 0, 0, 1, 1, 1, 0, 0};
	for(unsigned int i = 0; i < NUM_OF_EDGES; i++)
	{	
		ASSERT_EQ(innerPiecesExpected[i], mapper.extractInnerPiece(EDGES_MOST_SIGNIFICANT, i, cubeState));
	}
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertOuterEdgesToIntSolvedCube)
{
    int expectedSum = 0; 
    int actualOutput = mapper.convertOuterEdgesToInt(mapper.solvedCube); 
	ASSERT_EQ(actualOutput, expectedSum);
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertOuterEdgesToIntRandomCube)
{
    rotation randomMoves[SIX_MOVES] = {rotation::LEFT, rotation::MIDDLE_VERTICAL_BACK_ROTATION, rotation::UP_2, rotation::FRONT, rotation::UP_INVERTED, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION};

    CrazyCube cube;

    for (int i = 0; i < SIX_MOVES; ++i)
        cube.move(randomMoves[i]);

    int expectedSum = 3487; // calculated in Octave
    int actualOutput = mapper.convertOuterEdgesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);

    // 2nd case
    cube.resetCube();
    rotation randomMoves2[FIVE_MOVES] = {rotation::FRONT, rotation::MIDDLE_VERTICAL, rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, rotation::LEFT, rotation::UP_2};

    for (int i = 0; i < FIVE_MOVES; ++i)
        cube.move(randomMoves2[i]);
   
    expectedSum = 22888;
    actualOutput = mapper.convertOuterEdgesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);

    // 3rd case
    cube.resetCube();
    rotation randomMoves3[FIVE_MOVES] = {rotation::UP, rotation::LEFT, rotation::FRONT, rotation::LEFT, rotation::MIDDLE_HORIZONTAL};

    for (int i = 0; i < FIVE_MOVES; ++i)
        cube.move(randomMoves3[i]);
   
    expectedSum = 36562;
    actualOutput = mapper.convertOuterEdgesToInt(cube.getCubeState()); 
	ASSERT_EQ(actualOutput, expectedSum);
}



TEST_F(CrazyCubeMoveMapperTest, TestConvertIntToOuterEdgesSolvedCube)
{	
	unsigned long long cubeState = solvedCube & 0xEEEEEEEE;
	int outerEdgesInt = 0;
	ASSERT_EQ_HEX(cubeState, mapper.convertIntToOuterEdges(outerEdgesInt));
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertIntToOuterEdgesRandomCube)
{
    // TODO: 2 more cases

	//rotation randomMoves[moves] = {rotation::LEFT, rotation::MIDDLE_VERTICAL_BACK_ROTATION, rotation::UP_2, rotation::FRONT, rotation::UP_INVERTED, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION};

    int outerEdgesInt = 3487;
    unsigned long long int expectedOutput = 0x0000000062A8C04E;
    unsigned long long int actualOutput = mapper.convertIntToOuterEdges(outerEdgesInt); 
	ASSERT_EQ_HEX(actualOutput, expectedOutput);
}


#endif
