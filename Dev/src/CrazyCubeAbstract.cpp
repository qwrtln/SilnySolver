/*
 * CrazyCubeAbstract.cpp
 *
 *  Created on: Aug 20, 2015
 *      Author: qwrtln
 */
#include "CrazyCubeAbstract.h"

//============================================================================
// Poprawnie ułożona kostka
// Szczegolowe objasnienia w dokumentacji. Kolejne bity:
// C, CP0, cp0, CP1, cp1, ..., CP6, cp6, EP0, ep0, EP1, ep1, ..., EP7, ep7
// Gdzie:
// C, cp, ep - zajmują po jednym bicie (true or false)
// CP, EP - zajmują po trzy bity; wartości od 0 do 7 (kostka ma 8 krawędzi i 8 rogów)
//============================================================================
const unsigned long long CrazyCubeAbstract::solvedCube = 0x102469BD02469BDF;

// Maski bitowe na poszczególne etapy ułożenia:
const unsigned long long CrazyCubeAbstract::solvedInnerCircle = 0x1000011100001111;
const unsigned long long CrazyCubeAbstract::solvedCentre = 0x1000000000000000;
const unsigned long long CrazyCubeAbstract::solvedEdges = 0x2468ACE;
const unsigned long long CrazyCubeAbstract::solvedInnerEdges = 0x1111;
const unsigned long long CrazyCubeAbstract::solvedCorners = 0x2468AC00000000;
const unsigned long long CrazyCubeAbstract::solvedInnerCorners = 0x11100000000;


// Pozycje bitow danych elementow
const unsigned short int CrazyCubeAbstract::CornerPieces[7] = {56, 52, 48, 44, 40, 36, 32};
const unsigned short int CrazyCubeAbstract::EdgePieces[8]  = {28, 24, 20, 16, 12, 8, 4, 0};
const unsigned short int CrazyCubeAbstract::centrePosition = 60;

// Zahardcodowane wyniki funkcji w celu optymalizacji
const unsigned short int CrazyCubeAbstract::factorials[NUM_OF_EDGES + 1] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
const unsigned short int CrazyCubeAbstract::pow2toX[NUM_OF_EDGES] = {1, 2, 4, 8, 16, 32, 64, 128};


