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

    mapper.convertCentreToInt(cubeState);
    mapper.convertInnerCornersToInt(cubeState);
    mapper.convertInnerEdgesToInt(cubeState);
    mapper.convertIntToCentre(1);
    mapper.convertIntToInnerCorners(2);
    mapper.convertIntToInnerEdges(3);
    mapper.convertIntToOuterEdges(5);
    mapper.convertOuterEdgesToInt(cubeState);
    mapper.extractInnerPiece(1,2,cubeState);
    mapper.extractOuterPiece(3,4,cubeState);
    mapper.generateCentreMap();
    mapper.generateInnerCornersMap();
    mapper.generateInnerEdgesMap();
    mapper.generateOuterEdgesMap();
	mapper.generatePieceMap(factorials[NUM_OF_EDGES],&CrazyCubeMoveMapper::convertIntToOuterEdges,&CrazyCubeMoveMapper::convertOuterEdgesToInt);
    mapper.generatePieceMap(factorials[NUM_OF_CORNERS], &CrazyCubeMoveMapper::convertIntToInnerCorners,&CrazyCubeMoveMapper::convertInnerCornersToInt);
	mapper.generatePieceMap(factorials[NUM_OF_EDGES],&CrazyCubeMoveMapper::convertIntToInnerEdges,&CrazyCubeMoveMapper::convertInnerEdgesToInt);
	mapper.generatePieceMap(factorials[2],&CrazyCubeMoveMapper::convertIntToCentre,&CrazyCubeMoveMapper::convertCentreToInt);
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

