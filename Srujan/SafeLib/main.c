/* strncpy example */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main ()
{
	char str1[]= "This is the best test possible";  
	char str2[10]; 

	strncpy(str2, str1, 10);

}



