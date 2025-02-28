
No I cannot read my file when I take away my read permissions in the User section. I can read my file when the 
octal digit that represents the first digit of the 'modes' is equal to 1, 3, or 7. This is because 'read' for user would 
require the first bit to be on. It will look like this: 00000001 - as long as the LSB is turned on, User can read the file!

Access of a file depends on your definition of access. I am able to write to a file when I am not allowed to read it, as long as 
I have write permission (I can use an 'echo x  >> fn'  to append to filename fn. 

An access control list that for an entry contains 256*3 ON rwx bits will have full permission for everyone on the system to access.

In this experiment I again learned the usefulness of binary in Unix systems.  


Script started on 2025-02-28 10:14:05-0500
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ cat filenmae[K[Ka[K[K[Ka[Kname.txt 
cat: filename.txt: Permission denied
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ ls -l
total 4
--wx---rwx 1 domenic.mancuso domenic.mancuso 20 Feb 28 10:07 filename.txt
-rw------- 1 domenic.mancuso domenic.mancuso  0 Feb 28 10:14 README.txt
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ chj[Kmod filename.txt [1@7[1@0[1@7[1@ 
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ s[Kls -l
total 4
-rwx---rwx 1 domenic.mancuso domenic.mancuso 20 Feb 28 10:07 filename.txt
-rw------- 1 domenic.mancuso domenic.mancuso  0 Feb 28 10:14 README.txt
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ ls -lchmod 707 filename.txt ls -l[K[Kcat E[KE[KR[Kt[Kfilename.txt 
ASDnASDNASONDjASDAN
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ cat filename.txt ls -l[Kchmod 707 filename.txt [1P[C[1@7
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ chmod 777 filename.txt [6Pat[C[C[C[C[C[C[C[C[C[C[C[C[C[Cls -l[Kcat filename.txt ls -l[K
total 4
-rwxrwxrwx 1 domenic.mancuso domenic.mancuso 20 Feb 28 10:07 filename.txt
-rw------- 1 domenic.mancuso domenic.mancuso  0 Feb 28 10:14 README.txt
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ ls -lchmod 777 filename.txt [6Pat[C[C[C[C[C[C[C[C[C[C[C[C[C[C[6@hmod 777[C[C[C[C[C[C[C[C[C[C[C[C[C[C[6Pat[C[C[C[C[C[C[C[C[C[C[C[C[C[C
ASDnASDNASONDjASDAN
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ cat filename.txt ls -l[Kchmod 777 filename.txt [C[1P[1@2[C[1P[1@0
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ chmod 207 filename.txt [6Pat[C[C[C[C[C[C[C[C[C[C[C[C[C[Cls -l[K
total 4
--w----rwx 1 domenic.mancuso domenic.mancuso 20 Feb 28 10:07 filename.txt
-rw------- 1 domenic.mancuso domenic.mancuso  0 Feb 28 10:14 README.txt
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ ls -lchmod 207 filename.txt [6Pat[C[C[C[C[C[C[C[C[C[C[C[C[C[C
cat: filename.txt: Permission denied
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ echo asdas[K[K[K[K[Knewwrite> filename[C.txte[C[C[C[C[K[1@ 
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ catfish [K [K[K[K[K[K[K[K[Kecho newwrite > filename.txt[11Pcat filename.txt ls -l[Kchmod 207 filename.txt [1P[1@7
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ chmod 707 filename.txt echo newwrite > filename.txt[11Pcat filename.txt \[K
newwrite
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ chmod 507 filename.txt 
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ ls -l
total 8
-r-x---rwx 1 domenic.mancuso domenic.mancuso    9 Feb 28 10:15 filename.txt
-rw------- 1 domenic.mancuso domenic.mancuso 3281 Feb 28 10:15 README.txt
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ cat filename.txt 
newwrite
domenic.mancuso@honeybee:~/COS350/experiments/Experiment11$ exit
^X
Script done on 2025-02-28 10:15:43-0500
