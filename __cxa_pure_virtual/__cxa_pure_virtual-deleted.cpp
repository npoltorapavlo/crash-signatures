#include <stdio.h>

class BaseClassWithPrintInDestructor {
public:
  virtual ~BaseClassWithPrintInDestructor() { printf("%s\n", __FUNCTION__); }

  virtual void pureVirtualFunction() = 0;
};

template <class BASE>
class DerivedClass : public BASE {
public:
  void pureVirtualFunction() {}
};

int main(int argc, char** argv) {
  BaseClassWithPrintInDestructor *b = nullptr;

  {
    DerivedClass<BaseClassWithPrintInDestructor> d;
    b = &d;
  }

  b->pureVirtualFunction();

  return 0;
}
