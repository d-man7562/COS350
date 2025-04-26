#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char* argv[]){
	char ** file_array;
	
	if (argc<=1)
		{fprintf(stderr,"Usage: <program name> <file>,...<file>\n");
		return 1;}

	if ((file_array = malloc(sizeof(char)*(argc-1))) == NULL)	{
			fprintf(stderr, "malloc failed\n");
			free(file_array);
			return 1;	}
	
	for (int i = 1; i< argc; i++){	
		file_array[i-1] = argv[i];
		printf("%s\n",file_array[i-1]);

	}
	FILE * fp;
	pid_t pid;	
	
	for (int i = 0; i < (sizeof(file_array)/sizeof(char*)); i++)	{
		pid = fork();
		if (pid < 0){
		fprintf(stderr, "Fork failed\n");
        	exit(1);
		} else if (pid==0){
		char * new_arr[5];
		new_arr[0] = "wc1";
		new_arr[1] = file_array[i];
		new_arr[2] = ">";
		new_arr[3] = "stdin";
		new_arr[4] = NULL;
		execvp("wc1",new_arr);
		exit(0);
		}
	
		else{
		int status;
	printf("Parent checking on child (non-blocking)...\n");

	// Non-blocking wait
	pid_t result = waitpid(pid, &status, WNOHANG);

	if (result == 0) {
	    printf("Child is still running\n");
	    // Do other work...
	} else if (result > 0) {
   	 printf("Child (PID: %d) has terminated\n", result);
	    // Process the status...
	} else {
	    perror("waitpid error");
	}
		
	}
	}
	free(file_array);
	return 0;
	}
