# crash-signatures
Crash signatures in C/C++

| Name | Signature |
| :-------- | :-------- |
| [__cxa_finalize](__cxa_finalize) | `__cxa_finalize` |
| [__cxa_pure_virtual](__cxa_pure_virtual) | `__cxa_pure_virtual/SIGABRT` |
| [__run_exit_handlers](__run_exit_handlers) | `__run_exit_handlers` |
| [_M_realloc_insert](_M_realloc_insert) | `std::vector<...>::_M_realloc_insert/SIGSEGV` |
| [corrupted](corrupted) | `??/SIGSEGV` |
| [missing-return-statement](missing-return-statement) | undefined behavior |
| [std-terminate](std-terminate) | `std::terminate/SIGABRT` |

# build
The table below lists ways to build

| Type | Example |
| :-------- | :-------- |
| cmake | `git clean -fdx && cmake . && make` |
| yocto | `devtool add --autorev crash-signatures "https://github.com/npoltorapavlo/crash-signatures.git;branch=main" && devtool build crash-signatures` |
