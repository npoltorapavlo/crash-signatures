#include <map>

std::map<int, int> ErrCodeMap = {
    { 0, 200 },
    { 1, 201 },
};

int dl6()
{
    return ErrCodeMap.at(0);
}
