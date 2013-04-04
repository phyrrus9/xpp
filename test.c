/*
 * Simple function call and argv use test for the x++ language
 * ~2013 Ethan Laur
 */
#include <stdio.h>

void stuff(char * name)
{
	printf("Hello, %s!\n", name);
}

int start(int argc, char * * argv)
{
	if (argc < 2)
	{
		printf("Usage: %s [name]\n", argv[0]);
		return 1;
	}
	stuff(argv[1]);
	return 0;
}
