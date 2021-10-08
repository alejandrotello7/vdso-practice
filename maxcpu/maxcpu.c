#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <asm/vgtod.h>
#include <vdso/datapage.h>
#include <vdso/helpers.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(maxcpu)
{
	int cp = NR_CPUS;
	return cp;
}
