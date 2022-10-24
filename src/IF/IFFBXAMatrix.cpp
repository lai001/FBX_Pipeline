#include "IFFBXAMatrix.hpp"
#include "IFFbxVector4.hpp"

namespace nlohmann
{
	void nlohmann::adl_serializer<fbxsdk::FbxAMatrix>::to_json(json& j, const fbxsdk::FbxAMatrix& p)
	{
		std::vector<json> values;
		values.push_back(p.mData[0]);
		values.push_back(p.mData[1]);
		values.push_back(p.mData[2]);
		values.push_back(p.mData[3]);
		j = values;
	}

	void nlohmann::adl_serializer<fbxsdk::FbxAMatrix>::from_json(const json& j, fbxsdk::FbxAMatrix& p)
	{
		assert(false);
	}
}