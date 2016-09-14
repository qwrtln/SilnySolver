#include "CrazyCubeBase.h"
#include "CrazyCubeAbstract.h"
#include <stdlib.h>
#include <time.h>


void CrazyCubeBase::scramble()
{
	srand (static_cast<unsigned int>(time(NULL)));

	const int scrambleDepth = 15;


	int numberOfMoves = rand() % scrambleDepth;

	for(int i = 0;  i < numberOfMoves; i++)
	{
		rotation moveToMake = static_cast<rotation> ( rand() % NUM_OF_MOVES) ;
		move(moveToMake);
	}

}
