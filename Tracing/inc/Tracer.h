

#include <stdio.h>

#ifdef ACT_TRACE_ALL


#ifdef ACT_TRACELEVEL

const int activatedTraceLevel =  ACT_TRACELEVEL;
#else

const int activatedTraceLevel =  -1;

#endif

#define TRACE(OBJECT, LEVEL, TEXT, ...) \
	if(activatedTraceLevel == LEVEL \
			|| activatedTraceLevel == -1){\
	printf(#OBJECT " " #LEVEL ":" TEXT "\n" , ##  __VA_ARGS__);\
	}

#else	
#define TRACE(OBJECT, LEVEL, TEXT, ...) 
#endif

#define TRACE_ALL "TRACE_ALL"
