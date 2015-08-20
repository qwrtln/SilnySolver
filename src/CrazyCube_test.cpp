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
	CrazyCube cube;
};

TEST(CrazyCubeTest, setCornersTest)
{
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setCorners(corners);
	ASSERT_EQ((solvedCube & cube.getCubeState()), cube.getCubeState() )

}
TEST(CrazyCubeTest, setEdgesTest)
{
	edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	cube.setEdges(edges);
	ASSERT_EQ((solvedCube & cube.getCubeState()), cube.getCubeState());


}
TEST(CrazyCubeTest, setCubeTest)
{
	ASSERT_EQ(cube.checkIfSolved(solvedCube), 1);
}

