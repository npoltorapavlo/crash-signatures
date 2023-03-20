# external-linkage

`_dl_fini/__do_global_dtors_aux/__cxa_finalize/double free/SIGABRT`

If a global is static/const its scope is local (translation unit, or .cpp).
Otherwise a global has external linkage.
If an application is linked against several shared libraries that have similar globals with external linkage, at runtime only one will be used by all components of the process.
At exit, __cxa_finalize runs for each shared library and calls destructor on the same object, causing double free.
Same problem if several shared libraries link against the same static library that has a global with external linkage.
