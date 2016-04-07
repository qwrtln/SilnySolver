

#include <stdio.h>

#define TRACE(OBJECT, LEVEL, TEXT, ...) \
	printf(#OBJECT " " #LEVEL ":" TEXT "\n")

#define TRACE_ALL "TRACE_ALL"
