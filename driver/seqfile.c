#include <linux/seq_file.h>
#include <linux/jiffies.h>
#include <linux/proc_fs.h>
#define PROC_NAME "driver/serica"

extern unsigned long timestamp;

static int seq_show(struct seq_file *file, void *v)
{
    //TODO: show() depending on user demands, here is only a demo func.
    seq_printf(file, "Welcome to use Serica Device.\n"
                "Device onlined for %ld seconds.\n", (jiffies - timestamp)/HZ);
    return 0;
}

static int proc_open(struct inode * inode, struct file * file)
{
    return single_open(file, seq_show, NULL);
}

static struct file_operations proc_fops = {
    .owner	= THIS_MODULE,
    .open	= proc_open,
    .read	= seq_read,
    .release= seq_release,
};

int create_seq_file(struct proc_dir_entry *entry, umode_t mode, struct proc_dir_entry *parent)
{
    #ifdef CONFIG_PROC_FS
        entry = proc_create(PROC_NAME, mode, parent, &proc_fops);
        if(entry == NULL)
        {
            printk(KERN_ERR "Serica: failed to create seq file.\n");
            return -1;
        }
        else
        {
            return 1;
        }
    #else
        printk(KERN_INFO "Serica: This module requests the kernel to support procfs, need set CONFIG_PROC_FS configure Y\n");
    #endif
    return -1;
}

void remove_seq_file(struct proc_dir_entry *entry)
{
    #ifdef CONFIG_PROC_FS
        proc_remove(entry);
    #endif
}