#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <linux/cpumask.h>
#include <linux/sched.h>
#include <asm/vgtod.h>
#include <asm/smp.h>
#include <asm/processor.h> // cpu_data(), struct cpuinfo_x86
#include <asm/mce.h>

#include "../../../../lib/vdso/getmaxpid.c"
#include "../../../../lib/vdso/gettimeofday.c"

//extern int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2);

//notrace int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2)
//notrace int __vdso_cpu_getter(int num1, int num2)
//notrace int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2)
//notrace int __vdso_cpu_getter(struct __kernel_old_timeval *tv, struct timezone *tz)
//int cpugetter(void);

 
extern notrace int __vdso_get_maxpid(void)
{
    //int x = num_present_cpus();
    //unsigned int x = NR_CPUS; //maximum number of CPUS that OS can handle
    //unsigned int x = nr_cpu_ids; 
    //unsigned int x = num_online_cpus();
    //int pid = task_pid_nr(current);
    //return __cvdso_cpu_getter();
    //vdso_get_cpunode(cpu,dummy,cpu2);
 	//return num1+num2;
    //return smp_processor_id(); 
    //return 0;
    /*unsigned cpu;
    struct cpuinfo_x86 *info;

    cpu = get_cpu();
    info = &cpu_data(cpu);
    //pr_info("CPU: %u, core: %d\n", cpu, info->cpu_core_id);
    put_cpu(); // Don't forget this!
    
    return info->cpu_core_id;*/
    //int pid = getpidd();

    //void *vdso = (uintptr_t) getauxval(AT_SYSINFO_EHDR);
    //unsigned int y = CONFIG_NR_CPUS_DEFAULT;
    //unsigned int x = NR_CPUS;
    //unsigned int p = current->state;
    return cvdso_getmaxpid();
}

extern notrace int __vdso_nr_cpus_getter(void)
{
    unsigned int x = NR_CPUS;
    return x;
}

int get_maxpid(void)
    __attribute__((weak, alias("__vdso_get_maxpid")));

int nr_cpus_getter(void)
    __attribute__((weak, alias("__vdso_nr_cpus_getter")));
    
    
    
    
