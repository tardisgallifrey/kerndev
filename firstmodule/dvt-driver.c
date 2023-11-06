#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

// Module metadata
MODULE_AUTHOR("Ruan de Bruyn");
MODULE_DESCRIPTION("Hello world driver");
MODULE_LICENSE("GPL");

// Custom init and exit methods
static int __init custom_init(void) {

    //printk() writes to dmesg log
    printk(KERN_INFO "Hello world driver loaded.");
    return 0;
}

static void __exit custom_exit(void) {
    printk(KERN_INFO "Goodbye my friend, I shall miss you dearly...");
}

//register your custom module init and exit functions
module_init(custom_init);
module_exit(custom_exit);

/* Always use:
    sudo yum install "kernel-devel-uname-r = $(uname -r)"
   to install kernel devel headers in Fedora/Redhat
   so that your headers match your running kernel
*/