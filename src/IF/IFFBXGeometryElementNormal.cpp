#include "IFFBXGeometryElementNormal.hpp"
#include "IFFbxVector4.hpp"

namespace nlohmann
{
    json adl_serializer<fbxsdk::FbxGeometryElementNormal*>::to_json(const fbxsdk::FbxGeometryElementNormal* p, const int ControlPointsCount)
    {
        assert(p);
        std::vector<fbxsdk::FbxDouble4> values;
        for (int i = 0; i < ControlPointsCount; i++)
        {
            if (p->GetMappingMode() == FbxGeometryElement::eByControlPoint)
            {
                if (p->GetReferenceMode() == FbxGeometryElement::eDirect || p->GetReferenceMode() == FbxGeometryElement::eIndexToDirect)
                {
                    fbxsdk::FbxVector4 NormalVector = p->GetDirectArray().GetAt(i);
                    values.push_back(NormalVector);
                }
            }
        }
        if (values.empty())
        {
            return nullptr;
        }
        else
        {
            return json { values };
        }
    }

    void adl_serializer<fbxsdk::FbxGeometryElementNormal*>::from_json(const json& j, fbxsdk::FbxGeometryElementNormal* p)
    {
        assert(false);
    }
}
