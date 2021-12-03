#include <unistd.h>

#include <dlfcn.h>

int main() {
  void *handle = dlopen("./libdl1.so", RTLD_LAZY);

  dlclose(handle);

  sleep(2);

  return 0;
}
