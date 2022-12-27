#include "dl6.h"

#include <map>

std::map<ErrorCode, std::string> ErrCodeMap = {
    { FileNotPresent, "File not found" },
    { FileAccessFailed, "File access failed" },
};

std::string getErrorDescription2(ErrorCode errCode)
{
    std::string errMsg;

    auto it = ErrCodeMap.find(errCode);
    if (ErrCodeMap.end() != it) {
        errMsg = it->second;
    }
    return errMsg;
}
