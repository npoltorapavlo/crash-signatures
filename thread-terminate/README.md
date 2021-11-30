# thread-terminate

thread terminate call stack

| Arg | Description | Default |
| :-------- | :-------- | :-------- |
| 1 | 1 to detach thread, 2 to join | |

```shell script
root@pacexi5:/opt# ./gdbserver localhost:11111 ./thread-terminate 
Process ./thread-terminate created; pid = 6084
Listening on port 11111
Remote debugging from host 10.42.0.1
Framework load
Plugin load
Hello World (plugin)
Hello World (framework)
terminate called without an active exception

$ gdb-multiarch ./thread-terminate
(gdb) thread apply all bt 

Thread 2 (Thread 6084.8484):
#0  0xb6f71dc6 in clone () from target:/lib/libc.so.6
#1  0xb6eb1850 in ?? () from target:/lib/libpthread.so.0
Backtrace stopped: previous frame identical to this frame (corrupt stack?)

Thread 1 (Thread 6084.6084):
#0  0xb6f09856 in ?? () from target:/lib/libc.so.6
#1  0xb6f154be in raise () from target:/lib/libc.so.6
#2  0xb6f16078 in abort () from target:/lib/libc.so.6
#3  0xb6e40af0 in __gnu_cxx::__verbose_terminate_handler() () from target:/usr/lib/libstdc++.so.6
#4  0xb6e3f7f8 in ?? () from target:/usr/lib/libstdc++.so.6
#5  0xb6e3f84e in std::terminate() () from target:/usr/lib/libstdc++.so.6
#6  0xb6ed1b16 in std::thread::~thread (this=<optimized out>, __in_chrg=<optimized out>) at /usr/include/c++/6.4.0/thread:146
#7  0xb6f16c88 in ?? () from target:/lib/libc.so.6
Backtrace stopped: previous frame identical to this frame (corrupt stack?)
(gdb) 
```
```shell script
$ ./thread-terminate 1
Framework load
Plugin load
Hello World (plugin)
Hello World (framework)
Plugin thread is detaching
Plugin thread is running
Plugin unload
Framework unload
```
```shell script
$ ./thread-terminate 2
Framework load
Plugin load
Plugin thread is running
Hello World (plugin)
Hello World (framework)
Plugin thread is detaching
Plugin thread has finished running
Plugin unload
Framework unload
```