I am super proud of myself for getting this complete. 
While I thought that the already created code made the project a little easier, job control with pid, fork, exec 
is still a challenge for me and needs more time. 
If I had the option I would choose to fix the core dump every time you input an empty argslist.
Also, I would fix this so that if you pause the shell(CTRL+Z) it kills itself automatically. 
Also, that it prints a newline once you CTRL+D so it doesn't mess up the bash command line.

I suppose the only real deviation is that my prompt changes and tells you what
directory you are in, it also has a (smsh) in parentheses so that you know which shell you're in.

				Points	Works	Mostly Works	Occasionally Works	Not Implemented	Explanation
changed prompt			10	yes(ITS INTERACTIVE!!!!)					
correct command execution	10	yes				
exit				10	yes				
exit value			10	yes				
cd dir				15	yes				
cd				15	yes				
start job in background		15	yes				
notify background job is complete15	yes				
