# crash-samples
Crash samples in C/C++

| Name | Dependencies | Description |
| :-------- | :-------- | :-------- |
| [destructed-twice](destructed-twice) | | global destructed twice |
| [global-qthread](global-qthread) | qt, libc | global QThread segv |
| [corrupt-stack](corrupt-stack) | dl, pthread | segv with '??' callstack |
| [quit-gmain-loop](quit-gmain-loop) | dl, pthread, glib-2.0 | GMainLoop segv on dlclose |
| [rfcapi-test](rfcapi-test) | [rfcapi](https://code.rdkcentral.com/r/admin/repos/rdk/components/generic/rfc) | rfcapi overflow |
| [thread-terminate](thread-terminate) | pthread | thread terminate call stack |

# build
The table below lists ways to build

| Type | Example |
| :-------- | :-------- |
| cmake | git clean -fdx && cmake . && make |
| yocto | devtool add --autorev crash-samples \\<br>"https://github.com/npoltorapavlo/crash-samples.git;branch=main"<br>devtool build crash-samples<br>devtool reset crash-samples<br>rm -rf workspace/sources/crash-samples |
