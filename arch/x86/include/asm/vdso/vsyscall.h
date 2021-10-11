/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_VDSO_VSYSCALL_H
#define __ASM_VDSO_VSYSCALL_H

#ifndef __ASSEMBLY__

#include <linux/hrtimer.h>
#include <linux/timekeeper_internal.h>
#include <vdso/datapage.h>
#include <asm/vgtod.h>
#include <asm/vvar.h>

DEFINE_VVAR(int, maxpid_data);
DEFINE_VVAR(struct vdso_data, _vdso_data);
DEFINE_VVAR(int, maxcpus_data);


/*
 * Update the vDSO data page to keep in sync with kernel timekeeping.
 */
static __always_inline
struct vdso_data *__x86_get_k_vdso_data(void)
{
	return _vdso_data;
}

static __always_inline
int *__x86_get_pid_vdso_data(void)
{
	return maxpid_data;
}

#define __arch_get_k_vdso_data __x86_get_k_vdso_data

/* The asm-generic header needs to be included after the definitions above */
#include <asm-generic/vdso/vsyscall.h>

#endif /* !__ASSEMBLY__ */

#endif /* __ASM_VDSO_VSYSCALL_H */
