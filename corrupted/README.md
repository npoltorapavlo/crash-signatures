# corrupted

?? (corrupted stack)

```shell script
$ ./corrupted-pthread
Segmentation fault (core dumped)

(gdb) bt
SIGSEGV
??
```
```shell script
$ ./corrupted-gloop 
load
unload
Segmentation fault (core dumped)

(gdb) bt
SIGSEGV
??
g_main_context_dispatch
g_main_loop_run
```
