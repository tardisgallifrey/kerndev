#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

MODULE_LICENSE("GPL");

//This is the proper method to create a /proc entry and 
//return something 

//This function creates a "file" with data for content
static int hello_proc_show(struct seq_file *m, void *v) {
  seq_printf(m, "Hello proc!\n");
  return 0;
}


//This creates the open method to load up the "file" in /proc
static int hello_proc_open(struct inode *inode, struct  file *file) {
  return single_open(file, hello_proc_show, NULL);
}

//This is how to register (create)  the /proc entry
static const struct proc_ops hello_proc_fops = {
  .proc_open = hello_proc_open,
  .proc_read = seq_read,
  .proc_lseek = seq_lseek,
  .proc_release = single_release,
};

//init function for the module
static int __init hello_proc_init(void) {
  proc_create("hello_proc", 0, NULL, &hello_proc_fops);
  return 0;
}


//exit function for the module
static void __exit hello_proc_exit(void) {
  remove_proc_entry("hello_proc", NULL);
}

//register module functions
module_init(hello_proc_init);
module_exit(hello_proc_exit);
