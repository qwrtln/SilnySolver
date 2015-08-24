/*
 * CrazyCube_test.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */
#include "CrazyCube.h"
#include "TestExecuter.h"
#include "ConstDefs.h"

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
protected:
	static CrazyCube cube;
};

CrazyCube CrazyCubeTest::cube;

TEST_F(CrazyCubeTest, setCentreTest)
{
	cube.setCentre(true);
	ASSERT_EQ( (cube.getCubeState() & (static_cast<unsigned long long>(true) << cube.centrePosition)),
			static_cast<unsigned long long>(true) << cube.centrePosition )
}

TEST_F(CrazyCubeTest, setCornersTest)
{
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setCorners(corners);
	cout << hex;
	ASSERT_EQ((solvedCube & cube.getCubeState()), cube.getCubeState() )
	cout << dec;
}

TEST_F(CrazyCubeTest, setEdgesTest)
{
	edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	cube.setEdges(edges);
	cout << hex;
	ASSERT_EQ((solvedCube & cube.getCubeState()), cube.getCubeState())
	cout << dec;
}

TEST_F(CrazyCubeTest, setCubeTest)
{
	ASSERT_EQ(cube.checkIfSolved(), 1);
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
	ASSERT_EQ(cube.checkIfSolved(), 1)
}

TEST_F(CrazyCubeTest, L)
{
	edgeNames edges[NUM_OF_EDGES] = {yry, wbw, yoy, ygy, wrw, yby, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, wobw, wbrw, yogy, wrgw, yboy, yrby};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.L();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, U) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.U();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, F) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.F();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Ui) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.Ui();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, U2) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.U2();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Mv) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.Mv();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Mh) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.Mh();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MhRr) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.MhRr();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MhLr) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.MhLr();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MvFr) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.MvFr();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MvBr) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.MvBr();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

