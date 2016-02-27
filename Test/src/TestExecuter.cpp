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
  cout << "Running CrazyCubeSolver tests: " << endl;
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
  cout << "Running CrazyCube tests: " << endl;
  for(std::multimap<std::string, BaseTest*>::iterator mmit = testsMap.begin(); mmit != testsMap.end(); ++mmit) {
    if(!(*mmit).first.compare("CrazyCubeTest")) {
      mmit->second->Run();
      mmit->second->Print(withTime);
      cout << endl;
    }
  }
}

void TestExecuter::RunCrazyCubeImprovedTests(bool withTime = true)
{
  cout << "Running CrazyCubeImproved tests: " << endl;
  for(std::multimap<std::string, BaseTest*>::iterator mmit = testsMap.begin(); mmit != testsMap.end(); ++mmit) {
    if(!(*mmit).first.compare("CrazyCubeImprovedTest")) {
      mmit->second->Run();
      mmit->second->Print(withTime);
      cout << endl;
    }
  }
}

void TestExecuter::RunCrazyCubeMapperTests(bool withTime = true)
{
  cout << "Running CrazyCubeMapper tests: " << endl;
  for(std::multimap<std::string, BaseTest*>::iterator mmit = testsMap.begin(); mmit != testsMap.end(); ++mmit) {
    if(!(*mmit).first.compare("CrazyCubeMapperTest")) {
      mmit->second->Run();
      mmit->second->Print(withTime);
      cout << endl;
    }
  }
}


void TestExecuter::RunPerformanceTests(bool withTime = true)
{
  cout << "Running Performance tests: " << endl;
  for(std::multimap<std::string, BaseTest*>::iterator mmit = testsMap.begin(); mmit != testsMap.end(); ++mmit) {
    if(!(*mmit).first.compare("PerformanceTest")) {
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
