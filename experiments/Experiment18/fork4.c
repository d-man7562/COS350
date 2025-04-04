#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    
    
printf("count: 1 -- pid:%d \n", getpid());
int parent_pid = getpid();
fork();
for(int i=2; i<6; i++){
if (getpid()!= parent_pid){
printf("count: %d -- pid: %d\n",i,getpid());
/* Linked List sort of thing going on here */
parent_pid = getpid();
fork();

}
usleep(1);
}
int status;
wait(&status);
return 0;
}
