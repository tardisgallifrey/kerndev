#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>   

#define SIZE 8

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Liran B.H");


//module parameters
//declaring an array as a parameter uses a different
//function
static int addr[SIZE];
static int count;
/*
addr is a pointer since it is defined as an array,
int means the addr array contains integers,
&count is an output, the number of elements the user lists in insmod,
0660 is permissions
*/
module_param_array(addr, int, &count,  0660);



//init function
static int simple_init(void)
{
	//printk() like printf() uses variables and keys
	printk(KERN_INFO "hello...");
	return 0;
}

//exit function
static void simple_cleanup(void)
{
	printk(KERN_WARNING "bye...");
}

//register our functions
module_init(simple_init);
module_exit(simple_cleanup);