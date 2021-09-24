#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <asm/vgtod.h>


static int cpugetter(void){
    /*unsigned cpu = cpumask_first(cpu_online_mask);

        while (cpu < nr_cpu_ids) {
                pr_info("CPU: %u, freq: %u kHz\n", cpu, cpufreq_get(cpu));
                cpu = cpumask_next(cpu, cpu_online_mask);
        }*/

    return 0;
}
