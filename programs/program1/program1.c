#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{

int space = 8;

if (argc>1){
if (strcmp(argv[1], "-t") != 0){
   fprintf(stderr, "Error: Invalid flag\n");
   return 1;
}

if (argv[2] == NULL){
   fprintf(stderr, "Error: Argument must contain an integer\n");
   return 1;
}

if (strspn(argv[2], "0123456789") != strlen(argv[2])) {
   fprintf(stderr, "Error: Argument must be a positive integer\n");
   return 1;
}

space = atoi(argv[2]); 
}

int c; 

char tab= '\t';
int column = 0;

while ((c = getchar()) != EOF) {
if (c==tab){
int spaces = space - (column % space);
for (int i = 0; i< spaces; i++){
putchar(' ');
column++;
}
}
else{
putchar(c);
column++;
if (c == '\n'){
column = 0;
}

}
}
return 0;
}
