# Lab 1 - Basics of xv6 and its system calls

## Instructions for Running the Programs
1. Add each program to the UPROGS section of the Makefile. 

```
UPROGS=\
    ...

    $U/_pingpong\
    $U/_primes\
    $U/_find\
    $U/_xargs
```

2. Start xv6 
```
make qemu
```

3. Run the Programs \
After starting xv6, each program can be executed using its name, such as `pingpong`, `primes`, `find`, and `xargs`.

## Lab requirements
### Exercise 1: pingpong
Write a user-level program that uses xv6 system calls to ''ping-pong'' a byte between two
processes over a pair of pipes, one for each direction. The parent should send a byte to the
child; the child should print "<pid>: received ping", where <pid> is its process ID, write the
byte on the pipe to the parent, and exit; the parent should read the byte from the child, print
"<pid>: received pong", and exit. 

The solution for this exercise is in the file `user/pingpong.c`.

### Exercise 2: primes
Write a program to implement a pipe-based version of the Sieve of Eratosthenes. \
The program should print prime numbers up to 280 by filtering numbers through a pipeline of processes.

The solution for this exercise is in the file `user/primes.c`.


### Exercise 3: find
Write a simple version of the UNIX find program for xv6: find all the files in a directory tree with a specific name. 

The solution for this exercise is in the file `user/find.c`.


### Exercise 4: xargs
Write a simple version of the UNIX xargs program for xv6: its arguments describe a command to run, it reads lines from the standard input, and it runs the command for each line, appending the line to the command's arguments.

The solution for this exercise is in the file `user/xargs.c`.


## Lab Report


## References
https://pdos.csail.mit.edu/6.828/2023/labs/util.html
