# crash-samples
Crash samples in C/C++

| Name | Signature |
| :-------- | :-------- |
| [__cxa_pure_virtual](__cxa_pure_virtual) | __cxa_pure_virtual/abort |
| [corrupted](corrupted) | ?? |
| [terminate](terminate) | std::terminate/abort/std::thread::~thread/__cxa_throw |

# build
The table below lists ways to build

| Type | Example |
| :-------- | :-------- |
| cmake | git clean -fdx && cmake . && make |
| yocto | devtool add --autorev crash-samples \\<br>"https://github.com/npoltorapavlo/crash-samples.git;branch=main"<br>devtool build crash-samples<br>devtool reset crash-samples<br>rm -rf workspace/sources/crash-samples |
