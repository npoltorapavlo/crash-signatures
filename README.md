# crash-samples
Crash samples in C/C++

| Name | Signature |
| :-------- | :-------- |
| [__cxa_pure_virtual](__cxa_pure_virtual) | `__cxa_pure_virtual/abort` |
| [corrupted](corrupted) | `??` |
| [terminate](terminate) | `std::terminate/abort, ~thread, __cxa_throw, __clang_call_terminate` |
| [double-free](double-free) | __cxa_finalize destroys a global twice |
| [missing-return-statement](missing-return-statement) | undefined behavior |
| [race-condition](race-condition) | race condition |
| [static-initialization-order](static-initialization-order) | `exit/__run_exit_handlers` |

# build
The table below lists ways to build

| Type | Example |
| :-------- | :-------- |
| cmake | `git clean -fdx && cmake . && make` |
| yocto | `devtool add --autorev crash-samples "https://github.com/npoltorapavlo/crash-samples.git;branch=main" && devtool build crash-samples` |
