#include "types.h"
#include "riscv.h"
#include "param.h"
#include "spinlock.h"
#include "defs.h"
#include "proc.h" //to use myproc()

#include "sysinfo.h"

int get_sysinfo(uint64 addr)
{
    // get the current proc
    // Return the current struct proc *, or zero if none.
    struct proc *cur_proc = myproc();
    
    struct sysinfo info; //this struct is local, stores sysinfo 

    info.freemem = freemem(); 
    info.nproc = nproc();

    /*
    copy the sysinfo struct to the provided user-space addr
     * cur_proc->pagetable: page table of the calling process
     * (char *)&info: kernel-space ptr to the sysinfo data to be copied
    */
    if(copyout(cur_proc->pagetable, addr, (char*)&info, sizeof(info)) < 0)
    {
        return -1; //error
    }

    return 0; //succeeded


}