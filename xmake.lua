FBX_VERSION = "2020.2.1"
FBX_HOME = "D:/Program Files/Autodesk/FBX/FBX SDK/" .. FBX_VERSION
FBX_INCLUDE = FBX_HOME .. "/include"
FBX_RELEASE_LIB = FBX_HOME .. "/lib/vs2019/x64/release"
FBX_DEBUG_LIB = FBX_HOME .. "/lib/vs2019/x64/debug"
VS_RUNTIME_TYPE = ""

NLOHMANN_JSON = "nlohmann_json"
SPDLOG = "spdlog"
TCLAP = "tclap"

add_requires(NLOHMANN_JSON)
add_requires(SPDLOG)
add_requires(TCLAP)

target("FBX_Pipeline")
    set_kind("binary")
    set_languages("c++17")
    add_rules("mode.debug", "mode.release")
    add_files("src/*.cpp")
    add_files("src/IF/*.cpp")
    add_headerfiles("src/*.hpp")
    add_headerfiles("src/IF/*.hpp")
    add_includedirs("src/IF")
    add_includedirs("src")
    add_includedirs(FBX_INCLUDE)
    add_filegroups("src", {rootdir = "src"})
    if is_mode("debug") then 
        VS_RUNTIME_TYPE = "-md"
        set_runtimes("MDd")
        add_linkdirs(FBX_DEBUG_LIB)
    elseif is_mode("release") then 
        VS_RUNTIME_TYPE = "-mt"
        set_runtimes("MT")
        add_linkdirs(FBX_RELEASE_LIB)
    end
    add_links("libfbxsdk" .. VS_RUNTIME_TYPE, "libxml2" .. VS_RUNTIME_TYPE, "zlib" .. VS_RUNTIME_TYPE)
    add_packages(NLOHMANN_JSON)
    add_packages(SPDLOG)
    add_packages(TCLAP)
