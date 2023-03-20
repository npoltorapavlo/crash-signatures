#include <map>

std::map<int, int> ErrCodeMap = {
    { 0, 100 },
    { 1, 101 },
    { 2, 102 },
    { 3, 103 },
    { 4, 104 },
    { 5, 105 },
};

int dl5()
{
    return ErrCodeMap.at(0);
}
