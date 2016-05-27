# C-Tutorial-Demos

Reference code for demonstrating esoteric, often annoying, features of C.

This repository has grown organically as I add codes to experiment due to requests from students, curiousity, or the need to puzzle out code found online or in projects.

A frequent pattern to them is that, since we are trying to understand not only behavior, but what is allowed, they contain code that works as well as commented code that does not work.

The best way to see what these are doing is to use the debugger. I use lldb on my Mac, but you may need to use gdb depending on your environment. They are similar.

The Makefile compiles the codes with debugging symbols included.

As an example, I can run *integerConversionRules* using the debugger to try to suss out how different primitive types are converted during runtime:

```
lldb ./integerConversionRules
(lldb) target create "./integerConversionRules"
Current executable set to './integerConversionRules' (x86_64).
(lldb) type format add --format dec char
(lldb) b main
Breakpoint 1: where = integerConversionRules`main + 24 at integerConversionRules.c:11, address = 0x0000000100000e98
(lldb) r
Process 9050 launched: './integerConversionRules' (x86_64)
```

From here, I can just step until I reach something interesting, then ask the debugger to dump all of the variables out :

```
(lldb) s
Process 9050 stopped
* thread #1: tid = 0x12d73f, 0x0000000100000ebe integerConversionRules`main(argc=1, argv=140734799805256) + 62 at integerConversionRules.c:22, queue = 'com.apple.main-thread', stop reason = step in
    frame #0: 0x0000000100000ebe integerConversionRules`main(argc=1, argv=140734799805256) + 62 at integerConversionRules.c:22
   19  		// x86 favor unsigned: -1UL > 1UL IE MAX > 1 TRUE
   20  		// x86_64 rank promotion -1L > 1L (U -> L)
   21  		// True on x86, false on x86_64
-> 22  		printf ("x86 -1L > 1U    %d\n",-1L > 1U);
   23  	
   24  	
   25  		// SCHAR_MAX == CHAR_MAX 
(lldb) frame variable
(int) argc = 1
(char **) argv = 140734799805256
(char) appleCharOp1 = 127
(char) appleCharOp2 = 127
(char) appleCharSum = -2
(int) appleIntSum = 254
(int) x = 0
```

Yay knowledge!

Here is a cow :cow:.  Here is some code:

* integerConversionRules.c 

