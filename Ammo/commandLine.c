#include <stdio.h>

int main(int argc, char** argv) {

	char commandArgv [1000];
	int i; 
	
	printf ("Enter the command:\n");
	gets (commandArgv);
	
	for(i=0; commandArgv[i] != '\0';i++)
	{
		if(commandArgv[i] == ';')
		{
			return 0;
		}
		if(commandArgv[i] == '`')
		{
			return 0;
		}
		if(commandArgv[i] == '|')
		{
			return 0;
		}
		if(commandArgv[i] == '+')
		{
			return 0;
		}
		if(commandArgv[i] == '>')
		{
			return 0;
		}
		if(commandArgv[i] == '<')
		{
			return 0;
		}
		if(commandArgv[i] == '<')
		{
			return 0;
		}
		if(commandArgv[i] == '&')
		{
			return 0;
		}
	}

	printf ("This string works\n");
}
