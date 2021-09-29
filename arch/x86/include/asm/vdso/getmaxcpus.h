#include <uapi/linux/time.h>
#include <asm/vgtod.h>
#include <asm/vvar.h>
#include <asm/unistd.h>
#include <asm/msr.h>
#include <asm/pvclock.h>
#include <clocksource/hyperv_timer.h>

#define _maxcpus_data (VVAR(maxcpus_data))

static __always_inline const int *get_maxcpus_vdso(void)
{
	return _maxcpus_data;
}