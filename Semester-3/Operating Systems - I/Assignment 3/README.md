# Assignment 3
## System Calls

There are 3 tasks in this assignment.

### Task 1: 

helloWorld.c

–Compile it and save as helloWorld.o

–Run the following commands and report your observations by copying the commands and their outputs into your report

–ltrace ./helloWorld.o (options –c, -S, -t, -T)

–strace ./helloWorld.o (options –c, -C, -t, -w)

–time ./helloWorld.o

–/usr/bin/time –v ./helloWorld.o

–Is helloWorld.c a CPU-bound or I/O-bound job?

–If it’s CPU-bound, convert it to I/O-bound job, vice versa

 

### Task 2:

Take one of big programs that you had written earlier as part of Programming in C course

–Report outputs of ltrace, strace, time commands

–Is it a CPU-bound or I/O-bound job? Explain with stats

–Which system call is called most frequently? Why?

–Which system call consumed more execution time?

 

### Task 3: 

Refer Example 2 and Example 2’ in Slides 13 & 14 in the slide deck of LM2

–Modify them to include some printf calls

–Use ltrace, strace and time on these programs

–Also report procedure and system calls called by each of them

 

### Deliverables:

1. A PDF report that contains

The following Plagiarism statement
The desired outcomes as required for all tasks in this particular assignment.
 

PLAGIARISM STATEMENT


I certify that this assignment/report is my own work, based on my personal study and/or research and that
I have acknowledged all material and sources used in its preparation, whether they be books, articles,
reports, lecture notes, and any other kind of document, electronic or personal communication. I also
certify that this assignment/report has not previously been submitted for assessment in any other course,
except where specific permission has been granted from all course instructors involved, or at any other
time in this course, and that I have not copied in part or whole or otherwise plagiarised the work of other
students and/or persons. I pledge to uphold the principles of honesty and responsibility at CSE@IITH. In
addition, I understand my responsibility to report honour violations by other students if I become aware
of it.


Name:
Date:
Signature: 

