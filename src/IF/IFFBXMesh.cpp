#include "IFFBXMesh.hpp"
#include "IFFbxVector4.hpp"
#include "IFFbxVector2.hpp"
#include "IFFBXGeometryElementNormal.hpp"
#include "Util.hpp"

namespace nlohmann
{
	void adl_serializer<fbxsdk::FbxMesh>::to_json(json& j, fbxsdk::FbxMesh& p)
	{
		j = json
		{

		};
		
		fbxsdk::FbxStatus pStatus;
		fbxsdk::FbxVector4* lControlPoints = p.GetControlPoints(&pStatus);
		const int lControlPointsCount = p.GetControlPointsCount();
		const int lElementNormalCount = p.GetElementNormalCount();
		const int lPolygonCount = p.GetPolygonCount();
		const int lPolygonVertexCount = p.GetPolygonVertexCount();
		const int lElementPolygonGroupCount = p.GetElementPolygonGroupCount();
		const int lElementUVCount = p.GetElementUVCount();

		j["ControlPointsCount"] = lControlPointsCount;
		j["ElementNormalCount"] = lElementNormalCount;
		j["PolygonCount"] = lPolygonCount;
		j["PolygonVertexCount"] = lPolygonVertexCount;
		j["ElementPolygonGroupCount"] = lElementPolygonGroupCount;
		j["ElementUVCount"] = lElementUVCount;

		{
			std::vector<json> lElementUVJson;
			for (int i = 0; i < lElementUVCount; i++)
			{
				json leUVJson;
				std::vector<fbxsdk::FbxVector2> lUVDirectArray;

				fbxsdk::FbxGeometryElementUV* leUV = p.GetElementUV(i);
				for (int j = 0; j < leUV->GetDirectArray().GetCount(); j++)
				{
					fbxsdk::FbxVector2 UV = leUV->GetDirectArray().GetAt(j);
					lUVDirectArray.push_back(UV);
				}
				leUVJson["Name"] = ks::Util::FbxUTF8ToAnsi(leUV->GetName());
				leUVJson["DirectArray"] = lUVDirectArray;
				lElementUVJson.push_back(leUVJson);
			}
			j["ElementUV"] = lElementUVJson;
		}

		std::vector<json> Polygons;
		for (int i = 0; i < lPolygonCount; i++)
		{
			json lPolygonJson;
			const int lPolygonSize = p.GetPolygonSize(i);
			for (int j = 0; j < lPolygonSize; j++)
			{
				json lPolygonVertexJson;
				std::vector<json> lPolygonUVsJson;
				int lControlPointIndex = p.GetPolygonVertex(i, j);
				//fbxsdk::FbxVector4 lControlPoint = lControlPoints[lControlPointIndex];

				for (int l = 0; l < lElementUVCount; ++l)
				{

					fbxsdk::FbxGeometryElementUV* leUV = p.GetElementUV(l);
			
					switch (leUV->GetMappingMode())
					{
					default:
						break;
					case FbxGeometryElement::eByControlPoint:
						switch (leUV->GetReferenceMode())
						{
						case FbxGeometryElement::eDirect:
						{
							//fbxsdk::FbxVector2 UV = leUV->GetDirectArray().GetAt(lControlPointIndex);
							lPolygonUVsJson.push_back(lControlPointIndex);
						}
						break;
						case FbxGeometryElement::eIndexToDirect:
						{
							int id = leUV->GetIndexArray().GetAt(lControlPointIndex);
							//fbxsdk::FbxVector2 UV = leUV->GetDirectArray().GetAt(id);
							lPolygonUVsJson.push_back(id);
						}
						break;
						default:
							break;
						}
						break;

					case FbxGeometryElement::eByPolygonVertex:
					{
						int lTextureUVIndex = p.GetTextureUVIndex(i, j);
						switch (leUV->GetReferenceMode())
						{
						case FbxGeometryElement::eDirect:
						case FbxGeometryElement::eIndexToDirect:
						{
							//fbxsdk::FbxVector2 UV = leUV->GetDirectArray().GetAt(lTextureUVIndex);
							lPolygonUVsJson.push_back(lTextureUVIndex);
						}
						break;
						default:
							break;
						}
					}
					break;

					case FbxGeometryElement::eByPolygon:
					case FbxGeometryElement::eAllSame:
					case FbxGeometryElement::eNone:
						break;
					}
				}

				lPolygonVertexJson["VertexIndex"] = lControlPointIndex;
				//lPolygonVertexJson["Vertex"] = lControlPoint;
				lPolygonVertexJson["ElementUVIndex"] = lPolygonUVsJson;
				lPolygonJson.push_back(lPolygonVertexJson);
			}
			Polygons.push_back(lPolygonJson);
		}
		j["Polygons"] = Polygons;
	
		if (pStatus)
		{
			j["ControlPoints"] = adl_serializer<fbxsdk::FbxDouble4*>::to_json(lControlPoints, lControlPointsCount);

			std::vector<std::vector<json>> leNormalsGroup;

			for (int i = 0; i < lControlPointsCount; i++)
			{
				std::vector<json> leNormals;
				for (int e = 0; e < lElementNormalCount; e++)
				{
					fbxsdk::FbxGeometryElementNormal* leNormal = p.GetElementNormal(e);
					json lj = adl_serializer<fbxsdk::FbxGeometryElementNormal*>::to_json(leNormal, lElementNormalCount);
					if (!lj.is_null())
					{
						leNormals.push_back(lj);
					}
				}
				if (!leNormals.empty())
				{
					leNormalsGroup.push_back(leNormals);
				}
			}
			if (!leNormalsGroup.empty())
			{
				j["NormalsGroup"] = leNormalsGroup;
			}
			else
			{
				j["NormalsGroup"] = nullptr;
			}
		}
		else
		{
			j["ControlPoints"] = nullptr;
		}
	}

	void adl_serializer<fbxsdk::FbxMesh>::from_json(const json& j, fbxsdk::FbxMesh& p)
	{
		assert(false);
	}
}
