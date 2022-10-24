#include "IFFBXDocumentInfo.hpp"

#include "Util.hpp"

namespace nlohmann
{
	void nlohmann::adl_serializer<fbxsdk::FbxDocumentInfo>::to_json(json& j, fbxsdk::FbxDocumentInfo& p)
	{
		j = json
		{
			{"Title", ks::Util::FbxUTF8ToAnsi(p.mTitle)},
			{"Subject", ks::Util::FbxUTF8ToAnsi(p.mSubject)},
			{"Author", ks::Util::FbxUTF8ToAnsi(p.mAuthor)},
			{"Keywords", ks::Util::FbxUTF8ToAnsi(p.mKeywords)},
			{"Revision", ks::Util::FbxUTF8ToAnsi(p.mRevision)},
			{"Comment", ks::Util::FbxUTF8ToAnsi(p.mComment)},
		};
	}

	void nlohmann::adl_serializer<fbxsdk::FbxDocumentInfo>::from_json(const json& j, fbxsdk::FbxDocumentInfo& p)
	{
		assert(false);
	}
}