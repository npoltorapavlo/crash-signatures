#include <cstdio>

class token {
public:
  token() : _foo(new foo) { printf("%s %p\n", __FUNCTION__, this); }
  ~token() {
    printf("%s %p\n", __FUNCTION__, this);
    delete _foo;
  }
  token(const token &) = delete;
  void operator=(const token &) = delete;

private:
  class foo {
  };
  foo *_foo;
};

token _token;

void token1() {}
