#include <exception>

#include <cstdio>

class ClassWithThrowInDestructor {
public:
  ~ClassWithThrowInDestructor() { throw std::exception(); }
};

int main() {
  try {
    ClassWithThrowInDestructor classWithThrowInDestructor;
  } catch (...) {
    printf("catch\n");
  }
}
