#include <stdio.h>
#include <stdlib.h>

void tabular(int a);

int main()
{

int a = 4;
for (int i=0; i<8; i++)
{

tabular(a);
a = a+4;
}
return 0;
}


void tabular(int a)
{
char *array[1000];
int size = sizeof(array)/sizeof(char*);
int bytes = a;
for (int i=0; i<size; i++)
{
	array[i] = malloc(bytes);
}

long diff = (long)array[size-1] - (long)array[0];
printf("\nSize of malloc: %d bytes\n", bytes);
printf("Address of first block (array[0]): %p\n", (void*)array[0]);
printf("Address of last block (array[999]): %p\n", (void*)array[size-1]);
printf("Difference between array 0 and array %d: %ld\n",size-1, diff);


printf("\nArray element addresses:\n");
printf("&array[0]: %p\n", (void*)&array[0]);
printf("&array[999]: %p\n", (void*)&array[999]);
printf("Array element difference: %ld\n", (long)&array[999] - (long)&array[0]);

for (int i=0; i<size; i++)
{
	free(array[i]);
}

}

