#ifndef INTERMEDIATEFORMAT_IFFBXCLASSID_HPP
#define INTERMEDIATEFORMAT_IFFBXCLASSID_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
	template <>
	struct adl_serializer<fbxsdk::FbxClassId>
	{
		static void to_json(json& j, fbxsdk::FbxClassId& p);

		static void from_json(const json& j, fbxsdk::FbxClassId& p);
	};
}

#endif // !INTERMEDIATEFORMAT_IFFBXCLASSID_HPP
