#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>   

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Liran B.H");

//paramater variable
static int num;

//module parameters
static int irq=10;
module_param(irq,int,0660);

static int debug=0;
module_param(debug,int,0660);

static char *devname = "mykerneldev";
module_param(devname,charp,0660);

/* Tutorial speaks of this struct,
	it is defined in a header file from
	above.
	It is here for reference only, to see
	how things work

struct kernel_param_ops {

	// How the ops should behave 
	unsigned int flags;

	//Returns 0, or -errno.  arg is in kp->arg.
	int (*set)(const char *val, const struct kernel_param *kp);

	// Returns length written or -errno.  Buffer is 4k (ie. be short!)
	int (*get)(char *buffer, const struct kernel_param *kp);

	// Optional function to free kp->arg when module unloaded. 
	void (*free)(void *arg);
};
*/


//implement setter
static int my_set(const char *val, const struct kernel_param *kp)
{
	int n = 0, ret;

	ret = kstrtoint(val, 10, &n);
	if (ret != 0 || n < 1 || n > 32)
		return -EINVAL;

	return param_set_int(val, kp);
}


//register setter/getter in kernel by setting
//a struct as below and defining member values
//
static const struct kernel_param_ops param_ops = {
	.set	= my_set,
	.get	= param_get_int,
};




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
module_param_cb(simpcb, &param_ops, &num, 0664);