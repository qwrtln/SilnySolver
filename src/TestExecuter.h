#pragma once
#include "BaseTest.h"
class TestExecuter
{
public:
	TestExecuter()
	{
	}
	void RunAllTests(bool withTime);
	void AddTest(BaseTest* test);
protected:
	vector<BaseTest*> tests;
};
