#include "CrazyCubeAbstract.h"
#include "CrazyCubeCache.h"
#include "TestExecuter.h"
#include "TestMacros.h"
#include <iostream>
#include <cstdio>

int main(int argc, char* argv[])
{
    using namespace std;

    bool help = false;
    cout << "Welcome to the SilneTesty!" << endl;

    if(argc > 1)
    {
        string paramStr(argv[1]);
        if (!paramStr.compare("--help"))
        {
            help = true;
            cout << "List of available test cases:\n" <<
                  "CrazyCube\n" <<
                  "CrazyCubeSolver\n" <<
                  "CrazyCubeImproved\n" <<
                  "CrazyCubeMapper\n";
        }
        else
        {
            cout << "Please run with \"--help\" flag to see list of available parameters." << endl;
        }

      if (!paramStr.compare("CrazyCube")) 
      {
          RUN_CRAZYCUBE_TESTS(1);
      }
      else if (!paramStr.compare("CrazyCubeSolver")) 
      {
          RUN_CRAZYCUBE_SOLVER_TESTS(1);  
      }
      else if (!paramStr.compare("CrazyCubeImproved"))
      {
          RUN_CRAZYCUBEIMPROVED_TESTS(1);
      }
      else if (!paramStr.compare("CrazyCubeMapper"))
      {
          RUN_CRAZYCUBMAPPER_TESTS(1);
      }
      else if (!paramStr.compare("Performance"))
      {
          RUN_PERFORMANCE_TESTS(1);
      }
      else if (!help)
      {
        cout << "You've specified a wrong parameter." << endl;
      }
    }
    else 
    {
      if (!help) // Don't run the tests, if user specified they need help.
          RUN_ALL_TESTS(1);
    }

    CrazyCubeCache:: getInstance()->cleanup();
    return 0;
}
