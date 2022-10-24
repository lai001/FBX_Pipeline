#ifndef INTERMEDIATEFORMAT_IFFBXDOCUMENTINFO_HPP
#define INTERMEDIATEFORMAT_IFFBXDOCUMENTINFO_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
	template <>
	struct adl_serializer<fbxsdk::FbxDocumentInfo>
	{
		static void to_json(json& j, fbxsdk::FbxDocumentInfo& p);

		static void from_json(const json& j, fbxsdk::FbxDocumentInfo& p);
	};
}

#endif // !INTERMEDIATEFORMAT_IFFBXDOCUMENTINFO_HPP
