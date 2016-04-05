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
		L,		// Left 0
		F,		// Front
		U,		// Up
		UI,		// Up inverted
		U2, 	// U^2
		MV,		// Middle vertical
		MH, 	// Middle horizontal
		MHRR,	// Middle horizontal Right rotation
		MHLR,	// ...
		MVFR,	// Middle vertical Front rotation
		MVBR	// ... 10
	};

	// Nazwy rogow
	enum class cornerNames {
		YGRY = 0x0,	// yellow green red (inner yellow)
		YGRW = 0x1,	// yellow green red (inner white)
		YRBY = 0x2,	// etc
		YRBW = 0x3,	//...
		YBOY = 0x4,
		YBOW = 0x5,
		YOGY = 0x6,
		YOGW = 0x7,
		WRGY = 0x8,	// white red green (inner yellow)
		WRGW = 0x9,	// white red green (inner white)
		WBRY = 0xA,	// etc
		WBRW = 0xB,	// ...
		WOBY = 0xC,
		WOBW = 0xD
	};

	// Nazwy krawedzi
	enum class edgeNames {
		YRY = 0x0,	// yellow red (inner yellow)
		YRW = 0x1,	// yellow red (inner white) 
    YBY = 0x2,	// etc
		YBW = 0x3,
		YOY = 0x4,
		YOW = 0x5,
		YGY = 0x6,
		YGW = 0x7,
		WRY = 0x8,	// white red (inner yellow)
		WRW = 0x9,	// white red (inner white)
		WBY = 0xA,	// etc
		WBW = 0xB,
		WOY = 0xC,
		WOW = 0xD,
		WGY = 0xE,
		WGW = 0xF
	};
};


#endif /* CONSTDEFS_H_ */
