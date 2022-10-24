#ifndef FBX_PIPELINE_SRC_UTIL_HPP
#define FBX_PIPELINE_SRC_UTIL_HPP

#include <string>

namespace ks
{
    struct Util
    {
        static std::string FbxUTF8ToAnsi(const char* pInANSI);
        static std::string FbxAnsiToUTF8(const char* pInANSI);
    };
}

#endif // !FBX_PIPELINE_SRC_UTIL_HPP
