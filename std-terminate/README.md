# std-terminate

`std::terminate/SIGABRT`

std::terminate abort can occur in cases described in https://en.cppreference.com/w/cpp/error/terminate.
Most commonly, it can be an exception is thrown and not caught, or a joinable std::thread is destroyed or assigned to.
