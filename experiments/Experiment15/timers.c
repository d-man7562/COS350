#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/time.h>

void rtimer_handler(){
struct timeval tv;
gettimeofday(&tv,NULL);

printf("REAL TIME is %ld.%ld\n",tv.tv_sec,tv.tv_usec);

}

int main(){

struct itimerval timer;
struct sigaction sa;
sa.sa_handler = &rtimer_handler;
timer.it_value.tv_sec = 0;
timer.it_interval.tv_sec = 0;
timer.it_value.tv_usec = 1000;
timer.it_interval.tv_usec = 1000;
sigaction(SIGALRM, &sa, NULL);

setitimer(ITIMER_REAL, &timer, NULL);

}

