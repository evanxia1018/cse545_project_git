#include <stdio.h> 
#include <stdlib.h>
main() 
{ 
	test_fprintf();
}

test_fprintf(){
   FILE * fp;

   fp = fopen ("file.txt", "w+");
   fprintf(fp, "%s %s %s %d %n", "We", "are", "in", 2012);
   
   fclose(fp);
   
   return(0);
}




