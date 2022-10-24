#include "IFFBXScene.hpp"
#include <vector>
#include <functional>
#include "IFFBXDocumentInfo.hpp"
#include "IFFBXNode.hpp"
#include "Util.hpp"

namespace nlohmann
{
	std::vector<fbxsdk::FbxNode*> FlatNodes(fbxsdk::FbxNode& lRootNode)
	{
		std::vector<fbxsdk::FbxNode*> lNodes;
		std::function<void(fbxsdk::FbxNode*)> Loop = nullptr;
		Loop = [&lNodes, &Loop](fbxsdk::FbxNode* Node)
		{
			lNodes.push_back(Node);
			for (int i = 0; i < Node->GetChildCount(); i++)
			{
				fbxsdk::FbxNode* lChildNode = Node->GetChild(i);
				Loop(lChildNode);
			}
		};
		Loop(&lRootNode);
		return lNodes;
	}

	void nlohmann::adl_serializer<fbxsdk::FbxScene>::to_json(json& j, fbxsdk::FbxScene& lScene)
	{
		j = json
		{
			{"Name", ks::Util::FbxUTF8ToAnsi(lScene.GetName())},
			{"SelfUniqueID", lScene.GetUniqueID()},
			{"RootMemberCount", lScene.GetRootMemberCount()},
		};

		if (lScene.GetRootDocument())
		{
			fbxsdk::FbxDocument* lRootDocument = lScene.GetRootDocument();
			j["RootDocumentInfo"] = *lRootDocument->GetDocumentInfo();
		}
		else
		{
			j["RootDocumentInfo"] = nullptr;
		}

		if (lScene.GetRootNode())
		{
			fbxsdk::FbxNode* RootNode = lScene.GetRootNode();
			j["RootNodeUniqueID"] = RootNode->GetUniqueID();
			std::vector<fbxsdk::FbxNode*> Nodes = FlatNodes(*RootNode);
			std::vector<json> NodesJson;
			for (fbxsdk::FbxNode* Node : Nodes)
			{
				NodesJson.push_back(*Node);
			}
			j["Nodes"] = NodesJson;
		}
		else
		{
			j["RootNodeUniqueID"] = nullptr;
			j["Nodes"] = nullptr;
		}
	}

	void nlohmann::adl_serializer<fbxsdk::FbxScene>::from_json(const json& j, fbxsdk::FbxScene& p)
	{
		assert(false);
	}
}