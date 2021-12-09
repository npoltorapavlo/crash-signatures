# __cxa_pure_virtual

`__cxa_pure_virtual/abort`

> The __cxa_pure_virtual function is an error handler that is invoked when a pure virtual function is called.

```shell script
$ ./__cxa_pure_virtual-deleted 
~BaseClassWithPrintInDestructor
libc++abi: Pure virtual function called!

(lldb) bt
SIGABRT
abort
__cxa_pure_virtual
__cxa_pure_virtual-deleted
```

```shell script
$ ./__cxa_pure_virtual-deleted 
~BaseClassWithPrintInDestructor
pure virtual method called
terminate called without an active exception

(gdb) bt
SIGABRT
__GI_abort
??
std::terminate
__cxa_pure_virtual
```
