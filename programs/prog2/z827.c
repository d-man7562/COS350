#include <stdio.h>

int main(int argc, char**argv)
{
int in_fd, out_fd;
char buffer[100]

/*check input*/
if ( ac != 3 ){ 
fprintf( stderr, "usage: %s source destination\n", *av);
exit(1);
}
/*check if file opens*/
if ( (in_fd=open(av[1], O_RDONLY)) == -1 )
{
oops("Cannot open ", av[1]);
}

buffer = sprintf(buffer, ".z827",argv[1]);
/*create new file*/
if ( (out_fd=creat(buffer, COPYMODE)) == -1 )
{
oops("Cannot creat", buffer);
}


}
void oops(char *s1, char *s2)
{
fprintf(stderr,"Error: %s ", s1);
perror(s2);
exit(1);
}

