#ifndef INTERMEDIATEFORMAT_IFFBXEULERORDER_HPP
#define INTERMEDIATEFORMAT_IFFBXEULERORDER_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::FbxEuler::EOrder>
    {
        static void to_json(json& j, const fbxsdk::FbxEuler::EOrder& p);

        static void from_json(const json& j, fbxsdk::FbxEuler::EOrder& p);
    };
}

#endif // !INTERMEDIATEFORMAT_IFFBXEULERORDER_HPP
