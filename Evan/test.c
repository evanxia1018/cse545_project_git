#include <stdio.h> 
#include <stdlib.h>
main() 
{ 
	test_printf();
	test_fprintf();
	test_sprintf();
}

test_printf(){
	printf("This is a normal string\n");
	printf("%s","This is a normal format string\n");
	printf("This is an evil string with one devil%n");
	printf("This is an evil string with ten devils%n%n%n%n%n%n%n%n%n%n");
	printf("This is an evil string with fifty devils%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n");
}

test_fprintf(){
	FILE * fp;
	fp = fopen ("file.txt", "w+");
   	fprintf(fp, "%s %s %s %d %n", "We", "are", "in", 2012);
   	fclose(fp);
   
   return(0);
	fprintf("This is a normal string\n");
	fprintf("%s","This is a normal format string\n");
	fprintf("This is an evil string with one devil%n");
	fprintf("This is an evil string with ten devils%n%n%n%n%n%n%n%n%n%n");
	fprintf("This is an evil string with fifty devils%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n");
}



test_sprintf(){

}



