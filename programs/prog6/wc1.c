#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int wc_single_file(char * filename);
int wc_multiple(char ** array, int argc);
int total = 0, count = 0;
int main(int argc, char* argv[]){
	if (argc<=1)
		{fprintf(stderr,"Usage: <program name> <file>,...<file>\n");
		return 1;}
	if (argc ==2 ){
		wc_single_file(argv[1]);
	}	
	else{ wc_multiple(argv, argc);
	}
	return 0;
}



int wc_single_file (char * filename){
	int fd, bytesread;
	char buf[4096];
	fd = open(filename, O_RDONLY);
	if (fd == -1){
		perror("open");
	}
	
	while (( bytesread = read(fd, buf, sizeof(buf))) > 0){
		for (int i = 0; i < bytesread; i++){
		if (buf[i] == '\n'){
		count++;
		
		}
		}
		}	
		if (bytesread == -1){
		perror("read");
		}
		close(fd);		
		printf("%d %s\n",count, filename);
		write(3, &count, sizeof(count));
		return 0;
		}

int wc_multiple(char ** array,int argc){	
        int fd, bytesread;	
        char buf[4096];
	for (int i = 1; i< argc; i++){
	count = bytesread = 0;
        fd = open(array[i], O_RDONLY);
        if (fd == -1){
                perror("open");
        }

        while (( bytesread = read(fd, buf, sizeof(buf))) > 0){
                for (int i = 0; i < bytesread; i++){
                if (buf[i] == '\n'){
                count++;
		total++;
                }
                }
                }
                if (bytesread == -1){
                perror("read");
                }
                close(fd);
                printf(" %d %s\n",count, array[i]);
	}
		printf(" %d total\n", total);
		return 0;
                }
		


























