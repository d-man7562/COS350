#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <string.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int total = 0;

void *thread_func(void * arg){
 	char * filename = (char*) arg;
	char buf[4096];
	int count = 0;
       	int fd, bytesread;
  	fd = open(filename, O_RDONLY);
	if (fd<0){ perror("open"); return NULL;}
	while (( bytesread = read(fd, buf, sizeof(buf))) > 0){
                for (int i = 0; i < bytesread; i++){
                if (buf[i] == '\n'){
                count++;	
		}
		}
	}
               pthread_mutex_lock(&mutex);
	       	total+= count;
		pthread_mutex_unlock(&mutex);



close(fd);
printf("%d %s\n",count, filename);
return NULL;
}

int main(int argc, char * argv[]){
if (argc<=1){
	perror("usage: lc3 <filesname(s)>");
	return 0;
}
	pthread_t t[argc-1];
for (int i = 1; i < argc; i++){
	
	pthread_create(&t[i-1], NULL,thread_func, argv[i]);
}
	for (int i = 0; i < argc-1; i++){
	pthread_join(t[i], NULL);


}

printf("%d total\n",total);
pthread_mutex_destroy(&mutex);

return 0;
}
