#include <thread>
#include <chrono>

// a thread is neither joined nor detached

std::thread pluginGlobalThread([] {
  printf("Plugin thread is running\n");

  std::this_thread::sleep_for(std::chrono::seconds(3));

  printf("Plugin thread has finished running\n");
});

extern "C" {

void pluginGlobalThreadDetach(int detachThread) {
  printf("Plugin thread is detaching\n");

  if (detachThread == 1)
    pluginGlobalThread.detach();
  else if (detachThread == 2)
    pluginGlobalThread.join();
}

} // extern "C"
