#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <asm/vgtod.h>
#include <vdso/datapage.h>
#include <vdso/helpers.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(maxpid)
{
	int cp = PID_MAX_LIMIT;
	return cp;
}
