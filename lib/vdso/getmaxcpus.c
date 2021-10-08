#include <linux/kernel.h>
#include <linux/time.h>
#include <linux/sched.h>
#include <asm/vgtod.h>
#include <vdso/datapage.h>
#include <vdso/helpers.h>

#include <linux/mm.h>
#include <linux/err.h>
#include <linux/sched/task_stack.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/random.h>
#include <linux/elf.h>
#include <linux/cpu.h>
#include <linux/ptrace.h>
#include <linux/time_namespace.h>

#include <asm/pvclock.h>
#include <asm/vgtod.h>
#include <asm/proto.h>
#include <asm/vdso.h>
#include <asm/vvar.h>
#include <asm/tlb.h>
#include <asm/page.h>
#include <asm/desc.h>
#include <asm/cpufeature.h>
#include <clocksource/hyperv_timer.h>

#include "../../arch/x86/include/asm/vdso/getmaxcpus.h"

static int 
__cvdso_getmaxcpus_data(const int *cp)
{
	//cp = NR_CPUS;
	//cp = task_pid_nr(current);
	//cp = current->pid;
	return cp;
}

static int cvdso_getmaxcpus(void)
{
   return __cvdso_getmaxcpus_data(get_maxcpus_vdso());
}
