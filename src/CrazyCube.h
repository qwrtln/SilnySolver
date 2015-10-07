/*
 * CrazyCube.h
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#ifndef CRAZYCUBE_H_
#define CRAZYCUBE_H_
#include "ConstDefs.h"

/**
 *  3x3x2 CrazyCube representation.
 */
class CrazyCube: public CrazyCubeAbstract
{
private:
	unsigned long long cubeState;
	void(CrazyCube::*moveTab[NUM_OF_MOVES])();
	void(CrazyCube::*undoMoveTab[NUM_OF_MOVES])();

public:

    /**
     * Basic constructor.
     */
	CrazyCube();

    /**
     * Generic cube constructor
     *
     * @param genericCube. If != 0 genericCube is created. Otherwise normal constructor is called.
     */
	CrazyCube(int genericCube);

    /**
     * Virtual destructor.
     */
	virtual ~CrazyCube();

    /**
     * Checks if CrazyCube is solved.
     *
     * @return true if cube is solved. False if it is not.
     */
	bool checkIfSolved();

    /**
     * Checks if CrazyCube's inner circle is solved.
     *
     * @return true if inner circle is solved. False if it is not.
     */
	bool checkInnerCircle();

    /**
     * Checks if CrazyCube's edges are solved
     *
     * @return true if edges are solved. False if it is not.
     */
	bool checkEdges();

    /**
     * Checks if CrazyCube's corners are solved
     *
     * @return true if corners are solved. False if it is not.
     */
	bool checkCorners();

    /**
     * Checks if CrazyCube is solved with respect to provided mask
     *
     * @param solvedMask parts of CrazyCube expected to be solved
     * @return true if indeed our CrazyCube is solved. False if it is unfortunately not.
     */
	bool checkIfSolved(unsigned long long int solvedMask);

    /**
     * Sets CrazyCube state
     *
     * @param cubeState state to which our cube is about to be set
     */
	void setCubeState(unsigned long long cubeState);

    /**
     * Gets CrazyCube state
     *
     * @return CrazyCube state as an unsigned long long int value
     */
	unsigned long long getCubeState();

    /**
     * Sets CrazyCube centre
     *
     * @param centres state
     */
	void setCentre(bool);

    /**
     * Sets CrazyCube edges as an array of edgeNames
     *
     * @param edges array of edgeNames
     */
	void setEdges(edgeNames edges[NUM_OF_EDGES]);

    /**
     * Sets CrazyCube corners as an array of cornerNames
     *
     * @param corners array of cornerNames
     */
	void setCorners(cornerNames corners[NUM_OF_CORNERS]);

    /**
     * Sets the whole cube to state provided in separate arrays
     *
     * @param edges see above
     * @param corners see above
     * @param centre see above
     */
	void setWholeCube(bool, edgeNames edges[NUM_OF_EDGES], cornerNames corners[NUM_OF_CORNERS]);

    /**
     * CrazyCube moves implementation
     */
	void L();
	void F();
	void U();
	void Ui();
	void U2();
	void Mv();
	void Mh();
	void MhRr();
	void MhLr();
	void MvFr();
	void MvBr();

    /**
     * CrazyCube move implementation using move index
     *
     * @param m index of move to be done
     */
	void move(unsigned short int m);
		/**
     * Inversion of a provided move
     *
     * @param m index of move to be undone
     */
	void undoMove(unsigned short int m);
		/**
     * Toggles the cube centre orientation
     */
	void toggleCentre();
		/**
     * Cube is solved again with no effort :)
     */
	void resetCube();
};

#endif /* CRAZYCUBE_H_ */
