#include <cstdio>

class Base {
public:
    virtual ~Base() { printf("%s\n", __FUNCTION__); }

    virtual void pureVirtual() = 0;
};

class Derived : public Base {
public:
    void pureVirtual() { printf("%s\n", __FUNCTION__); }
};

int main(int argc, char** argv)
{
    Base* b = nullptr;

    {
        Derived d;
        b = &d;
        b->pureVirtual();
    }

    b->pureVirtual();

    return 0;
}
