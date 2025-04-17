/* execute.c - code used by small shell to execute commands */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
int execute(char *argv[])
/*
 * purpose: run a program passing it arguments
 * returns: status returned via wait, or -1 on error
 *  errors: -1 on fork() or wait() errors
 */
{
  int	pid ;
  int	child_info = -1;
  int is_background = 0;
  if ( argv[0] == NULL )		/* nothing succeeds	*/
    return 0;
   if (strcmp(argv[0], "exit") == 0) {
        int exit_val = 0;    
    if (argv[1] != NULL) {
            exit_val = atoi(argv[1]);
        }
        exit(exit_val);
   }
  for (int i = 0; argv[i] != NULL; i++){
    if (strcmp(argv[i], "&") == 0 ){
      argv[i] = NULL;
      is_background = 1;
    }
  }
     
  if ( (pid = fork())  == -1 )
    perror("fork");
  else if ( pid == 0 ){
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    execvp(argv[0], argv);
    perror("cannot execute command");
    exit(1);
  }
  else {
    if (is_background){
      printf("In background: %s %d\n",argv[0],pid);
    }
    else{ if (waitpid(pid, &child_info, 0) == -1) {
                perror("waitpid");
  }
    }
  }
 int status;
  pid_t background_pid;
    while ((background_pid = waitpid(-1, &status, WNOHANG)) > 0) {
        printf("Finished background process %d\n", background_pid);
    }
  return child_info;
}
