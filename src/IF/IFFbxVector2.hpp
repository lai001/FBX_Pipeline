#ifndef INTERMEDIATEFORMAT_IFFBXVECTOR2_HPP
#define INTERMEDIATEFORMAT_IFFBXVECTOR2_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::FbxVector2>
    {
        static void to_json(json& j, const fbxsdk::FbxVector2& p);

        static void from_json(const json& j, fbxsdk::FbxVector2& p);
    };

    template <>
    struct adl_serializer<fbxsdk::FbxVector2*>
    {
        static json to_json(fbxsdk::FbxVector2* p, const int nums);

        static void from_json(const json& j, fbxsdk::FbxVector2* p);
    };
}

#endif // !INTERMEDIATEFORMAT_IFFBXVECTOR2_HPP