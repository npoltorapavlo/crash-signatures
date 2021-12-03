#include <pthread.h>

#include <unistd.h>

pthread_t thread;

void *threadRun(void *) {
  while (true) {
    sleep(1);
  }
}

__attribute__((constructor)) static void load() {
  pthread_create(&thread, nullptr, (void* (*)(void*))threadRun, nullptr);
}
