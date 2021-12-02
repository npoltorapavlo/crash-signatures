# __terminate

std::terminate/std::__terminate/abort/__cxa_throw/~thread

> If the thread is joinable when destroyed, terminate() is called. (<https://www.cplusplus.com/reference/thread/thread/~thread/>)

```shell script
$ ./__terminate-thread 
libc++abi: terminating

(lldb) bt
SIGABRT
abort
std::__terminate
std::terminate
~thread
```

> After a call to this function, the thread object becomes non-joinable and can be destroyed safely. (http://www.cplusplus.com/reference/thread/thread/detach/)

```shell script
./__terminate-thread-detach
```

> This function is automatically called when no catch handler can be found for a thrown exception. (<https://www.cplusplus.com/reference/exception/terminate/>)

```shell script
$ ./__terminate-throw 
libc++abi: terminating with uncaught exception of type int
Abort trap: 6

(lldb) bt
SIGABRT
abort
std::__terminate
__cxa_throw
```
