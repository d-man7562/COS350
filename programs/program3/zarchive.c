#include <stdio.h>

void archive(char* fn, char * archivename);
void unarchive(char* fn);

int main(int argc, char**argv) {

char* archivename;

if (argv[3] !=NULL) {
archivename = argv[3];
}

/*Check that first argument is a character, x or c. If not,
throw an error. */
/*archive*/
if (strcmp(argv[1],"c") == 0) {
archive(argv[2], archivename);
}

/*extract*/
if (strcmp(argv[1],"x") == 0) {
unarchive(argv[2]);
}
else{
perror("Usage: zarchive [x,c] filename");
}

return 0;
}

void archive(char * fn,char * archivename) { 
if (fn == NULL){
perror("Error: missing filename");
return 1;
}
if (archivename == NULL)
printf("Archived file name has not been provided. Please enter name of archived file:\n");
archivename = scanf(stdin);
size_t len = strlen(filename);
if (len >= 2 && filename[len-2] == '.' && filename[len-1] == 'z') {
}

}


 


/* read file to archive
check if argv3 is null
