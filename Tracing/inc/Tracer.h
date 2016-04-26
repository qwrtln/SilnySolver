

#include <stdio.h>

#ifdef ACT_TRACE_ALL

#ifdef ACT_TRACELEVEL

const int activatedTraceLevel = #ACT_TRACELEVEL;
#endif

#define TRACE(OBJECT, LEVEL, TEXT, ...) \
	if(activatedTraceLevel == #LEVEL){\
	printf(#OBJECT " " #LEVEL ":" TEXT "\n" , ##  __VA_ARGS__)\
	}

#else	
#define TRACE(OBJECT, LEVEL, TEXT, ...) 
#endif

#define TRACE_ALL "TRACE_ALL"
