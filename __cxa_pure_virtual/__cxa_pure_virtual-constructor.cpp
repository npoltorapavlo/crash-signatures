class BaseClassCallingVirtualInConstructor {
public:
  BaseClassCallingVirtualInConstructor() { pureVirtualFunction(); }

  virtual void pureVirtualFunction() = 0;
};

template <class BASE>
class DerivedClass : public BASE {
public:
  void pureVirtualFunction() {}
};

int main(int argc, char** argv) {
  DerivedClass<BaseClassCallingVirtualInConstructor> d;

  return 0;
}
