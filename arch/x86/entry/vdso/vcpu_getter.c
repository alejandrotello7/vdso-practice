#include <asm/linkage.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/cpu.h>
#include <linux/getcpu.h>
#include <asm/vgtod.h>
#include <linux/time.h>
#include <linux/export.h>
#include <linux/smp.h>
#include <linux/sched.h>
//#include "../../../../lib/vdso/cpugetter.c"
//#include "../../../../lib/vdso/gettimeofday.c"

//extern int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2);

//notrace int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2)
notrace int __vdso_cpu_getter(int num1, int num2)
{
    //int x = num_present_cpus();
    //int x = NR_CPUS;
    //int x = num_online_cpus();
    //int pid = task_pid_nr(current);
    //return __cvdso_cpu_getter();
    
    //vdso_get_cpunode(cpu,dummy,cpu2);
    return num1+num2;
    //return 0;
}


int cpu_getter(int num1, int num2)
    __attribute__((weak, alias("__vdso_cpu_getter")));
