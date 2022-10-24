#ifndef INTERMEDIATEFORMAT_IFFBXNODEPIVOT_HPP
#define INTERMEDIATEFORMAT_IFFBXNODEPIVOT_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::FbxNode::EPivotState>
    {
        static void to_json(json& j, const fbxsdk::FbxNode::EPivotState& p);

        static void from_json(const json& j, fbxsdk::FbxNode::EPivotState& p);
    };

    template <>
    struct adl_serializer<fbxsdk::FbxNode::Pivot>
    {
        static void to_json(json& j, fbxsdk::FbxNode::Pivot& p);

        static void from_json(const json& j, fbxsdk::FbxNode::Pivot& p);
    };

    template <>
    struct adl_serializer<fbxsdk::FbxNode::Pivots>
    {
        static void to_json(json& j, fbxsdk::FbxNode::Pivots& p);

        static void from_json(const json& j, fbxsdk::FbxNode::Pivots& p);
    };
}

#endif // !INTERMEDIATEFORMAT_IFFBXNODEPIVOT_HPP
