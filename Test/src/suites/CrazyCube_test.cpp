/*
 * CrazyCube_test.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */
#include "CrazyCube.h"
#include "TestExecuter.h"
#include "CrazyCubeAbstract.h"
#include <cmath>

class CrazyCubeTest: public BaseTest
{
public:
	CrazyCubeTest(string testCase, string testName)
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
	void TestMove(unsigned int depth, bool showTime = true)
	{
		if(showTime)
		{
			cout << "Test of depth " << depth << "(" << (unsigned int)pow((double)NUM_OF_MOVES, (double)depth + 1) << " moves): ";
			cout.flush();
		}
		time_t start;
		if(showTime)
		{
			start = clock();
		}
		unsigned int max = (unsigned int)pow((double)NUM_OF_MOVES, (double)depth);

		for(unsigned int i = 0; i < max; i++) 
		{
			for(unsigned short int j = 0; j < NUM_OF_MOVES; j++)
			{			
				cube.move(static_cast<rotation>(j));
			}		
		}
		if(showTime)
		{
			cout << ((float)(clock() - start))/CLOCKS_PER_SEC << "s\n";
		}
	}
	void TestMoveAverage(unsigned int depth, unsigned int averageOf)
	{
		cout << "Test of depth " << depth << "(" << (unsigned int)pow((double)NUM_OF_MOVES, (double)depth + 1) << " moves): ";
		cout.flush();
		time_t start = clock();		
		for(unsigned short int i = 1; i <= averageOf; i++)
		{
			TestMove(depth, false);
		}
		cout << (((float)(clock() - start)) / (double)averageOf)/CLOCKS_PER_SEC << "s (avg of " << averageOf << " trials) \n";
	}
protected:
	static CrazyCube cube;
};

CrazyCube CrazyCubeTest::cube;

#ifdef MEMORY_CHECK
TEST_F(CrazyCubeTest, findingMemoryLeaks)
{
    edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
    cube.F();
    cube.L();
    cube.Mh();
    cube.MhLr();
    cube.MhRr();
    cube.Mv();
    cube.MvBr();
    cube.MvFr();
    cube.U();
    cube.U2();
    cube.Ui();
    cube.checkCorners();
    cube.checkEdges();
    cube.checkInnerCircle();
    cube.getCubeState();
    cube.isSolved();
    cube.isSolved(cube.getCubeState());
    cube.move(rotation::LEFT);
    // cube.printCubeState(); /* ~~This suppresses unnecessary output~~ */
    cube.resetCube();
    cube.setCentre(true);
    cube.setCorners(corners);
    cube.setCubeState(0);
    cube.setEdges(edges);
    cube.setWholeCube(true, edges, corners);
    cube.toggleCentre();
    cube.undoMove(rotation::LEFT);
}
#else
TEST_F(CrazyCubeTest, setCentreTest)
{
	cube.setCentre(true);
	ASSERT_EQ_HEX( (cube.getCubeState() & (static_cast<unsigned long long>(true) << cube.centrePosition)),
			static_cast<unsigned long long>(true) << cube.centrePosition )
}

TEST_F(CrazyCubeTest, setCornersTest)
{
	CrazyCube genericCube(1);
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	genericCube.setCorners(corners);
	ASSERT_EQ((genericCube.checkCorners()), true )
}

TEST_F(CrazyCubeTest, setEdgesTest)
{
	CrazyCube genericCube(1);
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	genericCube.setEdges(edges);
	ASSERT_EQ((genericCube.checkEdges()), true )
}

TEST_F(CrazyCubeTest, innerCircleTest)
{
	CrazyCube genericCube(1);
	genericCube.setCentre(true);
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_RED_WHITE, edgeNames::YELLOW_RED_WHITE, edgeNames::YELLOW_RED_WHITE, edgeNames::YELLOW_RED_WHITE};
	genericCube.setEdges(edges);
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_GREEN_RED_WHITE, cornerNames::YELLOW_GREEN_RED_WHITE, cornerNames::YELLOW_GREEN_RED_WHITE};
	genericCube.setCorners(corners);
	ASSERT_EQ((genericCube.checkInnerCircle()), true )
}

TEST_F(CrazyCubeTest, setCubeTest)
{
	ASSERT_EQ_HEX(cube.isSolved(), 1);
	cout << dec;
}

TEST_F(CrazyCubeTest, setNEGATIVEcubeTest)
{
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::WHITE_GREEN_WHITE, edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE}; // Wrong sequence
	cube.setEdges(edges);
	ASSERT_NE(cube.isSolved(), 1)
}

TEST_F(CrazyCubeTest, setWholeCubeTest)
{
	cube.setCubeState(0xf);
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	ASSERT_EQ_HEX(cube.isSolved(), 1)
}

TEST_F(CrazyCubeTest, L)
{
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_RED_YELLOW, edgeNames::WHITE_BLUE_WHITE, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::WHITE_ORANGE_BLUE_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.L();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, U)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_GREEN_YELLOW, edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	
	cubeToCompare.U();
	ASSERT_EQ_HEX(cubeToCompare.getCubeState(), cube.getCubeState())
}

TEST_F(CrazyCubeTest, F)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::WHITE_RED_WHITE, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::YELLOW_RED_YELLOW, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.F();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, UI) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::YELLOW_RED_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.Ui();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, U2) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.U2();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MV) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::WHITE_ORANGE_WHITE, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::WHITE_BLUE_WHITE, edgeNames::YELLOW_RED_YELLOW, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	cube.toggleCentre();
	CrazyCube cubeToCompare;
	cubeToCompare.Mv();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MH)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_RED_YELLOW, edgeNames::WHITE_GREEN_WHITE, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_RED_WHITE, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::WHITE_ORANGE_WHITE, edgeNames::YELLOW_BLUE_YELLOW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	cube.toggleCentre();
	CrazyCube cubeToCompare;
	cubeToCompare.Mh();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MHRR) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_RED_YELLOW, edgeNames::WHITE_GREEN_WHITE, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::YELLOW_GREEN_YELLOW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MhRr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MHLR)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::WHITE_BLUE_WHITE, edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MhLr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MVFR) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::WHITE_RED_WHITE, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_RED_YELLOW, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MvFr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MVBR)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::WHITE_ORANGE_WHITE, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::WHITE_GREEN_WHITE};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MvBr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Move_undoMoveTest_onebyone)
{
	cube.resetCube();
	for(unsigned short int j = 0; j < NUM_OF_MOVES; j++)
	{
		cube.move(static_cast<rotation>(j));
		//cout << "cube.move    (" << j << ")\t" << hex << showbase << cube.getCubeState() << noshowbase << dec << endl;
		//cout << endl;
		cube.undoMove(static_cast<rotation>(j));
		//cout << "cube.undoMove(" << j << ")\t" << hex << showbase << cube.getCubeState() << noshowbase << dec << endl;
		ASSERT_EQ(cube.isSolved(), true);
	}

	ASSERT_EQ(cube.isSolved(), true);
}


TEST_F(CrazyCubeTest, Move_undoMoveTest)
{
	cube.resetCube();
	for(unsigned short int j = 0; j < NUM_OF_MOVES; j++)
	{
		cube.move(static_cast<rotation>(j));
	}
	for(short int j = NUM_OF_MOVES - 1; j >= 0; --j)
	{
		//cout << j << endl;
		cube.undoMove(static_cast<rotation>(j));
	}
	//cout << hex << showbase << cube.getCubeState() << noshowbase << dec << endl;
	ASSERT_EQ(cube.isSolved(), true);
}

TEST_F(CrazyCubeTest, isSolvedMasksTest)
{
	CrazyCube genericCube(1);

	// ------------------- outer
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	genericCube.setEdges(edges);
	ASSERT_EQ(genericCube.isSolved(solvedEdges), true );

	genericCube.resetCube();
	genericCube.setCentre(true);
	ASSERT_EQ(genericCube.isSolved(solvedCentre), true );

	genericCube.resetCube();
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	genericCube.setCorners(corners);
	ASSERT_EQ(genericCube.isSolved(solvedCorners), true );

	// ------------------- inner
	genericCube.resetCube();
	edgeNames edges2[NUM_OF_EDGES] = {edgeNames::YELLOW_RED_YELLOW, edgeNames::YELLOW_BLUE_YELLOW, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::YELLOW_GREEN_YELLOW, edgeNames::WHITE_RED_WHITE, edgeNames::WHITE_BLUE_WHITE, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_GREEN_WHITE};
	genericCube.setEdges(edges2);
	ASSERT_EQ(genericCube.isSolved(solvedInnerEdges), true );

	genericCube.resetCube();
	cornerNames corners2[NUM_OF_CORNERS] = {cornerNames::YELLOW_RED_BLUE_YELLOW, cornerNames::YELLOW_GREEN_RED_YELLOW, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE, cornerNames::WHITE_BLUE_RED_WHITE, cornerNames::WHITE_ORANGE_BLUE_WHITE};
	genericCube.setCorners(corners2);
	ASSERT_EQ(genericCube.isSolved(solvedInnerCorners), true );

	// ------------------- random masks
	genericCube.resetCube();
	edgeNames edges3[NUM_OF_EDGES] = {edgeNames::YELLOW_RED_YELLOW, edgeNames::WHITE_ORANGE_WHITE, edgeNames::WHITE_BLUE_YELLOW, edgeNames::YELLOW_RED_WHITE, edgeNames::WHITE_GREEN_YELLOW, edgeNames::YELLOW_BLUE_WHITE, edgeNames::YELLOW_ORANGE_YELLOW, edgeNames::WHITE_GREEN_WHITE};
	genericCube.setEdges(edges3);
	cornerNames corners3[NUM_OF_CORNERS] = {cornerNames::YELLOW_GREEN_RED_WHITE, cornerNames::YELLOW_RED_BLUE_WHITE, cornerNames::YELLOW_ORANGE_GREEN_YELLOW, cornerNames::YELLOW_BLUE_ORANGE_YELLOW, cornerNames::WHITE_ORANGE_BLUE_YELLOW, cornerNames::WHITE_BLUE_RED_YELLOW, cornerNames::WHITE_RED_GREEN_WHITE};
	genericCube.setCorners(corners3);
	ASSERT_NE(genericCube.isSolved(solvedInnerEdges), true );
	ASSERT_NE(genericCube.isSolved(solvedInnerCorners), true );

	cube.resetCube();
}
#endif
