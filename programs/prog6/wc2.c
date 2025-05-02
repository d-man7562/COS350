#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define fail(x,y) { perror(x),exit(y); }

int main(int argc, char * argv[]){
	pid_t pid;
	int leakypipe[2];
	if (pipe(leakypipe) == -1) { fail("pipe failed", 1); }
	int total = 0;
	if (argc <= 1){
		printf("usage: wc2 <filename, ...>\n");
		return 0;
	}
		
	for (int i = 1; i < argc; i++){
	 pid = fork();
	//	if (pid == -1) { fail("fork failed", 1); }
		if (pid == 0){
		close(leakypipe[0]); //close read
		dup2(leakypipe[1], 1);
		close(leakypipe[1]);
		execlp("wc1","wc1",argv[i],NULL);
		fail("made it to end of child!",1);
		}	}


/*	parent process */
		close(leakypipe[1]); //close write
    char buffer[256];
    int bytes_read, count;
    while ((bytes_read = read(leakypipe[0], buffer, sizeof(buffer)-1)) > 0) {
        buffer[bytes_read] = '\0'; // null-terminate
        
        char *line = strtok(buffer, "\n");
        while (line) {
		printf("%s\n",line);
            if (sscanf(line, "%d", &count) == 1) {
                total += count;
            }
            line = strtok(NULL, "\n");
        }
    }
    close(leakypipe[0]);

    for (int i = 1; i < argc; i++) {
        wait(NULL);
    }

    printf("%d total\n", total);
    return 0;
} 	
