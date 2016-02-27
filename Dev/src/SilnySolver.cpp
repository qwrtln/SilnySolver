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
#include "CrazyCubeMapper.h"
#include "CrazyCubeImproved.h"
#include <iostream>
#include <cstdio>


void translateMove(unsigned short move)
{
    switch(move)
    {
        case 0: cout << "L "; return;
        case 1: cout << "F "; return;
        case 2: cout << "U "; return;
        case 3: cout << "Ui "; return;
        case 4: cout << "U2 "; return;
        case 5: cout << "Mv "; return;
        case 6: cout << "Mh "; return;
        case 7: cout << "MhRr "; return;
        case 8: cout << "MhLr "; return;
        case 9: cout << "MvFr "; return;
        case 10: cout << "MvBr "; return;
    }

}

int main(int argc, char* argv[])
{
    using namespace std;

    CrazyCubeImproved impCube;

    CrazyCubeSolver solver;
	solver.setCrazyCube(&impCube);

    int movesToDo = 12;
    int movesMap[movesToDo] = {impCube.MvBr, impCube.L, impCube.F, impCube.MhRr, impCube.Mv, impCube.Mv, impCube.U2, impCube.MhLr, impCube.Mv, impCube.Ui, impCube.MvFr, impCube.L};//, impCube.MhRr, impCube.MvBr, impCube.F};

    for (int i = 0; i < movesToDo; ++i)
    {
        impCube.move(movesMap[i]);
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



