# __cxa_finalize

`__cxa_finalize`

> Each shared library includes a copy of global variable from static library.
> However, at runtime only one will be used by all the components of the process.
> __cxa_finalize runs for each shared library and calls destructor on the same object.

```shell script
$ gdb ./__cxa_finalize
0x7ffff7fba060
0x7ffff7fba060

(gdb) b token::~token()
Breakpoint 1 at 0x7ffff7fb228e (2 locations)
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   <MULTIPLE>         
1.1                         y   0x00007ffff7fb228e <token::~token()+8>
1.2                         y   0x00007ffff7fb728e <token::~token()+8>
(gdb) i symbol 0x00007ffff7fb228e
token::~token() + 8 in section .text of .../libdl3.so
(gdb) i symbol 0x00007ffff7fb728e
token::~token() + 8 in section .text of .../libdl2.so
(gdb) i symbol 0x7ffff7fba060
global_token in section .bss of .../libdl2.so

Breakpoint 1, 0x00007ffff7fb728e in token::~token() () from .../libdl2.so
(gdb) bt
#0  0x00007ffff7fb728e in token::~token() () from .../libdl2.so
#1  0x00007ffff7dbba56 in __cxa_finalize (d=0x7ffff7fba048) at ./stdlib/cxa_finalize.c:83
#2  0x00007ffff7fb7197 in __do_global_dtors_aux () from .../libdl2.so
#3  0x00007fffffffdc80 in ?? ()
#4  0x00007ffff7fc924e in _dl_fini () at ./elf/dl-fini.c:142
Backtrace stopped: frame did not save the PC
(gdb) c
Continuing.
~0x7ffff7fba060

Breakpoint 1, 0x00007ffff7fb728e in token::~token() () from .../libdl2.so
(gdb) bt
#0  0x00007ffff7fb728e in token::~token() () from .../libdl2.so
#1  0x00007ffff7dbba56 in __cxa_finalize (d=0x7ffff7fb5048) at ./stdlib/cxa_finalize.c:83
#2  0x00007ffff7fb2197 in __do_global_dtors_aux () from .../libdl3.so
#3  0x00007fffffffdc80 in ?? ()
#4  0x00007ffff7fc924e in _dl_fini () at ./elf/dl-fini.c:142
Backtrace stopped: frame did not save the PC
(gdb) c
Continuing.
~0x7ffff7fba060
free(): double free detected in tcache 2
```