Domenic Mancuso	
Experiment 4

In this program I used fflush and removed it to test the difference. Fflush() writes all buffered data to the disk immediately. Without fflush, writes occur when the buffer is full. It took a little over 60 seconds to write 8192 bytes to my output program without fflush. Not using fflush is the better overhead because it takes away rapid system calls and portrays a realistic control flow of programming.

In summary, after the first write, output is 8192 bytes in size. This is likely the buffer size of the honeybee CS lab machine.

using fflush: -rw------- 1 domenic.mancuso domenic.mancuso 19677 Jan 27 20:59  minecraft.txt
not using fflush: -rw------- 1 domenic.mancuso domenic.mancuso  8192 Jan 27 21:03  output.txt