TEST_F(CrazyCubeMoveMapperTest, TestConvertInnerCornersToIntSolvedCube)
{
    int expectedSum = 7; // result after bin2dec operation
    int actualOutput = mapper.convertInnerCornersToInt(mapper.solvedCube); 
	ASSERT_EQ(actualOutput, expectedSum);
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertInnerCornersToIntRandomCube)
{
    rotation randomMoves[SIX_MOVES] = {rotation::MIDDLE_VERTICAL_FRONT_ROTATION, rotation::UP_2, rotation::MIDDLE_HORIZONTAL, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION, rotation::LEFT, rotation::FRONT};

    CrazyCube cube;

    for (int i = 0; i < SIX_MOVES; ++i)
        cube.move(randomMoves[i]);

    int expectedSum = 0b110100; // result of dec2bin operation
    int actualOutput = mapper.convertInnerCornersToInt(cube.getCubeState()); 
	ASSERT_EQ_BIN(actualOutput, expectedSum);

    // double checking
    cube.resetCube();
    rotation randomMoves2[SIX_MOVES] = {rotation::FRONT, rotation::LEFT, rotation::FRONT, rotation::MIDDLE_VERTICAL, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION, rotation::MIDDLE_VERTICAL};
    
    for (int i = 0; i < SIX_MOVES; ++i)
    {
        cube.move(randomMoves2[i]);
    }

    expectedSum = 0b0000111; 
    actualOutput = mapper.convertInnerCornersToInt(cube.getCubeState()); 
	ASSERT_EQ_BIN(expectedSum, actualOutput);
    
    // triple check - let's be thorough this time :)
    cube.resetCube();
    rotation randomMoves3[SIX_MOVES] = {rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, rotation::MIDDLE_VERTICAL_FRONT_ROTATION, rotation::UP_2, rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION, rotation::UP_INVERTED, rotation::FRONT};
    
    for (int i = 0; i < SIX_MOVES; ++i)
    {
        cube.move(randomMoves3[i]);
    }

    expectedSum = 0b1100001; 
    actualOutput = mapper.convertInnerCornersToInt(cube.getCubeState()); 
	ASSERT_EQ_BIN(expectedSum, actualOutput);
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertInnerEdgesToIntSolvedCube)
{
    int expectedSum = 15; // just as above
    int actualOutput = mapper.convertInnerEdgesToInt(mapper.solvedCube); 
	ASSERT_EQ(actualOutput, expectedSum);
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertInnerEdgesToIntRandomCube)
{
    const int moves = 5;
    rotation randomMoves[moves] = {rotation::LEFT, rotation::UP, rotation::FRONT, rotation::UP_INVERTED, rotation::MIDDLE_VERTICAL};

    CrazyCube cube;

    for (int i = 0; i < moves; ++i)
        cube.move(randomMoves[i]);

    int expectedSum = 0b11000011; // still the same magic number
    int actualOutput = mapper.convertInnerEdgesToInt(cube.getCubeState()); 
	ASSERT_EQ_BIN(actualOutput, expectedSum);

    // double check just to be sure
    cube.resetCube();
    rotation randomMoves2[FIVE_MOVES] = {rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, rotation::LEFT, rotation::MIDDLE_HORIZONTAL, rotation::MIDDLE_VERTICAL_BACK_ROTATION, rotation::FRONT};
    
    for (int i = 0; i < FIVE_MOVES; ++i)
    {
        cube.move(randomMoves2[i]);
    }

    expectedSum = 0b10100101; 
    actualOutput = mapper.convertInnerEdgesToInt(cube.getCubeState()); 
	ASSERT_EQ_BIN(actualOutput, expectedSum);
	//-------------------------------------------------------------------------
	
	unsigned long long cubeState = 0x102469BD12479BCE;
	int expectedEdgesInt = 0b10011100;
	actualOutput = mapper.convertInnerEdgesToInt(cubeState);
	ASSERT_EQ_BIN(actualOutput, expectedEdgesInt);
	
	//-------------------------------------------------------------------------
	
	cubeState = 0x102469BD13578ACE;
	expectedEdgesInt = 0b11110000;
	actualOutput = mapper.convertInnerEdgesToInt(cubeState);
	ASSERT_EQ_BIN(actualOutput, expectedEdgesInt);
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertCentreToIntSolvedCube)
{
	unsigned long long cubeState = 0x102469BD02469BDF;
	int intCentreExpected = 1;
	ASSERT_EQ(intCentreExpected, mapper.convertCentreToInt(cubeState));
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertCentreToIntRandomCube)
{
    // TODO: 2 more cases

	unsigned long long cubeState = 0x0DB204962964BFD0;
	int intCentreExpected = 0;
	ASSERT_EQ(intCentreExpected, mapper.convertCentreToInt(cubeState));
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

TEST_F(CrazyCubeMoveMapperTest, TestConvertIntToInnerCornersSolvedCube)
{
	//unsigned long long int cubeState = 0x1 02469BD 02469BDF;
	int innerCornersInt = 0x7;
	unsigned long long int innerCornersExpected = 0x0000011100000000;
	ASSERT_EQ_HEX(innerCornersExpected, mapper.convertIntToInnerCorners(innerCornersInt));
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertIntToInnerCornersRandomCube)
{
	//unsigned long long int cubeState = 0x1 DB96420 02469BDF;
	int innerCornersInt = 0x70;
	unsigned long long int innerCornersExpected = 0x0111000000000000;
	ASSERT_EQ_HEX(innerCornersExpected, mapper.convertIntToInnerCorners(innerCornersInt));
	
	innerCornersInt = 0x61;
	innerCornersExpected = 0x0110000100000000;
	ASSERT_EQ_HEX(innerCornersExpected, mapper.convertIntToInnerCorners(innerCornersInt));
	
	innerCornersInt = 0x54;
	innerCornersExpected = 0x0101010000000000;
	ASSERT_EQ_HEX(innerCornersExpected, mapper.convertIntToInnerCorners(innerCornersInt));
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertIntToInnerEdgesSolvedCube)
{
	//unsigned long long int cubeState = 0x1 02469BD 02469BDF;
	// innerEdgesInt = 2^0 + 2^1 + 2^2 + 2^3 = 0xF
	int innerEdgesInt = 0xF;
	unsigned long long int innerEdgesExpected = 0x0000000000001111;
	ASSERT_EQ_HEX(innerEdgesExpected, mapper.convertIntToInnerEdges(innerEdgesInt));
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertIntToInnerEdgesRandomCube)
{
	int innerEdgesInt = 0xF0;
	unsigned long long int innerEdgesExpected = 0x0000000011110000;
	ASSERT_EQ_HEX(innerEdgesExpected, mapper.convertIntToInnerEdges(innerEdgesInt));
	
	innerEdgesInt = 0xC3;
	innerEdgesExpected = 0x0000000011000011;
	ASSERT_EQ_HEX(innerEdgesExpected, mapper.convertIntToInnerEdges(innerEdgesInt));
	
	innerEdgesInt = 0xAA;
	innerEdgesExpected = 0x0000000010101010;
	ASSERT_EQ_HEX(innerEdgesExpected, mapper.convertIntToInnerEdges(innerEdgesInt));
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertIntToCentreSolvedCube)
{
	int centre = 1;
	unsigned long long int centreExpected = 0x1000000000000000;
	ASSERT_EQ_HEX(centreExpected, mapper.convertIntToCentre(centre));
}

TEST_F(CrazyCubeMoveMapperTest, TestConvertIntToCentreRandomCube)
{
	int centre = 0;
	unsigned long long int centreExpected = 0x0000000000000000;
	ASSERT_EQ_HEX(centreExpected, mapper.convertIntToCentre(centre));
}
#endif
