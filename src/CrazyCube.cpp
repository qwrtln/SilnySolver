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
	return (cubeState == solvedCube);
}

void CrazyCube::setCubeState(unsigned long long cubeState)
{
	this->cubeState = cubeState;
}

unsigned long long CrazyCube::getCubeState()
{
	return this->cubeState;
}

void CrazyCube::setCentre(bool ok)
{
	unsigned long long centre = static_cast<unsigned long long>(ok) << centrePosition;
	this->cubeState |= centre;
}

void CrazyCube::setEdges(edgeNames edges[NUM_OF_EDGES])
{
	unsigned short int bitsToFirstEdge = 52;
	unsigned long long pieceSize = 0xF;
	unsigned long long pieceMask;

	for(unsigned short i = 0; i < NUM_OF_EDGES; i++)
	{
		pieceMask = ~(pieceSize << ( (bitsToFirstEdge) - (4*i)) );
		this-> cubeState &= pieceMask;
		this-> cubeState |= (unsigned long long)(edges[i]) << ((bitsToFirstEdge) - (4*i));
	}
}

void CrazyCube::setCorners(cornerNames corners[NUM_OF_CORNERS])
{
	unsigned short int bitsToFirstCorner = 56;
	unsigned long long pieceSize = 0xF;
	unsigned long long pieceMask;
	for(unsigned short i = 0; i < NUM_OF_CORNERS; i++)
	{
		pieceMask = ~(pieceSize << ( (bitsToFirstCorner) - (4*i)) );						// Tworzenie maski bitowej na zadanej pozycji
		this-> cubeState &= pieceMask;																	// Zerowanie tej pozycji na kości

		this-> cubeState |= (unsigned long long)(corners[i]) << ((bitsToFirstCorner) - (4*i));	// Ustawianie pozycji z klocka
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
