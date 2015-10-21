/*
 * CrazyCube_test.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */
#include "CrazyCube.h"
#include "TestExecuter.h"
#include "ConstDefs.h"
#include <cmath>

extern TestExecuter testExecuter;
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

TEST_F(CrazyCubeTest, setCentreTest)
{
	cube.setCentre(true);
	ASSERT_EQ_HEX( (cube.getCubeState() & (static_cast<unsigned long long>(true) << cube.centrePosition)),
			static_cast<unsigned long long>(true) << cube.centrePosition )
}

TEST_F(CrazyCubeTest, setCornersTest)
{
	CrazyCube genericCube(1);
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	genericCube.setCorners(corners);
	ASSERT_EQ((genericCube.checkCorners()), true )
}

TEST_F(CrazyCubeTest, setEdgesTest)
{
	CrazyCube genericCube(1);
	edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	genericCube.setEdges(edges);
	ASSERT_EQ((genericCube.checkEdges()), true )
}

TEST_F(CrazyCubeTest, innerCircleTest)
{
	CrazyCube genericCube(1);
	genericCube.setCentre(true);
	edgeNames edges[NUM_OF_EDGES] = {yry, yry, yry, yry, yrw, yrw, yrw, yrw};
	genericCube.setEdges(edges);
	cornerNames corners[NUM_OF_CORNERS] = {ygry, ygry, ygry, ygry, ygrw, ygrw, ygrw};
	genericCube.setCorners(corners);
	ASSERT_EQ((genericCube.checkInnerCircle()), true )
}

TEST_F(CrazyCubeTest, setCubeTest)
{
	ASSERT_EQ_HEX(cube.checkIfSolved(), 1);
	cout << dec;
}

TEST_F(CrazyCubeTest, setNEGATIVEcubeTest)
{
	edgeNames edges[NUM_OF_EDGES] = {wgw, yry, yby, yoy, ygy, wrw, wbw, wow}; // Wrong sequence
	cube.setEdges(edges);
	ASSERT_NE(cube.checkIfSolved(), 1)
}

TEST_F(CrazyCubeTest, setWholeCubeTest)
{
	cube.setCubeState(0xf);
	edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	ASSERT_EQ_HEX(cube.checkIfSolved(), 1)
}

TEST_F(CrazyCubeTest, L)
{
	edgeNames edges[NUM_OF_EDGES] = {yry, wbw, yoy, ygy, wrw, yby, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, wobw, wbrw, yogy, wrgw, yboy, yrby};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.L();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, U)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {ygy, yry, yby, yoy, wrw, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yogy, ygry, yrby, yboy, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	
	cubeToCompare.U();
	ASSERT_EQ_HEX(cubeToCompare.getCubeState(), cube.getCubeState())
}

TEST_F(CrazyCubeTest, F)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {wrw, yby, yoy, ygy, yry, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {wbrw, wrgw, yboy, yogy, yrby, ygry, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.F();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Ui) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yby, yoy, ygy, yry, wrw, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yrby, yboy, yogy, ygry, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.Ui();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, U2) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yoy, ygy, yry, yby, wrw, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yboy, yogy, ygry, yrby, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.U2();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Mv) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {wow, yby, wrw, ygy, yoy, wbw, yry, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	cube.toggleCentre();
	CrazyCube cubeToCompare;
	cubeToCompare.Mv();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Mh)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yry, wgw, yoy, wbw, wrw, ygy, wow, yby};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	cube.toggleCentre();
	CrazyCube cubeToCompare;
	cubeToCompare.Mh();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MhRr) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yoy, yby, yry, wgw, wrw, wbw, wow, ygy};
	cornerNames corners[NUM_OF_CORNERS] = {yboy, yogy, ygry, yrby, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MhRr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MhLr)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yoy, wbw, yry, ygy, wrw, yby, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yboy, yogy, ygry, yrby, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MhLr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MvFr) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {wrw, ygy, yoy, yby, yry, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yboy, yogy, ygry, yrby, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MvFr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MvBr)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yry, ygy, wow, yby, wrw, wbw, yoy, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yboy, yogy, ygry, yrby, wrgw, wbrw, wobw};
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
		ASSERT_EQ(cube.checkIfSolved(), true);
	}

	ASSERT_EQ(cube.checkIfSolved(), true);
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
	ASSERT_EQ(cube.checkIfSolved(), true);
}

/*
TEST_F(CrazyCubeTest, PerformanceTest)
{
	cube.resetCube(); 
	for(unsigned short int i = 0; i < 9; i++)
	{
		TestMove(i);
	}
}
*/
TEST_F(CrazyCubeTest, PerformanceAvgTest)
{
	cube.resetCube(); 
	#ifndef PREF_DEPTH
	for(unsigned short int i = 0; i <= 6; i++)
	{
		TestMoveAverage(i, 5);
	}
	#else
	for(unsigned short int i = 0; i <= PREF_DEPTH; i++)
	{
		TestMoveAverage(i, 5);
	}
	#endif
}

TEST_F(CrazyCubeTest, checkIfSolvedMasksTest)
{
	CrazyCube genericCube(1);

	// ------------------- outer
	edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	genericCube.setEdges(edges);
	ASSERT_EQ(genericCube.checkIfSolved(solvedEdges), true );

	genericCube.resetCube();
	genericCube.setCentre(true);
	ASSERT_EQ(genericCube.checkIfSolved(solvedCentre), true );

	genericCube.resetCube();
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	genericCube.setCorners(corners);
	ASSERT_EQ(genericCube.checkIfSolved(solvedCorners), true );

	// ------------------- inner
	genericCube.resetCube();
	edgeNames edges2[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	genericCube.setEdges(edges2);
	ASSERT_EQ(genericCube.checkIfSolved(solvedInnerEdges), true );

	genericCube.resetCube();
	cornerNames corners2[NUM_OF_CORNERS] = {yrby, ygry, yboy, yogy, wrgw, wbrw, wobw};
	genericCube.setCorners(corners2);
	ASSERT_EQ(genericCube.checkIfSolved(solvedInnerCorners), true );

	// ------------------- random masks
	genericCube.resetCube();
	edgeNames edges3[NUM_OF_EDGES] = {yry, wow, wby, yrw, wgy, ybw, yoy, wgw};
	genericCube.setEdges(edges3);
	cornerNames corners3[NUM_OF_CORNERS] = {ygrw, yrbw, yogy, yboy, woby, wbry, wrgw};
	genericCube.setCorners(corners3);
	ASSERT_NE(genericCube.checkIfSolved(solvedInnerEdges), true );
	ASSERT_NE(genericCube.checkIfSolved(solvedInnerCorners), true );

	cube.resetCube();


}
