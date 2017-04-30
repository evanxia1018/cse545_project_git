#include <stdio.h>

// Function: strncpy
// This function makes strncpy copy more safe by inputing a '\0' at the end.
char *strncpy(char *dest, const char *src, int n)
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

