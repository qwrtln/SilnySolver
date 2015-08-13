//============================================================================
// Name        : SilnySolver.cpp
// Author      : PkozDelta
// Version     : e-6
// Copyright   : Solve anything you like
// Description : Most probably Crazy 3x3x2
//============================================================================

#include "CrazyCube.h"
#include "CrazyCube_test.h"
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
	CrazyCube_test tester;

	CrazyCube kosteczka;
	cout << "To jest Silny Solver." << endl;
	cout << "A tak wyglada ulozona kostka:" << endl;
	cout << "Hex: ";
	printf("%llx\n",solvedCube);
	cout << "Dec: ";
	printf("%llu\n",solvedCube);

	tester.CrazyCubeTests();

	return 0;
}
