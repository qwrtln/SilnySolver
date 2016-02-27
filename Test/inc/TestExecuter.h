#pragma once
#include "BaseTest.h"
#include "TestMacros.h"
#include <map>

class TestExecuter
{
	static TestExecuter* instance;

public:
	TestExecuter()
	{
	}
	void RunAllTests(bool withTime);
    void RunCrazyCubeSolverTests(bool withTime);
    void RunCrazyCubeTests(bool withTime);
    void RunCrazyCubeImprovedTests(bool withTime);
    void RunCrazyCubeMapperTests(bool withTime);
    void RunPerformanceTests(bool withTime);
	void AddTest(BaseTest* test, std::string name);

	static TestExecuter* getInstance()
    {
        if(!instance)
        {
            instance = new TestExecuter();
        }
        return instance; 
    }

protected:
    multimap<string, BaseTest*> testsMap;
};

