

#include <stdio.h>

#ifdef ACT_TRACE_ALL
#define TRACE(OBJECT, LEVEL, TEXT, ...) \
	printf(#OBJECT " " #LEVEL ":" TEXT "\n" , ##  __VA_ARGS__)

#else	
#define TRACE(OBJECT, LEVEL, TEXT, ...) 
#endif

#define TRACE_ALL "TRACE_ALL"
