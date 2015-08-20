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
	ASSERT_EQ(cube.getCubeState(), (unsigned long long)1 << cube.centrePosition);
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
	ASSERT_EQ((solvedCube & cube.getCubeState()), cube.getCubeState());
	cout << dec;
}

TEST(CrazyCubeTest, setCubeTest)
{
	ASSERT_EQ(cube.checkIfSolved(), 1);
	cout << dec;
}

TEST(CrazyCubeTest, setNEGATIVEcubeTest)
{
	edgeNames edges[NUM_OF_EDGES] = {wgw, yry, yby, yoy, ygy, wrw, wbw, wow};
	cube.setEdges(edges);
	ASSERT_NE(cube.checkIfSolved(), 1);
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
	cube.L();
	ASSERT_EQ(cube.checkIfSolved(), 1)
}
