#include <unistd.h>

extern void dl2();
extern void dl3();

int main()
{
    dl2();
    dl3();
    sleep(2);

    return 0;
}
