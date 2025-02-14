Domenic Mancuso
For this code snippet I used a factorial expression. 
This function calls itself 262028 times! After that, it returns a segmentation fault.
The exact error message returned is the following:
[1]    16053 segmentation fault  ./a.out
The terminal commands used (on my macbook) were:
touch recursion.c
gcc recursion.c
./a.out
touch README.txt
for the C file I used std input,
printf to count number of iterations
and whatever generic boilerplate C code I used thereafter. 
