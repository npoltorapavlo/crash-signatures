#include <dlfcn.h>
#include <unistd.h>

int main()
{
    void* handle = dlopen("./libdl4.so", RTLD_LAZY);
    dlclose(handle);
    sleep(2);

    return 0;
}
