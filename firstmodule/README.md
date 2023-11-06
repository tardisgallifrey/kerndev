# First attempt at writing/copying Linux kernel mod

I found the lesson for this on medium.com at:

https://medium.com/dvt-engineering/how-to-write-your-first-linux-kernel-module-cf284408beeb

The author is Ruan de Bruyn.

The module works at the beginning portion, but the later portion has problems. It seems to be from an older kernel.  I have found that kernel functions in the library can change dramatically.

Good for the first instance, but didn't keep me going.

The Makefile is not from the lesson.  I discovered it while watching Youtube videos.  It is outlined here:

https://www.youtube.com/watch?v=4tgluSJDA_E

When we run make, the Makefile tells make to go to a certain directory and run the Makefile there.

The "shell uname -r" variable gets our kernel's pattern and runs the make from that folder in the library.  The PWD command tells that Makefile to target the current directory for compilation.

By appending "modules" on the end, make compiles and links.

By appending "clean" on the end, make already has a "clean" make function built into the library.

I am copying this Makefile throughout the folders.