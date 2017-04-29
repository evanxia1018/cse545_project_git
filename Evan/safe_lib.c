#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typeof(printf) *old_printf;

int printf(const char *format,...)
{
	// get a pointer to the function "printf"
        old_printf = dlsym(RTLD_NEXT, "printf");
	//(*old_printf)("You are now doing safe_printf: ");// for demo and debug purpose
	va_list list;
        char *parg;
        /*
                SANITIZE INPUT
        */
	
	if((checkinput(format,"%n")+
		checkinput(format,"%hhn") +
		checkinput(format,"%hn") +
		checkinput(format,"%ln") +
		checkinput(format,"%lln") +
		checkinput(format,"%Ln") +
		checkinput(format,"%zn") +
		checkinput(format,"%jn") +
		checkinput(format,"%tn")) == 0){
		// format variable arguments
        	va_start(list, format);
        	vasprintf(&parg, format, list);
        	va_end(list);
		(*old_printf)("%s",parg); // and we call the function with previous arguments
		free(parg);
	} 
	else (*old_printf)("ERROR: User input contains prohibited characters.\n");
}

int checkinput(char* input,char* forbidden){
	if(strstr(input,forbidden)!=NULL)	return 1;
	return 0;
}




