#include <dlfcn.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int detachThread = ((argc > 1) ? atoi(argv[1]) : 0);

  void *handle = dlopen("./libthread-terminate-framework.so", RTLD_GLOBAL | RTLD_NOW);
  void (*frameworkStart)() = dlsym(handle, "frameworkStart");
  frameworkStart(detachThread);
  dlclose(handle);

  return 0;
}
