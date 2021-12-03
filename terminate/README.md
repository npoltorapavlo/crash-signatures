# terminate

std::terminate/abort/std::thread::~thread/__cxa_throw

> If the thread is joinable when destroyed, terminate() is called. (<https://www.cplusplus.com/reference/thread/thread/~thread/>)

```shell script
$ ./terminate-thread 
libc++abi: terminating

(lldb) bt
SIGABRT
abort
std::__terminate
std::terminate
std::thread::~thread
```
```shell script
$ ./terminate-thread 
terminate called without an active exception

(gdb) bt
SIGABRT
__GI_abort
??
std::terminate
std::thread::~thread
```

> After a call to this function, the thread object becomes non-joinable and can be destroyed safely. (http://www.cplusplus.com/reference/thread/thread/detach/)

```shell script
./terminate-thread-detach
```

> This function is automatically called when no catch handler can be found for a thrown exception. (<https://www.cplusplus.com/reference/exception/terminate/>)

```shell script
$ ./terminate-throw 
libc++abi: terminating with uncaught exception of type int

(lldb) bt
SIGABRT
abort
std::__terminate
__cxa_throw
```
```shell script
$ ./terminate-throw 
terminate called after throwing an instance of 'int'

(gdb) bt
SIGABRT
__GI_abort
??
std::terminate
__cxa_throw
```
