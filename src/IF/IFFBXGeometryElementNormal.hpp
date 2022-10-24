#ifndef INTERMEDIATEFORMAT_IFFBXGEOMETRYELEMENTNORMAL_HPP
#define INTERMEDIATEFORMAT_IFFBXGEOMETRYELEMENTNORMAL_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
    template <>
    struct adl_serializer<fbxsdk::FbxGeometryElementNormal*>
    {
        static json to_json(const fbxsdk::FbxGeometryElementNormal* p, const int ControlPointsCount);

        static void from_json(const json& j, fbxsdk::FbxGeometryElementNormal* p);
    };
}

#endif // !INTERMEDIATEFORMAT_IFFBXGEOMETRYELEMENTNORMAL_HPP