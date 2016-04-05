#include <iostream>

using std::cout;
using std::endl;

#define TRACE(OBJECT, LEVEL, TEXT, ...) \
	cout<<OBJECT<<LEVEL<<":"<<TEXT<<endl;

#define TRACE_ALL "TRACE_ALL"
