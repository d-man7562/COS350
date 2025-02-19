#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aux(const void* a, const void* b)
{

const char * str1 = *(const char**)a;
const char * str2 = *(const char**)b;
return strlen(str1)-strlen(str2);
}

int main(int argc, char** argv)
{

qsort(argv, argc, sizeof(char*), aux);
for (int i=0; i<argc; i++)
{
printf("%s ", argv[i]);
}
return 0;
}

