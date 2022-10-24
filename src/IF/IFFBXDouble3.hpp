#ifndef INTERMEDIATEFORMAT_IFFBXDOUBLE3_HPP
#define INTERMEDIATEFORMAT_IFFBXDOUBLE3_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::FbxDouble3>
    {
        static void to_json(json& j, const fbxsdk::FbxDouble3& p);

        static void from_json(const json& j, fbxsdk::FbxDouble3& p);
    };
}

#endif // !INTERMEDIATEFORMAT_IFFBXDOUBLE3_HPP