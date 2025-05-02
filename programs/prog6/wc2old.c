#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define oops(m,x)       { perror(m); exit(x); }
int main(int argc, char* argv[]){
	char ** file_array;
	int hipipe[2], total = 0, count;	
	if (argc<=1)
		{fprintf(stderr,"Usage: <program name> <file>,...<file>\n");
		return 1;}

	if ((file_array = malloc(sizeof(char)*(argc-1))) == NULL)	{
			perror("malloc");
			free(file_array);
			exit(1);	}
	
	for (int i = 1; i< argc; i++){	
		file_array[i-1] = argv[i];
		printf("%s\n",file_array[i-1]);

	
	for (int i = 0; i < (sizeof(file_array)/sizeof(char*)); i++)	{
		pit_t pid = fork();

			if (pid > 0){
				
			//read if parent
			close(hipipe[1]);
			if (dup2(hipipe[0],0) == -1){
			oops("dup2 parent",1);
			}	

				read(pipefd[0], &count, sizeof(count));
				
					printf("%d %s\n",count, argv[1]);


		 if (pid==0){
			 close(printpipe[0]);
			
			 //set to stdout
			 if (dup2(printpipe[1],0)==-1){
				 perror("dup2");
				 exit(1);
			 }
			
		char * new_array[] = {"wc1",file_array[i],NULL};

		execvp("wc1",new_array[i]);
		
		
		}
						}
				else{
				
				}
		return 0;
	}
