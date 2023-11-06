#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>   

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Liran B.H");

/* To change module parameters at load:
	use -- insmod mydev.ko irq=44 devname=newdev debug=0
	
	the parameter names above have to exactly match those
	listed below.
	
	To change while module is loaded, use:
	echo "1" > /sys/module/mydev/parameters/debug
	  or similar.
	
	again, parameter names and module name must exactly
	match as below.
	
	You will not see a change in the parameter in 
	dmesg while the module is loaded.
	You will only see the change when you 'rmmod' 
	the module.
*/

//module parameters
static int irq=10;
module_param(irq,int,0660);

static int debug=0;
module_param(debug,int,0660);

static char *devname = "simpdev";
module_param(devname,charp,0660);

//init function
static int simple_init(void)
{
	//printk() like printf() uses variables and keys
	printk(KERN_WARNING "hello... irq=%d name=%s debug=%d\n",irq,devname,debug);
	return 0;
}

//exit function
static void simple_cleanup(void)
{
	printk(KERN_WARNING "bye... irq=%d name=%s debug=%d\n",irq,devname,debug);
}

//register our functions
module_init(simple_init);
module_exit(simple_cleanup);