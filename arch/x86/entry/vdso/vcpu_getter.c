#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <linux/cpumask.h>
#include <linux/sched.h>
#include <asm/vgtod.h>
#include <asm/smp.h>
#include <asm/processor.h> // cpu_data(), struct cpuinfo_x86
#include <asm/mce.h>


#include <linux/threads.h>
#include <linux/bitmap.h>
#include <linux/atomic.h>
#include <linux/bug.h>

#include <linux/mm.h>
#include <linux/err.h>
#include <linux/sched.h>
#include <linux/sched/task_stack.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/random.h>
#include <linux/elf.h>
#include <linux/cpu.h>
#include <linux/ptrace.h>
#include <linux/compiler.h>
#include <linux/types.h>
#include <linux/time_namespace.h>

#include <asm/pvclock.h>
#include <asm/proto.h>
#include <asm/vdso.h>
#include <asm/vvar.h>
#include <asm/tlb.h>
#include <asm/page.h>
#include <asm/desc.h>
#include <asm/cpufeature.h>
#include <clocksource/hyperv_timer.h>






//#include "../../../../lib/vdso/cpugetter.c"
#include "../../../../lib/vdso/gettimeofday.c"
//#include "vma.c"

//extern int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2);

//notrace int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2)
//notrace int __vdso_cpu_getter(int num1, int num2)
//notrace int __vdso_cpu_getter(unsigned *cpu, unsigned *dummy, unsigned *cpu2)
//notrace int __vdso_cpu_getter(struct __kernel_old_timeval *tv, struct timezone *tz)
//int cpugetter(void);

int getpidd(void);
extern notrace int __vdso_cpu_getter(void)
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
    VVAR(variablevar) = 1;
    unsigned int z = PID_MAX_LIMIT;
    return z;
}

extern notrace int __vdso_nr_cpus_getter(void)
{
    unsigned int x = NR_CPUS;
    return x;
}



int cpu_getter(void)
    __attribute__((weak, alias("__vdso_cpu_getter")));

int nr_cpus_getter(void)
    __attribute__((weak, alias("__vdso_nr_cpus_getter")));
    
    
    
    
