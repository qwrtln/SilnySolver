//============================================================================
// Name        : SilnySolver.cpp
// Author      : PkozDelta
// Version     : e-6
// Copyright   : Solve anything you like
// Description : Most probably Crazy 3x3x2
//============================================================================

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
const unsigned long long solvedCube = 0x102468ac13579bd;

// Legalne ruchy
enum rotation {
	L,		// Left
	F,		// Front
	U,		// Up
	Ui,		// Up inverted
	U2, 	// U^2
	Mv,		// Middle vertical
	Mh, 	// Middle horizontal
	MhRr,	// Middle horizontal Right rotation
	MhLr,	// ...
	MvFr,	// Middle vertical Front rotation
	MvBr	// ...
};

bool checkIfSolved(unsigned long long cubeState)
{
	return (cubeState == solvedCube);
}

int main()
{
	cout << "To jest Silny Solver." << endl;
	cout << "A tak wyglada ulozona kostka:" << endl;
	cout << "Hex: ";
	printf("%llx\n",solvedCube);
	cout << "Dec: ";
	printf("%llu\n",solvedCube);
	return 0;
}
