#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <asm/vgtod.h>
#include <vdso/datapage.h>
#include <vdso/helpers.h>

static int 
__cvdso_getvariable_data(const int *cp)
{
	cp = PID_MAX_LIMIT;
	return cp;
}

static int cvdso_getvariable(void)
{
   return __cvdso_getvariable_data(get_variablevar());
}
