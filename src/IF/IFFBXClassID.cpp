#include "IFFBXClassID.hpp"

#include "Util.hpp"

namespace nlohmann
{
	void adl_serializer<fbxsdk::FbxClassId>::to_json(json& j, fbxsdk::FbxClassId& p)
	{
		j = json
		{
			{"Name", ks::Util::FbxUTF8ToAnsi(p.GetName())},
			{"FbxFileSubTypeName", ks::Util::FbxUTF8ToAnsi(p.GetFbxFileSubTypeName())},
			{"FbxFileTypeName", ks::Util::FbxUTF8ToAnsi(p.GetFbxFileTypeName())},
			{"ObjectTypePrefix", ks::Util::FbxUTF8ToAnsi(p.GetObjectTypePrefix())},
		};
	}

	void adl_serializer<fbxsdk::FbxClassId>::from_json(const json& j, fbxsdk::FbxClassId& p)
	{
		assert(false);
	}
}
