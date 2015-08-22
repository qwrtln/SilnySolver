/*
 * CrazyCube.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#include "CrazyCube.h"
#include <iostream>

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
	swapCorners(1,6);
	swapCorners(2,5);
	swapEdges(1,5);
}
void CrazyCube::F()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0]cp0 <-> CP[5]cp5
// CP[1]cp1 <-> CP[4]cp4
// EP[0]ep0 <-> EP[4]ep4
//============================================================================
	swapCorners(0,5);
	swapCorners(1,4);
	swapEdges(0,4);
}
void CrazyCube::U()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0] -> CP[1] -> CP[2] -> CP[3] -> CP[0]
// EP[0] -> EP[1] -> EP[2] -> EP[3] -> EP[0]
//============================================================================
	cycleCorners(0,1,2,3);
	cycleEdges(0,1,2,3);
}
void CrazyCube::Ui()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[3] -> CP[2] -> CP[1] -> CP[0] -> CP[3]
// EP[3] -> EP[2] -> EP[1] -> EP[0] -> EP[3]
//============================================================================
	cycleCorners(3,2,1,0);
	cycleEdges(3,2,1,0);
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
	cycleCorners(0,1,2,3);
	cycleEdges(0,1,2,3);
	cycleCorners(0,1,2,3);
	cycleEdges(0,1,2,3);
}
void CrazyCube::Mv()
{
//============================================================================
// Schemat przemieszczania elementow
// EP[0]ep0 <-> EP[6]ep6
// EP[2]ep2 <-> EP[4]ep4
// ~C
//============================================================================
	swapEdges(0,6);
	swapEdges(2,4);
	toggleCentre();
}
void CrazyCube::Mh()
{
//============================================================================
// Schemat przemieszczania elementow
// EP[1]ep1 <-> EP[7]ep7
// EP[3]ep3 <-> EP[5]ep5
// ~C
//============================================================================
	swapEdges(1,7);
	swapEdges(3,5);
	toggleCentre();
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

void CrazyCube::swapEdges(unsigned short int edgeOneIndex, unsigned short int edgeTwoIndex)
{
	// Set bit masks for pieces
	unsigned long long edgeOneMask = (unsigned long long)0xf << EdgePieces[edgeOneIndex];
	unsigned long long edgeTwoMask = (unsigned long long)0xf << EdgePieces[edgeTwoIndex];

	// Remember pieces
	unsigned long long edgeOne = (getCubeState() & edgeOneMask) >> EdgePieces[edgeOneIndex];
	unsigned long long edgeTwo = (getCubeState() & edgeTwoMask) >> EdgePieces[edgeTwoIndex];

	// Clear spots of swapping pieces
	cubeState &= ~(edgeOneMask | edgeTwoMask);

	// Set right positions after the swap
	edgeOne <<= EdgePieces[edgeTwoIndex]; // Reversed order!!
	edgeTwo <<= EdgePieces[edgeOneIndex]; // Don't change or I'll find you, hunt you down and tickle you to death

	// Put them in the cube
	cubeState |= (edgeOne | edgeTwo);
}

void CrazyCube::swapCorners(unsigned short int cornerOneIndex, unsigned short int cornerTwoIndex)
{
	unsigned long long cornerOneMask = (unsigned long long)0xf << CornerPieces[cornerOneIndex];
	unsigned long long cornerTwoMask = (unsigned long long)0xf << CornerPieces[cornerTwoIndex];

	// Remember pieces
	unsigned long long cornerOne = (getCubeState() & cornerOneMask) >> CornerPieces[cornerOneIndex];
	unsigned long long cornerTwo = (getCubeState() & cornerTwoMask) >> CornerPieces[cornerTwoIndex];

	// Clear spots of swapping pieces
	cubeState &= ~(cornerOneMask | cornerTwoMask);

	// Set right positions after the swap
	cornerOne <<= CornerPieces[cornerTwoIndex];
	cornerTwo <<= CornerPieces[cornerOneIndex];

	// Put them in the cube
	cubeState |= (cornerOne | cornerTwo);
}

void CrazyCube::cycleCorners(unsigned short int cornerOneIndex, unsigned short int cornerTwoIndex,
		unsigned short int cornerThreeIndex, unsigned short int cornerFourIndex)
{
	// Set bit masks
	unsigned long long cornerOneMask = (unsigned long long)0xe << CornerPieces[cornerOneIndex]; // E because cycle doesn't move inner pieces
	unsigned long long cornerTwoMask = (unsigned long long)0xe << CornerPieces[cornerTwoIndex];
	unsigned long long cornerThreeMask = (unsigned long long)0xe << CornerPieces[cornerThreeIndex];
	unsigned long long cornerFourMask = (unsigned long long)0xe << CornerPieces[cornerFourIndex];

	// Remember the pieces
	unsigned long long cornerOne = (getCubeState() & cornerOneMask) >> CornerPieces[cornerOneIndex];
	unsigned long long cornerTwo = (getCubeState() & cornerTwoMask) >> CornerPieces[cornerTwoIndex];
	unsigned long long cornerThree = (getCubeState() & cornerThreeMask) >> CornerPieces[cornerThreeIndex];
	unsigned long long cornerFour = (getCubeState() & cornerFourMask) >> CornerPieces[cornerFourIndex];

	// Clear current cube status on those positions
	cubeState &= ~(cornerOneMask | cornerTwoMask | cornerThreeMask | cornerFourMask);

	// Set right positions after the cycle
	cornerOne <<= CornerPieces[cornerTwoIndex];
	cornerTwo <<= CornerPieces[cornerThreeIndex];
	cornerThree <<= CornerPieces[cornerFourIndex];
	cornerFour <<= CornerPieces[cornerOneIndex];

	// Put everything back where it belongs
	cubeState |= (cornerOne | cornerTwo | cornerThree | cornerFour);
}

void CrazyCube::cycleEdges(unsigned short int edgeOneIndex, unsigned short int edgeTwoIndex,
		unsigned short int edgeThreeIndex, unsigned short int edgeFourIndex)
{
	// Set bit masks
	unsigned long long edgeOneMask = (unsigned long long)0xe << EdgePieces[edgeOneIndex]; // E because cycle doesn't move inner pieces
	unsigned long long edgeTwoMask = (unsigned long long)0xe << EdgePieces[edgeTwoIndex];
	unsigned long long edgeThreeMask = (unsigned long long)0xe << EdgePieces[edgeThreeIndex];
	unsigned long long edgeFourMask = (unsigned long long)0xe << EdgePieces[edgeFourIndex];

	// Remember the pieces
	unsigned long long edgeOne = (getCubeState() & edgeOneMask) >> EdgePieces[edgeOneIndex];
	unsigned long long edgeTwo = (getCubeState() & edgeTwoMask) >> EdgePieces[edgeTwoIndex];
	unsigned long long edgeThree = (getCubeState() & edgeThreeMask) >> EdgePieces[edgeThreeIndex];
	unsigned long long edgeFour = (getCubeState() & edgeFourMask) >> EdgePieces[edgeFourIndex];

	// Clear current cube status on those positions
	cubeState &= ~(edgeOneMask | edgeTwoMask | edgeThreeMask | edgeFourMask);

	// Set right positions after the cycle
	edgeOne <<= EdgePieces[edgeTwoIndex];
	edgeTwo <<= EdgePieces[edgeThreeIndex];
	edgeThree <<= EdgePieces[edgeFourIndex];
	edgeFour <<= EdgePieces[edgeOneIndex];

	// Put everything back where it belongs
	cubeState |= (edgeOne | edgeTwo | edgeThree | edgeFour);
}

void CrazyCube::toggleCentre()
{
	this->cubeState ^= static_cast<unsigned long long>(true) << centrePosition;
}

void CrazyCube::resetCube()
{
	cubeState = solvedCube;
}
