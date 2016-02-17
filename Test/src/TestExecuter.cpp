#include "TestExecuter.h"

TestExecuter* TestExecuter::instance = NULL;

void TestExecuter::RunAllTests(bool withTime = true)
{
  cout << "Running all tests:" << endl;
  for(std::multimap<std::string, BaseTest*>::iterator mmit = testsMap.begin(); mmit != testsMap.end(); ++mmit) {
      mmit->second->Run();
      mmit->second->Print(withTime);
      cout << endl;
  }
}
void TestExecuter::RunCrazyCubeSolverTests(bool withTime = true)
{
  cout << "Running CrazyCubeSolverTests: " << endl;
  for(std::multimap<std::string, BaseTest*>::iterator mmit = testsMap.begin(); mmit != testsMap.end(); ++mmit) {
    if(!(*mmit).first.compare("CrazyCubeSolverTest")) {
      mmit->second->Run();
      mmit->second->Print(withTime);
      cout << endl;
    }
  }
}
void TestExecuter::RunCrazyCubeTests(bool withTime = true)
{
  cout << "Running CrazyCubeTests: " << endl;
  for(std::multimap<std::string, BaseTest*>::iterator mmit = testsMap.begin(); mmit != testsMap.end(); ++mmit) {
    if(!(*mmit).first.compare("CrazyCubeTest")) {
      mmit->second->Run();
      mmit->second->Print(withTime);
      cout << endl;
    }
  }
}

void TestExecuter::AddTest(BaseTest* test, std::string name)
{
	//cout << "TestExecuter ["<< this <<"] Add()" << endl;
  testsMap.insert(std::pair<std::string, BaseTest*>(name, test));
}
/*void TestExecuter::AddTest(void (*test)())
{
	functions.push_back(test);
}
*/
