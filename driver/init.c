/*
 * Filename: init.c (Not tested on 32bit OS)
 * Version: 1.0
 * Description: Linux PCIe device driver for Serica-Tech Gemini-3xxx Devices. Uses Linux kernel APIs in
 *  version 2.6.32+ (tested on version 2.6.32 - 4.4.0).
 * Author: Huang Ye
 * History: Rewrite based on University of California @mattj: Matthew Jacobsen RIFFA Project
*/


#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>


// Local includes:
#include "seqfile.h"

#ifdef MAY_USE_API
DEFINE_TIMER(my_timer);
add_timer(my_timer);
wait_event_timeout();
volatile int flags;
#include <linux/delay.h>
loops_per_jiffy //3202928 on this server

//used for exec time measurement on Pentium
// ns = cycles * (10^6 / cpu_khz)
unsigned long long tsc_ticks0, tsc_ticks1;
tsc_ticks0 = rdtsc();
tsc_ticks1 = rdtsc();
printk(KERN_INFO "rdtsc: %lu %llu nsec\n", tsc_ticks1 - tsc_ticks0, (tsc_ticks1 - tsc_ticks0)*1000000/cpu_khz);
// find / -name '*.[ch]' | xargs grep -E 'cpu_khz' to find specific string

#include <linux/atomic.h>
local_irq_save();
local_irq_restore();

CONFIG_SMP 
CONFIG_PREEMPT
#endif


unsigned long timestamp;
struct proc_dir_entry *entry = NULL;


static int __init dev_init(void)
{
    printk(KERN_INFO "serica: %s done\n", __func__);
    timestamp = jiffies;
    create_seq_file(entry, S_IRUSR, NULL);
    return 0;
}
static void __exit dev_exit(void)
{
    remove_seq_file(entry);
    printk(KERN_INFO "serica: %s done. \n", __func__);
}

module_exit(dev_exit);
module_init(dev_init);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("Gemini3XXX driver for Serica-Tech, Linux (2.6.32+)");
MODULE_AUTHOR("Serica-Tech LTD, CO.");