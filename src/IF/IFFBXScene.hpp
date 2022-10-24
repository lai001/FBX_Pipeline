#ifndef INTERMEDIATEFORMAT_IFFBXSCENE_HPP
#define INTERMEDIATEFORMAT_IFFBXSCENE_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
	template <>
	struct adl_serializer<fbxsdk::FbxScene>
	{
		static void to_json(json& j, fbxsdk::FbxScene& lRootNode);

		static void from_json(const json& j, fbxsdk::FbxScene& lScene);
	};
}

#endif