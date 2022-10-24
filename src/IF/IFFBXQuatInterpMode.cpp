#include "IFFBXQuatInterpMode.hpp"

namespace nlohmann
{
	void adl_serializer<fbxsdk::EFbxQuatInterpMode>::to_json(json& j, const fbxsdk::EFbxQuatInterpMode& p)
	{
		std::vector<std::string> names = { 
			"QuatInterpOff",
			"QuatInterpClassic", 
			"QuatInterpSlerp", 
			"QuatInterpCubic", 
			"QuatInterpTangentDependent",
			"QuatInterpCount"
		};
		j = json
		{
			{"QuatInterpMode", names[static_cast<int>(p)]}
		};
	}

	void adl_serializer<fbxsdk::EFbxQuatInterpMode>::from_json(const json& j, fbxsdk::EFbxQuatInterpMode& p)
	{
		assert(false);
	}
}
