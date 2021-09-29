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


extern notrace int __vdso_get_maxpid(void)
{
    return cvdso_getmaxpid();
}


int get_maxpid(void)
    __attribute__((weak, alias("__vdso_get_maxpid")));

    
    
    
