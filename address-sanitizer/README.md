# address-sanitizer

* `-fsanitize=address` - in both C(XX) and LD flags
* `-fno-omit-frame-pointer` - nicer stack traces
* `-fsanitize-recover=address` - attempt to continue as if no error happened
* `ASAN_OPTIONS=halt_on_error=0` - don't exit on first error
* `ASAN_OPTIONS=exitcode=0` - exit code if exit on error
* `ASAN_OPTIONS=fast_unwind_on_malloc=0:malloc_context_size=2` - nicer stack traces
* `ASAN_OPTIONS=detect_leaks=0` - disable memory leak detection
