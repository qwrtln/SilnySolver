/*
 * CrazyCube_test.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */
#include <iostream>
#include <cstdio>
#include "CrazyCube.h"
using namespace std;

class CrazyCube_test
{
private:
	CrazyCube cube;

public:
	bool setCornersTest()
	{
		cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
		cube.setCorners(corners);
		if( !(solvedCube & cube.getCubeState()) == cube.getCubeState() )
		{
			return false;
		}
		return true;
	}

	bool setEdgesTest()
	{
		edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
		cube.setEdges(edges);
		if( !(solvedCube & cube.getCubeState()) == cube.getCubeState() )
		{
			return false;
		}
		return true;
	}

	bool setCubeTest()
	{
		return cube.checkIfSolved(solvedCube);
	}

	void CrazyCubeTests()
	{
		std::cout << "Test setting cornes...";
		if (setCornersTest())
		{
			cout << "ok!" << std::endl;
		}
		else
		{
			cout << "smoething went wrong :(" << std::endl;
		}

		std::cout << "Test setting edges...";
		if (setEdgesTest())
		{
			cout << "ok!" << std::endl;
		}
		else
		{
			cout << "smoething went wrong :(" << std::endl;
		}

		if (setCubeTest())
		{
			cout << "Everything went well!" << std::endl;
		}
		else
		{
			cout << "Sorry, keep debugging." << std::endl;
		}
	}

};
