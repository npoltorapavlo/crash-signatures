# static-initialization-order

`exit/__run_exit_handlers`

```shell script
$  ./static-initialization-order-on-exit 
Input
keyPressed: 0
Segmentation fault (core dumped)

(gdb) bt
SIGSEGV
...
__run_exit_handlers
__GI_exit
```
