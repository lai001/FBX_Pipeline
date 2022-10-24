#include "Util.hpp"
#include <assert.h>
#include <fbxsdk.h>

namespace ks
{
    std::string Util::FbxUTF8ToAnsi(const char* pInUTF8)
    {
        assert(pInUTF8);
        size_t pOutUTF8Size;
        char* pOutANSI = nullptr;
        fbxsdk::FbxUTF8ToAnsi(pInUTF8, pOutANSI, &pOutUTF8Size);
        assert(pOutANSI);
        std::string str = std::string(pOutANSI);
        return str;
    }

    std::string Util::FbxAnsiToUTF8(const char* pInANSI)
    {
        assert(pInANSI);
        size_t pOutUTF8Size;
        char* pOutUTF8 = nullptr;
        fbxsdk::FbxAnsiToUTF8(pInANSI, pOutUTF8, &pOutUTF8Size);
        assert(pOutUTF8);
        std::string str = std::string(pOutUTF8);
        return str;
    }
}