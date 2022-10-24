#include <iostream>
#include <fstream>
#include <filesystem>

#include <nlohmann/json.hpp>
#include <fbxsdk.h>
#include <tclap/CmdLine.h>
#include <spdlog/spdlog.h>

#include "IFFBXWriter.hpp"

int main(int argc, char** argv)
{
	using namespace fbxsdk;
	try
	{
		const std::string lName = "FBX_Pipeline";
		TCLAP::CmdLine cmd(lName, ' ', "0.1.0");
		TCLAP::ValueArg<std::string> nameArg("i", "input_file_path", "input file path", true, "", "string");
		TCLAP::ValueArg<std::string> nameArg1("o", "output_file_path", "output file path", false, "", "string");
		TCLAP::SwitchArg nameArg2("y", "overwrite", "overwrite", false);
		cmd.add(nameArg);
		cmd.add(nameArg1);
		cmd.add(nameArg2);
		cmd.parse(argc, argv);

		const std::string inputFBXFilePath = nameArg.getValue();
		std::string outputFilePath = nameArg1.getValue();
		const bool overwrite = nameArg2.getValue();

		if (outputFilePath.size() < 1)
		{
			outputFilePath = fmt::format("./{}.json", lName);
		}

		const std::filesystem::path lPath(outputFilePath);
		if (!overwrite && std::filesystem::exists(lPath))
		{
			return -3;
		}

        ks::IFFBXWriteConfig config;
        config.inputFilePath = inputFBXFilePath;
        config.outputFilePath = outputFilePath;
        std::unique_ptr<ks::IFFBXWriter> Writer = std::unique_ptr<ks::IFFBXWriter>(ks::IFFBXWriter::New(config));
		if (Writer)
		{
			Writer->Write();
		}
		else
		{
			return -2;
		}
	}
	catch (TCLAP::ArgException& e)
	{
		spdlog::error("{} for arg {}", e.error(), e.argId());
        return -1;
	}
    return 0;
}
