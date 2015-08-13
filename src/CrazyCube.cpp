/*
 * CrazyCube.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#include "CrazyCube.h"

CrazyCube::CrazyCube()
{
	// TODO Auto-generated constructor stub

}

CrazyCube::~CrazyCube()
{
	// TODO Auto-generated destructor stub
}

bool CrazyCube::checkIfSolved(unsigned long long cubeState)
{
	return (cubeState == ::solvedCube);
}

void CrazyCube::setCubeState(unsigned long long cubeState)
{
	this->cubeState = cubeState;
}

unsigned long long CrazyCube::getCubeState()
{
	return this-> cubeState;
}

void CrazyCube::setCentre(bool ok)
{
	unsigned long long centre = static_cast<unsigned long long>(ok) << 63;
	this->cubeState |= centre;
}

void setEdges(edgeNames edges[NUM_OF_EDGES])
{
	for(unsigned short i = 0; i < NUM_OF_EDGES; i++)
	{

	}
}
void setCorners(cornerNames corners[NUM_OF_CORNERS])
{
	for(unsigned short i = 0; i < NUM_OF_CORNERS; i++)
	{

	}
}

void CrazyCube::L()
{

}
void CrazyCube::F()
{

}
void CrazyCube::U()
{

}
void CrazyCube::Ui()
{

}
void CrazyCube::U2()
{

}
void CrazyCube::Mv()
{

}
void CrazyCube::Mh()
{

}
void CrazyCube::MhRr()
{

}
void CrazyCube::MhLr()
{

}
void CrazyCube::MvFr()
{

}
void CrazyCube::MvBr()
{

}

void move(unsigned int move)
{

}
