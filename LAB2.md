# Lab 2 - System Call
Implement new system calls to xv6 to gain a deeper understanding of how they and the internals of the xv6 kernel work. 

## Lab requirements
### Exercise 1: trace

Implement the system call `trace` that will control tracing, track system calls invoked by a process and logs their occurrences.

It should take one argument, an integer "mask", whose bits specify which system calls to trace.

Refer to the files `user/trace.c`, `sysproc.c`, and `proc.c` for the details of the implementation.

### Exercise 2: sysinfo
Implement the system call sysinfo to retrieve system statistics.

This system call provides information about the system, particularly the amount of free memory `freemem` and the number of active processes `nproc`.

Refer to the files `kernel/sysinfo.c` and `kernel/sysproc.c` for the details of the implementation.

## Instructions for Running the Programs
1. Prepare for Adding System Calls \
To prepare for adding new system calls to xv6, you can follow the step-by-step guide in this tutorial:
[Adding a New System Call in xv6](https://www.geeksforgeeks.org/xv6-operating-system-adding-a-new-system-call/)

2. Modify the Makefile \
Add each program to the UPROGS section and include the object file `sysinfo.o` in OBJS: 
```
OBJS = \
    ...
  $K/sysinfo.o

UPROGS=\
    ...

	$U/_trace\
	$U/_sysinfotest

```

3. Start xv6 
```
make qemu
```

4. Test the System Calls 
- To verify the functionality of `trace`, run the commands `trace [mask]`. For example: `trace 32 grep hello README`.
- For `sysinfo`, run `sysinfotest.c`.

## References
https://pdos.csail.mit.edu/6.1810/2023/labs/syscall.html
https://www.geeksforgeeks.org/xv6-operating-system-adding-a-new-system-call/