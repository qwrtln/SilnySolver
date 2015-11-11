//============================================================================
// Name        : SilnySolver.cpp
// Author      : PkozDelta
// Version     : e-6
// Copyright   : Solve anything you like
// Description : Most probably Crazy 3x3x2
//============================================================================

#include "CrazyCubeAbstract.h"
#include "CrazyCube.h"
#include "CrazyCubeSolver.h"
#include <iostream>
#include <cstdio>


int main(int argc, char* argv[])
{
    using namespace std;

	CrazyCube kosteczka;
    CrazyCubeSolver solver;

	solver.setCrazyCube(&kosteczka);

	kosteczka.move(10);
	kosteczka.move(0);
	kosteczka.move(1);
	kosteczka.move(7);
	kosteczka.move(5);

	solver.setMinDepth(4);
	solver.setMaxDepth(6);
	solver.setNumberOfSolutions(2);
	solver.setSolvedMask(kosteczka.solvedCube);
	solver.solve();

	vector<vector<unsigned short int> > rozwiazania;
	rozwiazania = solver.getSolutions();

	if (rozwiazania.size() == 0)
	{
		cout << "Nie umiem tego rozwiazac. Sory." << endl;
	}

	for (unsigned short int i = 0; i < rozwiazania.size(); ++i)
	{
		for (unsigned short int j = 0; j < rozwiazania[i].size(); ++j)
		{
			cout << rozwiazania[i][j] << " ";
		}
		cout << endl;
	}
    cout << "Excellent! Now my cube is complete." << endl;

	return 0;
}
















