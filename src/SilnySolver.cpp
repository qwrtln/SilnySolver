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
// CP[0] = 000
// CP[1] = 001
// ...
// CP[6] = 110
//
// EP[0] = 000
// EP[1] = 001
// ...
// EP[7] = 111
//
// cp[0-3] = 1
//
// cp[3] = 1
// cp[4-6] = 0
//
// ep[1-3] = 1
// ep[4-7] = 0
//
// C = 0
//
// Razem: 61 bitów
//============================================================================
const unsigned long long solvedCube = 0xa72e053977f1e0;

// Legalne ruchy
enum rotation {
	R,
	Ri,
	B,
	Bi,
	U,
	Ui,
	U2,
	Mh,
	Mv,
	MhR,
	MhL,
	MvR,
	MvL
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
