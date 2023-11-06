# a Kernel module that makes use of /proc files

There is a Linux directory where the kernel modules can be utilized somewhat as just files.

This is similar to what you can get through /sys/module, except /sys/module seems to only hold parameter values.

In /proc, modules can express many different kinds of values, both read and written.

Several authors I looked up had similar modules, but they used an older method which has been removed from the kernal libraries.

I found this one on StackOverflow at:

https://stackoverflow.com/questions/8516021/proc-create-example-for-kernel-module

Go to the answer at the very bottom of the post.