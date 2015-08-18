#ifndef BASE_TEST_H
#define BASE_TEST_H
#include <string>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;
#include "ConstDefs.h"

class BaseTest: public CrazyCubeAbstract
{
public:
	BaseTest(string testCase, string testName);
	virtual ~BaseTest(void);
	virtual void TestCode() = 0;
	virtual void Run();
	virtual void Print(bool withTime);

protected:
	string testCase;
	string testName;
	int result;
	bool testExecuted;
	float runningTime;
	//HANDLE  hConsole;
	void SetTextColor(unsigned short int color);
	void SetDefaultTextColor();
};
#endif
