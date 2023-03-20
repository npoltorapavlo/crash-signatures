#include <cstdio>

extern int dl5();
extern int dl6();

int main()
{
    printf("%d\n", dl5()); // "100" printed
    printf("%d\n", dl6()); // "100" printed

    return 0;
}

// free(): double free detected in tcache 2
