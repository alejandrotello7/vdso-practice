#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <asm/vgtod.h>
#include <vdso/datapage.h>
#include <vdso/helpers.h>
#include "../../arch/x86/include/asm/vdso/getmaxpid.h"

static int 
__cvdso_getmaxpid_data(const int *cp)
{
	cp = PID_MAX_LIMIT;
	return cp;
}

static int cvdso_getmaxpid(void)
{
   return __cvdso_getmaxpid_data(get_maxpid_vdso());
}
