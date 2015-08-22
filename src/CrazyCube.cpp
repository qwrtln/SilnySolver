/*
 * CrazyCube.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#include "CrazyCube.h"

CrazyCube::CrazyCube()
{
	cubeState = solvedCube;
}

CrazyCube::~CrazyCube()
{
	// TODO Auto-generated destructor stub
}

bool CrazyCube::checkIfSolved()
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
	unsigned long long pieceSize = 0xF;
	unsigned long long pieceMask;

	for(unsigned short i = 0; i < NUM_OF_EDGES; i++)
	{
		pieceMask = ~(pieceSize << this->EdgePieces[i]);
		this-> cubeState &= pieceMask;
		this-> cubeState |= (unsigned long long)(edges[i]) << this->EdgePieces[i];
	}
}

void CrazyCube::setCorners(cornerNames corners[NUM_OF_CORNERS])
{
	unsigned long long pieceSize = 0xF;
	unsigned long long pieceMask;

	for(unsigned short i = 0; i < NUM_OF_CORNERS; i++)
	{
		pieceMask = ~(pieceSize << this->CornerPieces[i]);						// Tworzenie maski bitowej na zadanej pozycji
		this-> cubeState &= pieceMask;																	// Zerowanie tej pozycji na kości
		this-> cubeState |= (unsigned long long)(corners[i]) << this->CornerPieces[i];	// Ustawianie pozycji z klocka
	}
}

void CrazyCube::setWholeCube(bool centreOK, edgeNames edges[NUM_OF_EDGES], cornerNames corners[NUM_OF_CORNERS])
{
	setCentre(centreOK);
	setEdges(edges);
	setCorners(corners);
}

void CrazyCube::L()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[1]cp1 <-> CP[6]cp6
// CP[2]cp2 <-> CP[5]cp5
// EP[1]ep1 <-> EP[5]ep1
//============================================================================
}
void CrazyCube::F()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0]cp0 <-> CP[5]cp5
// CP[1]cp1 <-> CP[4]cp4
// EP[0]ep0 <-> EP[4]ep4
//============================================================================
}
void CrazyCube::U()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0] -> CP[1] -> CP[2] -> CP[3] -> CP[0]
// EP[0] -> EP[1] -> EP[2] -> EP[3] -> EP[0]
//============================================================================
}
void CrazyCube::Ui()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[3] -> CP[2] -> CP[1] -> CP[0] -> CP[3]
// EP[3] -> EP[2] -> EP[1] -> EP[0] -> EP[3]
//============================================================================
}
void CrazyCube::U2()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0] -> CP[2]
// CP[1] -> CP[3]
// CP[2] -> CP[0]
// CP[3] -> CP[1]
// EP[0] -> EP[2]
// EP[1] -> EP[3]
// EP[2] -> EP[0]
// EP[3] -> EP[1]
//============================================================================
}
void CrazyCube::Mv()
{
//============================================================================
// Schemat przemieszczania elementow
// EP[0]ep0 <-> EP[6]ep6
// EP[2]ep2 -> EP[4]ep4
// ~C
//============================================================================
}
void CrazyCube::Mh()
{
//============================================================================
// Schemat przemieszczania elementow
// EP[1]ep1 <-> EP[7]ep7
// EP[3]ep3 -> EP[5]ep5
// ~C
//============================================================================
}
void CrazyCube::MhRr()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0] <-> CP[2]
// CP[1] <-> CP[3]
// EP[0] <-> EP[2]
// EP[3]ep3 <-> EP[7]ep7
//============================================================================
}
void CrazyCube::MhLr()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0] <-> CP[2]
// CP[1] <-> CP[3]
// EP[0] <-> EP[2]
// EP[1]ep1 <-> EP[5]ep5
//============================================================================
}
void CrazyCube::MvFr()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0] <-> CP[2]
// CP[1] <-> CP[3]
// EP[1] <-> EP[3]
// EP[0]ep0 <-> EP[4]ep4
//============================================================================
}
void CrazyCube::MvBr()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0] <-> CP[2]
// CP[1] <-> CP[3]
// EP[1] <-> EP[3]
// EP[2]ep2 <-> EP[6]ep6
//============================================================================
}

void CrazyCube::move(rotation move)
{

}

void CrazyCube::swapPieces(unsigned short int pieceOne, unsigned short int pieceTwo)
{

}

void CrazyCube::cyclePieces(unsigned short int pieceOne, unsigned short int pieceTwo, unsigned short int pieceThree, unsigned short int pieceFour)
{

}

void CrazyCube::toggleCentre()
{
	this->cubeState ^= static_cast<unsigned long long>(true) << centrePosition;
}
