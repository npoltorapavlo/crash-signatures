#include <cstdio>

struct token {
    struct foo {
    };
    foo* _foo;
    token()
        : _foo(new foo)
    {
        printf("%p\n", this);
    }
    ~token()
    {
        printf("~%p\n", this);
        delete _foo;
    }
};

token global_token;

void dl1() {}
