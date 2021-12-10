#include <pthread.h>

#include <cstdio>
#include <cerrno>

struct Ctx {
  pthread_t threadId;
  bool modeEnabled;
  char response[256];
};

static Ctx *gCtx = 0;

static void *connectionThread( void *arg ) {
  Ctx *ctx = (Ctx *) arg;

  sprintf(ctx->response, "%d: mode %d", 0, gCtx->modeEnabled);

  return nullptr;
}

Ctx* CtxInit() {
  Ctx *ctx = new Ctx;

  pthread_attr_t attr;

  if (pthread_attr_init(&attr)) {
    printf("unable to init pthread attr: errno %d\n", errno);
  }

  if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED)) {
    printf("unable to set pthread attr detached: errno %d\n", errno);
  }

  pthread_create(&ctx->threadId, &attr, connectionThread, ctx);

  return ctx;
}

int main() {
  gCtx = CtxInit();

  return 0;
}
