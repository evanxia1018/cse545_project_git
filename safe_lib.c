#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typeof(printf) *old_printf;
typeof(fprintf) *old_fprintf;
typeof(sprintf) *old_sprintf;
int printf(const char *format,...)//Still vulnerable to a bunch of other format string such as %s. REMEMBER to remove degugging comment before deployment.
{
	// get a pointer to the function "printf"
        old_printf = dlsym(RTLD_NEXT, "printf");
	(*old_printf)("You are now doing safe_printf: \n");// for demo and debug purpose
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

int fprintf(FILE *stream, const char *format, ...){
	// get a pointer to the function "fprintf"
        old_fprintf = dlsym(RTLD_NEXT, "fprintf");
	(*old_fprintf)(stream, "You are now doing safe_fprintf: \n");// for demo and debug purpose
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
		(*old_fprintf)(stream,"%s",parg); // and we call the function with previous arguments
		free(parg);
	} 
	else (*old_fprintf)(stderr,"ERROR: User input contains prohibited characters.\n");
}
int sprintf(char *str, const char *format, ...){
	// get a pointer to the function "sprintf"
        old_sprintf = dlsym(RTLD_NEXT, "sprintf");
	old_fprintf = dlsym(RTLD_NEXT, "fprintf");
	(*old_sprintf)(str, "You are now doing safe_sprintf: \n");// for demo and debug purpose
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
		(*old_sprintf)(str,"%s",parg); // and we call the function with previous arguments
		free(parg);
	} 
	else (*old_fprintf)(stderr,"ERROR: User input contains prohibited characters.\n");
}




int checkinput(char* input,char* forbidden){
	if(strstr(input,forbidden)!=NULL)	return 1;
	return 0;
}


// Function: strncpy
// This function makes strncpy copy more safe by inputing a '\0' at the end.
char *strncpy(char *dest, const char *src, size_t n)
{
    char *ret = dest;
    do {
        if (!n--)
	{
		*dest--;
		*dest = '\0';
		return ret;
	}
    } while (*dest++ = *src++);
    while (n--)
        *dest++ = '\0';
    
    return ret;
}



