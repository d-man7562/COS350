SIGINT -2 stops the process which can be resumes with SIGCHLD if you use -18.

This is surprising because SIGCHLD is an "ignore" option in the man page.

SIGFPE -8 causes a core dump

SIGKILL -9 kills the process

SIGCHLD allows 3 options, -20, -18, and -17. Even though SIGCHLD is default to "ignore" according to the manual, -20 stops the process, -18 resumes the process. -17 seems to do nothing.
