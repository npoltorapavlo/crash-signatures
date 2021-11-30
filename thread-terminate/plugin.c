#include <stdio.h>

__attribute__((constructor)) static void pluginLoad() {
  printf("Plugin load\n");
}

__attribute__((destructor)) static void pluginUnload() {
  printf("Plugin unload\n");
}

extern void frameworkHello();
extern void pluginGlobalThreadDetach();

void pluginHello(int detachThread) {
  printf("Hello World (plugin)\n");

  frameworkHello();

  pluginGlobalThreadDetach(detachThread);
}
