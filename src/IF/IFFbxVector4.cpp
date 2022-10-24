#include "IFFbxVector4.hpp"

namespace nlohmann
{
	void adl_serializer<fbxsdk::FbxDouble4>::to_json(json& j, const fbxsdk::FbxDouble4& p)
	{
		j = json
		{
			{"x", p[0]},
			{"y", p[1]},
			{"z", p[2]},
			{"w", p[3]},
		};
	}

	void adl_serializer<fbxsdk::FbxDouble4>::from_json(const json& j, fbxsdk::FbxDouble4& p)
	{
		assert(false);
	}

	json adl_serializer<fbxsdk::FbxDouble4*>::to_json(fbxsdk::FbxDouble4* p, const int nums)
	{
		assert(p);

		std::vector<json> values;
		for (int i = 0; i < nums; i++)
		{
			const fbxsdk::FbxDouble4 point = p[i];
			values.push_back(point);
		}
		return values;
	}

	void adl_serializer<fbxsdk::FbxDouble4*>::from_json(const json& j, fbxsdk::FbxDouble4* p)
	{
		assert(false);
	}
}

namespace nlohmann
{
	void adl_serializer<fbxsdk::FbxVector4>::to_json(json& j, const fbxsdk::FbxVector4& p)
	{
		j = json
		{
			{"x", p[0]},
			{"y", p[1]},
			{"z", p[2]},
			{"w", p[3]},
		};
	}

	void adl_serializer<fbxsdk::FbxVector4>::from_json(const json& j, fbxsdk::FbxVector4& p)
	{
		assert(false);
	}

	json adl_serializer<fbxsdk::FbxVector4*>::to_json(fbxsdk::FbxVector4* p, const int nums)
	{
		assert(p);

		std::vector<json> values;
		for (int i = 0; i < nums; i++)
		{
			const fbxsdk::FbxVector4 point = p[i];
			values.push_back(point);
		}
		return values;
	}

	void adl_serializer<fbxsdk::FbxVector4*>::from_json(const json& j, fbxsdk::FbxVector4* p)
	{
		assert(false);
	}
}
