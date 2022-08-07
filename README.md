# Operating System Lab - JSSSTU (updated)

## Left over programs (Round Robin, Producer-Consumer, Reader-Writer) will be added soon..

OS LAB TEST PROGRAMS
NOTE: For all the scheduling algorithms write the expected output for the given data (table with set
of processes, AT, BT) along with the Gantt chart. Execute the scheduling program for the same data.
The output should be in the form of table with all the necessary time parameters like AT, BT, CT, TT
and WT. Also display the Gantt chart and average WT.
1. A. Write a shell program to check whether a given string is a palindrome or not
B. Implement SJF Pre-emptive scheduling algorithm by defining process structure.
2. A. Write a shell program to generate prime no. in a given range
B. Implement Priority Pre-emptive scheduling algorithm by defining process structure.
3. A. Write a shell program to find largest of n numbers, storing numbers in an array.
B. Implement Round Robin scheduling algorithm by defining process structure.
4. A. Write a shell program to Read two matrices , find addition and display the input matrices
 and resultant in matrix format
B. Implement Priority Non-preemptive scheduling algorithm by defining process structure.
5. A. Write a program to perform the following task using I/O system calls for file I/O
i) Reading first 10 characters from file
ii) Skipping 5 characters from current position in the file
iii) Going to 5th last character in the file
iv) Going to the 3rd character in the file
B. Implement FCFS scheduling algorithm by defining process structure.
6. A. Write a program to demonstrate zombie and orphan process.
B. Implement SJF Non-preemptive scheduling algorithm by defining process structure.
7. A. Write a program to simulate grep command using system calls
B. Write a program to generate and print Fibonacci series with the following requirements:
- Parent program should create a child and distribute the task of generating Fibonacci no to
its child.
- The code for generating Fibonacci no. should reside in different program.
- Child should write the generated Fibonacci sequence to a shared memory.
- Parent process has to print by retrieving the Fibonacci sequence from the shared memory.
i) Implement the above using shmget and shmat
Note: Shared object should be removed at the end in the program
8. A. Write a program to simulate ls command using system calls
B. Write a program to generate and print Fibonacci series with the following requirements:
- Parent program should create a child and distribute the task of generating Fibonacci no to
its child.
- The code for generating Fibonacci no. should reside in different program.
- Child should write the generated Fibonacci sequence to a shared memory.
- Parent process has to print by retrieving the Fibonacci sequence from the shared memory.
i) Implement the above using shm_open and mmap
Note: Shared object should be removed at the end in the program
9. A. Write a program to check whether a given no. is a palindrome or not
B. Write a program to generate and print N ODD numbers with the following requirements:
- Parent program should create a child and distribute the task of generating odd numbers to
its child.
- The code for generating odd numbers should reside in different program.
- Child should write the generated odd numbers to a shared memory.
- Parent process has to print the odd numbers by retrieving from the shared memory.
i) Implement the above using shmget and shmat
Note: Shared object should be removed at the end in the program
10. A. Write a shell program to simulate a calculator
B. Write a program to generate and print Prime nos. between a given range (between M &
N) with the following requirements:
- M & N should be passed as command line arguments
- Error checking should be done to verify the required no. of arguments at the command line
- Parent program should create a child and distribute the task of generating Prime numbers
to its child.
- The code for generating Prime numbers should reside in different program.
- Child should write the generated Prime numbers to a shared memory.
- Parent process has to print the Prime numbers by retrieving from the shared memory.
i) Implement the above using shm_open and mmap
Note: Shared object should be removed at the end in the program
11. A. Write a program to perform the following tasks using system calls:
i) Parent process should create a child process
ii) Both parent child processes should display their pid and parent’s pid; parent process
should also its child’s pid
iii) Load a new program into child process
iv) The parent process should terminate after the child process terminates
B. Write a program that implements solution to Producer – Consumer problem using mutex
and semaphores.
12. A. Write a shell program to find the largest of three numbers
B. Write a program that implements solution to Readers-Writers problem using mutex and
semaphores.
