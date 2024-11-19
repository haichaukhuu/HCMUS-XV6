#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  if(n < 0)
    n = 0;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64
sys_trace(void) {
  // int trace_mask;
  // // if (argint(0, &trace_mask) < 0) {
  // //   return -1;
  // // }
  // argint(0, &trace_mask);
  // if (trace_mask < 0)
  // {
  //   return -1;
  // }
  // // struct proc* p = myproc();
  // // p->tracemask = trace_mask;
  // return 0;

	argint(0, &myproc()->tracemask);
  if (&myproc()->tracemask < 0)
		return -1;

	return 0;
}


/*
syscall handler for sysinfo
retrieves a user-space ptr (info) to sysinfo struct
-> validate -> pass to systeminfo function
*/


uint64
sys_sysinfo(void) 
{
  //ptr to stat (struct)
  uint64 info; 

  //See argaddr in syscall.c
  // void
  // argaddr(int n, uint64 *ip)
  // {
  //   *ip = argraw(n);
  // }
  if (argaddr(0, &info) < 0) 
  {
    return -1; //invalid arg or retrieve fails
  }
  return get_sysinfo(info);
  // int get_sysinfo(uint64 addr)
}


