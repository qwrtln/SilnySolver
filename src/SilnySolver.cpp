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
*
* TEST() - ZWYKLY TEST
* TEST_F() - TEST, W KTORYM MOZNA USTAWIC KONFIGURACJE TAKA, ZE WSZYSTKIE TESTCASE Z NIEJ KORZYSTAJA
*
*
*/

int main(int argc, char* argv[])
{
	cout << sizeof(void*) << endl;
	cout << sizeof(unsigned long int) << endl;
	RUN_ALL_TESTS(1);

	pthread_exit(NULL);

	return 0;
}
















