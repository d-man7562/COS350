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

#define	DFL_PROMPT	">: "


int main()
{
  char CWD_BUF[1024];
  char	*cmdline, prompt[1100], **arglist;
  int	result;
  void	setup();

  if (getcwd(CWD_BUF, sizeof(CWD_BUF)) != NULL)
  {
    sprintf(prompt, "%s%s",CWD_BUF, DFL_PROMPT);
  }else{
    perror("CWD error");
  }
  
  setup();

  while ( (cmdline = next_cmd(prompt, stdin)) != NULL ){
    if ( (arglist = splitline(cmdline)) != NULL  ){
      //getenv()
      if (strcmp("cd",arglist[0]) == 0){
        printf("cd\n");
        if (arglist[1] == NULL){
          if (chdir("HOME") != 0)
          perror("Error changing to home directory\n");
        }
        else{
          char * next_dir = arglist[1]; 
          chdir(next_dir);
        }

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

