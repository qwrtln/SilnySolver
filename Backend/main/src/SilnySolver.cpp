//============================================================================
// Name        : SilnySolver.cpp
// Author      : PkozDelta..orazGsta
// Version     : e-6
// Copyright   : Solve anything you like
// Description : Most probably Crazy 3x3x2
//============================================================================

#include "CrazyCubeAbstract.h"
#include "CrazyCube.h"
#include "CrazyCubeSolver.h"
#include <iostream>
#include <cstdio>
#include "Tracer.h"

void translateMove(unsigned short move)
{
    switch(move)
    {
        case 0: cout << "LEFT "; return;
        case 1: cout << "FRONT "; return;
        case 2: cout << "UP "; return;
        case 3: cout << "UP_INVERTED "; return;
        case 4: cout << "UP_2 "; return;
        case 5: cout << "MIDDLE_VERTICAL "; return;
        case 6: cout << "MIDDLE_HORIZONTAL "; return;
        case 7: cout << "MIDDLE_HORIZONTAL_RIGHT_ROTATION "; return;
        case 8: cout << "MIDDLE_HORIZONTAL_LEFT_ROTATION "; return;
        case 9: cout << "MIDDLE_VERTICAL_FRONT_ROTATION "; return;
        case 10: cout << "MIDDLE_VERTICAL_BACK_ROTATION "; return;
    }

}

int main(int argc, char* argv[])
{
    using namespace std;

    CrazyCube cube;

    CrazyCubeSolver solver;
	solver.setCrazyCube(&cube);

    TRACE( TRACE_ALL, 0, "Silny Solver start");

    const int movesToDo = 12;
    CrazyCube::rotation movesMap[movesToDo] = {CrazyCube::rotation::MIDDLE_VERTICAL_BACK_ROTATION, CrazyCube::rotation::LEFT, CrazyCube::rotation::FRONT, CrazyCube::rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, CrazyCube::rotation::MIDDLE_VERTICAL, CrazyCube::rotation::MIDDLE_VERTICAL, CrazyCube::rotation::UP_2, CrazyCube::rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION, CrazyCube::rotation::MIDDLE_VERTICAL, CrazyCube::rotation::UP_INVERTED, CrazyCube::rotation::MIDDLE_VERTICAL_FRONT_ROTATION, CrazyCube::rotation::LEFT};//, CrazyCube::rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION, CrazyCube::rotation::MIDDLE_VERTICAL_BACK_ROTATION, CrazyCube::rotation::FRONT};

    for (int i = 0; i < movesToDo; ++i)
    {
        cube.move(movesMap[i]);
    }

	solver.setMinDepth(movesToDo-1);
	solver.setMaxDepth(movesToDo+1);
	solver.setNumberOfSolutions(3);
    cout << "Solver przyjal parametry" << endl;

	solver.solve();

    cout << "Solver rozwiazal" << endl;

	vector<vector<unsigned short int> > rozwiazania;
	rozwiazania = solver.getSolutions();

	if (rozwiazania.size() == 0)
	{
		cout << "Nie umiem tego rozwiazac. Sory." << endl;
	}
    else
    {
        cout << "Oto rozwiazania: " << endl;

        for (unsigned short int i = 0; i < rozwiazania.size(); ++i)
        {
            for (unsigned short int j = 0; j < rozwiazania[i].size(); ++j)
            {
                translateMove(rozwiazania[i][j]);
            }
            cout << endl;
        }
    }

	return 0;
}



