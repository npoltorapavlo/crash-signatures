#include "dl5.h"
#include "dl6.h"

int main()
{
    printf("%s\n", getErrorDescription1(ErrorCode::OK).c_str());
    printf("%s\n", getErrorDescription2(ErrorCode::FileNotPresent).c_str());
    return 0;
}
