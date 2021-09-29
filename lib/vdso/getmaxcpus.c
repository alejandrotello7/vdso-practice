#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <asm/vgtod.h>
#include <vdso/datapage.h>
#include <vdso/helpers.h>
#include "../../arch/x86/include/asm/vdso/getmaxcpus.h"

static int 
__cvdso_getmaxcpus_data(const int *cp)
{
	cp = NR_CPUS;
	return cp;
}

static int cvdso_getmaxcpus(void)
{
   return __cvdso_getmaxcpus_data(get_maxcpus_vdso());
}
