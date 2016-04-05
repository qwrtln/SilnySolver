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
				cube.move(j);
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
    edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
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
    cube.move(0);
    // cube.printCubeState(); /* ~~This suppresses unnecessary output~~ */
    cube.resetCube();
    cube.setCentre(true);
    cube.setCorners(corners);
    cube.setCubeState(0);
    cube.setEdges(edges);
    cube.setWholeCube(true, edges, corners);
    cube.toggleCentre();
    cube.undoMove(0);
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
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YGRY, cornerNames::YRBY, cornerNames::YBOY, cornerNames::YOGY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	genericCube.setCorners(corners);
	ASSERT_EQ((genericCube.checkCorners()), true )
}

TEST_F(CrazyCubeTest, setEdgesTest)
{
	CrazyCube genericCube(1);
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YRY, edgeNames::YBY, edgeNames::YOY, edgeNames::YGY, edgeNames::WRW, edgeNames::WBW, edgeNames::WOW, edgeNames::WGW};
	genericCube.setEdges(edges);
	ASSERT_EQ((genericCube.checkEdges()), true )
}

TEST_F(CrazyCubeTest, innerCircleTest)
{
	CrazyCube genericCube(1);
	genericCube.setCentre(true);
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YRY, edgeNames::YRY, edgeNames::YRY, edgeNames::YRY, edgeNames::YRW, edgeNames::YRW, edgeNames::YRW, edgeNames::YRW};
	genericCube.setEdges(edges);
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YGRY, cornerNames::YGRY, cornerNames::YGRY, cornerNames::YGRY, cornerNames::YGRW, cornerNames::YGRW, cornerNames::YGRW};
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
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::WGW, edgeNames::YRY, edgeNames::YBY, edgeNames::YOY, edgeNames::YGY, edgeNames::WRW, edgeNames::WBW, edgeNames::WOW}; // Wrong sequence
	cube.setEdges(edges);
	ASSERT_NE(cube.isSolved(), 1)
}

TEST_F(CrazyCubeTest, setWholeCubeTest)
{
	cube.setCubeState(0xf);
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YRY, edgeNames::YBY, edgeNames::YOY, edgeNames::YGY, edgeNames::WRW, edgeNames::WBW, edgeNames::WOW, edgeNames::WGW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YGRY, cornerNames::YRBY, cornerNames::YBOY, cornerNames::YOGY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	cube.setWholeCube(true,edges,corners);
	ASSERT_EQ_HEX(cube.isSolved(), 1)
}

TEST_F(CrazyCubeTest, L)
{
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YRY, edgeNames::WBW, edgeNames::YOY, edgeNames::YGY, edgeNames::WRW, edgeNames::YBY, edgeNames::WOW, edgeNames::WGW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YGRY, cornerNames::WOBW, cornerNames::WBRW, cornerNames::YOGY, cornerNames::WRGW, cornerNames::YBOY, cornerNames::YRBY};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.L();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, U)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YGY, edgeNames::YRY, edgeNames::YBY, edgeNames::YOY, edgeNames::WRW, edgeNames::WBW, edgeNames::WOW, edgeNames::WGW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YOGY, cornerNames::YGRY, cornerNames::YRBY, cornerNames::YBOY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	
	cubeToCompare.U();
	ASSERT_EQ_HEX(cubeToCompare.getCubeState(), cube.getCubeState())
}

