#include "TestExecuter.h"

TestExecuter* TestExecuter::instance = NULL;

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
/*void TestExecuter::AddTest(void (*test)())
{
	functions.push_back(test);
}
*/
