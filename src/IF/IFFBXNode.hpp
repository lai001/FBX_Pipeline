#ifndef INTERMEDIATEFORMAT_IFNODE_HPP
#define INTERMEDIATEFORMAT_IFNODE_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::FbxNode> 
    {
        static void to_json(json& j, fbxsdk::FbxNode& p);

        static void from_json(const json& j, fbxsdk::FbxNode& p);
    };
}

#endif
