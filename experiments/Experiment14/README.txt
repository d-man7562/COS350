Script started on 2025-03-22 20:47:25-0400
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ cat exp14.c
#include <stdio.h>

int main(){
	while (1);
}
	


domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ex[14[K[K[Kp14 &
[1] 3859
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kill -2 3950[K9
bash: kill: (3959) - No such process
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kill -2 3959[K[K[K9[K859
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 3910 pts/6    00:00:00 ps
[1]+  Interrupt               exp14
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ echo this is interr[K[K[K[K[K[K[K from [K[K[K[K[K[K from[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[Kpskill -2 3859ps[K[Kkill -18 exp14[K[K[K[K[K3859
bash: kill: (3859) - No such process
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kill -18 3859[K[K[K[Kexcp[K[Kp14
bash: kill: exp14: arguments must be process or job IDs
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kill -18 exp14[K[K[K[K[K1
bash: kill: (1) - Operation not permitted
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4335 pts/6    00:00:00 ps
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ exp14 &
[1] 4352
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4352 pts/6    00:00:20 exp14
 4394 pts/6    00:00:00 ps
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kill -8[K[K[K[K[K[K[Kman sig[K[K[K7 n[Ksignal
[?1049h[22;0;0t[?1h=SIGNAL(7)                  Linux Programmer's Manual                 SIGNAL(7)[m
[m
[1mNAME[0m[m
       signal - overview of signals[m
[m
[1mDESCRIPTION[0m[m
       Linux  supports both POSIX reliable signals (hereinafter "standard sig‐[m
       nals") and POSIX real-time signals.[m
[m
   [1mSignal[0m [1mdispositions[0m[m
       Each signal has a current [4mdisposition[24m, which determines how the process[m
       behaves when it is delivered the signal.[m
[m
       The  entries  in  the  "Action"  column of the tables below specify the[m
       default disposition for each signal, as follows:[m
[m
       Term   Default action is to terminate the process.[m
[m
       Ign    Default action is to ignore the signal.[m
[m
       Core   Default action is to terminate the process and  dump  core  (see[m
              [1mcore[0m(5)).[m
[m
[7m Manual page signal(7) line 1 (press h for help or q to quit)[27m[K[K       Stop   Default action is to stop the process.[m
[7m Manual page signal(7) line 2 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 3 (press h for help or q to quit)[27m[K[K       Cont   Default  action  is  to  continue the process if it is currently[m
[7m Manual page signal(7) line 4 (press h for help or q to quit)[27m[K[K              stopped.[m
[7m Manual page signal(7) line 5 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 6 (press h for help or q to quit)[27m[K[K       A process can change the disposition of a signal using [1msigaction[0m(2)  or[m
[7m Manual page signal(7) line 7 (press h for help or q to quit)[27m[K[K       [1msignal[0m(2).   (The  latter  is  less portable when establishing a signal[m
[7m Manual page signal(7) line 8 (press h for help or q to quit)[27m[K[K       handler; see [1msignal[0m(2) for  details.)   Using  these  system  calls,  a[m
[7m Manual page signal(7) line 9 (press h for help or q to quit)[27m[K[K       process  can  elect one of the following behaviors to occur on delivery[m
[7m Manual page signal(7) line 10 (press h for help or q to quit)[27m[K[K       of the signal: perform the default action; ignore the signal; or  catch[m
[7m Manual page signal(7) line 11 (press h for help or q to quit)[27m[K[K       the signal with a [4msignal[24m [4mhandler[24m, a programmer-defined function that is[m
[7m Manual page signal(7) line 12 (press h for help or q to quit)[27m[K[K       automatically invoked when the signal is delivered.  (By  default,  the[m
[7m Manual page signal(7) line 13 (press h for help or q to quit)[27m[K[K       signal  handler is invoked on the normal process stack.  It is possible[m
[7m Manual page signal(7) line 14 (press h for help or q to quit)[27m[K[K       to arrange that the signal handler uses an alternate stack; see [1msigalt‐[0m[m
[7m Manual page signal(7) line 15 (press h for help or q to quit)[27m[K[K       [1mstack[0m(2)  for  a discussion of how to do this and when it might be use‐[m
[7m Manual page signal(7) line 16 (press h for help or q to quit)[27m[K[K       ful.)[m
[7m Manual page signal(7) line 17 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 18 (press h for help or q to quit)[27m[K[K       The signal disposition is a per-process attribute: in  a  multithreaded[m
[7m Manual page signal(7) line 19 (press h for help or q to quit)[27m[K[K       application, the disposition of a particular signal is the same for all[m
[7m Manual page signal(7) line 20 (press h for help or q to quit)[27m[K[K       threads.[m
[7m Manual page signal(7) line 21 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 22 (press h for help or q to quit)[27m[K[K       A child created via [1mfork[0m(2) inherits a copy of its parent's signal dis‐[m
[7m Manual page signal(7) line 23 (press h for help or q to quit)[27m[K[K       positions.   During  an  [1mexecve[0m(2), the dispositions of handled signals[m
[7m Manual page signal(7) line 24 (press h for help or q to quit)[27m[K[K       are reset to the default; the dispositions of ignored signals are  left[m
[7m Manual page signal(7) line 25 (press h for help or q to quit)[27m[K[K       unchanged.[m
[7m Manual page signal(7) line 26 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 27 (press h for help or q to quit)[27m[K[K   [1mSending[0m [1ma[0m [1msignal[0m[m
[7m Manual page signal(7) line 28 (press h for help or q to quit)[27m[K[K       The  following  system  calls and library functions allow the caller to[m
[7m Manual page signal(7) line 29 (press h for help or q to quit)[27m[K[K       send a signal:[m
[7m Manual page signal(7) line 30 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 31 (press h for help or q to quit)[27m[K[K       [1mraise[0m(3)        Sends a signal to the calling thread.[m
[7m Manual page signal(7) line 32 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 33 (press h for help or q to quit)[27m[K[K       [1mkill[0m(2)         Sends a signal to a specified process, to  all  members[m
[7m Manual page signal(7) line 34 (press h for help or q to quit)[27m[K[K                       of  a  specified  process group, or to all processes on[m
[7m Manual page signal(7) line 35 (press h for help or q to quit)[27m[K[K                       the system.[m
[7m Manual page signal(7) line 36 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 37 (press h for help or q to quit)[27m[K[K       [1mkillpg[0m(3)       Sends a signal to all of the  members  of  a  specified[m
[7m Manual page signal(7) line 38 (press h for help or q to quit)[27m[K[K                       process group.[m
[7m Manual page signal(7) line 39 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 40 (press h for help or q to quit)[27m[K[K       [1mpthread_kill[0m(3) Sends  a signal to a specified POSIX thread in the same[m
[7m Manual page signal(7) line 41 (press h for help or q to quit)[27m[K[K                       process as the caller.[m
[7m Manual page signal(7) line 42 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 43 (press h for help or q to quit)[27m[K[K       [1mtgkill[0m(2)       Sends a signal to a specified thread within a  specific[m
[7m Manual page signal(7) line 44 (press h for help or q to quit)[27m[K[K                       process.   (This  is  the system call used to implement[m
[7m Manual page signal(7) line 45 (press h for help or q to quit)[27m[K[K                       [1mpthread_kill[0m(3).)[m
[7m Manual page signal(7) line 46 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 47 (press h for help or q to quit)[27m[K[K       [1msigqueue[0m(3)     Sends a real-time signal with accompanying  data  to  a[m
[7m Manual page signal(7) line 48 (press h for help or q to quit)[27m[K[K                       specified process.[m
[7m Manual page signal(7) line 49 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 50 (press h for help or q to quit)[27m[K[K   [1mWaiting[0m [1mfor[0m [1ma[0m [1msignal[0m [1mto[0m [1mbe[0m [1mcaught[0m[m
[7m Manual page signal(7) line 51 (press h for help or q to quit)[27m[K[K       The  following system calls suspend execution of the calling process or[m
[7m Manual page signal(7) line 52 (press h for help or q to quit)[27m[K[K       thread until a signal is caught (or an unhandled signal terminates  the[m
[7m Manual page signal(7) line 53 (press h for help or q to quit)[27m[K[K       process):[m
[7m Manual page signal(7) line 54 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 55 (press h for help or q to quit)[27m[K[K       [1mpause[0m(2)        Suspends execution until any signal is caught.[m
[7m Manual page signal(7) line 56 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 57 (press h for help or q to quit)[27m[K[K       [1msigsuspend[0m(2)   Temporarily  changes  the  signal  mask (see below) and[m
[7m Manual page signal(7) line 58 (press h for help or q to quit)[27m[K[K                       suspends execution until one of the unmasked signals is[m
[7m Manual page signal(7) line 59 (press h for help or q to quit)[27m[K[K                       caught.[m
[7m Manual page signal(7) line 60 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 61 (press h for help or q to quit)[27m[K[K   [1mSynchronously[0m [1maccepting[0m [1ma[0m [1msignal[0m[m
[7m Manual page signal(7) line 62 (press h for help or q to quit)[27m[K[K       Rather  than  asynchronously catching a signal via a signal handler, it[m
[7m Manual page signal(7) line 63 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 62 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       process group.[m
[24;1H[K[7m Manual page signal(7) line 61 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mkillpg[0m(3)       Sends a signal to all of the  members  of  a  specified[m
[24;1H[K[7m Manual page signal(7) line 60 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 59 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       the system.[m
[24;1H[K[7m Manual page signal(7) line 58 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       of  a  specified  process group, or to all processes on[m
[24;1H[K[7m Manual page signal(7) line 57 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mkill[0m(2)         Sends a signal to a specified process, to  all  members[m
[24;1H[K[7m Manual page signal(7) line 56 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 57 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1msigsuspend[0m(2)   Temporarily  changes  the  signal  mask (see below) and[m
[7m Manual page signal(7) line 58 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                       suspends execution until one of the unmasked signals is[m
[7m Manual page signal(7) line 59 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                       caught.[m
[7m Manual page signal(7) line 60 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 61 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K   [1mSynchronously[0m [1maccepting[0m [1ma[0m [1msignal[0m[m
[7m Manual page signal(7) line 62 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       Rather  than  asynchronously catching a signal via a signal handler, it[m
[7m Manual page signal(7) line 63 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       is possible to synchronously accept the signal, that is, to block  exe‐[m
[7m Manual page signal(7) line 64 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       cution until the signal is delivered, at which point the kernel returns[m
[7m Manual page signal(7) line 65 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       information about the signal to the caller.  There are two general ways[m
[7m Manual page signal(7) line 66 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       to do this:[m
[7m Manual page signal(7) line 67 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 68 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       * [1msigwaitinfo[0m(2),  [1msigtimedwait[0m(2),  and  [1msigwait[0m(3)  suspend execution[m
[7m Manual page signal(7) line 69 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K         until one of the signals in a specified set is  delivered.   Each  of[m
[7m Manual page signal(7) line 70 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K         these calls returns information about the delivered signal.[m
[7m Manual page signal(7) line 71 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 72 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       * [1msignalfd[0m(2) returns a file descriptor that can be used to read infor‐[m
[7m Manual page signal(7) line 73 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K         mation about signals that are delivered to the caller.  Each  [1mread[0m(2)[m
[7m Manual page signal(7) line 74 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K         from  this file descriptor blocks until one of the signals in the set[m
[7m Manual page signal(7) line 75 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K         specified in the [1msignalfd[0m(2) call is delivered to  the  caller.   The[m
[7m Manual page signal(7) line 76 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K         buffer  returned  by [1mread[0m(2) contains a structure describing the sig‐[m
[7m Manual page signal(7) line 77 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K         nal.[m
[7m Manual page signal(7) line 78 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 79 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K   [1mSignal[0m [1mmask[0m [1mand[0m [1mpending[0m [1msignals[0m[m
[7m Manual page signal(7) line 80 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       A signal may be [4mblocked[24m, which means that  it  will  not  be  delivered[m
[7m Manual page signal(7) line 81 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       until it is later unblocked.  Between the time when it is generated and[m
[7m Manual page signal(7) line 82 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       when it is delivered a signal is said to be [4mpending[24m.[m
[7m Manual page signal(7) line 83 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 84 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       Each thread in a process has an independent [4msignal[24m  [4mmask[24m,  which  indi‐[m
[7m Manual page signal(7) line 85 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       cates  the  set  of  signals  that the thread is currently blocking.  A[m
[7m Manual page signal(7) line 86 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       thread can manipulate its signal mask using [1mpthread_sigmask[0m(3).   In  a[m
[7m Manual page signal(7) line 87 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       traditional  single-threaded application, [1msigprocmask[0m(2) can be used to[m
[7m Manual page signal(7) line 88 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       manipulate the signal mask.[m
[7m Manual page signal(7) line 89 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 90 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       A child created via [1mfork[0m(2) inherits a  copy  of  its  parent's  signal[m
[7m Manual page signal(7) line 91 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       mask; the signal mask is preserved across [1mexecve[0m(2).[m
[7m Manual page signal(7) line 92 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 93 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       A  signal  may be generated (and thus pending) for a process as a whole[m
[7m Manual page signal(7) line 94 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       (e.g., when sent using [1mkill[0m(2)) or for a specific thread (e.g., certain[m
[7m Manual page signal(7) line 95 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       signals, such as [1mSIGSEGV[0m and [1mSIGFPE[0m, generated as a consequence of exe‐[m
[7m Manual page signal(7) line 96 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       cuting a specific machine-language instruction are thread directed,  as[m
[7m Manual page signal(7) line 97 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       are  signals  targeted  at a specific thread using [1mpthread_kill[0m(3)).  A[m
[7m Manual page signal(7) line 98 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       process-directed signal may be delivered to any one of the threads that[m
[7m Manual page signal(7) line 99 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       does  not  currently  have the signal blocked.  If more than one of the[m
[7m Manual page signal(7) line 100 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       threads has the signal unblocked, then the kernel chooses an  arbitrary[m
[7m Manual page signal(7) line 101 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       thread to which to deliver the signal.[m
[7m Manual page signal(7) line 102 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 103 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       A  thread  can  obtain the set of signals that it currently has pending[m
[7m Manual page signal(7) line 104 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       using [1msigpending[0m(2).  This set will consist of the union of the set  of[m
[7m Manual page signal(7) line 105 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       pending process-directed signals and the set of signals pending for the[m
[7m Manual page signal(7) line 106 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       calling thread.[m
[7m Manual page signal(7) line 107 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 108 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       A child created via [1mfork[0m(2) initially has an empty pending signal  set;[m
[7m Manual page signal(7) line 109 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       the pending signal set is preserved across an [1mexecve[0m(2).[m
[7m Manual page signal(7) line 110 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 111 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K   [1mStandard[0m [1msignals[0m[m
[7m Manual page signal(7) line 112 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       Linux  supports the standard signals listed below.  Several signal num‐[m
[7m Manual page signal(7) line 113 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       bers are architecture-dependent, as indicated in  the  "Value"  column.[m
[7m Manual page signal(7) line 114 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       (Where three values are given, the first one is usually valid for alpha[m
[7m Manual page signal(7) line 115 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       and sparc, the middle one for x86, arm, and most  other  architectures,[m
[7m Manual page signal(7) line 116 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       and  the  last one for mips.  (Values for parisc are [4mnot[24m shown; see the[m
[7m Manual page signal(7) line 117 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       Linux kernel source for signal numbering on that architecture.)  A dash[m
[7m Manual page signal(7) line 118 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       (-) denotes that a signal is absent on the corresponding architecture.[m
[7m Manual page signal(7) line 119 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 120 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       First the signals described in the original POSIX.1-1990 standard.[m
[7m Manual page signal(7) line 121 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 122 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       Signal     Value     Action   Comment[m
[7m Manual page signal(7) line 123 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       ──────────────────────────────────────────────────────────────────────[m
[7m Manual page signal(7) line 124 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGHUP[0m        1       Term    Hangup detected on controlling terminal[m
[7m Manual page signal(7) line 125 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                                     or death of controlling process[m
[7m Manual page signal(7) line 126 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGINT[0m        2       Term    Interrupt from keyboard[m
[7m Manual page signal(7) line 127 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGQUIT[0m       3       Core    Quit from keyboard[m
[7m Manual page signal(7) line 128 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGILL[0m        4       Core    Illegal Instruction[m
[7m Manual page signal(7) line 129 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGABRT[0m       6       Core    Abort signal from [1mabort[0m(3)[m
[7m Manual page signal(7) line 130 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGFPE[0m        8       Core    Floating-point exception[m
[7m Manual page signal(7) line 131 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGKILL[0m       9       Term    Kill signal[m
[7m Manual page signal(7) line 132 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGSEGV[0m      11       Core    Invalid memory reference[m
[7m Manual page signal(7) line 133 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGPIPE[0m      13       Term    Broken pipe: write to pipe with no[m
[7m Manual page signal(7) line 134 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                                     readers; see [1mpipe[0m(7)[m
[7m Manual page signal(7) line 135 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGALRM[0m      14       Term    Timer signal from [1malarm[0m(2)[m
[7m Manual page signal(7) line 136 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTERM[0m      15       Term    Termination signal[m
[7m Manual page signal(7) line 137 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGUSR1[0m   30,10,16    Term    User-defined signal 1[m
[7m Manual page signal(7) line 138 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGUSR2[0m   31,12,17    Term    User-defined signal 2[m
[7m Manual page signal(7) line 139 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGCHLD[0m   20,17,18    Ign     Child stopped or terminated[m
[7m Manual page signal(7) line 140 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGCONT[0m   19,18,25    Cont    Continue if stopped[m
[7m Manual page signal(7) line 141 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGSTOP[0m   17,19,23    Stop    Stop process[m
[7m Manual page signal(7) line 142 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTSTP[0m   18,20,24    Stop    Stop typed at terminal[m
[7m Manual page signal(7) line 143 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTTIN[0m   21,21,26    Stop    Terminal input for background process[m
[7m Manual page signal(7) line 144 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTTOU[0m   22,22,27    Stop    Terminal output for background process[m
[7m Manual page signal(7) line 145 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 146 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       The signals [1mSIGKILL[0m and [1mSIGSTOP[0m cannot be caught, blocked, or ignored.[m
[7m Manual page signal(7) line 147 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 148 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mSIGHUP[0m        1       Term    Hangup detected on controlling terminal[m
[24;1H[K[7m Manual page signal(7) line 147 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       ──────────────────────────────────────────────────────────────────────[m
[24;1H[K[7m Manual page signal(7) line 146 (press h for help or q to quit)[27m[K[K[7m Manual page signal(7) line 146 (press h for help or q to quit)[27m[K[K[?1l>[?1049l[23;0;0tdomenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ echo ^C^?[K[K^V[K[K[K[K[K[Kman 7 signal
[?1049h[22;0;0t[?1h=SIGNAL(7)                  Linux Programmer's Manual                 SIGNAL(7)[m
[m
[1mNAME[0m[m
       signal - overview of signals[m
[m
[1mDESCRIPTION[0m[m
       Linux  supports both POSIX reliable signals (hereinafter "standard sig‐[m
       nals") and POSIX real-time signals.[m
[m
   [1mSignal[0m [1mdispositions[0m[m
       Each signal has a current [4mdisposition[24m, which determines how the process[m
       behaves when it is delivered the signal.[m
[m
       The  entries  in  the  "Action"  column of the tables below specify the[m
       default disposition for each signal, as follows:[m
[m
       Term   Default action is to terminate the process.[m
[m
       Ign    Default action is to ignore the signal.[m
[m
       Core   Default action is to terminate the process and  dump  core  (see[m
              [1mcore[0m(5)).[m
[m
[7m Manual page signal(7) line 1 (press h for help or q to quit)[27m[K[K       Stop   Default action is to stop the process.[m
[7m Manual page signal(7) line 2 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 3 (press h for help or q to quit)[27m[K[K       Cont   Default  action  is  to  continue the process if it is currently[m
              stopped.[m
[m
       A process can change the disposition of a signal using [1msigaction[0m(2)  or[m
       [1msignal[0m(2).   (The  latter  is  less portable when establishing a signal[m
       handler; see [1msignal[0m(2) for  details.)   Using  these  system  calls,  a[m
       process  can  elect one of the following behaviors to occur on delivery[m
       of the signal: perform the default action; ignore the signal; or  catch[m
       the signal with a [4msignal[24m [4mhandler[24m, a programmer-defined function that is[m
       automatically invoked when the signal is delivered.  (By  default,  the[m
       signal  handler is invoked on the normal process stack.  It is possible[m
       to arrange that the signal handler uses an alternate stack; see [1msigalt‐[0m[m
       [1mstack[0m(2)  for  a discussion of how to do this and when it might be use‐[m
       ful.)[m
[m
       The signal disposition is a per-process attribute: in  a  multithreaded[m
       application, the disposition of a particular signal is the same for all[m
       threads.[m
[m
       A child created via [1mfork[0m(2) inherits a copy of its parent's signal dis‐[m
       positions.   During  an  [1mexecve[0m(2), the dispositions of handled signals[m
       are reset to the default; the dispositions of ignored signals are  left[m
       unchanged.[m
[7m Manual page signal(7) line 26 (press h for help or q to quit)[27m[K[K[m
   [1mSending[0m [1ma[0m [1msignal[0m[m
       The  following  system  calls and library functions allow the caller to[m
       send a signal:[m
[m
       [1mraise[0m(3)        Sends a signal to the calling thread.[m
[m
       [1mkill[0m(2)         Sends a signal to a specified process, to  all  members[m
                       of  a  specified  process group, or to all processes on[m
                       the system.[m
[m
       [1mkillpg[0m(3)       Sends a signal to all of the  members  of  a  specified[m
                       process group.[m
[m
       [1mpthread_kill[0m(3) Sends  a signal to a specified POSIX thread in the same[m
                       process as the caller.[m
[m
       [1mtgkill[0m(2)       Sends a signal to a specified thread within a  specific[m
                       process.   (This  is  the system call used to implement[m
                       [1mpthread_kill[0m(3).)[m
[m
       [1msigqueue[0m(3)     Sends a real-time signal with accompanying  data  to  a[m
                       specified process.[m
[7m Manual page signal(7) line 49 (press h for help or q to quit)[27m[K[K[m
   [1mWaiting[0m [1mfor[0m [1ma[0m [1msignal[0m [1mto[0m [1mbe[0m [1mcaught[0m[m
       The  following system calls suspend execution of the calling process or[m
       thread until a signal is caught (or an unhandled signal terminates  the[m
       process):[m
[m
       [1mpause[0m(2)        Suspends execution until any signal is caught.[m
[m
       [1msigsuspend[0m(2)   Temporarily  changes  the  signal  mask (see below) and[m
                       suspends execution until one of the unmasked signals is[m
                       caught.[m
[m
   [1mSynchronously[0m [1maccepting[0m [1ma[0m [1msignal[0m[m
       Rather  than  asynchronously catching a signal via a signal handler, it[m
       is possible to synchronously accept the signal, that is, to block  exe‐[m
       cution until the signal is delivered, at which point the kernel returns[m
       information about the signal to the caller.  There are two general ways[m
       to do this:[m
[m
       * [1msigwaitinfo[0m(2),  [1msigtimedwait[0m(2),  and  [1msigwait[0m(3)  suspend execution[m
         until one of the signals in a specified set is  delivered.   Each  of[m
         these calls returns information about the delivered signal.[m
[m
[7m Manual page signal(7) line 72 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       specified process.[m
[24;1H[K[7m Manual page signal(7) line 71 (press h for help or q to quit)[27m[K[K[m
       * [1msignalfd[0m(2) returns a file descriptor that can be used to read infor‐[m
         mation about signals that are delivered to the caller.  Each  [1mread[0m(2)[m
         from  this file descriptor blocks until one of the signals in the set[m
         specified in the [1msignalfd[0m(2) call is delivered to  the  caller.   The[m
         buffer  returned  by [1mread[0m(2) contains a structure describing the sig‐[m
         nal.[m
[m
   [1mSignal[0m [1mmask[0m [1mand[0m [1mpending[0m [1msignals[0m[m
       A signal may be [4mblocked[24m, which means that  it  will  not  be  delivered[m
       until it is later unblocked.  Between the time when it is generated and[m
       when it is delivered a signal is said to be [4mpending[24m.[m
[m
       Each thread in a process has an independent [4msignal[24m  [4mmask[24m,  which  indi‐[m
       cates  the  set  of  signals  that the thread is currently blocking.  A[m
       thread can manipulate its signal mask using [1mpthread_sigmask[0m(3).   In  a[m
       traditional  single-threaded application, [1msigprocmask[0m(2) can be used to[m
       manipulate the signal mask.[m
[m
       A child created via [1mfork[0m(2) inherits a  copy  of  its  parent's  signal[m
       mask; the signal mask is preserved across [1mexecve[0m(2).[m
[m
       A  signal  may be generated (and thus pending) for a process as a whole[m
[7m Manual page signal(7) line 94 (press h for help or q to quit)[27m[K[K       (e.g., when sent using [1mkill[0m(2)) or for a specific thread (e.g., certain[m
       signals, such as [1mSIGSEGV[0m and [1mSIGFPE[0m, generated as a consequence of exe‐[m
       cuting a specific machine-language instruction are thread directed,  as[m
       are  signals  targeted  at a specific thread using [1mpthread_kill[0m(3)).  A[m
       process-directed signal may be delivered to any one of the threads that[m
       does  not  currently  have the signal blocked.  If more than one of the[m
       threads has the signal unblocked, then the kernel chooses an  arbitrary[m
       thread to which to deliver the signal.[m
[m
       A  thread  can  obtain the set of signals that it currently has pending[m
       using [1msigpending[0m(2).  This set will consist of the union of the set  of[m
       pending process-directed signals and the set of signals pending for the[m
       calling thread.[m
[m
       A child created via [1mfork[0m(2) initially has an empty pending signal  set;[m
       the pending signal set is preserved across an [1mexecve[0m(2).[m
[m
   [1mStandard[0m [1msignals[0m[m
       Linux  supports the standard signals listed below.  Several signal num‐[m
       bers are architecture-dependent, as indicated in  the  "Value"  column.[m
       (Where three values are given, the first one is usually valid for alpha[m
       and sparc, the middle one for x86, arm, and most  other  architectures,[m
       and  the  last one for mips.  (Values for parisc are [4mnot[24m shown; see the[m
[7m Manual page signal(7) line 117 (press h for help or q to quit)[27m[K[K       Linux kernel source for signal numbering on that architecture.)  A dash[m
       (-) denotes that a signal is absent on the corresponding architecture.[m
[m
       First the signals described in the original POSIX.1-1990 standard.[m
[m
       Signal     Value     Action   Comment[m
       ──────────────────────────────────────────────────────────────────────[m
       [1mSIGHUP[0m        1       Term    Hangup detected on controlling terminal[m
                                     or death of controlling process[m
       [1mSIGINT[0m        2       Term    Interrupt from keyboard[m
       [1mSIGQUIT[0m       3       Core    Quit from keyboard[m
       [1mSIGILL[0m        4       Core    Illegal Instruction[m
       [1mSIGABRT[0m       6       Core    Abort signal from [1mabort[0m(3)[m
       [1mSIGFPE[0m        8       Core    Floating-point exception[m
       [1mSIGKILL[0m       9       Term    Kill signal[m
       [1mSIGSEGV[0m      11       Core    Invalid memory reference[m
       [1mSIGPIPE[0m      13       Term    Broken pipe: write to pipe with no[m
                                     readers; see [1mpipe[0m(7)[m
       [1mSIGALRM[0m      14       Term    Timer signal from [1malarm[0m(2)[m
       [1mSIGTERM[0m      15       Term    Termination signal[m
       [1mSIGUSR1[0m   30,10,16    Term    User-defined signal 1[m
       [1mSIGUSR2[0m   31,12,17    Term    User-defined signal 2[m
       [1mSIGCHLD[0m   20,17,18    Ign     Child stopped or terminated[m
[7m Manual page signal(7) line 140 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGCONT[0m   19,18,25    Cont    Continue if stopped[m
[7m Manual page signal(7) line 141 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGSTOP[0m   17,19,23    Stop    Stop process[m
[7m Manual page signal(7) line 142 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTSTP[0m   18,20,24    Stop    Stop typed at terminal[m
[7m Manual page signal(7) line 143 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTTIN[0m   21,21,26    Stop    Terminal input for background process[m
[7m Manual page signal(7) line 144 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTTOU[0m   22,22,27    Stop    Terminal output for background process[m
[7m Manual page signal(7) line 145 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 146 (press h for help or q to quit)[27m[K[K [KESCESC[Kqq[K[7m Manual page signal(7) line 146 (press h for help or q to quit)[27m[K[K       The signals [1mSIGKILL[0m and [1mSIGSTOP[0m cannot be caught, blocked, or ignored.[m
[7m Manual page signal(7) line 147 (press h for help or q to quit)[27m[K[K[?1l>[?1049l[23;0;0tdomenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4352 pts/6    00:02:13 exp14
 4675 pts/6    00:00:00 ps
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kio[Kll -8 4352
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4694 pts/6    00:00:00 ps
[1]+  Floating point exception(core dumped) exp14
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ pskill -8 4352ps[Kman 7 signalps[Kexp14 &ps[Kexp14 &
[1] 4716
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ exp14 &[Kexp14 &ps[Kkill -8 4352[1P 43529 4352
bash: kill: (4352) - No such process
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4716 pts/6    00:00:12 exp14
 4741 pts/6    00:00:00 ps
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ pskill -9 4352[K[K[K[K4716
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4770 pts/6    00:00:00 ps
[1]+  Killed                  exp14
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ 
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ pskill -9 4716ps[Kkill -9 4352[5Pexp14 &kill -9 4352[5Pexp14 &
[1] 4804
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kill -18[K[K20
kill: usage: kill [-s sigspec | -n signum | -sigspec] pid | jobspec ... or kill -l [sigspec]
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kill -20[1Pexp14 &ps[Kkill -9 4716ps[Kkill -9 4352[5Pexp14 &ps[Kkill -8 4352ps[Kman 7 signal
[?1049h[22;0;0t[?1h=SIGNAL(7)                  Linux Programmer's Manual                 SIGNAL(7)[m
[m
[1mNAME[0m[m
       signal - overview of signals[m
[m
[1mDESCRIPTION[0m[m
       Linux  supports both POSIX reliable signals (hereinafter "standard sig‐[m
       nals") and POSIX real-time signals.[m
[m
   [1mSignal[0m [1mdispositions[0m[m
       Each signal has a current [4mdisposition[24m, which determines how the process[m
       behaves when it is delivered the signal.[m
[m
       The  entries  in  the  "Action"  column of the tables below specify the[m
       default disposition for each signal, as follows:[m
[m
       Term   Default action is to terminate the process.[m
[m
       Ign    Default action is to ignore the signal.[m
[m
       Core   Default action is to terminate the process and  dump  core  (see[m
              [1mcore[0m(5)).[m
[m
[7m Manual page signal(7) line 1 (press h for help or q to quit)[27m[K[K       Stop   Default action is to stop the process.[m
[m
       Cont   Default  action  is  to  continue the process if it is currently[m
              stopped.[m
[m
       A process can change the disposition of a signal using [1msigaction[0m(2)  or[m
       [1msignal[0m(2).   (The  latter  is  less portable when establishing a signal[m
       handler; see [1msignal[0m(2) for  details.)   Using  these  system  calls,  a[m
       process  can  elect one of the following behaviors to occur on delivery[m
       of the signal: perform the default action; ignore the signal; or  catch[m
       the signal with a [4msignal[24m [4mhandler[24m, a programmer-defined function that is[m
       automatically invoked when the signal is delivered.  (By  default,  the[m
       signal  handler is invoked on the normal process stack.  It is possible[m
       to arrange that the signal handler uses an alternate stack; see [1msigalt‐[0m[m
       [1mstack[0m(2)  for  a discussion of how to do this and when it might be use‐[m
       ful.)[m
[m
       The signal disposition is a per-process attribute: in  a  multithreaded[m
       application, the disposition of a particular signal is the same for all[m
       threads.[m
[m
       A child created via [1mfork[0m(2) inherits a copy of its parent's signal dis‐[m
       positions.   During  an  [1mexecve[0m(2), the dispositions of handled signals[m
[7m Manual page signal(7) line 24 (press h for help or q to quit)[27m[K[K       are reset to the default; the dispositions of ignored signals are  left[m
       unchanged.[m
[m
   [1mSending[0m [1ma[0m [1msignal[0m[m
       The  following  system  calls and library functions allow the caller to[m
       send a signal:[m
[m
       [1mraise[0m(3)        Sends a signal to the calling thread.[m
[m
       [1mkill[0m(2)         Sends a signal to a specified process, to  all  members[m
                       of  a  specified  process group, or to all processes on[m
                       the system.[m
[m
       [1mkillpg[0m(3)       Sends a signal to all of the  members  of  a  specified[m
                       process group.[m
[m
       [1mpthread_kill[0m(3) Sends  a signal to a specified POSIX thread in the same[m
                       process as the caller.[m
[m
       [1mtgkill[0m(2)       Sends a signal to a specified thread within a  specific[m
                       process.   (This  is  the system call used to implement[m
                       [1mpthread_kill[0m(3).)[m
[m
[7m Manual page signal(7) line 47 (press h for help or q to quit)[27m[K[K       [1msigqueue[0m(3)     Sends a real-time signal with accompanying  data  to  a[m
                       specified process.[m
[m
   [1mWaiting[0m [1mfor[0m [1ma[0m [1msignal[0m [1mto[0m [1mbe[0m [1mcaught[0m[m
       The  following system calls suspend execution of the calling process or[m
       thread until a signal is caught (or an unhandled signal terminates  the[m
       process):[m
[m
       [1mpause[0m(2)        Suspends execution until any signal is caught.[m
[m
       [1msigsuspend[0m(2)   Temporarily  changes  the  signal  mask (see below) and[m
                       suspends execution until one of the unmasked signals is[m
                       caught.[m
[m
   [1mSynchronously[0m [1maccepting[0m [1ma[0m [1msignal[0m[m
       Rather  than  asynchronously catching a signal via a signal handler, it[m
       is possible to synchronously accept the signal, that is, to block  exe‐[m
       cution until the signal is delivered, at which point the kernel returns[m
       information about the signal to the caller.  There are two general ways[m
       to do this:[m
[m
       * [1msigwaitinfo[0m(2),  [1msigtimedwait[0m(2),  and  [1msigwait[0m(3)  suspend execution[m
         until one of the signals in a specified set is  delivered.   Each  of[m
[7m Manual page signal(7) line 70 (press h for help or q to quit)[27m[K[K         these calls returns information about the delivered signal.[m
[m
       * [1msignalfd[0m(2) returns a file descriptor that can be used to read infor‐[m
         mation about signals that are delivered to the caller.  Each  [1mread[0m(2)[m
         from  this file descriptor blocks until one of the signals in the set[m
         specified in the [1msignalfd[0m(2) call is delivered to  the  caller.   The[m
         buffer  returned  by [1mread[0m(2) contains a structure describing the sig‐[m
         nal.[m
[m
   [1mSignal[0m [1mmask[0m [1mand[0m [1mpending[0m [1msignals[0m[m
       A signal may be [4mblocked[24m, which means that  it  will  not  be  delivered[m
       until it is later unblocked.  Between the time when it is generated and[m
       when it is delivered a signal is said to be [4mpending[24m.[m
[m
       Each thread in a process has an independent [4msignal[24m  [4mmask[24m,  which  indi‐[m
       cates  the  set  of  signals  that the thread is currently blocking.  A[m
       thread can manipulate its signal mask using [1mpthread_sigmask[0m(3).   In  a[m
       traditional  single-threaded application, [1msigprocmask[0m(2) can be used to[m
       manipulate the signal mask.[m
[m
       A child created via [1mfork[0m(2) inherits a  copy  of  its  parent's  signal[m
       mask; the signal mask is preserved across [1mexecve[0m(2).[m
[m
[7m Manual page signal(7) line 93 (press h for help or q to quit)[27m[K[K       A  signal  may be generated (and thus pending) for a process as a whole[m
       (e.g., when sent using [1mkill[0m(2)) or for a specific thread (e.g., certain[m
       signals, such as [1mSIGSEGV[0m and [1mSIGFPE[0m, generated as a consequence of exe‐[m
       cuting a specific machine-language instruction are thread directed,  as[m
       are  signals  targeted  at a specific thread using [1mpthread_kill[0m(3)).  A[m
       process-directed signal may be delivered to any one of the threads that[m
       does  not  currently  have the signal blocked.  If more than one of the[m
       threads has the signal unblocked, then the kernel chooses an  arbitrary[m
       thread to which to deliver the signal.[m
[m
       A  thread  can  obtain the set of signals that it currently has pending[m
       using [1msigpending[0m(2).  This set will consist of the union of the set  of[m
       pending process-directed signals and the set of signals pending for the[m
       calling thread.[m
[m
       A child created via [1mfork[0m(2) initially has an empty pending signal  set;[m
       the pending signal set is preserved across an [1mexecve[0m(2).[m
[m
   [1mStandard[0m [1msignals[0m[m
       Linux  supports the standard signals listed below.  Several signal num‐[m
       bers are architecture-dependent, as indicated in  the  "Value"  column.[m
       (Where three values are given, the first one is usually valid for alpha[m
       and sparc, the middle one for x86, arm, and most  other  architectures,[m
[7m Manual page signal(7) line 116 (press h for help or q to quit)[27m[K[K       and  the  last one for mips.  (Values for parisc are [4mnot[24m shown; see the[m
       Linux kernel source for signal numbering on that architecture.)  A dash[m
       (-) denotes that a signal is absent on the corresponding architecture.[m
[m
       First the signals described in the original POSIX.1-1990 standard.[m
[m
       Signal     Value     Action   Comment[m
       ──────────────────────────────────────────────────────────────────────[m
       [1mSIGHUP[0m        1       Term    Hangup detected on controlling terminal[m
                                     or death of controlling process[m
       [1mSIGINT[0m        2       Term    Interrupt from keyboard[m
       [1mSIGQUIT[0m       3       Core    Quit from keyboard[m
       [1mSIGILL[0m        4       Core    Illegal Instruction[m
       [1mSIGABRT[0m       6       Core    Abort signal from [1mabort[0m(3)[m
       [1mSIGFPE[0m        8       Core    Floating-point exception[m
       [1mSIGKILL[0m       9       Term    Kill signal[m
       [1mSIGSEGV[0m      11       Core    Invalid memory reference[m
       [1mSIGPIPE[0m      13       Term    Broken pipe: write to pipe with no[m
                                     readers; see [1mpipe[0m(7)[m
       [1mSIGALRM[0m      14       Term    Timer signal from [1malarm[0m(2)[m
       [1mSIGTERM[0m      15       Term    Termination signal[m
       [1mSIGUSR1[0m   30,10,16    Term    User-defined signal 1[m
       [1mSIGUSR2[0m   31,12,17    Term    User-defined signal 2[m
[7m Manual page signal(7) line 139 (press h for help or q to quit)[27m[K[K       [1mSIGCHLD[0m   20,17,18    Ign     Child stopped or terminated[m
[7m Manual page signal(7) line 140 (press h for help or q to quit)[27m[K[K       [1mSIGCONT[0m   19,18,25    Cont    Continue if stopped[m
[7m Manual page signal(7) line 141 (press h for help or q to quit)[27m[K[K       [1mSIGSTOP[0m   17,19,23    Stop    Stop process[m
[7m Manual page signal(7) line 142 (press h for help or q to quit)[27m[K[K[?1l>[?1049l[23;0;0tdomenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ man 7 signal[4Pkill -20
kill: usage: kill [-s sigspec | -n signum | -sigspec] pid | jobspec ... or kill -l [sigspec]
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ p
p: command not found
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4804 pts/6    00:00:32 exp14
 4899 pts/6    00:00:00 ps
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps[Kkill -20 4804

[1]+  Stopped                 exp14
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4804 pts/6    00:00:55 exp14
 4946 pts/6    00:00:00 ps
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4804 pts/6    00:00:55 exp14
 4955 pts/6    00:00:00 ps
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ pskill -20 4804[C[1P 4804[1P 48041 48048 4804
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ ps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4804 pts/6    00:00:56 exp14
 4993 pts/6    00:00:00 ps
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ pskill -18 4804ps[Kkill -20 4804

[1]+  Stopped                 exp14
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kill -20 4804ps[Kkill -18 4804
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kill -18 480420[C[C[C[C[C

[1]+  Stopped                 exp14
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ kill -20 480418[C[C[C[C[C20[C[C[C[C[Cps[Kkill -18 4804ps[Kkill -20 4804ps[K[Kkill -20man 7 signal[4Pkill -20man 7 signal
[?1049h[22;0;0t[?1h=SIGNAL(7)                  Linux Programmer's Manual                 SIGNAL(7)[m
[m
[1mNAME[0m[m
       signal - overview of signals[m
[m
[1mDESCRIPTION[0m[m
       Linux  supports both POSIX reliable signals (hereinafter "standard sig‐[m
       nals") and POSIX real-time signals.[m
[m
   [1mSignal[0m [1mdispositions[0m[m
       Each signal has a current [4mdisposition[24m, which determines how the process[m
       behaves when it is delivered the signal.[m
[m
       The  entries  in  the  "Action"  column of the tables below specify the[m
       default disposition for each signal, as follows:[m
[m
       Term   Default action is to terminate the process.[m
[m
       Ign    Default action is to ignore the signal.[m
[m
       Core   Default action is to terminate the process and  dump  core  (see[m
              [1mcore[0m(5)).[m
[m
[7m Manual page signal(7) line 1 (press h for help or q to quit)[27m[K[K       Stop   Default action is to stop the process.[m
[m
       Cont   Default  action  is  to  continue the process if it is currently[m
              stopped.[m
[m
       A process can change the disposition of a signal using [1msigaction[0m(2)  or[m
       [1msignal[0m(2).   (The  latter  is  less portable when establishing a signal[m
       handler; see [1msignal[0m(2) for  details.)   Using  these  system  calls,  a[m
       process  can  elect one of the following behaviors to occur on delivery[m
       of the signal: perform the default action; ignore the signal; or  catch[m
       the signal with a [4msignal[24m [4mhandler[24m, a programmer-defined function that is[m
       automatically invoked when the signal is delivered.  (By  default,  the[m
       signal  handler is invoked on the normal process stack.  It is possible[m
       to arrange that the signal handler uses an alternate stack; see [1msigalt‐[0m[m
       [1mstack[0m(2)  for  a discussion of how to do this and when it might be use‐[m
       ful.)[m
[m
       The signal disposition is a per-process attribute: in  a  multithreaded[m
       application, the disposition of a particular signal is the same for all[m
       threads.[m
[m
       A child created via [1mfork[0m(2) inherits a copy of its parent's signal dis‐[m
       positions.   During  an  [1mexecve[0m(2), the dispositions of handled signals[m
[7m Manual page signal(7) line 24 (press h for help or q to quit)[27m[K[K       are reset to the default; the dispositions of ignored signals are  left[m
       unchanged.[m
[m
   [1mSending[0m [1ma[0m [1msignal[0m[m
       The  following  system  calls and library functions allow the caller to[m
       send a signal:[m
[m
       [1mraise[0m(3)        Sends a signal to the calling thread.[m
[m
       [1mkill[0m(2)         Sends a signal to a specified process, to  all  members[m
                       of  a  specified  process group, or to all processes on[m
                       the system.[m
[m
       [1mkillpg[0m(3)       Sends a signal to all of the  members  of  a  specified[m
                       process group.[m
[m
       [1mpthread_kill[0m(3) Sends  a signal to a specified POSIX thread in the same[m
                       process as the caller.[m
[m
       [1mtgkill[0m(2)       Sends a signal to a specified thread within a  specific[m
                       process.   (This  is  the system call used to implement[m
                       [1mpthread_kill[0m(3).)[m
[m
[7m Manual page signal(7) line 47 (press h for help or q to quit)[27m[K[K       [1msigqueue[0m(3)     Sends a real-time signal with accompanying  data  to  a[m
                       specified process.[m
[m
   [1mWaiting[0m [1mfor[0m [1ma[0m [1msignal[0m [1mto[0m [1mbe[0m [1mcaught[0m[m
       The  following system calls suspend execution of the calling process or[m
       thread until a signal is caught (or an unhandled signal terminates  the[m
       process):[m
[m
       [1mpause[0m(2)        Suspends execution until any signal is caught.[m
[m
       [1msigsuspend[0m(2)   Temporarily  changes  the  signal  mask (see below) and[m
                       suspends execution until one of the unmasked signals is[m
                       caught.[m
[m
   [1mSynchronously[0m [1maccepting[0m [1ma[0m [1msignal[0m[m
       Rather  than  asynchronously catching a signal via a signal handler, it[m
       is possible to synchronously accept the signal, that is, to block  exe‐[m
       cution until the signal is delivered, at which point the kernel returns[m
       information about the signal to the caller.  There are two general ways[m
       to do this:[m
[m
       * [1msigwaitinfo[0m(2),  [1msigtimedwait[0m(2),  and  [1msigwait[0m(3)  suspend execution[m
         until one of the signals in a specified set is  delivered.   Each  of[m
[7m Manual page signal(7) line 70 (press h for help or q to quit)[27m[K[K         these calls returns information about the delivered signal.[m
[m
       * [1msignalfd[0m(2) returns a file descriptor that can be used to read infor‐[m
         mation about signals that are delivered to the caller.  Each  [1mread[0m(2)[m
         from  this file descriptor blocks until one of the signals in the set[m
         specified in the [1msignalfd[0m(2) call is delivered to  the  caller.   The[m
         buffer  returned  by [1mread[0m(2) contains a structure describing the sig‐[m
         nal.[m
[m
   [1mSignal[0m [1mmask[0m [1mand[0m [1mpending[0m [1msignals[0m[m
       A signal may be [4mblocked[24m, which means that  it  will  not  be  delivered[m
       until it is later unblocked.  Between the time when it is generated and[m
       when it is delivered a signal is said to be [4mpending[24m.[m
[m
       Each thread in a process has an independent [4msignal[24m  [4mmask[24m,  which  indi‐[m
       cates  the  set  of  signals  that the thread is currently blocking.  A[m
       thread can manipulate its signal mask using [1mpthread_sigmask[0m(3).   In  a[m
       traditional  single-threaded application, [1msigprocmask[0m(2) can be used to[m
       manipulate the signal mask.[m
[m
       A child created via [1mfork[0m(2) inherits a  copy  of  its  parent's  signal[m
       mask; the signal mask is preserved across [1mexecve[0m(2).[m
[m
[7m Manual page signal(7) line 93 (press h for help or q to quit)[27m[K[K       A  signal  may be generated (and thus pending) for a process as a whole[m
       (e.g., when sent using [1mkill[0m(2)) or for a specific thread (e.g., certain[m
       signals, such as [1mSIGSEGV[0m and [1mSIGFPE[0m, generated as a consequence of exe‐[m
       cuting a specific machine-language instruction are thread directed,  as[m
       are  signals  targeted  at a specific thread using [1mpthread_kill[0m(3)).  A[m
       process-directed signal may be delivered to any one of the threads that[m
       does  not  currently  have the signal blocked.  If more than one of the[m
       threads has the signal unblocked, then the kernel chooses an  arbitrary[m
       thread to which to deliver the signal.[m
[m
       A  thread  can  obtain the set of signals that it currently has pending[m
       using [1msigpending[0m(2).  This set will consist of the union of the set  of[m
       pending process-directed signals and the set of signals pending for the[m
       calling thread.[m
[m
       A child created via [1mfork[0m(2) initially has an empty pending signal  set;[m
       the pending signal set is preserved across an [1mexecve[0m(2).[m
[m
   [1mStandard[0m [1msignals[0m[m
       Linux  supports the standard signals listed below.  Several signal num‐[m
       bers are architecture-dependent, as indicated in  the  "Value"  column.[m
       (Where three values are given, the first one is usually valid for alpha[m
       and sparc, the middle one for x86, arm, and most  other  architectures,[m
[7m Manual page signal(7) line 116 (press h for help or q to quit)[27m[K[K       and  the  last one for mips.  (Values for parisc are [4mnot[24m shown; see the[m
       Linux kernel source for signal numbering on that architecture.)  A dash[m
       (-) denotes that a signal is absent on the corresponding architecture.[m
[m
       First the signals described in the original POSIX.1-1990 standard.[m
[m
       Signal     Value     Action   Comment[m
       ──────────────────────────────────────────────────────────────────────[m
       [1mSIGHUP[0m        1       Term    Hangup detected on controlling terminal[m
                                     or death of controlling process[m
       [1mSIGINT[0m        2       Term    Interrupt from keyboard[m
       [1mSIGQUIT[0m       3       Core    Quit from keyboard[m
       [1mSIGILL[0m        4       Core    Illegal Instruction[m
       [1mSIGABRT[0m       6       Core    Abort signal from [1mabort[0m(3)[m
       [1mSIGFPE[0m        8       Core    Floating-point exception[m
       [1mSIGKILL[0m       9       Term    Kill signal[m
       [1mSIGSEGV[0m      11       Core    Invalid memory reference[m
       [1mSIGPIPE[0m      13       Term    Broken pipe: write to pipe with no[m
                                     readers; see [1mpipe[0m(7)[m
       [1mSIGALRM[0m      14       Term    Timer signal from [1malarm[0m(2)[m
       [1mSIGTERM[0m      15       Term    Termination signal[m
       [1mSIGUSR1[0m   30,10,16    Term    User-defined signal 1[m
       [1mSIGUSR2[0m   31,12,17    Term    User-defined signal 2[m
[7m Manual page signal(7) line 139 (press h for help or q to quit)[27m[K[K       [1mSIGCHLD[0m   20,17,18    Ign     Child stopped or terminated[m
[7m Manual page signal(7) line 140 (press h for help or q to quit)[27m[K[K       [1mSIGCONT[0m   19,18,25    Cont    Continue if stopped[m
[7m Manual page signal(7) line 141 (press h for help or q to quit)[27m[K[K       [1mSIGSTOP[0m   17,19,23    Stop    Stop process[m
[7m Manual page signal(7) line 142 (press h for help or q to quit)[27m[K[K       [1mSIGTSTP[0m   18,20,24    Stop    Stop typed at terminal[m
[7m Manual page signal(7) line 143 (press h for help or q to quit)[27m[K[K       [1mSIGTTIN[0m   21,21,26    Stop    Terminal input for background process[m
[7m Manual page signal(7) line 144 (press h for help or q to quit)[27m[K[K       [1mSIGTTOU[0m   22,22,27    Stop    Terminal output for background process[m
[7m Manual page signal(7) line 145 (press h for help or q to quit)[27m[K[K[m
[7m Manual page signal(7) line 146 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Signal     Value     Action   Comment[m
[24;1H[K[7m Manual page signal(7) line 145 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 144 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       First the signals described in the original POSIX.1-1990 standard.[m
[24;1H[K[7m Manual page signal(7) line 143 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 142 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       (-) denotes that a signal is absent on the corresponding architecture.[m
[24;1H[K[7m Manual page signal(7) line 141 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Linux kernel source for signal numbering on that architecture.)  A dash[m
[24;1H[K[7m Manual page signal(7) line 140 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       and  the  last one for mips.  (Values for parisc are [4mnot[24m shown; see the[m
[24;1H[K[7m Manual page signal(7) line 139 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       and sparc, the middle one for x86, arm, and most  other  architectures,[m
[24;1H[K[7m Manual page signal(7) line 138 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       (Where three values are given, the first one is usually valid for alpha[m
[24;1H[K[7m Manual page signal(7) line 137 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       bers are architecture-dependent, as indicated in  the  "Value"  column.[m
[24;1H[K[7m Manual page signal(7) line 136 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Linux  supports the standard signals listed below.  Several signal num‐[m
[24;1H[K[7m Manual page signal(7) line 135 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM   [1mStandard[0m [1msignals[0m[m
[24;1H[K[7m Manual page signal(7) line 134 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 133 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       the pending signal set is preserved across an [1mexecve[0m(2).[m
[24;1H[K[7m Manual page signal(7) line 132 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A child created via [1mfork[0m(2) initially has an empty pending signal  set;[m
[24;1H[K[7m Manual page signal(7) line 131 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGKILL[0m       9       Term    Kill signal[m
[7m Manual page signal(7) line 132 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGSEGV[0m      11       Core    Invalid memory reference[m
[7m Manual page signal(7) line 133 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGPIPE[0m      13       Term    Broken pipe: write to pipe with no[m
[7m Manual page signal(7) line 134 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                                     readers; see [1mpipe[0m(7)[m
[7m Manual page signal(7) line 135 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGALRM[0m      14       Term    Timer signal from [1malarm[0m(2)[m
[7m Manual page signal(7) line 136 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTERM[0m      15       Term    Termination signal[m
[7m Manual page signal(7) line 137 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGUSR1[0m   30,10,16    Term    User-defined signal 1[m
[7m Manual page signal(7) line 138 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGUSR2[0m   31,12,17    Term    User-defined signal 2[m
[7m Manual page signal(7) line 139 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGCHLD[0m   20,17,18    Ign     Child stopped or terminated[m
[7m Manual page signal(7) line 140 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGCONT[0m   19,18,25    Cont    Continue if stopped[m
[7m Manual page signal(7) line 141 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGSTOP[0m   17,19,23    Stop    Stop process[m
[7m Manual page signal(7) line 142 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTSTP[0m   18,20,24    Stop    Stop typed at terminal[m
[7m Manual page signal(7) line 143 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTTIN[0m   21,21,26    Stop    Terminal input for background process[m
[7m Manual page signal(7) line 144 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTTOU[0m   22,22,27    Stop    Terminal output for background process[m
[7m Manual page signal(7) line 145 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 146 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       The signals [1mSIGKILL[0m and [1mSIGSTOP[0m cannot be caught, blocked, or ignored.[m
[7m Manual page signal(7) line 147 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 148 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       Next  the  signals  not  in  the POSIX.1-1990 standard but described in[m
[7m Manual page signal(7) line 149 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       SUSv2 and POSIX.1-2001.[m
[7m Manual page signal(7) line 150 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mSIGINT[0m        2       Term    Interrupt from keyboard[m
[24;1H[K[7m Manual page signal(7) line 149 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                                     or death of controlling process[m
[24;1H[K[7m Manual page signal(7) line 148 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mSIGHUP[0m        1       Term    Hangup detected on controlling terminal[m
[24;1H[K[7m Manual page signal(7) line 147 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       ──────────────────────────────────────────────────────────────────────[m
[24;1H[K[7m Manual page signal(7) line 146 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Signal     Value     Action   Comment[m
[24;1H[K[7m Manual page signal(7) line 145 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 144 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mSIGTTOU[0m   22,22,27    Stop    Terminal output for background process[m
[7m Manual page signal(7) line 145 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 144 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       First the signals described in the original POSIX.1-1990 standard.[m
[24;1H[K[7m Manual page signal(7) line 143 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 142 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       (-) denotes that a signal is absent on the corresponding architecture.[m
[24;1H[K[7m Manual page signal(7) line 141 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Linux kernel source for signal numbering on that architecture.)  A dash[m
[24;1H[K[7m Manual page signal(7) line 140 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       and  the  last one for mips.  (Values for parisc are [4mnot[24m shown; see the[m
[24;1H[K[7m Manual page signal(7) line 139 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       and sparc, the middle one for x86, arm, and most  other  architectures,[m
[24;1H[K[7m Manual page signal(7) line 138 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       (Where three values are given, the first one is usually valid for alpha[m
[24;1H[K[7m Manual page signal(7) line 137 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       bers are architecture-dependent, as indicated in  the  "Value"  column.[m
[24;1H[K[7m Manual page signal(7) line 136 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Linux  supports the standard signals listed below.  Several signal num‐[m
[24;1H[K[7m Manual page signal(7) line 135 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM   [1mStandard[0m [1msignals[0m[m
[24;1H[K[7m Manual page signal(7) line 134 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 133 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       the pending signal set is preserved across an [1mexecve[0m(2).[m
[24;1H[K[7m Manual page signal(7) line 132 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A child created via [1mfork[0m(2) initially has an empty pending signal  set;[m
[24;1H[K[7m Manual page signal(7) line 131 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 130 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       calling thread.[m
[24;1H[K[7m Manual page signal(7) line 129 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       pending process-directed signals and the set of signals pending for the[m
[24;1H[K[7m Manual page signal(7) line 128 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       using [1msigpending[0m(2).  This set will consist of the union of the set  of[m
[24;1H[K[7m Manual page signal(7) line 127 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A  thread  can  obtain the set of signals that it currently has pending[m
[24;1H[K[7m Manual page signal(7) line 126 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 125 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       thread to which to deliver the signal.[m
[24;1H[K[7m Manual page signal(7) line 124 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       threads has the signal unblocked, then the kernel chooses an  arbitrary[m
[24;1H[K[7m Manual page signal(7) line 123 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       does  not  currently  have the signal blocked.  If more than one of the[m
[24;1H[K[7m Manual page signal(7) line 122 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       process-directed signal may be delivered to any one of the threads that[m
[24;1H[K[7m Manual page signal(7) line 121 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       are  signals  targeted  at a specific thread using [1mpthread_kill[0m(3)).  A[m
[24;1H[K[7m Manual page signal(7) line 120 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       cuting a specific machine-language instruction are thread directed,  as[m
[24;1H[K[7m Manual page signal(7) line 119 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       signals, such as [1mSIGSEGV[0m and [1mSIGFPE[0m, generated as a consequence of exe‐[m
[24;1H[K[7m Manual page signal(7) line 118 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       (e.g., when sent using [1mkill[0m(2)) or for a specific thread (e.g., certain[m
[24;1H[K[7m Manual page signal(7) line 117 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A  signal  may be generated (and thus pending) for a process as a whole[m
[24;1H[K[7m Manual page signal(7) line 116 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 115 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       mask; the signal mask is preserved across [1mexecve[0m(2).[m
[24;1H[K[7m Manual page signal(7) line 114 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A child created via [1mfork[0m(2) inherits a  copy  of  its  parent's  signal[m
[24;1H[K[7m Manual page signal(7) line 113 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 112 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       manipulate the signal mask.[m
[24;1H[K[7m Manual page signal(7) line 111 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K   [1mStandard[0m [1msignals[0m[m
[7m Manual page signal(7) line 112 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       Linux  supports the standard signals listed below.  Several signal num‐[m
[7m Manual page signal(7) line 113 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       bers are architecture-dependent, as indicated in  the  "Value"  column.[m
[7m Manual page signal(7) line 114 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       (Where three values are given, the first one is usually valid for alpha[m
[7m Manual page signal(7) line 115 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       mask; the signal mask is preserved across [1mexecve[0m(2).[m
[24;1H[K[7m Manual page signal(7) line 114 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A child created via [1mfork[0m(2) inherits a  copy  of  its  parent's  signal[m
[24;1H[K[7m Manual page signal(7) line 113 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 112 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       manipulate the signal mask.[m
[24;1H[K[7m Manual page signal(7) line 111 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       traditional  single-threaded application, [1msigprocmask[0m(2) can be used to[m
[24;1H[K[7m Manual page signal(7) line 110 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       thread can manipulate its signal mask using [1mpthread_sigmask[0m(3).   In  a[m
[24;1H[K[7m Manual page signal(7) line 109 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       cates  the  set  of  signals  that the thread is currently blocking.  A[m
[24;1H[K[7m Manual page signal(7) line 108 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Each thread in a process has an independent [4msignal[24m  [4mmask[24m,  which  indi‐[m
[24;1H[K[7m Manual page signal(7) line 107 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 106 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       when it is delivered a signal is said to be [4mpending[24m.[m
[24;1H[K[7m Manual page signal(7) line 105 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       until it is later unblocked.  Between the time when it is generated and[m
[24;1H[K[7m Manual page signal(7) line 104 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A signal may be [4mblocked[24m, which means that  it  will  not  be  delivered[m
[24;1H[K[7m Manual page signal(7) line 103 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM   [1mSignal[0m [1mmask[0m [1mand[0m [1mpending[0m [1msignals[0m[m
[24;1H[K[7m Manual page signal(7) line 102 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 101 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM         nal.[m
[24;1H[K[7m Manual page signal(7) line 100 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM         buffer  returned  by [1mread[0m(2) contains a structure describing the sig‐[m
[24;1H[K[7m Manual page signal(7) line 99 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM         specified in the [1msignalfd[0m(2) call is delivered to  the  caller.   The[m
[24;1H[K[7m Manual page signal(7) line 98 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM         from  this file descriptor blocks until one of the signals in the set[m
[24;1H[K[7m Manual page signal(7) line 97 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM         mation about signals that are delivered to the caller.  Each  [1mread[0m(2)[m
[24;1H[K[7m Manual page signal(7) line 96 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       * [1msignalfd[0m(2) returns a file descriptor that can be used to read infor‐[m
[24;1H[K[7m Manual page signal(7) line 95 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 94 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM         these calls returns information about the delivered signal.[m
[24;1H[K[7m Manual page signal(7) line 93 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM         until one of the signals in a specified set is  delivered.   Each  of[m
[24;1H[K[7m Manual page signal(7) line 92 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       * [1msigwaitinfo[0m(2),  [1msigtimedwait[0m(2),  and  [1msigwait[0m(3)  suspend execution[m
[24;1H[K[7m Manual page signal(7) line 91 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 90 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       to do this:[m
[24;1H[K[7m Manual page signal(7) line 89 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       information about the signal to the caller.  There are two general ways[m
[24;1H[K[7m Manual page signal(7) line 88 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       cution until the signal is delivered, at which point the kernel returns[m
[24;1H[K[7m Manual page signal(7) line 87 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       is possible to synchronously accept the signal, that is, to block  exe‐[m
[24;1H[K[7m Manual page signal(7) line 86 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Rather  than  asynchronously catching a signal via a signal handler, it[m
[24;1H[K[7m Manual page signal(7) line 85 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM   [1mSynchronously[0m [1maccepting[0m [1ma[0m [1msignal[0m[m
[24;1H[K[7m Manual page signal(7) line 84 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 83 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       caught.[m
[24;1H[K[7m Manual page signal(7) line 82 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       suspends execution until one of the unmasked signals is[m
[24;1H[K[7m Manual page signal(7) line 81 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1msigsuspend[0m(2)   Temporarily  changes  the  signal  mask (see below) and[m
[24;1H[K[7m Manual page signal(7) line 80 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 79 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mpause[0m(2)        Suspends execution until any signal is caught.[m
[24;1H[K[7m Manual page signal(7) line 78 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 77 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       process):[m
[24;1H[K[7m Manual page signal(7) line 76 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       thread until a signal is caught (or an unhandled signal terminates  the[m
[24;1H[K[7m Manual page signal(7) line 75 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       The  following system calls suspend execution of the calling process or[m
[24;1H[K[7m Manual page signal(7) line 74 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM   [1mWaiting[0m [1mfor[0m [1ma[0m [1msignal[0m [1mto[0m [1mbe[0m [1mcaught[0m[m
[24;1H[K[7m Manual page signal(7) line 73 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 72 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       specified process.[m
[24;1H[K[7m Manual page signal(7) line 71 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1msigqueue[0m(3)     Sends a real-time signal with accompanying  data  to  a[m
[24;1H[K[7m Manual page signal(7) line 70 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 69 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       [1mpthread_kill[0m(3).)[m
[24;1H[K[7m Manual page signal(7) line 68 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       process.   (This  is  the system call used to implement[m
[24;1H[K[7m Manual page signal(7) line 67 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mtgkill[0m(2)       Sends a signal to a specified thread within a  specific[m
[24;1H[K[7m Manual page signal(7) line 66 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 65 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       process as the caller.[m
[24;1H[K[7m Manual page signal(7) line 64 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mpthread_kill[0m(3) Sends  a signal to a specified POSIX thread in the same[m
[24;1H[K[7m Manual page signal(7) line 63 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 62 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       process group.[m
[24;1H[K[7m Manual page signal(7) line 61 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mkillpg[0m(3)       Sends a signal to all of the  members  of  a  specified[m
[24;1H[K[7m Manual page signal(7) line 60 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 59 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       the system.[m
[24;1H[K[7m Manual page signal(7) line 58 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM                       of  a  specified  process group, or to all processes on[m
[24;1H[K[7m Manual page signal(7) line 57 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mkill[0m(2)         Sends a signal to a specified process, to  all  members[m
[24;1H[K[7m Manual page signal(7) line 56 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 55 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mraise[0m(3)        Sends a signal to the calling thread.[m
[24;1H[K[7m Manual page signal(7) line 54 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 53 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       send a signal:[m
[24;1H[K[7m Manual page signal(7) line 52 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       The  following  system  calls and library functions allow the caller to[m
[24;1H[K[7m Manual page signal(7) line 51 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM   [1mSending[0m [1ma[0m [1msignal[0m[m
[24;1H[K[7m Manual page signal(7) line 50 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 49 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       unchanged.[m
[24;1H[K[7m Manual page signal(7) line 48 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       are reset to the default; the dispositions of ignored signals are  left[m
[24;1H[K[7m Manual page signal(7) line 47 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       positions.   During  an  [1mexecve[0m(2), the dispositions of handled signals[m
[24;1H[K[7m Manual page signal(7) line 46 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A child created via [1mfork[0m(2) inherits a copy of its parent's signal dis‐[m
[24;1H[K[7m Manual page signal(7) line 45 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 44 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       threads.[m
[24;1H[K[7m Manual page signal(7) line 43 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       application, the disposition of a particular signal is the same for all[m
[24;1H[K[7m Manual page signal(7) line 42 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       The signal disposition is a per-process attribute: in  a  multithreaded[m
[24;1H[K[7m Manual page signal(7) line 41 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 40 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       ful.)[m
[24;1H[K[7m Manual page signal(7) line 39 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mstack[0m(2)  for  a discussion of how to do this and when it might be use‐[m
[24;1H[K[7m Manual page signal(7) line 38 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       to arrange that the signal handler uses an alternate stack; see [1msigalt‐[0m[m
[24;1H[K[7m Manual page signal(7) line 37 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       signal  handler is invoked on the normal process stack.  It is possible[m
[24;1H[K[7m Manual page signal(7) line 36 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       automatically invoked when the signal is delivered.  (By  default,  the[m
[24;1H[K[7m Manual page signal(7) line 35 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       the signal with a [4msignal[24m [4mhandler[24m, a programmer-defined function that is[m
[24;1H[K[7m Manual page signal(7) line 34 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       of the signal: perform the default action; ignore the signal; or  catch[m
[24;1H[K[7m Manual page signal(7) line 33 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       process  can  elect one of the following behaviors to occur on delivery[m
[24;1H[K[7m Manual page signal(7) line 32 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       handler; see [1msignal[0m(2) for  details.)   Using  these  system  calls,  a[m
[24;1H[K[7m Manual page signal(7) line 31 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1msignal[0m(2).   (The  latter  is  less portable when establishing a signal[m
[24;1H[K[7m Manual page signal(7) line 30 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A process can change the disposition of a signal using [1msigaction[0m(2)  or[m
[24;1H[K[7m Manual page signal(7) line 29 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       send a signal:[m
[7m Manual page signal(7) line 30 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 31 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mraise[0m(3)        Sends a signal to the calling thread.[m
[7m Manual page signal(7) line 32 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 33 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mkill[0m(2)         Sends a signal to a specified process, to  all  members[m
[7m Manual page signal(7) line 34 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                       of  a  specified  process group, or to all processes on[m
[7m Manual page signal(7) line 35 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                       the system.[m
[7m Manual page signal(7) line 36 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 37 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mkillpg[0m(3)       Sends a signal to all of the  members  of  a  specified[m
[7m Manual page signal(7) line 38 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                       process group.[m
[7m Manual page signal(7) line 39 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 40 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mpthread_kill[0m(3) Sends  a signal to a specified POSIX thread in the same[m
[7m Manual page signal(7) line 41 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                       process as the caller.[m
[7m Manual page signal(7) line 42 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 43 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mtgkill[0m(2)       Sends a signal to a specified thread within a  specific[m
[7m Manual page signal(7) line 44 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                       process.   (This  is  the system call used to implement[m
[7m Manual page signal(7) line 45 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                       [1mpthread_kill[0m(3).)[m
[7m Manual page signal(7) line 46 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 47 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1msigqueue[0m(3)     Sends a real-time signal with accompanying  data  to  a[m
[7m Manual page signal(7) line 48 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K                       specified process.[m
[7m Manual page signal(7) line 49 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 50 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 49 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       unchanged.[m
[24;1H[K[7m Manual page signal(7) line 48 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       are reset to the default; the dispositions of ignored signals are  left[m
[24;1H[K[7m Manual page signal(7) line 47 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       positions.   During  an  [1mexecve[0m(2), the dispositions of handled signals[m
[24;1H[K[7m Manual page signal(7) line 46 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A child created via [1mfork[0m(2) inherits a copy of its parent's signal dis‐[m
[24;1H[K[7m Manual page signal(7) line 45 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 44 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       threads.[m
[24;1H[K[7m Manual page signal(7) line 43 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       application, the disposition of a particular signal is the same for all[m
[24;1H[K[7m Manual page signal(7) line 42 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       The signal disposition is a per-process attribute: in  a  multithreaded[m
[24;1H[K[7m Manual page signal(7) line 41 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 40 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       ful.)[m
[24;1H[K[7m Manual page signal(7) line 39 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1mstack[0m(2)  for  a discussion of how to do this and when it might be use‐[m
[24;1H[K[7m Manual page signal(7) line 38 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       to arrange that the signal handler uses an alternate stack; see [1msigalt‐[0m[m
[24;1H[K[7m Manual page signal(7) line 37 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       signal  handler is invoked on the normal process stack.  It is possible[m
[24;1H[K[7m Manual page signal(7) line 36 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       automatically invoked when the signal is delivered.  (By  default,  the[m
[24;1H[K[7m Manual page signal(7) line 35 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       the signal with a [4msignal[24m [4mhandler[24m, a programmer-defined function that is[m
[24;1H[K[7m Manual page signal(7) line 34 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       of the signal: perform the default action; ignore the signal; or  catch[m
[24;1H[K[7m Manual page signal(7) line 33 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       process  can  elect one of the following behaviors to occur on delivery[m
[24;1H[K[7m Manual page signal(7) line 32 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       handler; see [1msignal[0m(2) for  details.)   Using  these  system  calls,  a[m
[24;1H[K[7m Manual page signal(7) line 31 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       [1msignal[0m(2).   (The  latter  is  less portable when establishing a signal[m
[24;1H[K[7m Manual page signal(7) line 30 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       A process can change the disposition of a signal using [1msigaction[0m(2)  or[m
[24;1H[K[7m Manual page signal(7) line 29 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 28 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM              stopped.[m
[24;1H[K[7m Manual page signal(7) line 27 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Cont   Default  action  is  to  continue the process if it is currently[m
[24;1H[K[7m Manual page signal(7) line 26 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 25 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Stop   Default action is to stop the process.[m
[24;1H[K[7m Manual page signal(7) line 24 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 23 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM              [1mcore[0m(5)).[m
[24;1H[K[7m Manual page signal(7) line 22 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Core   Default action is to terminate the process and  dump  core  (see[m
[24;1H[K[7m Manual page signal(7) line 21 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 20 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Ign    Default action is to ignore the signal.[m
[24;1H[K[7m Manual page signal(7) line 19 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 18 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Term   Default action is to terminate the process.[m
[24;1H[K[7m Manual page signal(7) line 17 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 16 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       default disposition for each signal, as follows:[m
[24;1H[K[7m Manual page signal(7) line 15 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       The  entries  in  the  "Action"  column of the tables below specify the[m
[24;1H[K[7m Manual page signal(7) line 14 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 13 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       behaves when it is delivered the signal.[m
[24;1H[K[7m Manual page signal(7) line 12 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Each signal has a current [4mdisposition[24m, which determines how the process[m
[24;1H[K[7m Manual page signal(7) line 11 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM   [1mSignal[0m [1mdispositions[0m[m
[24;1H[K[7m Manual page signal(7) line 10 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 9 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       nals") and POSIX real-time signals.[m
[24;1H[K[7m Manual page signal(7) line 8 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Linux  supports both POSIX reliable signals (hereinafter "standard sig‐[m
[24;1H[K[7m Manual page signal(7) line 7 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[1mDESCRIPTION[0m[m
[24;1H[K[7m Manual page signal(7) line 6 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 5 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       signal - overview of signals[m
[24;1H[K[7m Manual page signal(7) line 4 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[1mNAME[0m[m
[24;1H[K[7m Manual page signal(7) line 3 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 2 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HMSIGNAL(7)                  Linux Programmer's Manual                 SIGNAL(7)[m
[24;1H[K[7m Manual page signal(7) line 1 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[K[7m Manual page signal(7) line 1 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[K[7m Manual page signal(7) line 1 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[K[7m Manual page signal(7) line 1 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[K[7m Manual page signal(7) line 1 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       Stop   Default action is to stop the process.[m
[7m Manual page signal(7) line 2 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 3 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       Cont   Default  action  is  to  continue the process if it is currently[m
[7m Manual page signal(7) line 4 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K              stopped.[m
[7m Manual page signal(7) line 5 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 6 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       A process can change the disposition of a signal using [1msigaction[0m(2)  or[m
[7m Manual page signal(7) line 7 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1msignal[0m(2).   (The  latter  is  less portable when establishing a signal[m
[7m Manual page signal(7) line 8 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       handler; see [1msignal[0m(2) for  details.)   Using  these  system  calls,  a[m
[7m Manual page signal(7) line 9 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       process  can  elect one of the following behaviors to occur on delivery[m
[7m Manual page signal(7) line 10 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       of the signal: perform the default action; ignore the signal; or  catch[m
[7m Manual page signal(7) line 11 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       the signal with a [4msignal[24m [4mhandler[24m, a programmer-defined function that is[m
[7m Manual page signal(7) line 12 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       automatically invoked when the signal is delivered.  (By  default,  the[m
[7m Manual page signal(7) line 13 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       signal  handler is invoked on the normal process stack.  It is possible[m
[7m Manual page signal(7) line 14 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       to arrange that the signal handler uses an alternate stack; see [1msigalt‐[0m[m
[7m Manual page signal(7) line 15 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       [1mstack[0m(2)  for  a discussion of how to do this and when it might be use‐[m
[7m Manual page signal(7) line 16 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       ful.)[m
[7m Manual page signal(7) line 17 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K[m
[7m Manual page signal(7) line 18 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KBB[K       The signal disposition is a per-process attribute: in  a  multithreaded[m
[7m Manual page signal(7) line 19 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 18 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       Term   Default action is to terminate the process.[m
[24;1H[K[7m Manual page signal(7) line 17 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 16 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       default disposition for each signal, as follows:[m
[24;1H[K[7m Manual page signal(7) line 15 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM       The  entries  in  the  "Action"  column of the tables below specify the[m
[24;1H[K[7m Manual page signal(7) line 14 (press h for help or q to quit)[27m[K[K [KESCESC[KOO[KAA[K[HM[m
[24;1H[K[7m Manual page signal(7) line 13 (press h for help or q to quit)[27m[K[K[?1l>[?1049l[23;0;0tdomenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ man 7 signalkill -20 480418[C[C[C[C[C20[C[C[C[C[C18[C[C[C[C[C20[C[C[C[C[C18[C[C[C[C[C[C[1P 48047 4804
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ [s[K[Kps
  PID TTY          TIME CMD
 3824 pts/6    00:00:00 bash
 4804 pts/6    00:01:05 exp14
 5291 pts/6    00:00:00 ps
domenic.mancuso@honeybee:~/COS350/experiments/Experiment14$ pskill -17 4804[1Pman 7 signal
[?1049h[22;0;0t[?1h=SIGNAL(7)                  Linux Programmer's Manual                 SIGNAL(7)[m
[m
[1mNAME[0m[m
       signal - overview of signals[m
[m
[1mDESCRIPTION[0m[m
       Linux  supports both POSIX reliable signals (hereinafter "standard sig‐[m
       nals") and POSIX real-time signals.[m
[m
   [1mSignal[0m [1mdispositions[0m[m
       Each signal has a current [4mdisposition[24m, which determines how the process[m
       behaves when it is delivered the signal.[m
[m
       The  entries  in  the  "Action"  column of the tables below specify the[m
       default disposition for each signal, as follows:[m
[m
       Term   Default action is to terminate the process.[m
[m
       Ign    Default action is to ignore the signal.[m
[m
       Core   Default action is to terminate the process and  dump  core  (see[m
              [1mcore[0m(5)).[m
[m
[7m Manual page signal(7) line 1 (press h for help or q to quit)[27m[K[K       Stop   Default action is to stop the process.[m
[m
       Cont   Default  action  is  to  continue the process if it is currently[m
              stopped.[m
[m
       A process can change the disposition of a signal using [1msigaction[0m(2)  or[m
       [1msignal[0m(2).   (The  latter  is  less portable when establishing a signal[m
       handler; see [1msignal[0m(2) for  details.)   Using  these  system  calls,  a[m
       process  can  elect one of the following behaviors to occur on delivery[m
       of the signal: perform the default action; ignore the signal; or  catch[m
       the signal with a [4msignal[24m [4mhandler[24m, a programmer-defined function that is[m
       automatically invoked when the signal is delivered.  (By  default,  the[m
       signal  handler is invoked on the normal process stack.  It is possible[m
       to arrange that the signal handler uses an alternate stack; see [1msigalt‐[0m[m
       [1mstack[0m(2)  for  a discussion of how to do this and when it might be use‐[m
       ful.)[m
[m
       The signal disposition is a per-process attribute: in  a  multithreaded[m
       application, the disposition of a particular signal is the same for all[m
       threads.[m
[m
       A child created via [1mfork[0m(2) inherits a copy of its parent's signal dis‐[m
       positions.   During  an  [1mexecve[0m(2), the dispositions of handled signals[m
[7m Manual page signal(7) line 24 (press h for help or q to quit)[27m[K[K       are reset to the default; the dispositions of ignored signals are  left[m
       unchanged.[m
[m
   [1mSending[0m [1ma[0m [1msignal[0m[m
       The  following  system  calls and library functions allow the caller to[m
       send a signal:[m
[m
       [1mraise[0m(3)        Sends a signal to the calling thread.[m
[m
       [1mkill[0m(2)         Sends a signal to a specified process, to  all  members[m
                       of  a  specified  process group, or to all processes on[m
                       the system.[m
[m
       [1mkillpg[0m(3)       Sends a signal to all of the  members  of  a  specified[m
                       process group.[m
[m
       [1mpthread_kill[0m(3) Sends  a signal to a specified POSIX thread in the same[m
                       process as the caller.[m
[m
       [1mtgkill[0m(2)       Sends a signal to a specified thread within a  specific[m
                       process.   (This  is  the system call used to implement[m
                       [1mpthread_kill[0m(3).)[m
[m
[7m Manual page signal(7) line 47 (press h for help or q to quit)[27m[K[K       [1msigqueue[0m(3)     Sends a real-time signal with accompanying  data  to  a[m
                       specified process.[m
[m
   [1mWaiting[0m [1mfor[0m [1ma[0m [1msignal[0m [1mto[0m [1mbe[0m [1mcaught[0m[m
       The  following system calls suspend execution of the calling process or[m
       thread until a signal is caught (or an unhandled signal terminates  the[m
       process):[m
[m
       [1mpause[0m(2)        Suspends execution until any signal is caught.[m
[m
       [1msigsuspend[0m(2)   Temporarily  changes  the  signal  mask (see below) and[m
                       suspends execution until one of the unmasked signals is[m
                       caught.[m
[m
   [1mSynchronously[0m [1maccepting[0m [1ma[0m [1msignal[0m[m
       Rather  than  asynchronously catching a signal via a signal handler, it[m
       is possible to synchronously accept the signal, that is, to block  exe‐[m
       cution until the signal is delivered, at which point the kernel returns[m
       information about the signal to the caller.  There are two general ways[m
       to do this:[m
[m
       * [1msigwaitinfo[0m(2),  [1msigtimedwait[0m(2),  and  [1msigwait[0m(3)  suspend execution[m
         until one of the signals in a specified set is  delivered.   Each  of[m
[7m Manual page signal(7) line 70 (press h for help or q to quit)[27m[K[K         these calls returns information about the delivered signal.[m
[m
       * [1msignalfd[0m(2) returns a file descriptor that can be used to read infor‐[m
         mation about signals that are delivered to the caller.  Each  [1mread[0m(2)[m
         from  this file descriptor blocks until one of the signals in the set[m
         specified in the [1msignalfd[0m(2) call is delivered to  the  caller.   The[m
         buffer  returned  by [1mread[0m(2) contains a structure describing the sig‐[m
         nal.[m
[m
   [1mSignal[0m [1mmask[0m [1mand[0m [1mpending[0m [1msignals[0m[m
       A signal may be [4mblocked[24m, which means that  it  will  not  be  delivered[m
       until it is later unblocked.  Between the time when it is generated and[m
       when it is delivered a signal is said to be [4mpending[24m.[m
[m
       Each thread in a process has an independent [4msignal[24m  [4mmask[24m,  which  indi‐[m
       cates  the  set  of  signals  that the thread is currently blocking.  A[m
       thread can manipulate its signal mask using [1mpthread_sigmask[0m(3).   In  a[m
       traditional  single-threaded application, [1msigprocmask[0m(2) can be used to[m
       manipulate the signal mask.[m
[m
       A child created via [1mfork[0m(2) inherits a  copy  of  its  parent's  signal[m
       mask; the signal mask is preserved across [1mexecve[0m(2).[m
[m
[7m Manual page signal(7) line 93 (press h for help or q to quit)[27m[K[K       A  signal  may be generated (and thus pending) for a process as a whole[m
       (e.g., when sent using [1mkill[0m(2)) or for a specific thread (e.g., certain[m
       signals, such as [1mSIGSEGV[0m and [1mSIGFPE[0m, generated as a consequence of exe‐[m
       cuting a specific machine-language instruction are thread directed,  as[m
       are  signals  targeted  at a specific thread using [1mpthread_kill[0m(3)).  A[m
       process-directed signal may be delivered to any one of the threads that[m
       does  not  currently  have the signal blocked.  If more than one of the[m
       threads has the signal unblocked, then the kernel chooses an  arbitrary[m
       thread to which to deliver the signal.[m
[m
       A  thread  can  obtain the set of signals that it currently has pending[m
       using [1msigpending[0m(2).  This set will consist of the union of the set  of[m
       pending process-directed signals and the set of signals pending for the[m
       calling thread.[m
[m
       A child created via [1mfork[0m(2) initially has an empty pending signal  set;[m
       the pending signal set is preserved across an [1mexecve[0m(2).[m
[m
   [1mStandard[0m [1msignals[0m[m
       Linux  supports the standard signals listed below.  Several signal num‐[m
       bers are architecture-dependent, as indicated in  the  "Value"  column.[m
       (Where three values are given, the first one is usually valid for alpha[m
       and sparc, the middle one for x86, arm, and most  other  architectures,[m
[7m Manual page signal(7) line 116 (press h for help or q to quit)[27m[K[K       and  the  last one for mips.  (Values for parisc are [4mnot[24m shown; see the[m
       Linux kernel source for signal numbering on that architecture.)  A dash[m
       (-) denotes that a signal is absent on the corresponding architecture.[m
[m
       First the signals described in the original POSIX.1-1990 standard.[m
[m
       Signal     Value     Action   Comment[m
       ─────────────────────────