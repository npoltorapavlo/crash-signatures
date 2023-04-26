# malloc

`operator new/__libc_malloc/malloc_consolidate/SIGABRT`

Any core dump inside malloc always indicates heap corruption.
This would require asan build or valgrind to check what's going on.
