

#include <stdio.h>

#define TRACE(OBJECT, LEVEL, TEXT, ...) \
	printf(#OBJECT " " #LEVEL ":" TEXT "\n" , ##  __VA_ARGS__)

#define TRACE_ALL "TRACE_ALL"
