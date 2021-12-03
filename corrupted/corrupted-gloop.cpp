#include <unistd.h>

#include <dlfcn.h>

int main() {
  void *handle = dlopen("./libdl-gloop.so", RTLD_LAZY);

  sleep(5);

  dlclose(handle);

  sleep(5);

  return 0;
}
