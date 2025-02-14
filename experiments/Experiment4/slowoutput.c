/* Domenic Mancuso 1/27/2025 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char**argv)
{
	/*establish pointer for stdin*/
	char filename[200];
	/*test cases for stdin*/
	if (argc>2)
	{
		fprintf(stderr, "Usage: %s '<filename>'. DEFAULT(BLANK) = output.txt\n", argv[0]);
		return 1;
	}
		/*if no filename is provided, deafult to output.txt*/
	if (argc == 1)
	{
		strcpy(filename, "output.txt");
	}
	else
	{
	strcpy(filename, argv[1]);
	}
		/*remove newline character from custom filename*/
	char *newline = strchr(filename, '\n');
	if (newline != NULL)
	{
		*newline = '\0';
	}
	
	/*open file, check for errors*/
	FILE *file;
	file = fopen(filename,"w");
	if (file==NULL)
	{
		fprintf(stderr, "Error opening file\n");
		return 1;
	}
	/*write to file*/
	while(1)
	{
	fprintf(file, "a");
//used to test without buffering	fflush(file);
	usleep(10000);
	}
	fclose(file);
	return 0;
	}
