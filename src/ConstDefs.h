/*
 * ConstDefs.h
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#ifndef CONSTDEFS_H_
#define CONSTDEFS_H_

const unsigned long long solvedCube = 0x102469BD02469BDF;


// Legalne ruchy
enum rotation {
	L,		// Left
	F,		// Front
	U,		// Up
	Ui,		// Up inverted
	U2, 	// U^2
	Mv,		// Middle vertical
	Mh, 	// Middle horizontal
	MhRr,	// Middle horizontal Right rotation
	MhLr,	// ...
	MvFr,	// Middle vertical Front rotation
	MvBr	// ...
};

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
	wbr = 0xB,
	woy = 0xC,
	wow = 0xD,
	wgy = 0xE,
	wgw = 0xF
};

#endif /* CONSTDEFS_H_ */
