#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define XPP_VERSION "1.0-alpha"
int main(int argc, char * * argv)
{
	//arg1 : outfile
	//arg2+: infiles (object)
	int offset = 0;
	char linker_fwd[100];
	strcpy(linker_fwd, "");
	/*for (int i = 0; i < argc; i++)
	{
		printf("arg[%d]: %s\n", i, argv[i]);
	}*/
	if (argc < 3)
	{
		printf("Usage: %s [-v] [-l # link1 ...] <outfile> <source files (.o)>\n"
		       "-v option will display the version and then exit\n"
		       "-l option (optional) will forward all the options to the linker \n"
		       "syntax is [-l # arg1 arg2 arg3], where # is the number of total\n"
		       "args, in this case 3. Example: %s -l 1 -lncurses ncurses.x ncurses.o\n\n", argv[0], argv[0]);
		return -1;
	}
	if (strcmp(argv[1], "-v") == 0)
	{
		printf("x++ compiler version %s\n", XPP_VERSION);
		return 0;
	}
	if (strcmp(argv[1], "-l") == 0) //linker options
	{
		int num_options = atoi(argv[2]);
		//printf("#: %d\n", num_options);
		char tmp[30];
		offset = 2 + num_options;
		for (int i = 3, j = 0; j < num_options; i++, j++)
		{
			sprintf(tmp, "%s ", argv[i]);
			//printf("i: %d s: %s\n", i, argv[i]);
			strcat(linker_fwd, tmp);
		}
		//printf("Linker fwd: %s\n", linker_fwd);
	}
	char outfile[30];
	char infiles[argc * 30];
	char command[(argc * 30) * 2];
	strcpy(infiles, "");	
	strcpy(outfile, argv[offset + 1]);
	for (int i = 0, j = offset + 2; j < argc; i++, j++)
	{
		char tmp[30];
		sprintf(tmp, "%s ", argv[j]);
		strcat(infiles, tmp);
	}
	//printf("%s\n", infiles);
	sprintf(command, "g++ -dynamiclib %s %s -o %s", infiles, linker_fwd, outfile);
	//printf("Command line call: %s\n", command);
	system(command);
}
