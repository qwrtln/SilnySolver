//============================================================================
// Name        : SilnySolver.cpp
// Author      : PkozDelta
// Version     : e-6
// Copyright   : Solve anything you like
// Description : Most probably Crazy 3x3x2
//============================================================================

#include "CrazyCube.h"
#include <iostream>
#include <cstdio>
using namespace std;

//============================================================================
// Poprawnie ułożona kostka
// C, CP0, cp0, ..., CP6, cp6, EP0, ep0, ..., EP7, ep7
// traktowanie C jako true, cp jako false i ep jako true, pozostałe
// to wartości w systemie binarnym, zapisywane na trzech bitach
// Razem: 61 bitów
//============================================================================




int main()
{
	CrazyCube kosteczka;
	cout << "To jest Silny Solver." << endl;
	cout << "A tak wyglada ulozona kostka:" << endl;
	cout << "Hex: ";
	printf("%llx\n",::solvedCube);
	cout << "Dec: ";
	printf("%llu\n",::solvedCube);

	kosteczka.setCubeState(0x102468ac13579bdf);

	//unsigned long long klockiNp[7] = {1,3,5,7,9,0xb,0xd};
	//unsigned long long klockiP[7] = {0,2,4,6,8,0xa,0xc};
	unsigned short klockiRandom[7] = {3,7,2,0xf,4,0xb,0xa};
	cout << "Kosteczka: " << endl;
	cout << "Hex: ";
	printf("%llx\n",kosteczka.getCubeState());
	cout << "Hex: ";
	printf("%llx\n",::solvedCube);

	return 0;
}
