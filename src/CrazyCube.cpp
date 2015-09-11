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
	cubeState = ( ((cubeState & 0x0EEE0000EEE00000) >> 4) |
				  ((cubeState & 0x0000E000000E0000) << 12) ) |
				   (cubeState & 0x11111FFF1111FFFF);

}
void CrazyCube::Ui()
{
//============================================================================
// Schemat przemieszczania elementow
// CP[3] -> CP[2] -> CP[1] -> CP[0] -> CP[3]
// EP[3] -> EP[2] -> EP[1] -> EP[0] -> EP[3]
//============================================================================
	cubeState = ( ((cubeState & 0x00EEE0000EEE0000) << 4) |
			 	  ((cubeState & 0x0E000000E0000000) >> 12) ) |
			 	   (cubeState & 0x11111FFF1111FFFF);

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
	cubeState = (cubeState & 0xF1111FFF1111FFFF) |
			  ( (cubeState & 0x0EE00000EE000000) >> 8 ) |
			  ( (cubeState & 0x000EE00000EE0000) << 8 ) ;
}
void CrazyCube::Mv()
{
//============================================================================
// Schemat przemieszczania elementow
// EP[0]ep0 <-> EP[6]ep6
// EP[2]ep2 <-> EP[4]ep4
// ~C
//============================================================================
	   	   	   	   	   	    //0x1.......F.F.F.F.
	cubeState = ((cubeState & 0xFFFFFFFF0F0F0F0F) |
			   ( (cubeState & 0x00000000F0000000) >> 24 ) |
			   ( (cubeState & 0x0000000000F00000) >> 8 ) |
			   ( (cubeState & 0x000000000000F000) << 8 ) |
			   ( (cubeState & 0x00000000000000F0) << 24 )) ^
			  	 (  	  	  0x1000000000000000)          ;

}
void CrazyCube::Mh()
{
//============================================================================
// Schemat przemieszczania elementow
// EP[1]ep1 <-> EP[7]ep7
// EP[3]ep3 <-> EP[5]ep5
// ~C
//============================================================================
							//0x1........F.F.F.F
	cubeState = ((cubeState & 0xFFFFFFFFF0F0F0F0) |
			   ( (cubeState & 0x000000000F000000) >> 24 ) |
			   ( (cubeState & 0x00000000000F0000) >> 8 ) |
			   ( (cubeState & 0x0000000000000F00) << 8 ) |
			   ( (cubeState & 0x000000000000000F) << 24 )) ^
			   (  	  	  	  0x1000000000000000)          ;
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
							//0x.EEEE...E.EF...F
	cubeState = ((cubeState & 0xF1111FFF1F10FFF0) |
			   ( (cubeState & 0x0EE00000E0000000) >> 8 ) |
			   ( (cubeState & 0x000EE00000E00000) << 8 ) |
			   ( (cubeState & 0x00000000000F0000) >> 16 ) |
			   ( (cubeState & 0x000000000000000F) << 16 ));
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
							//0x.EEEE...EFE..F..
	cubeState = ((cubeState & 0xF1111FFF1F1FF0FF) |
			   ( (cubeState & 0x0EE00000E0000000) >> 8 ) |
			   ( (cubeState & 0x000EE00000E00000) << 8 ) |
			   ( (cubeState & 0x000000000F000000) >> 16 ) |
			   ( (cubeState & 0x0000000000000F00) << 16 ));
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
							//0x.EEEE...FE.EF...
	cubeState = ((cubeState & 0xF1111FFF01F10FFF) |
			   ( (cubeState & 0x0EE000000E000000) >> 8 ) |
			   ( (cubeState & 0x000EE000000E0000) << 8 ) |
			   ( (cubeState & 0x00000000F0000000) >> 16 ) |
			   ( (cubeState & 0x000000000000F000) << 16 ));
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
							//0x.EEEE....EFE..F.
	cubeState = ((cubeState & 0xF1111FFFF101FF0F) |
			   ( (cubeState & 0x0EE000000E000000) >> 8 ) |
			   ( (cubeState & 0x000EE000000E0000) << 8 ) |
			   ( (cubeState & 0x0000000000F00000) >> 16 ) |
			   ( (cubeState & 0x00000000000000F0) << 16 ));
}

void CrazyCube::move(unsigned short int move)
{
	(*this.*moveTab[move])(); // Wow! So advanced.
}

void CrazyCube::undoMove(unsigned short int move)
{
	(this->*undoMoveTab[move])(); // Two options possible. So readable.
}

void CrazyCube::toggleCentre()
{
	this->cubeState ^= static_cast<unsigned long long>(true) << centrePosition;
}

void CrazyCube::resetCube()
{
	cubeState = solvedCube;
}
