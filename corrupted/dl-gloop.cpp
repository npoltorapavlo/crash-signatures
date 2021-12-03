#include <glib.h>

#include <pthread.h>

#include <unistd.h>
#include <cstdio>

GMainLoop *Gloop = nullptr;

pthread_t a_thread;

static guint work_id = 0;

static gboolean work(gpointer data) {
  sleep(1);

  return TRUE;
}

void * Loop(void* data) {
  if (Gloop) {
    g_main_loop_run(Gloop);

    g_main_loop_unref(Gloop);
  }

  return nullptr;
}

__attribute__((constructor)) static void load (void) {
  printf("%s\n", __FUNCTION__);

  Gloop = g_main_loop_new(nullptr, FALSE);

  pthread_create(&a_thread, nullptr, Loop, nullptr);

  pthread_detach(a_thread);

  work_id = g_timeout_add_seconds(1, work, Gloop);
}

__attribute__((destructor)) static void unload() {
  printf("%s\n", __FUNCTION__);

  g_main_loop_quit(Gloop);
}
