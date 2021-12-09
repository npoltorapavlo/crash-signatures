#include <exception>

#include <cstdio>

class ClassWithThrowInDestructor {
public:
  ~ClassWithThrowInDestructor() noexcept(false) { throw std::exception(); }
};

int main() {
  try {
    ClassWithThrowInDestructor classWithThrowInDestructor;
  } catch (...) {
    printf("catch first\n");
  }

  try {
    ClassWithThrowInDestructor classWithThrowInDestructor;

    throw 1;
  } catch (...) {
    printf("catch second\n");
  }
}
