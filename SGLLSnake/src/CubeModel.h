#pragma once

#include <SGLL/Graphics/RawModel.h>
#include <vector>

class CubeModel
{
public:
	static void init();


	static std::vector<float> getVertexPositions()
	{
		return sVertexPositions;
	}

	static std::vector<float> getUvs()
	{
		return sUvs;
	}

	static std::vector<unsigned int> getIndices()
	{
		return sIndices;
	}

	static SGLL::RawModel getModel()
	{
		return sModel;
	}
private:
	static std::vector<float> sVertexPositions;
	static std::vector<float> sUvs;
	static std::vector<unsigned int> sIndices;

	static SGLL::RawModel sModel;
};