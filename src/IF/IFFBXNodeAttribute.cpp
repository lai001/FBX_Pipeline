#include "IFFBXNodeAttribute.hpp"

#include "Util.hpp"

namespace nlohmann
{
    std::string GetAttributeTypeName(const fbxsdk::FbxNodeAttribute::EType& type)
    {
        switch (type)
        {
        case fbxsdk::FbxNodeAttribute::eUnknown: return "Unknown";
        case fbxsdk::FbxNodeAttribute::eNull: return "Null";
        case fbxsdk::FbxNodeAttribute::eMarker: return "Marker";
        case fbxsdk::FbxNodeAttribute::eSkeleton: return "Skeleton";
        case fbxsdk::FbxNodeAttribute::eMesh: return "Mesh";
        case fbxsdk::FbxNodeAttribute::eNurbs: return "Nurbs";
        case fbxsdk::FbxNodeAttribute::ePatch: return "Patch";
        case fbxsdk::FbxNodeAttribute::eCamera: return "Camera";
        case fbxsdk::FbxNodeAttribute::eCameraStereo: return "CameraStereo";
        case fbxsdk::FbxNodeAttribute::eCameraSwitcher: return "CameraSwitcher";
        case fbxsdk::FbxNodeAttribute::eLight: return "Light";
        case fbxsdk::FbxNodeAttribute::eOpticalReference: return "OpticalReference";
        case fbxsdk::FbxNodeAttribute::eOpticalMarker: return "OpticalMarker";
        case fbxsdk::FbxNodeAttribute::eNurbsCurve: return "NurbsCurve";
        case fbxsdk::FbxNodeAttribute::eTrimNurbsSurface: return "TrimNurbsSurface";
        case fbxsdk::FbxNodeAttribute::eBoundary: return "Boundary";
        case fbxsdk::FbxNodeAttribute::eNurbsSurface: return "NurbsSurface";
        case fbxsdk::FbxNodeAttribute::eShape: return "Shape";
        case fbxsdk::FbxNodeAttribute::eLODGroup: return "LODGroup";
        case fbxsdk::FbxNodeAttribute::eSubDiv: return "SubDiv";
        default: return "Unknown";
        }
    }

	void adl_serializer<fbxsdk::FbxNodeAttribute>::to_json(json& j, const fbxsdk::FbxNodeAttribute& p)
	{
        const std::string typeName = GetAttributeTypeName(p.GetAttributeType());
        const char* attrName = p.GetName();
        const int NodeCount = p.GetNodeCount();
        const FbxUInt64 UniqueID = p.GetUniqueID();
        j = json
        {
            {"AttributeTypeName", typeName },
            {"AttributeName", ks::Util::FbxUTF8ToAnsi(attrName) },
            {"NodeCount", NodeCount },
            {"UniqueID", UniqueID },
		};
	}

    void adl_serializer<fbxsdk::FbxNodeAttribute>::from_json(const json& j, fbxsdk::FbxNodeAttribute& p)
	{
		assert(false);
	}    

    json adl_serializer<fbxsdk::FbxNodeAttribute*>::to_json(const fbxsdk::FbxNodeAttribute* p, const int count)
    {
        std::vector<json> values;
        for (int i = 0; i < count; i++)
        {
            values.push_back(p[i]);
        }
        return json{ values };
    }

    void adl_serializer<fbxsdk::FbxNodeAttribute*>::from_json(const json& j, fbxsdk::FbxNodeAttribute* p)
	{
		assert(false);
	}
}