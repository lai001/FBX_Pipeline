#include "IFFBXEulerOrder.hpp"

namespace nlohmann
{
	void adl_serializer<fbxsdk::FbxEuler::EOrder>::to_json(json& j, const fbxsdk::FbxEuler::EOrder& p)
	{
		std::vector<std::string> names = { 
			"OrderXYZ", 
			"OrderXZY", 
			"OrderYZX", 
			"OrderYXZ", 
			"OrderZXY", 
			"OrderZYX", 
			"OrderSphericXYZ" 
		};
		j = json
		{
			{"EulerOrder", names[static_cast<int>(p)]}
		};
	}

	void adl_serializer<fbxsdk::FbxEuler::EOrder>::from_json(const json& j, fbxsdk::FbxEuler::EOrder& p)
	{
		assert(false);
	}
}
