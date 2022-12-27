#include "dl5.h"

#include <map>

std::map<ErrorCode, std::string> ErrCodeMap = {
    { OK, "OK" },
    { MethodNotFound, "Method not found" },
    { MissingKeyValues, "Missing key/value(s)" },
    { FileNotPresent, "File not found" },
    { FileAccessFailed, "File access failed" },
    { Unexpected, "Unexpected error" },
};

std::string getErrorDescription1(ErrorCode errCode)
{
    std::string errMsg;

    auto it = ErrCodeMap.find(errCode);
    if (ErrCodeMap.end() != it) {
        errMsg = it->second;
    }
    return errMsg;
}
