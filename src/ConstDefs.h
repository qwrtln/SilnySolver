/*
 * ConstDefs.h
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */

#ifndef CONSTDEFS_H_
#define CONSTDEFS_H_
class CrazyCubeAbstract
{
public:
//============================================================================
// Poprawnie ułożona kostka
// C, CP0, cp0, ..., CP6, cp6, EP0, ep0, ..., EP7, ep7
// traktowanie C jako true, cp jako false i ep jako true, pozostałe
// to wartości w systemie binarnym, zapisywane na trzech bitach
// Razem: 61 bitów
//============================================================================
	const static unsigned long long solvedCube = 0x102469BD02469BDF;

	// Pozycje ulozonych bitow
	unsigned short int CornerPieces[7] = {56, 52, 48, 44, 40, 36, 32};
	unsigned short int EdgePieces[8] = {56, 52, 48, 44, 40, 36, 32, 28};
	unsigned short int centrePosition = 60;


	// Legalne ruchy
	enum rotation {
		L,		// Left
		F,		// Frontmask
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
		wbw = 0xB,
		woy = 0xC,
		wow = 0xD,
		wgy = 0xE,
		wgw = 0xF
	};
	enum textColors
	{
		Black = 30,
		Red = 31,
		Green = 32,
		Yellow = 33,
		Blue = 34,
		Magenta = 35,
		Cyan = 36,
		White = 37
	};
};

#define NUM_OF_EDGES 8
#define NUM_OF_CORNERS 7

// Test macros

#define TEST(TestClass, TestName)\
	class TestClass##_##TestName: public TestClass\
	{\
	public:\
		TestClass##_##TestName():TestClass(#TestClass,#TestName){testExecuter.AddTest(this);}\
	void TestCode();\
	};\
		TestClass##_##TestName T_##TestClass##_##TestName;\
	void TestClass##_##TestName::TestCode()

// Macro executing all testcases
#define RUN_ALL_TESTS(withTime)\
	testExecuter.RunAllTests(withTime)


// Przykladowe makra. Mozna dopisac inne jak zajdzie taka potrzeba :)
#define ASSERT_EQ(actual, expected)\
if(!(actual == expected))\
{\
	result = 0;\
	cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
	cout << "Value of:  " << #actual << "\n";\
	cout << "Actual:    " << actual << "\n";\
	cout << "Assertion: " << "= " << "\n";\
	cout << "Expected:  " << expected << "\n";\
}\
else\
{\
	result = result && 1;\
}

#define ASSERT_NE(actual, expected)\
if(!(actual != expected))\
{\
	result = 0;\
	cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
	cout << "Value of:  " << #actual << "\n";\
	cout << "Actual:    " << actual << "\n";\
	cout << "Assertion: " << "!= " << "\n";\
	cout << "Expected:  " << expected << "\n";\
}\
else\
{\
	result = result && 1;\
}


#endif /* CONSTDEFS_H_ */
