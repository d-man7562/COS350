#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	pid_t pid = getpid();
if (argv[1] == NULL)
{
	argv[1] = "1";
	printf("%s %d\n", argv[1],pid);
	execvp(argv[0], argv);
}
else{

	char buf[12];
	int num = atoi(argv[1]);
	
	if (num > 4){
	printf("done\n");
	return 0;
	}
	
	num++;	
	sprintf(buf, "%d", num);
	argv[1] = buf;
	printf("%s %d\n", argv[1], pid);
	execvp(argv[0], argv);
}
}

