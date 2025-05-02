Domenic Mancuso

No known incomplete parts. 
WC1 may be coded in an ugly way because I was in a rush to figure things out. I used getchar in my first iteration until I realized per our instructions that I needed to use a more efficient method. 

I found WC1 and WC2's relationship confusing at first which is why I wrote 2 methods for single file input and multiple (which is probably bad). Anyway, it works, and I was under time pressure before I realized last class that lc3 was not required. I still did it anyway.

WC2 definitely improved after our final experiment which helped me with writing the program.

I found the pthreads slideshow very helpful when writing WC3. Thanks!


After optimizing lc3 I was able to improve it to the point that it's better than lc2 which was outperforming my prototype lc3.


Name: Domenic Mancuso
Project 6
COS 350 Spring 2025

Implementation (80 points):

yes___ lc1 gets correct individual file line counts (15pts)
    notes: code looks ugly

yes___ lc1 get correct total (5pts)
    notes: always correct

yes___ lc2 gets correct individual file line counts (15pts)
    notes: 

yes___ lc2 get correct total (15pts)
    notes:

yes___ lc3 gets correct individual file line counts (15pts)
    notes:

yes___ lc3 get correct total (15pts)
    notes:

Timing Results (10 points): yes

Machine tests were perfored on: honeybee____________________

Program             real        user            sys
---------           ----------  -------------   ----------
lc1		    0.067	0.041		0.009
lc2		    0.031	0.034		0.013
lc3		    0.023	0.034		0.008


Discussion (10 points):

Which version was the fastest, and why do you think that was?
lc3 because I was able to intelligently optimize it and threads are just more efficient (when programmed correctly) overall. 



Script started on 2025-05-01 22:00:58-0400
WELCOME BACK DOMENIC!!
domenic.mancuso@honeybee:~/COS350/programs/prog6$: time lc1 f*
 175641 f1
 26175 f10
 345130 f2
 65336 f3
 211035 f4
 53835 f5
 33055 f6
 13426 f7
 16271 f8
 54544 f9
 994448 total

real	0m0.067s
user	0m0.041s
sys	0m0.009s
domenic.mancuso@honeybee:~/COS350/programs/prog6$: time lc2 f*
26175 f10
13426 f7
65336 f3
54544 f9
175641 f1
345130 f2
211035 f4
16271 f8
33055 f6
53835 f5
994448 total

real    0m0.031s
user    0m0.034s
sys     0m0.013s
domenic.mancuso@honeybee:~/COS350/programs/prog6$: time lc3 f*
26175 f10
345130 f2
33055 f6
175641 f1
65336 f3
53835 f5
54544 f9
13426 f7
16271 f8
211035 f4
994448 total

real    0m0.023s
user    0m0.034s
sys     0m0.008s

domenic.mancuso@honeybee:~/COS350/programs/prog6$: exit

Script done on 2025-05-01 22:01:52-0400
