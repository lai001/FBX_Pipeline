#include "IFFbxVector2.hpp"

namespace nlohmann
{
	void adl_serializer<fbxsdk::FbxVector2>::to_json(json& j, const fbxsdk::FbxVector2& p)
	{
		j = json
		{
			{"x", p[0]},
			{"y", p[1]},
		};
	}

	void adl_serializer<fbxsdk::FbxVector2>::from_json(const json& j, fbxsdk::FbxVector2& p)
	{
		assert(false);
	}

	json adl_serializer<fbxsdk::FbxVector2*>::to_json(fbxsdk::FbxVector2* p, const int nums)
	{
		assert(p);

		std::vector<fbxsdk::FbxVector2> values;
		for (int i = 0; i < nums; i++)
		{
			const fbxsdk::FbxVector2 point = p[i];
			values.push_back(point);
		}
		return json{ values };
	}

	void adl_serializer<fbxsdk::FbxVector2*>::from_json(const json& j, fbxsdk::FbxVector2* p)
	{
		assert(false);
	}

}