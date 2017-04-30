#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
   char src[40];
   char dest[12];

   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strncpy(dest, src, 10);

   system("dir");

   printf("Final copied string : %s\n", dest);


   return(0);
}