TEST_F(CrazyCubeTest, F)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::WRW, edgeNames::YBY, edgeNames::YOY, edgeNames::YGY, edgeNames::YRY, edgeNames::WBW, edgeNames::WOW, edgeNames::WGW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::WBRW, cornerNames::WRGW, cornerNames::YBOY, cornerNames::YOGY, cornerNames::YRBY, cornerNames::YGRY, cornerNames::WOBW};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.F();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, UI) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YBY, edgeNames::YOY, edgeNames::YGY, edgeNames::YRY, edgeNames::WRW, edgeNames::WBW, edgeNames::WOW, edgeNames::WGW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YRBY, cornerNames::YBOY, cornerNames::YOGY, cornerNames::YGRY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.Ui();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, U2) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YOY, edgeNames::YGY, edgeNames::YRY, edgeNames::YBY, edgeNames::WRW, edgeNames::WBW, edgeNames::WOW, edgeNames::WGW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YBOY, cornerNames::YOGY, cornerNames::YGRY, cornerNames::YRBY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.U2();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MV) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::WOW, edgeNames::YBY, edgeNames::WRW, edgeNames::YGY, edgeNames::YOY, edgeNames::WBW, edgeNames::YRY, edgeNames::WGW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YGRY, cornerNames::YRBY, cornerNames::YBOY, cornerNames::YOGY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	cube.setWholeCube(true,edges,corners);
	cube.toggleCentre();
	CrazyCube cubeToCompare;
	cubeToCompare.Mv();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MH)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YRY, edgeNames::WGW, edgeNames::YOY, edgeNames::WBW, edgeNames::WRW, edgeNames::YGY, edgeNames::WOW, edgeNames::YBY};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YGRY, cornerNames::YRBY, cornerNames::YBOY, cornerNames::YOGY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	cube.setWholeCube(true,edges,corners);
	cube.toggleCentre();
	CrazyCube cubeToCompare;
	cubeToCompare.Mh();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MHRR) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YOY, edgeNames::YBY, edgeNames::YRY, edgeNames::WGW, edgeNames::WRW, edgeNames::WBW, edgeNames::WOW, edgeNames::YGY};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YBOY, cornerNames::YOGY, cornerNames::YGRY, cornerNames::YRBY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MhRr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MHLR)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YOY, edgeNames::WBW, edgeNames::YRY, edgeNames::YGY, edgeNames::WRW, edgeNames::YBY, edgeNames::WOW, edgeNames::WGW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YBOY, cornerNames::YOGY, cornerNames::YGRY, cornerNames::YRBY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MhLr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MVFR) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::WRW, edgeNames::YGY, edgeNames::YOY, edgeNames::YBY, edgeNames::YRY, edgeNames::WBW, edgeNames::WOW, edgeNames::WGW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YBOY, cornerNames::YOGY, cornerNames::YGRY, cornerNames::YRBY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MvFr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MVBR)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YRY, edgeNames::YGY, edgeNames::WOW, edgeNames::YBY, edgeNames::WRW, edgeNames::WBW, edgeNames::YOY, edgeNames::WGW};
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YBOY, cornerNames::YOGY, cornerNames::YGRY, cornerNames::YRBY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
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
		cube.move(j);
		//cout << "cube.move    (" << j << ")\t" << hex << showbase << cube.getCubeState() << noshowbase << dec << endl;
		//cout << endl;
		cube.undoMove(j);
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
		cube.move(j);
	}
	for(short int j = NUM_OF_MOVES - 1; j >= 0; --j)
	{
		//cout << j << endl;
		cube.undoMove(j);
	}
	//cout << hex << showbase << cube.getCubeState() << noshowbase << dec << endl;
	ASSERT_EQ(cube.isSolved(), true);
}

TEST_F(CrazyCubeTest, isSolvedMasksTest)
{
	CrazyCube genericCube(1);

	// ------------------- outer
	edgeNames edges[NUM_OF_EDGES] = {edgeNames::YRY, edgeNames::YBY, edgeNames::YOY, edgeNames::YGY, edgeNames::WRW, edgeNames::WBW, edgeNames::WOW, edgeNames::WGW};
	genericCube.setEdges(edges);
	ASSERT_EQ(genericCube.isSolved(solvedEdges), true );

	genericCube.resetCube();
	genericCube.setCentre(true);
	ASSERT_EQ(genericCube.isSolved(solvedCentre), true );

	genericCube.resetCube();
	cornerNames corners[NUM_OF_CORNERS] = {cornerNames::YGRY, cornerNames::YRBY, cornerNames::YBOY, cornerNames::YOGY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	genericCube.setCorners(corners);
	ASSERT_EQ(genericCube.isSolved(solvedCorners), true );

	// ------------------- inner
	genericCube.resetCube();
	edgeNames edges2[NUM_OF_EDGES] = {edgeNames::YRY, edgeNames::YBY, edgeNames::YOY, edgeNames::YGY, edgeNames::WRW, edgeNames::WBW, edgeNames::WOW, edgeNames::WGW};
	genericCube.setEdges(edges2);
	ASSERT_EQ(genericCube.isSolved(solvedInnerEdges), true );

	genericCube.resetCube();
	cornerNames corners2[NUM_OF_CORNERS] = {cornerNames::YRBY, cornerNames::YGRY, cornerNames::YBOY, cornerNames::YOGY, cornerNames::WRGW, cornerNames::WBRW, cornerNames::WOBW};
	genericCube.setCorners(corners2);
	ASSERT_EQ(genericCube.isSolved(solvedInnerCorners), true );

	// ------------------- random masks
	genericCube.resetCube();
	edgeNames edges3[NUM_OF_EDGES] = {edgeNames::YRY, edgeNames::WOW, edgeNames::WBY, edgeNames::YRW, edgeNames::WGY, edgeNames::YBW, edgeNames::YOY, edgeNames::WGW};
	genericCube.setEdges(edges3);
	cornerNames corners3[NUM_OF_CORNERS] = {cornerNames::YGRW, cornerNames::YRBW, cornerNames::YOGY, cornerNames::YBOY, cornerNames::WOBY, cornerNames::WBRY, cornerNames::WRGW};
	genericCube.setCorners(corners3);
	ASSERT_NE(genericCube.isSolved(solvedInnerEdges), true );
	ASSERT_NE(genericCube.isSolved(solvedInnerCorners), true );

	cube.resetCube();
}
#endif
