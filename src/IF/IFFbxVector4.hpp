#ifndef INTERMEDIATEFORMAT_IFFBXVECTOR4_HPP
#define INTERMEDIATEFORMAT_IFFBXVECTOR4_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::FbxDouble4>
    {
        static void to_json(json& j, const fbxsdk::FbxDouble4& p);

        static void from_json(const json& j, fbxsdk::FbxDouble4& p);
    };

    template <>
    struct adl_serializer<fbxsdk::FbxDouble4*>
    {
        static json to_json(fbxsdk::FbxDouble4* p, const int nums);

        static void from_json(const json& j, fbxsdk::FbxDouble4* p);
    };
}

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::FbxVector4>
    {
        static void to_json(json& j, const fbxsdk::FbxVector4& p);

        static void from_json(const json& j, fbxsdk::FbxVector4& p);
    };

    template <>
    struct adl_serializer<fbxsdk::FbxVector4*>
    {
        static json to_json(fbxsdk::FbxVector4* p, const int nums);

        static void from_json(const json& j, fbxsdk::FbxVector4* p);
    };
}

#endif // !INTERMEDIATEFORMAT_IFFBXVECTOR4_HPP