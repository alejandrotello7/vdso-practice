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
#include "../../../../lib/vdso/getmaxcpus.c"


extern notrace int __vdso_nr_cpus_getter(void)
{
    return cvdso_getmaxcpus();
}

int nr_cpus_getter(void)
    __attribute__((weak, alias("__vdso_nr_cpus_getter")));
    
    
    
    
