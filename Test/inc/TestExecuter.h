#pragma once
#include "BaseTest.h"
#include "TestMacros.h"

class TestExecuter
{

	static TestExecuter* instance;

public:
	TestExecuter()
	{
	}
	void RunAllTests(bool withTime);
	void AddTest(BaseTest* test);

	static TestExecuter* getInstance()
{
	if(!instance)
{
instance = new TestExecuter();

}
return instance; 

}

	//void AddTest(void (*test)());
protected:
	vector<BaseTest*> tests;
	//vector<void(*)()> functions;
};


