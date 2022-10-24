#ifndef INTERMEDIATEFORMAT_IFFBXQUATINTERPMODE_HPP
#define INTERMEDIATEFORMAT_IFFBXQUATINTERPMODE_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::EFbxQuatInterpMode>
    {
        static void to_json(json& j, const fbxsdk::EFbxQuatInterpMode& p);

        static void from_json(const json& j, fbxsdk::EFbxQuatInterpMode& p);
    };
}

#endif // !INTERMEDIATEFORMAT_IFFBXQUATINTERPMODE_HPP
