#ifndef INTERMEDIATEFORMAT_IFFBXAMATRIX_HPP
#define INTERMEDIATEFORMAT_IFFBXAMATRIX_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::FbxAMatrix>
    {
        static void to_json(json& j, const fbxsdk::FbxAMatrix& p);

        static void from_json(const json& j, fbxsdk::FbxAMatrix& p);
    };
}

#endif // !INTERMEDIATEFORMAT_IFFBXAMATRIX_HPP
