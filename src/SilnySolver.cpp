//============================================================================
// Name        : SilnySolver.cpp
// Author      : PkozDelta
// Version     : e-6
// Copyright   : Solve anything you like
// Description : Most probably Crazy 3x3x2
//============================================================================

//#include "CrazyCube.h"
//#include "CrazyCube_test.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	CrazyCube_test tester;

	CrazyCube kosteczka;
	cout << "To jest Silny Solver." << endl;
	cout << "A tak wyglada ulozona kostka:" << endl;
	cout << "Hex: ";
	printf("%llx\n",tester.solvedCube);
	cout << "Dec: ";
	printf("%llu\n",tester.solvedCube);


	RUN_ALL_TESTS();
	//tester.CrazyCubeTests();

	return 0;
}
