/*
 * CrazyCubeAbstract.h
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#ifndef CONSTDEFS_H_
#define CONSTDEFS_H_
#define NUM_OF_EDGES 8
#define NUM_OF_CORNERS 7
#define NUM_OF_MOVES 11
#define CORNERS_MOST_SIGNIFICANT 56
#define EDGES_MOST_SIGNIFICANT 28
#define CENTRE_MOST_SIGNIFICANT 60
#define CORNERS_LEAST_SIGNIFICANT 32
#define EDGES_LEAST_SIGNIFICANT 0

class CrazyCubeAbstract
{
public:
	const static unsigned long long solvedCube;
	const static unsigned long long solvedInnerCircle;
	const static unsigned long long solvedCentre;
	const static unsigned long long solvedEdges;
	const static unsigned long long solvedInnerEdges;
	const static unsigned long long solvedCorners;
	const static unsigned long long solvedInnerCorners;

	const static unsigned short int CornerPieces[NUM_OF_CORNERS];
	const static unsigned short int EdgePieces[NUM_OF_EDGES];
	const static unsigned short int centrePosition;
	
	const static unsigned short int factorials[NUM_OF_EDGES + 1]; // Thus will work like function, eg. factorials[8] = 40320
	const static unsigned short int pow2toX[NUM_OF_EDGES];

	// Legalne ruchy < 11
    enum class rotation {
		LEFT,		// Left 0
		FRONT,		// Front
		UP,		// Up
		UP_INVERTED,		// Up inverted
		UP_2, 	// U^2
		MIDDLE_VERTICAL,		// Middle vertical
		MIDDLE_HORIZONTAL, 	// Middle horizontal
		MIDDLE_HORIZONTAL_RIGHT_ROTATION,	// Middle horizontal Right rotation
		MIDDLE_HORIZONTAL_LEFT_ROTATION,	// ...
		MIDDLE_VERTICAL_FRONT_ROTATION,	// Middle vertical Front rotation
		MIDDLE_VERTICAL_BACK_ROTATION	// ... 10
	};

	// Nazwy rogow
	enum class cornerNames {
		YELLOW_GREEN_RED_YELLOW = 0x0,	// yellow green red (inner yellow)
		YELLOW_GREEN_RED_WHITE = 0x1,	// yellow green red (inner white)
		YELLOW_RED_BLUE_YELLOW = 0x2,	// etc
		YELLOW_RED_BLUE_WHITE = 0x3,	//...
		YELLOW_BLUE_ORANGE_YELLOW = 0x4,
		YELLOW_BLUE_ORANGE_WHITE = 0x5,
		YELLOW_ORANGE_GREEN_YELLOW = 0x6,
		YELLOW_ORANGE_GREEN_WHITE = 0x7,
		WHITE_RED_GREEN_YELLOW = 0x8,	// white red green (inner yellow)
		WHITE_RED_GREEN_WHITE = 0x9,	// white red green (inner white)
		WHITE_BLUE_RED_YELLOW = 0xA,	// etc
		WHITE_BLUE_RED_WHITE = 0xB,	// ...
		WHITE_ORANGE_BLUE_YELLOW = 0xC,
		WHITE_ORANGE_BLUE_WHITE = 0xD
	};

	// Nazwy krawedzi
	enum class edgeNames {
		YELLOW_RED_YELLOW = 0x0,	// yellow red (inner yellow)
		YELLOW_RED_WHITE = 0x1,	// yellow red (inner white) 
    YELLOW_BLUE_YELLOW = 0x2,	// etc
		YELLOW_BLUE_WHITE = 0x3,
		YELLOW_ORANGE_YELLOW = 0x4,
		YELLOW_ORANGE_WHITE = 0x5,
		YELLOW_GREEN_YELLOW = 0x6,
		YELLOW_GREEN_WHITE = 0x7,
		WHITE_RED_YELLOW = 0x8,	// white red (inner yellow)
		WHITE_RED_WHITE = 0x9,	// white red (inner white)
		WHITE_BLUE_YELLOW = 0xA,	// etc
		WHITE_BLUE_WHITE = 0xB,
		WHITE_ORANGE_YELLOW = 0xC,
		WHITE_ORANGE_WHITE = 0xD,
		WHITE_GREEN_YELLOW = 0xE,
		WHITE_GREEN_WHITE = 0xF
	};
};


#endif /* CONSTDEFS_H_ */
