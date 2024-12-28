# Lab 3 - page tables
Explore and modify page tables to speed up certain system calls, print a page table and detect accessed pages.

## Lab requirements

### Exercise 1: Speed up system calls
Implement a shared read-only page at `USYSCALL` to store the PID for optimizing `getpid()`.  


### Exercise 2: Print a page table
Create a `vmprint()` function which takes a pagetable_t argument, and print that page table in a given format.  


### Exercise 3: Detect which pages have been accessed
Implement `pgaccess()` system call to report accessed pages to userspace using the RISC-V access bits.  
 
## References
https://pdos.csail.mit.edu/6.1810/2023/labs/pgtbl.html