#include "BaseTest.h"

BaseTest::BaseTest(string testCase, string testName)
:testCase(testCase),testName(testName),result(1),testExecuted(0)
{
}

BaseTest::~BaseTest(void)
{
}
void BaseTest::Run()
{
	cout << "[  RUN\t\t] ";
	SetTextColor(Yellow);
	cout << testCase;
	SetTextColor(Blue);
	cout << "." << testName << endl;
	SetDefaultTextColor();
	time_t start = clock();
	TestCode();
	runningTime = ((float)(clock() - start))/CLOCKS_PER_SEC;
	testExecuted = 1;
}
void BaseTest::Print(bool withTime = false)
{
	if (testExecuted)
	{
		if(result)
		{
			SetTextColor(Green);
			cout << "[\tPASSED  ] ";
			SetDefaultTextColor();
		}
		else
		{
			SetTextColor(Red);
			cout << "[\tFAILED  ] ";
			SetDefaultTextColor();
		}
	}
	SetTextColor(Yellow);
	cout << testCase;
	SetTextColor(Blue);
	cout << "." << testName;
	SetDefaultTextColor();
	if(withTime)
	{
		//SetTextColor(Magenta);
		cout << " (" << runningTime << " s)";
		//SetDefaultTextColor();
	}
}

void BaseTest::SetTextColor(unsigned short int color)
{
	cout << "\033[0;" << color << "m";
}


void BaseTest::SetDefaultTextColor()
{
	cout << "\033[0m";
}

