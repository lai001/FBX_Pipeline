#include "IFFbxNodePivot.hpp"

#include "IFFBXQuatInterpMode.hpp"
#include "IFFBXEulerOrder.hpp"
#include "IFFbxVector4.hpp"

namespace nlohmann
{
    void adl_serializer<fbxsdk::FbxNode::EPivotState>::to_json(json& j, const fbxsdk::FbxNode::EPivotState& p)
    {
        std::vector<std::string> names = { "PivotActive", "PivotReference" };

        j = json
        {
            {"PivotState", names[static_cast<int>(p)]}
        };
    }

    void adl_serializer<fbxsdk::FbxNode::EPivotState>::from_json(const json& j, fbxsdk::FbxNode::EPivotState& p)
    {
        assert(false);
    }

     void adl_serializer<fbxsdk::FbxNode::Pivot>::to_json(json& j, fbxsdk::FbxNode::Pivot& p)
    {
        j = json
        {
            {"GeometricRotation", p.GetGeometricRotation()},
            {"GeometricScaling", p.GetGeometricScaling()},
            {"GeometricTranslation", p.GetGeometricTranslation()},
            {"PostRotation", p.GetPostRotation()},
            {"PreRotation", p.GetPreRotation()},
            {"RotationOffset", p.GetRotationOffset()},
            {"RotationPivot", p.GetRotationPivot()},
            {"RotationSpaceForLimitOnly", p.GetRotationSpaceForLimitOnly()},
            {"ScalingOffset", p.GetScalingOffset()},
            {"ScalingPivot", p.GetScalingPivot()},
            {"PivotState", p.GetPivotState()},
            {"QuaternionInterpolate", p.GetQuaternionInterpolate()},
            {"RotationOrder", p.GetRotationOrder()},
        };
    }

    void adl_serializer<fbxsdk::FbxNode::Pivot>::from_json(const json& j, fbxsdk::FbxNode::Pivot& p)
    {
        assert(false);
    }


    void adl_serializer<fbxsdk::FbxNode::Pivots>::to_json(json& j, fbxsdk::FbxNode::Pivots& p)
    {
        j = json
        {
            {"Pivot0", p.Get(0)},
            {"Pivot1", p.Get(1)},
        };
    }

    void adl_serializer<fbxsdk::FbxNode::Pivots>::from_json(const json& j, fbxsdk::FbxNode::Pivots& p)
    {
        assert(false);
    }
}
