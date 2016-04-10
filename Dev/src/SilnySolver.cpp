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
        case 0: cout << "rotation::L "; return;
        case 1: cout << "rotation::F "; return;
        case 2: cout << "rotation::U "; return;
        case 3: cout << "rotation::UI "; return;
        case 4: cout << "rotation::U2 "; return;
        case 5: cout << "rotation::MV "; return;
        case 6: cout << "rotation::MH "; return;
        case 7: cout << "rotation::MHRR "; return;
        case 8: cout << "rotation::MHLR "; return;
        case 9: cout << "rotation::MVFR "; return;
        case 10: cout << "rotation::MVBR "; return;
    }

}

int main(int argc, char* argv[])
{
    using namespace std;

    CrazyCubeImproved impCube;

    CrazyCubeSolver solver;
	solver.setCrazyCube(&impCube);

    const int movesToDo = 12;
    CrazyCubeImproved::rotation movesMap[movesToDo] = {CrazyCubeImproved::rotation::MVBR, CrazyCubeImproved::rotation::L, CrazyCubeImproved::rotation::F, CrazyCubeImproved::rotation::MHRR, CrazyCubeImproved::rotation::MV, CrazyCubeImproved::rotation::MV, CrazyCubeImproved::rotation::U2, CrazyCubeImproved::rotation::MHLR, CrazyCubeImproved::rotation::MV, CrazyCubeImproved::rotation::UI, CrazyCubeImproved::rotation::MVFR, CrazyCubeImproved::rotation::L};//, CrazyCubeImproved::rotation::MHRR, CrazyCubeImproved::rotation::MVBR, CrazyCubeImproved::rotation::F};

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



