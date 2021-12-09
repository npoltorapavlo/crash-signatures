# double-free

__cxa_finalize destroys a global twice

```shell script
./double-free-global 
token 0x7ffff7fc6060
token 0x7ffff7fc6060
~token 0x7ffff7fc6060
~token 0x7ffff7fc6060
free(): double free detected in tcache 2

(gdb) bt
SIGABRT
malloc_printerr (str=str@entry=0x7ffff7f715d0 "free(): double free detected in tcache 2") at malloc.c:5347
..
__cxa_finalize
_do_global_dtors_aux

(gdb) b token::~token()
Breakpoint 1 at 0x7ffff7fbe286 (2 locations)
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   <MULTIPLE>         
1.1                         y   0x00007ffff7fbe286 <token::~token()>
1.2                         y   0x00007ffff7fc3286 <token::~token()>

$ readelf -d double-free-global|grep double-free-dl
 0x0000000000000001 (NEEDED)             Shared library: [libdouble-free-dl2.so]
 0x0000000000000001 (NEEDED)             Shared library: [libdouble-free-dl3.so]
$ cat /proc/$(pidof double-free-global)/maps |grep double-free-dl| grep r-xp
7ffff7fbe000-7ffff7fbf000 r-xp 00001000 08:02 7810091                    libdouble-free-dl3.so
7ffff7fc3000-7ffff7fc4000 r-xp 00001000 08:02 7810097                    libdouble-free-dl2.so
```