/*
 * CrazyCube_test.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */
#include <iostream>
#include <cstdio>
#include "CrazyCube.h"
using namespace std;

class CrazyCube_test: public CrazyCubeAbstract
{
private:
	CrazyCube cube;

public:
	bool setCornersTest(void);
	bool setEdgesTest(void);

	bool setCubeTest(void);
	void CrazyCubeTests(void);

};
