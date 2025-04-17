/**  smsh1.c  small-shell version 1
 **		first really useful version after prompting shell
 **		this one parses the command line into strings
 **		uses fork, exec, wait, and ignores signals
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "smsh.h"
#include <string.h>
#include <errno.h>

#define	DFL_PROMPT	" (smsh) "


int main()
{
  char CWD_BUF[1024];
  char	*cmdline, prompt[1100], **arglist;
  int	result;
  void	setup();

  
  setup();
  if (getcwd(CWD_BUF, sizeof(CWD_BUF)) != NULL)
  {
    sprintf(prompt, "%s%s",CWD_BUF, DFL_PROMPT);
  }else{
    perror("CWD error");
  }
  
  while ( (cmdline = next_cmd(prompt, stdin)) != NULL ){
    if ( (arglist = splitline(cmdline)) != NULL  ){
   
      if (strcmp("cd",arglist[0]) == 0){

        if (arglist[1] == NULL){
          char * env = getenv("HOME");
          if (env==NULL){
            perror("Error: HOME environment variable is not set");
          }else{
          if (chdir(env) != 0)
          perror("Error changing to home directory\n");
        }
        }
        else{
          
         if (chdir(arglist[1]) != 0) {
            perror("Error changing directory");
        }
        }

        freelist(arglist);
        free(cmdline);
        if (getcwd(CWD_BUF, sizeof(CWD_BUF)) != NULL)
  {
      sprintf(prompt, "%s%s",CWD_BUF, DFL_PROMPT);
    }else{
    perror("CWD error");
    }
        continue;
        
        }
      

      result = execute(arglist);
      freelist(arglist);
    }
    free(cmdline);
  }
  
  return 0;
}

void setup()
/*
 * purpose: initialize shell
 * returns: nothing. calls fatal() if trouble
 */
{
  signal(SIGINT,  SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
}

void fatal(char *s1, char *s2, int n)
{
  fprintf(stderr,"Error: %s,%s\n", s1, s2);
  exit(n);
}

