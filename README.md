I found this experiment very fun.
The terminal setting " termuios.c_lflag &= ~ECHO " suppressed echoing of the password characters.
To get an immediate response upon typing a character, when you use the 
tcsetattr() command, you need to make sure the second parameter says "TCSANOW",
so what I added was tcsetattr(0,TCSANOW,&x);


