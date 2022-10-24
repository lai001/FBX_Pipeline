#include "IFFBXWriter.hpp"

#include <iostream>
#include <fstream>
#include <assert.h>
#include <spdlog/spdlog.h>

#include "IFFBXScene.hpp"
#include "Util.hpp"

namespace ks
{
	IFFBXWriter::IFFBXWriter(fbxsdk::FbxScene& lScene, const IFFBXWriteConfig& config)
		:lScene(&lScene), config(config)
	{
	}

	IFFBXWriter::~IFFBXWriter()
	{
		if (lSdkManager)
		{
			lSdkManager->Destroy();
		}
	}

	IFFBXWriter* IFFBXWriter::New(const IFFBXWriteConfig& config)
	{
		fbxsdk::FbxManager* lSdkManager = fbxsdk::FbxManager::Create();
		fbxsdk::FbxIOSettings* ios = fbxsdk::FbxIOSettings::Create(lSdkManager, IOSROOT);
		lSdkManager->SetIOSettings(ios);
		(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_MATERIAL, false);
		(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_TEXTURE, false);
		(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_LINK, false);
		(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_SHAPE, false);
		(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_GOBO, false);
		(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_ANIMATION, false);
		(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_GLOBAL_SETTINGS, true);
		fbxsdk::FbxImporter* lImporter = fbxsdk::FbxImporter::Create(lSdkManager, "");
		if (!lImporter->Initialize(ks::Util::FbxAnsiToUTF8(config.inputFilePath.c_str()).c_str(), -1, lSdkManager->GetIOSettings())) {
			spdlog::error("Call to FbxImporter::Initialize() failed.");
			spdlog::error("Error returned: {0}", lImporter->GetStatus().GetErrorString());
			spdlog::error("Initialize file {0} failed.", config.inputFilePath);
			lSdkManager->Destroy();
			return nullptr;
		}
		fbxsdk::FbxScene* lScene = fbxsdk::FbxScene::Create(lSdkManager, "Scene");
		lImporter->Import(lScene);
		fbxsdk::FbxSystemUnit::cm.ConvertScene(lScene);
		fbxsdk::FbxAxisSystem lSystem = fbxsdk::FbxAxisSystem(
			fbxsdk::FbxAxisSystem::EUpVector::eZAxis,
			fbxsdk::FbxAxisSystem::EFrontVector::eParityOdd,
			fbxsdk::FbxAxisSystem::ECoordSystem::eLeftHanded);
		//lSystem = fbxsdk::FbxAxisSystem(fbxsdk::FbxAxisSystem::EPreDefinedAxisSystem::eMayaZUp);
		lSystem.ConvertScene(lScene);
		IFFBXWriter* lWriter = new IFFBXWriter(*lScene, config);
		return lWriter;
	}

	void IFFBXWriter::Write()
	{
		std::ofstream o(config.outputFilePath);
		const nlohmann::json j(*lScene);
		o << std::setw(4) << j << std::endl;
	}
}