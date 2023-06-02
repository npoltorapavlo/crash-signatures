#include <pthread.h>
#include <unistd.h>

pthread_t thread;

void* threadRun(void*)
{
    for (int i = 0; i < 10; i++) {
        sleep(1);
    }
    return nullptr;
}

__attribute__((constructor)) static void load()
{
    pthread_create(&thread, nullptr, (void* (*)(void*))threadRun, nullptr);
}
