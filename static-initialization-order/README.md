# static-initialization-order

`exit/__run_exit_handlers`

> To avoid static initialization problem, can use the Construct On First Use Idiom. Using a pointer will leak the object. Using object doesn’t leak the object, but it does not control the order of static deinitialization. To guarantee both static initialization and static deinitialization, use the Nifty Counter Idiom. (https://isocpp.org/wiki/faq/ctors#static-init-order)

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
