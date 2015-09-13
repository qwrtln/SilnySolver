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
	const static unsigned long long solvedEdges;
	const static unsigned long long solvedCorners;

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



// Test macros

#define TEST(TestCase, TestName)\
void TestCase##_##TestName()


#define TEST_F(TestClass, TestName)\
	class TestClass##_##TestName: public TestClass\
	{\
	public:\
		TestClass##_##TestName():TestClass(#TestClass,#TestName)\
	{\
		SetUp();\
		testExecuter.AddTest(this);\
	}\
	virtual ~TestClass##_##TestName()\
	{\
		TearDown();\
	}\
	void TestCode();\
	};\
		TestClass##_##TestName T_##TestClass##_##TestName;\
	void TestClass##_##TestName::TestCode()

// Macro executing all testcases
#define RUN_ALL_TESTS(withTime)\
	testExecuter.RunAllTests(withTime)

// Przykladowe makra. Mozna dopisac inne jak zajdzie taka potrzeba :)

#define ASSERT_EQ_STL_CONTAINER(actual, expected)\
if(!(actual.size() == expected.size()))\
{\
	result =0;\
	cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
	cout << "Size of:" << #actual << "\n";\
	cout << "Expected:\t" << actual.size() << "\n";\
	cout << "Assertion: " << "= " << "\n";\
	cout << "Actual:\t\t" << expected.size() << "\n";\
}\
else\
{\
	for(unsigned int i = 0; i < actual.size(); i++)\
	{\
		if(actual[i] != expected[i])\
		{\
			result = 0;\
			cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
			cout << "Contents of: " << #actual << " differ from contents of " << #expected << "\n\n";\
			cout << "Index\t|\tActual\t|\tExpected" << endl;\
			for(unsigned int j = 0; j <=i; j++)\
			{\
				cout << j << "\t| \t" << actual[j] << "\t|\t" << expected[j]; \
				if(j!=i)\
				{\
					cout << endl;\
				}\
			}\
			cout << "\t <----" << endl;\
			break;\
		}\
	}\
}


#define ASSERT_EQ_HEX(actual, expected)\
if(!(actual == expected))\
{\
	result = 0;\
	cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
	cout << hex << showbase;\
	cout << "Value of:  " << #actual << "\n";\
	cout << "Expected:\t" << actual << "\n";\
	cout << "Assertion: " << "= " << "\n";\
	cout << "Actual:\t\t" << expected << "\n";\
	cout << dec << noshowbase;\
}\
else\
{\
	result = result && 1;\
}

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

#define ASSERT_NE_HEX(actual, expected)\
if(!(actual != expected))\
{\
	result = 0;\
	cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
	cout << hex << showbase;\
	cout << "Value of:  " << #actual << "\n";\
	cout << "Actual:    " << actual << "\n";\
	cout << "Assertion: " << "!= " << "\n";\
	cout << "Expected:  " << expected << "\n";\
	cout << dec << noshowbase;\
}\
else\
{\
	result = result && 1;\
}

#endif /* CONSTDEFS_H_ */
