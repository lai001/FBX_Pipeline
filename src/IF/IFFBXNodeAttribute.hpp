#ifndef INTERMEDIATEFORMAT_IFFBXNODEATTRIBUTE_HPP
#define INTERMEDIATEFORMAT_IFFBXNODEATTRIBUTE_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::FbxNodeAttribute>
    {
        static void to_json(json& j, const fbxsdk::FbxNodeAttribute& p);

        static void from_json(const json& j, fbxsdk::FbxNodeAttribute& p);
    };

    template <>
    struct adl_serializer<fbxsdk::FbxNodeAttribute*>
    {
        static json to_json(const fbxsdk::FbxNodeAttribute* p, const int count);

        static void from_json(const json& j, fbxsdk::FbxNodeAttribute* p);
    };
}

#endif // !INTERMEDIATEFORMAT_IFFBXNODEATTRIBUTE_HPP
