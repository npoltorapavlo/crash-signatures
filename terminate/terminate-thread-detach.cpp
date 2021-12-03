#include <thread>

int main() {
  {
    std::thread t([]() {});
    t.detach();
  }

  return 0;
}
