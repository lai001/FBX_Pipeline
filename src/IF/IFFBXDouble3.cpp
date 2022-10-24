#include "IFFBXDouble3.hpp"

namespace nlohmann
{
	void adl_serializer<fbxsdk::FbxDouble3>::to_json(json& j, const fbxsdk::FbxDouble3& p)
	{
		j = json
		{
			{"x", p[0]},
			{"y", p[1]},
			{"z", p[2]},
		};
	}

	void adl_serializer<fbxsdk::FbxDouble3>::from_json(const json& j, fbxsdk::FbxDouble3& p)
	{
		assert(false);
	}
}