# Kernel module with parameters

This is from the same author as the /betterfirstmod module.

It is from:

https://devarea.com/linux-kernel-development-kernel-module-parameters/

This adds in the concept of simple module arguments, things you might want to set at module load time (sudo insmod mymod arg1 value arg2 value).

This process is fairly straightforward.  Author noted that there is no validation or checking to see if the argument values are correct or in the right range.

See /paramvalidatemod for that feature.

