/*
 * ConstDefs.h
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#ifndef CONSTDEFS_H_
#define CONSTDEFS_H_
#define NUM_OF_EDGES 8
#define NUM_OF_CORNERS 7
#define NUM_OF_MOVES 11

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

	// Legalne ruchy < 11
	enum rotation {
		L,		// Left 0
		F,		// Front
		U,		// Up
		Ui,		// Up inverted
		U2, 	// U^2
		Mv,		// Middle vertical
		Mh, 	// Middle horizontal
		MhRr,	// Middle horizontal Right rotation
		MhLr,	// ...
		MvFr,	// Middle vertical Front rotation
		MvBr	// ... 10
	};

	// Nazwy rogow
	enum cornerNames {
		ygry = 0x0,	// yellow green red (inner yellow)
		ygrw = 0x1,	// yellow green red (inner white)
		yrby = 0x2,	// etc
		yrbw = 0x3,	//...
		yboy = 0x4,
		ybow = 0x5,
		yogy = 0x6,
		yogw = 0x7,
		wrgy = 0x8,	// white red green (inner yellow)
		wrgw = 0x9,	// white red green (inner white)
		wbry = 0xA,	// etc
		wbrw = 0xB,	// ...
		woby = 0xC,
		wobw = 0xD
	};

	// Nazwy krawedzi
	enum edgeNames {
		yry = 0x0,	// yellow red (inner yellow)
		yrw = 0x1,	// yellow red (inner white)
		yby = 0x2,	// etc
		ybw = 0x3,
		yoy = 0x4,
		yow = 0x5,
		ygy = 0x6,
		ygw = 0x7,
		wry = 0x8,	// white red (inner yellow)
		wrw = 0x9,	// white red (inner white)
		wby = 0xA,	// etc
		wbw = 0xB,
		woy = 0xC,
		wow = 0xD,
		wgy = 0xE,
		wgw = 0xF
	};
};


#endif /* CONSTDEFS_H_ */
