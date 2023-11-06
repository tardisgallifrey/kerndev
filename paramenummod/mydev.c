#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>   

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Liran B.H");


//module parameters
static int irq=10;
module_param(irq,int,0660);

static int debug=0;
module_param(debug,int,0660);

static char *devname = "mykerneldev";
module_param(devname,charp,0660);


//enum with different IRQ types
enum irq_type {
	IRQ_TYPE_LEVEL,
	IRQ_TYPE_EDGE,
	IRQ_TYPE_POLLING
};

//default variable set
static int irq_type = IRQ_TYPE_LEVEL; // default


//parameter write function (setter)
static int irqtype_op_write_handler(const char *val, const struct kernel_param *kp)
{
	char valcp[16];
	char *s;

	strncpy(valcp, val, 16);
	valcp[15] = '\0';

	s = strstrip(valcp);

	if (strcmp(s, "level") == 0)
		irq_type = IRQ_TYPE_LEVEL;
	else if (strcmp(s, "edge") == 0)
		irq_type = IRQ_TYPE_EDGE;
	else if (strcmp(s, "polling") == 0)
		irq_type = IRQ_TYPE_POLLING;
	else
		return -EINVAL;

	return 0;
}


//parameter read function (getter)
static int irqtype_op_read_handler(char *buffer, const struct kernel_param *kp)
{
	switch (irq_type) {
	case IRQ_TYPE_LEVEL:
		strcpy(buffer, "Level");
		break;

	case IRQ_TYPE_EDGE:
		strcpy(buffer, "Edge");
		break;

	case IRQ_TYPE_POLLING:
		strcpy(buffer, "Polling");
		break;

	default:
		strcpy(buffer, "error");
		break;
	}

	return strlen(buffer);
}

//register setter and getter functions in kernel param ops
static const struct kernel_param_ops irqtype_op_ops = {
	.set = irqtype_op_write_handler,
	.get = irqtype_op_read_handler
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
module_param_cb(irqtype, &irqtype_op_ops, NULL, 0660);