#include <stdio.h> 
#include <stdlib.h>
main() 
{ 
	test_printf();
}

test_printf(){
	printf("This is an evil string%n\n");
	printf("This is an evil string%hhn\n");
	printf("This is an evil string%hn\n");
	printf("This is an evil string%ln\n");
	printf("This is an evil string%lln\n");
	printf("This is an evil string%Ln\n");
	printf("This is an evil string%zn\n");
	printf("This is an evil string%jn\n");
	printf("This is an evil string%tn\n");
}




