/*
 * CrazyCube.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#include "CrazyCube.h"
#include <iostream>

CrazyCube::CrazyCube():threeBitMask(0xE)
{
	cubeState = solvedCube;

	// Moves tab
	moveTab[0] = &CrazyCube::L;
	moveTab[1] = &CrazyCube::F;
	moveTab[2] = &CrazyCube::U;
	moveTab[3] = &CrazyCube::Ui;
	moveTab[4] = &CrazyCube::U2;
	moveTab[5] = &CrazyCube::Mv;
	moveTab[6] = &CrazyCube::Mh;
	moveTab[7] = &CrazyCube::MhRr;
	moveTab[8] = &CrazyCube::MhLr;
	moveTab[9] = &CrazyCube::MvFr;
	moveTab[10] = &CrazyCube::MvBr;	

	// Undo moves tab
	undoMoveTab[0] = &CrazyCube::L;
	undoMoveTab[1] = &CrazyCube::F;
	undoMoveTab[2] = &CrazyCube::Ui;	// <-- Here's the change
	undoMoveTab[3] = &CrazyCube::U;	// And all the changes end here...
	undoMoveTab[4] = &CrazyCube::U2;
	undoMoveTab[5] = &CrazyCube::Mv;
	undoMoveTab[6] = &CrazyCube::Mh;
	undoMoveTab[7] = &CrazyCube::MhRr;
	undoMoveTab[8] = &CrazyCube::MhLr;
	undoMoveTab[9] = &CrazyCube::MvFr;
	undoMoveTab[10] = &CrazyCube::MvBr;	
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
// EP[1]ep1 <-> EP[5]ep5
//============================================================================
						   //0x..FF..FF.F...F..
	cubeState = (cubeState & 0xFF00FF00F0FFF0FF) |
			  ( (cubeState & 0x00F0000000000000) >> 20 ) |
			  ( (cubeState & 0x000F000000000000) >> 12 ) |
			  ( (cubeState & 0x000000F000000000) << 12 ) |
			  ( (cubeState & 0x0000000F00000000) << 20 ) |
			  ( (cubeState & 0x000000000F000000) >> 16 ) |
			  ( (cubeState & 0x0000000000000F00) << 16 );
}
void CrazyCube::F()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0]cp0 <-> CP[5]cp5
// CP[1]cp1 <-> CP[4]cp4
// EP[0]ep0 <-> EP[4]ep4
//============================================================================
						   //0x.FF..FF.F...F...
	cubeState = (cubeState & 0xF00FF00F0FFF0FFF) |
			  ( (cubeState & 0x0F00000000000000) >> 20 ) |
			  ( (cubeState & 0x00F0000000000000) >> 12 ) |
			  ( (cubeState & 0x00000F0000000000) << 12 ) |
			  ( (cubeState & 0x000000F000000000) << 20 ) |
			  ( (cubeState & 0x00000000F0000000) >> 16 ) |
			  ( (cubeState & 0x000000000000F000) << 16 );
}
void CrazyCube::U()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[0] -> CP[1] -> CP[2] -> CP[3] -> CP[0]
// EP[0] -> EP[1] -> EP[2] -> EP[3] -> EP[0]
//============================================================================
	cubeState = ( ((cubeState & 0x0EEE0000EEE00000) >> 4) | ((cubeState & 0x0000E000000E0000) << 12) ) | (cubeState & 0x11111FFF1111FFFF);
}
void CrazyCube::Ui()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[3] -> CP[2] -> CP[1] -> CP[0] -> CP[3]
// EP[3] -> EP[2] -> EP[1] -> EP[0] -> EP[3]
//============================================================================
	cubeState = ( ((cubeState & 0x00EEE0000EEE0000) << 4) | ((cubeState & 0x0E000000E0000000) >> 12) ) | (cubeState & 0x11111FFF1111FFFF);

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
	   	   	   	   	   	   //0x.EEEE...EEEE....
// TODO	cubeState = (cubeState & 0xF1111FFF1111FFFF) |
		/*	  ( (cubeState & 0x0F00000000000000) >> 20 ) |
			  ( (cubeState & 0x00F0000000000000) >> 12 ) |
			  ( (cubeState & 0x00000F0000000000) << 12 ) |
			  ( (cubeState & 0x000000F000000000) << 20 ) |
			  ( (cubeState & 0x00000000F0000000) >> 16 ) |
			  ( (cubeState & 0x000000000000F000) << 16 );*/
	swapEdges(0, 2, false);
	swapEdges(1, 3, false);
	swapCorners(0, 2, false);
	swapCorners(1, 3, false);
}
void CrazyCube::Mv()
{
//============================================================================
// Schemat przemieszczania elementow
// EP[0]ep0 <-> EP[6]ep6
// EP[2]ep2 <-> EP[4]ep4
// ~C
//============================================================================
	swapEdges(0,6,true);
	swapEdges(2,4,true);
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
	swapEdges(1,7,true);
	swapEdges(3,5,true);
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
	swapCorners(0,2,false);
	swapCorners(1,3,false);
	swapEdges(0,2,false);
	swapEdges(3,7,true);
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
	swapCorners(0,2,false);
	swapCorners(1,3,false);
	swapEdges(0,2,false);
	swapEdges(1,5,true);
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
	swapCorners(0,2,false);
	swapCorners(1,3,false);
	swapEdges(1,3,false);
	swapEdges(0,4,true);
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
	swapCorners(0,2,false);
	swapCorners(1,3,false);
	swapEdges(1,3,false);
	swapEdges(2,6,true);
}

void CrazyCube::move(unsigned short int move)
{
	(*this.*moveTab[move])(); // Wow! So advanced.
}

void CrazyCube::undoMove(unsigned short int move)
{
	(this->*undoMoveTab[move])(); // Two options possible. So readable.
}

void CrazyCube::swapEdges(unsigned short int edgeOneIndex, unsigned short int edgeTwoIndex,  bool withInnerPieces)
{
	initialMask = withInnerPieces ? 0xF : 0xE;
	// OxF: three bits for piece plus one for inner piece
	// 0xE: just three bits for piece

	// Set bit masks for pieces
	edgeOneMask = initialMask << EdgePieces[edgeOneIndex];
	edgeTwoMask = initialMask << EdgePieces[edgeTwoIndex];

	// Remember pieces
	edgeOne = (cubeState & edgeOneMask) >> EdgePieces[edgeOneIndex];
	edgeTwo = (cubeState & edgeTwoMask) >> EdgePieces[edgeTwoIndex];

	// Clear spots of swapping pieces
	cubeState &= ~(edgeOneMask | edgeTwoMask);

	// Set right positions after the swap
	edgeOne <<= EdgePieces[edgeTwoIndex]; // Reversed order!!
	edgeTwo <<= EdgePieces[edgeOneIndex]; // Don't change or I'll find you, hunt you down and tickle you to death

	// Put them in the cube
	cubeState |= (edgeOne | edgeTwo);
}

void CrazyCube::swapCorners(unsigned short int cornerOneIndex, unsigned short int cornerTwoIndex, bool withInnerPieces)
{
	initialMask = withInnerPieces ? 0xF : 0xE;
	// OxF: three bits for piece plus one for inner piece
	// 0xE: just three bits for piece

	cornerOneMask = initialMask << CornerPieces[cornerOneIndex];
	cornerTwoMask = initialMask << CornerPieces[cornerTwoIndex];

	// Remember pieces
	cornerOne = (cubeState & cornerOneMask) >> CornerPieces[cornerOneIndex];
	cornerTwo = (cubeState & cornerTwoMask) >> CornerPieces[cornerTwoIndex];

	// Clear spots of swapping pieces
	cubeState &= ~(cornerOneMask | cornerTwoMask);

	// Set right positions after the swap
	cornerOne <<= CornerPieces[cornerTwoIndex];
	cornerTwo <<= CornerPieces[cornerOneIndex];

	// Put them in the cube
	cubeState |= (cornerOne | cornerTwo);
}

void CrazyCube::cycleCounterClockwise()
{
	cubeState = ( ((cubeState & 0x00EEE0000EEE0000) << 4) | ((cubeState & 0x0E000000E0000000) >> 12) ) | (cubeState & 0x11111FFF1111FFFF);
}

void CrazyCube::cycleClockwise()
{
	cubeState = ( ((cubeState & 0x0EEE0000EEE00000) >> 4) | ((cubeState & 0x0000E000000E0000) << 12) ) | (cubeState & 0x11111FFF1111FFFF);
}

void CrazyCube::toggleCentre()
{
	this->cubeState ^= static_cast<unsigned long long>(true) << centrePosition;
}

void CrazyCube::resetCube()
{
	cubeState = solvedCube;
}
