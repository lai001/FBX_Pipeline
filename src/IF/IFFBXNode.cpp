#include "IFFBXNode.hpp"

#include "IFFBXDouble3.hpp"
#include "IFFbxVector4.hpp"
#include "IFFBXClassID.hpp"
#include "IFFBXGeometryElementNormal.hpp"
#include "IFFBXMesh.hpp"
#include "IFFbxNodePivot.hpp"
#include "IFFBXNodeAttribute.hpp"
#include "IFFBXEulerOrder.hpp"
#include "IFFBXQuatInterpMode.hpp"
#include "IFFBXAMatrix.hpp"
#include "Util.hpp"

namespace nlohmann
{
	void adl_serializer<fbxsdk::FbxNode> ::to_json(json& j, fbxsdk::FbxNode& p)
	{
		j = json
		{
			{"Name", ks::Util::FbxUTF8ToAnsi(p.GetName())},
			{"LclTranslation", p.LclTranslation.Get()},
			{"LclRotation", p.LclRotation.Get()},
			{"LclScaling", p.LclScaling.Get()},
			{"Pivots", p.GetPivots()},
			{"Visibility", p.GetVisibility()},
			{"ClassId", p.GetClassId()},
			{"TranslationMax", p.TranslationMax.Get()},
			{"IsTranslationActive", p.TranslationActive.Get()},
			{"EvaluateGlobalTransform", p.EvaluateGlobalTransform()},
			{"EvaluateLocalTransform", p.EvaluateLocalTransform()},
			{"EvaluateLocalRotation", p.EvaluateLocalRotation()},
			{"EvaluateLocalScaling", p.EvaluateLocalScaling()},
			{"EvaluateLocalTranslation", p.EvaluateLocalTranslation()},
		};
		
		{
			j["GeometricRotation"] = json
			{
				{"Value", p.GeometricRotation.Get()},
				{"SourcePivotRotation", p.GetGeometricRotation(fbxsdk::FbxNode::EPivotSet::eSourcePivot)},
				{"DestinationPivotRotation", p.GetGeometricRotation(fbxsdk::FbxNode::EPivotSet::eDestinationPivot)},
			};
			j["GeometricTranslation"] = json
			{
				{"Value", p.GeometricTranslation.Get()},
				{"SourcePivotTranslation", p.GetGeometricTranslation(fbxsdk::FbxNode::EPivotSet::eSourcePivot)},
				{"DestinationPivotTranslation", p.GetGeometricTranslation(fbxsdk::FbxNode::EPivotSet::eDestinationPivot)},
			};
			
			j["GeometricScaling"] = json
			{
				{"Value", p.GeometricScaling.Get()},
				{"SourcePivotScaling", p.GetGeometricScaling(fbxsdk::FbxNode::EPivotSet::eSourcePivot)},
				{"DestinationPivotScaling", p.GetGeometricScaling(fbxsdk::FbxNode::EPivotSet::eDestinationPivot)},
			};
			
			j["RotationOffset"] = json
			{
				{"Value", p.RotationOffset.Get()},
				{"SourcePivotRotationOffset", p.GetRotationOffset(fbxsdk::FbxNode::EPivotSet::eSourcePivot)},
				{"DestinationPivotRotationOffset", p.GetRotationOffset(fbxsdk::FbxNode::EPivotSet::eDestinationPivot)},
			};
			j["ScalingOffset"] = json
			{
				{"Value", p.ScalingOffset.Get()},
				{"SourcePivotScalingOffset", p.GetScalingOffset(fbxsdk::FbxNode::EPivotSet::eSourcePivot)},
				{"DestinationPivotScalingOffset", p.GetScalingOffset(fbxsdk::FbxNode::EPivotSet::eDestinationPivot)},
			};
		}

		if (fbxsdk::FbxMesh* Mesh = p.GetMesh())
		{
			j["MeshProp"] = *Mesh;
		}
		else
		{
			j["MeshProp"] = nullptr;
		}

		j["NodeAttributes"] = adl_serializer<fbxsdk::FbxNodeAttribute*>::to_json(p.GetNodeAttribute(), p.GetNodeAttributeCount());

		if (p.GetParent())
		{
			j["ParentNodeUniqueID"] = p.GetParent()->GetUniqueID();
			j["ParentNodeName"] = ks::Util::FbxUTF8ToAnsi(p.GetParent()->GetName());
		}
		else
		{
			j["ParentNodeUniqueID"] = nullptr;
			j["ParentNodeName"] = nullptr;
		}
		j["SelfUniqueID"] = p.GetUniqueID();

		std::vector<json> childs;
		for (int i = 0; i < p.GetChildCount(); i++)
		{
			const fbxsdk::FbxNode* lChildNode = p.GetChild(i);
			json child;
			child["SelfUniqueID"] = lChildNode->GetUniqueID();
			child["Name"] = ks::Util::FbxUTF8ToAnsi(lChildNode->GetName());
			childs.push_back(child);
		}
		if (childs.empty())
		{
			j["ChildNodes"] = nullptr;
		}
		else
		{
			j["ChildNodes"] = childs;
		}
	}

	void adl_serializer<fbxsdk::FbxNode>::from_json(const json& j, fbxsdk::FbxNode& p)
	{
		assert(false);
	}
}
