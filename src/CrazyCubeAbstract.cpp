/*
 * CrazyCubeAbstract.cpp
 *
 *  Created on: Aug 20, 2015
 *      Author: qwrtln
 */
#include "ConstDefs.h"

//============================================================================
// Poprawnie ułożona kostka
// C, CP0, cp0, ..., CP6, cp6, EP0, ep0, ..., EP7, ep7
// traktowanie C jako true, cp jako false i ep jako true, pozostałe
// to wartości w systemie binarnym, zapisywane na trzech bitach
// Razem: 61 bitów
//============================================================================
const unsigned long long CrazyCubeAbstract::solvedCube = 0x102469BD02469BDF;

// Pozycje bitow danych elementow
const unsigned short int CrazyCubeAbstract::CornerPieces[7] = {56, 52, 48, 44, 40, 36, 32};
const unsigned short int CrazyCubeAbstract::EdgePieces[8]  = {28, 24, 20, 16, 12, 8, 4, 0};
const unsigned short int CrazyCubeAbstract::centrePosition = 60;
