Script started on 2025-04-17 13:43:19-0400
WELCOME BACK DOMENIC!!
domenic.mancuso@honeybee:~/COS350/programs/p5new$: smsh1
/home/domenic.mancuso/COS350/programs/p5new (smsh) ls
execute.c  execute.o  Makefile	README.txt  sample  smsh1  smsh1.c  smsh1.o  smsh.h  splitline.c  splitline.o
/home/domenic.mancuso/COS350/programs/p5new (smsh) date
Thu Apr 17 13:43:38 EDT 2025
/home/domenic.mancuso/COS350/programs/p5new (smsh) bougs   gus
cannot execute command: No such file or directory
/home/domenic.mancuso/COS350/programs/p5new (smsh) exit
domenic.mancuso@honeybee:~/COS350/programs/p5new$: smsh1
/home/domenic.mancuso/COS350/programs/p5new (smsh) exit 7
domenic.mancuso@honeybee:~/COS350/programs/p5new$: smsh1[K[K[K[K[Kecho $?
7
domenic.mancuso@honeybee:~/COS350/programs/p5new$: smsh1
/home/domenic.mancuso/COS350/programs/p5new (smsh) pwd
/home/domenic.mancuso/COS350/programs/p5new
/home/domenic.mancuso/COS350/programs/p5new (smsh) cd ..
/home/domenic.mancuso/COS350/programs (smsh) pwd
/home/domenic.mancuso/COS350/programs
/home/domenic.mancuso/COS350/programs (smsh) cd /usr/bin
/usr/bin (smsh) pwd
/usr/bin
/usr/bin (smsh) cd boug  gus
Error changing directory: No such file or directory
/usr/bin (smsh) pwd
/usr/bin
/usr/bin (smsh) cd
/home/domenic.mancuso (smsh) pwd
/home/domenic.mancuso
/home/domenic.mancuso (smsh) sleep 1- 0 &
In background: sleep 4173
/home/domenic.mancuso (smsh) ps -l 
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S 988972 3283  3282  0  80   0 -  3309 wait   pts/9    00:00:00 bash
0 S 988972 3612  3283  0  80   0 -  1130 wait   pts/9    00:00:00 smsh1
0 S 988972 4173  3612  0  80   0 -  1869 hrtime pts/9    00:00:00 sleep
0 R 988972 4198  3612  0  80   0 -  7230 -      pts/9    00:00:00 ps
Finished background process 4173
/home/domenic.mancuso (smsh) ps -l
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S 988972 3283  3282  0  80   0 -  3309 wait   pts/9    00:00:00 bash
0 S 988972 3612  3283  0  80   0 -  1130 wait   pts/9    00:00:00 smsh1
0 R 988972 4272  3612  0  80   0 -  7230 -      pts/9    00:00:00 ps
/home/domenic.mancuso (smsh) sleep t 10 &^[[D^[[D^[[D                3 &
In background: sleep 4391
/home/domenic.mancuso (smsh) ps -l
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S 988972 3283  3282  0  80   0 -  3309 wait   pts/9    00:00:00 bash
0 S 988972 3612  3283  0  80   0 -  1130 wait   pts/9    00:00:00 smsh1
0 S 988972 4391  3612  0  80   0 -  1869 hrtime pts/9    00:00:00 sleep
0 R 988972 4413  3612  0  80   0 -  7230 -      pts/9    00:00:00 ps
/home/domenic.mancuso (smsh) ps -l
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S 988972 3283  3282  0  80   0 -  3309 wait   pts/9    00:00:00 bash
0 S 988972 3612  3283  0  80   0 -  1130 wait   pts/9    00:00:00 smsh1
0 Z 988972 4391  3612  0  80   0 -     0 -      pts/9    00:00:00 sleep <defunct>
0 R 988972 4428  3612  0  80   0 -  7230 -      pts/9    00:00:00 ps
Finished background process 4391
/home/domenic.mancuso (smsh) ps -l
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S 988972 3283  3282  0  80   0 -  3309 wait   pts/9    00:00:00 bash
0 S 988972 3612  3283  0  80   0 -  1130 wait   pts/9    00:00:00 smsh1
0 R 988972 4456  3612  0  80   0 -  7230 -      pts/9    00:00:00 ps
/home/domenic.mancuso (smsh) exit
domenic.mancuso@honeybee:~/COS350/programs/p5new$: exit
exit

Script done on 2025-04-17 13:46:14-0400
