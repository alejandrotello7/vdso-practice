#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <linux/cpumask.h>
#include <asm/vgtod.h>
#include <asm/smp.h>

#include <linux/threads.h>
#include <linux/bitmap.h>
#include <linux/atomic.h>
#include <linux/bug.h>


//#include "../../../../lib/vdso/cpugetter.c"
//#include "../../../../lib/vdso/gettimeofday.c"

//extern int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2);

//notrace int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2)
//notrace int __vdso_cpu_getter(int num1, int num2)
//notrace int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2)
//notrace int __vdso_cpu_getter(struct __kernel_old_timeval *tv, struct timezone *tz)
//int cpugetter(void);
extern notrace int __vdso_cpu_getter(void)
{
    //int x = num_present_cpus();
    //int x = NR_CPUS;
    unsigned int x = num_online_cpus();
    //int pid = task_pid_nr(current);
    //return __cvdso_cpu_getter();
    //vdso_get_cpunode(cpu,dummy,cpu2);
 	//return num1+num2;
    //return smp_processor_id(); 
    //return 0;
    return x;
}



int cpu_getter(void)
    __attribute__((weak, alias("__vdso_cpu_getter")));
    
    
    
    
    
