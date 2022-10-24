#ifndef INTERMEDIATEFORMAT_IFFBXMESH_HPP
#define INTERMEDIATEFORMAT_IFFBXMESH_HPP

#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace nlohmann
{
	template <>
	struct adl_serializer<fbxsdk::FbxMesh>
	{
		static void to_json(json& j, fbxsdk::FbxMesh& p);

		static void from_json(const json& j, fbxsdk::FbxMesh& p);
	};

}

#endif 
