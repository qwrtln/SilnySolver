#include "CrazyCubeAbstract.h"
#include "TestExecuter.h"
#include "TestMacros.h"
#include <iostream>
#include <cstdio>
extern TestExecuter testExecuter;

int main()
{
    using namespace std;

    cout << "Witamy w silnych testach." << endl;
    RUN_ALL_TESTS(1);

    return 0;
}
