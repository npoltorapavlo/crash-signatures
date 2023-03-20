#include <dlfcn.h>
#include <unistd.h>

int main()
{
    void* handle = dlopen("./libdl4.so", RTLD_LAZY);
    dlclose(handle);

    sleep(2); // Segmentation fault with address "??"

    return 0;
}
