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

const unsigned long long solvedCube = 0xa72e053977f1e1;

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
