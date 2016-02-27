#ifndef BASE_TEST_H
#define BASE_TEST_H
#include <string>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;
#include "CrazyCubeAbstract.h"

class BaseTest: public CrazyCubeAbstract
{
public:
	BaseTest(string testCase, string testName);
	virtual ~BaseTest();
	virtual void TestCode() = 0;
	virtual void Run();
	virtual void Print(bool withTime);

protected:
 	virtual void SetUp();
 	virtual void TearDown();
	string testCase;
	string testName;
	int result;
	bool testExecuted;
	float runningTime;
	//HANDLE  hConsole;
	void SetTextColor(unsigned short int color);
	void SetDefaultTextColor();
	// Nazwy kolorow
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
#endif
