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

TEST(CrazyCubeTest, setCentreTest)
{
	cube.setCentre(true);
	ASSERT_EQ( (cube.getCubeState() & (static_cast<unsigned long long>(true) << cube.centrePosition)),
			static_cast<unsigned long long>(true) << cube.centrePosition )
}

TEST(CrazyCubeTest, setCornersTest)
{
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setCorners(corners);
	cout << hex;
	ASSERT_EQ((solvedCube & cube.getCubeState()), cube.getCubeState() )
	cout << dec;
}

TEST(CrazyCubeTest, setEdgesTest)
{
	edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	cube.setEdges(edges);
	cout << hex;
	ASSERT_EQ((solvedCube & cube.getCubeState()), cube.getCubeState())
	cout << dec;
}

TEST(CrazyCubeTest, setCubeTest)
{
	ASSERT_EQ(cube.checkIfSolved(), 1);
	cout << dec;
}

TEST(CrazyCubeTest, setNEGATIVEcubeTest)
{
	edgeNames edges[NUM_OF_EDGES] = {wgw, yry, yby, yoy, ygy, wrw, wbw, wow}; // Wrong sequence
	cube.setEdges(edges);
	ASSERT_NE(cube.checkIfSolved(), 1)
}

TEST(CrazyCubeTest, setWholeCubeTest)
{
	cube.setCubeState(0xf);
	edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	ASSERT_EQ(cube.checkIfSolved(), 1)
}

TEST(CrazyCubeTest, L)
{
	edgeNames edges[NUM_OF_EDGES] = {yry, wbw, yoy, ygy, wrw, yby, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, wobw, wbrw, yogy, wrgw, yboy, yrby};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.L();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST(CrazyCubeTest, U) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.U();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST(CrazyCubeTest, F) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.F();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST(CrazyCubeTest, Ui) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.Ui();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST(CrazyCubeTest, U2) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.U2();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST(CrazyCubeTest, Mv) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.Mv();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST(CrazyCubeTest, Mh) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.Mh();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST(CrazyCubeTest, MhRr) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.MhRr();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST(CrazyCubeTest, MhLr) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.MhLr();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST(CrazyCubeTest, MvFr) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.MvFr();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST(CrazyCubeTest, MvBr) // Draft!!!
{
	cube.resetCube();
	CrazyCube cubeToCompare;
	cubeToCompare.MvBr();
	ASSERT_EQ(cube.getCubeState(), cubeToCompare.getCubeState())
}
