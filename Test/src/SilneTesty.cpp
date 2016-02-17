#include "CrazyCubeAbstract.h"
#include "TestExecuter.h"
#include "TestMacros.h"
#include <iostream>
#include <cstdio>
//extern TestExecuter testExecuter;

int main(int argc, char* argv[])
{
    using namespace std;

    cout << "Witamy w silnych testach." << endl;
    if(argc > 1) {
      string paramStr(argv[1]);
      if(!paramStr.compare("CrazyCube")) {
          RUN_CRAZYCUBE_TESTS(1);
      }
      else if(!paramStr.compare("CrazyCubeSolver")) {
        RUN_CRAZYCUBE_SOLVER_TESTS(1);  
      }
      else {
        cout << "Podales zly parametr!" << endl;
      }
    }
    else {
      RUN_ALL_TESTS(1);
    }

    return 0;
}
