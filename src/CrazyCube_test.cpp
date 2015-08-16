/*
 * CrazyCube_test.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */
#include "CrazyCube_test.h"

bool CrazyCube_test::setCornersTest()
{
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setCorners(corners);
	if( !(solvedCube & cube.getCubeState()) == cube.getCubeState() )
	{
		return false;
	}
	return true;
}

bool CrazyCube_test::setEdgesTest()
{
	edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	cube.setEdges(edges);
	if( !(solvedCube & cube.getCubeState()) == cube.getCubeState() )
	{
		return false;
	}
	return true;
}

bool CrazyCube_test::setCubeTest()
{
	return cube.checkIfSolved(solvedCube);
}

void CrazyCube_test::CrazyCubeTests()
{
	std::cout << "Test setting cornes...";
	if (setCornersTest())
	{
		cout << "ok!" << endl;
	}
	else
	{
		cout << "smoething went wrong :(" << endl;
	}

	std::cout << "Test setting edges...";
	if (setEdgesTest())
	{
		cout << "ok!" << endl;
	}
	else
	{
		cout << "smoething went wrong :(" << endl;
	}

	if (setCubeTest())
	{
		cout << "Everything went well!" << endl;
	}
	else
	{
		cout << "Sorry, keep debugging." << endl;
	}
}


