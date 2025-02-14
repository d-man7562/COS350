/*Domenic Mancuso*/
#include <stdio.h>

int recursive(int n)
{
int s = n;
printf("n =%d\n",s);
return (s * recursive(n-1));
}

int main(){
recursive(4);
return 0;
}
