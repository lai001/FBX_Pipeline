#ifndef INTERMEDIATEFORMAT_IFFBXWRITER_HPP
#define INTERMEDIATEFORMAT_IFFBXWRITER_HPP

#include <string>
#include <nlohmann/json.hpp>
#include <fbxsdk.h>

namespace ks
{
	struct IFFBXWriteConfig
	{
		std::string inputFilePath;
		std::string outputFilePath;
	};

	class IFFBXWriter
	{
	public:
		IFFBXWriter(fbxsdk::FbxScene& lScene, const IFFBXWriteConfig& config);
		~IFFBXWriter();

		static IFFBXWriter* New(const IFFBXWriteConfig& config);

		void Write();

	private:
		IFFBXWriteConfig config;
		fbxsdk::FbxScene* lScene = nullptr;
		fbxsdk::FbxImporter* lImporter = nullptr;
		fbxsdk::FbxManager* lSdkManager = nullptr;
		fbxsdk::FbxIOSettings* lIOSettings = nullptr;
	};
}

#endif // !INTERMEDIATEFORMAT_IFFBXWRITER_HPP
