#include <stddef.h>
#include <dlfcn.h>
#include <stdio.h>

static void *handle = NULL;

__attribute__((constructor)) static void frameworkLoad() {
  printf("Framework load\n");
}

__attribute__((destructor)) static void frameworkUnload() {
  printf("Framework unload\n");

  dlclose(handle);
}

void frameworkStart(int detachThread) {
  handle = dlopen("./libthread-terminate-plugin.so", RTLD_LOCAL | RTLD_NOW);
  void (*pluginHello)() = dlsym(handle, "pluginHello");
  pluginHello(detachThread);
}

void frameworkHello() {
  printf("Hello World (framework)\n");
}
