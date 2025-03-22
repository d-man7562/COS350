// ask user for password with no echoing typing
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

char *get_passwd(struct termios x);

int main()
{
  struct termios info;

  tcgetattr(0,&info);         /* get attribs   */
  info.c_lflag &= ~ECHO ;      /* turn off echo bit   */
  tcsetattr(0,TCSANOW,&info);   /* set attribs */

  printf("\npassword: ");
  char *passwd = get_passwd(info);
  printf("\nyou entered: %s\n\n", passwd);

  // turn the echo bit back on before exiting !!!
  tcgetattr(0,&info);         /* get attribs   */
  info.c_lflag |= ECHO ;       /* turn on echo bit   */
  tcsetattr(0,TCSANOW,&info);   /* set attribs */
}


#define BUFSIZE 100
char buf[BUFSIZE];

char *get_passwd(struct termios x)
{
  tcgetattr(0,&x);
  int c, len = 0;
  while ((c = getchar()) != EOF && c != '\n')
    {
      buf[len++] = c;
      if (len == BUFSIZE-1)
	break;
 x.c_lflag &= ECHO ;      /* turn on echo bit   */
 tcsetattr(0,TCSANOW,&x);   
 printf("*");
 x.c_lflag &= ~ECHO ;      /* turn off echo bit   */
 tcsetattr(0,TCSANOW,&x);   

    }
  buf[len] = 0;    // terminate string
  putchar('\n');   // output the newline
  return buf;
}


