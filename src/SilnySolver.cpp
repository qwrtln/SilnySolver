//============================================================================
// Name        : SilnySolver.cpp
// Author      : PkozDelta
// Version     : e-6
// Copyright   : Solve anything you like
// Description : Most probably Crazy 3x3x2
//============================================================================

#include "ConstDefs.h"
#include "TestExecuter.h"
#include <iostream>
#include <cstdio>
extern TestExecuter testExecuter;
using namespace std;

/**
*	Testy teraz piszemy tak, że tworzymy dla każdej klasy osobny plik .cpp na przykladzie pliku SilneTesty.cpp
*	Makro TEST tworzy i rejestruje testcase, nie trzeba go już ręcznie nigdzie dodawać.
*	W main() wystarczy wywołać makro RUN_ALL_TESTS() i wszystkie się ładnie odpalają.
*/

int main(int argc, char* argv[])
{
	RUN_ALL_TESTS(1);

	return 0;
}
