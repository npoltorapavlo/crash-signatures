# __cxa_pure_virtual

__cxa_pure_virtual/abort/__cxa_pure_virtual-deleted

```shell script
$ ./__cxa_pure_virtual-constructor 
libc++abi: Pure virtual function called!

(lldb) bt
SIGABRT
abort
__cxa_pure_virtual
```

```shell script
$ ./__cxa_pure_virtual-destructor 
libc++abi: Pure virtual function called!

(lldb) bt
SIGABRT
abort
__cxa_pure_virtual
```

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
