#include <climits>
#include <string>
#include <thread>
#include <vector>

int main()
{
    std::vector<std::string> v;

    std::thread t1([&]() {
        for (int i = 0; i < INT_MAX; i++) {
            v.emplace_back(std::to_string(i));
        }
    });

    std::thread t2([&]() {
        for (int i = 0; i < INT_MAX; i++) {
            v.emplace_back(std::to_string(i));
        }
    });

    t1.join();
    t2.join();

    return 0;
}
