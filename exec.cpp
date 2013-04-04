#include "dlfcn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define XEXEC_VERSION "1.0.1"
int main(int argc, char * * argv)
{
	int offset = 1; //for passing arglist
	bool debug = false;
	if (argc < 2)
	{
		printf("Usage: %s [options] <path to object file>\n"
		       "Options: -v (verbose debug)              \n"
		       "         -V (version)\n", argv[0]);
		return -2;
	}
	if (strcmp(argv[1], "-v") == 0)
	{
		debug = true;
		offset++;
	}
	if (strcmp(argv[1], "-V") == 0)
	{
		printf("x exec version: %s\n", XEXEC_VERSION);
		return 0;
	}
	void* lib_handle = dlopen(argv[offset], RTLD_NOW);
	if (lib_handle == NULL)
	{
		printf("Object file does not exist!\n");
		return -3;
	}
	void *test_shared_libs = dlsym(lib_handle, "start");
	if (test_shared_libs == NULL && !debug) //start isnt there, lets check for int main(int, char * *);
	{
		printf("Warning: symbol [start] is not in file!\n");
		test_shared_libs = dlsym(lib_handle, "main");
	}
	int (*func)(int, char * *) = (int (*)(int, char * *))test_shared_libs;
	if (func == NULL)
	{
		printf("Symbol not found!\n");
		if (debug)
		{
			printf("Print symbol table? (1\\0) ");
			char symbol_table = 0;
			scanf("%c", &symbol_table);
			if (symbol_table == '1')
			{
				char sys_command[50];
				sprintf(sys_command, "nm %s | less", argv[offset]);
				system(sys_command);
			}
			printf("New symbol: ");
			char symbol_new[30];
			scanf("%s", symbol_new);
			void *test_shared_libs = dlsym(lib_handle, symbol_new);
			if (test_shared_libs == NULL)
			{
				printf("Error!\n");
				return -4;
			}
			else
			{
				func = (int (*)(int, char * *))test_shared_libs;
			}
		}
		else
		{
			return -1;
		}
	}
	int retval = func(argc - offset, &argv[offset]);
	if (debug)
	{
		printf("Return value: %d\n", retval);
	}
	return retval;
}
