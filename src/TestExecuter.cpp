#include "TestExecuter.h"
void TestExecuter::RunAllTests(bool withTime = true)
{
	//cout << "TestExecuter ["<< this <<"] tests.size(): "<<tests.size();
	for(vector<BaseTest*>::iterator iter = tests.begin(); iter != tests.end(); iter++)
	{
		(*iter)->Run();
		(*iter)->Print(withTime);
		cout << endl;
	}
}
void TestExecuter::AddTest(BaseTest* test)
{
	//cout << "TestExecuter ["<< this <<"] Add()" << endl;
	tests.push_back(test);
}
