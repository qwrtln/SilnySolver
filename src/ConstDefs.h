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



#endif /* CONSTDEFS_H_ */
