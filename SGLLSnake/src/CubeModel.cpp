#include "CubeModel.h"

#include <SGLL/Graphics/ModelLoader.h>

std::vector<float> CubeModel::sVertexPositions;
std::vector<float> CubeModel::sUvs;
std::vector<unsigned int> CubeModel::sIndices;

SGLL::RawModel CubeModel::sModel;

void CubeModel::init()
{
	sVertexPositions =
	{
			-0.5f,0.5f,-0.5f,
			-0.5f,-0.5f,-0.5f,
			0.5f,-0.5f,-0.5f,
			0.5f,0.5f,-0.5f,

			-0.5f,0.5f,0.5f,
			-0.5f,-0.5f,0.5f,
			0.5f,-0.5f,0.5f,
			0.5f,0.5f,0.5f,

			0.5f,0.5f,-0.5f,
			0.5f,-0.5f,-0.5f,
			0.5f,-0.5f,0.5f,
			0.5f,0.5f,0.5f,

			-0.5f,0.5f,-0.5f,
			-0.5f,-0.5f,-0.5f,
			-0.5f,-0.5f,0.5f,
			-0.5f,0.5f,0.5f,

			-0.5f,0.5f,0.5f,
			-0.5f,0.5f,-0.5f,
			0.5f,0.5f,-0.5f,
			0.5f,0.5f,0.5f,

			-0.5f,-0.5f,0.5f,
			-0.5f,-0.5f,-0.5f,
			0.5f,-0.5f,-0.5f,
			0.5f,-0.5f,0.5f

	};

	sIndices =
	{

			0,1,3,
			3,1,2,
			4,5,7,
			7,5,6,
			8,9,11,
			11,9,10,
			12,13,15,
			15,13,14,
			16,17,19,
			19,17,18,
			20,21,23,
			23,21,22

	};

	sUvs =
	{
		0, 0,
		0, 1,
		1, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1,
		1, 0

	};

	
	sModel = SGLL::ModelLoader::loadModel(sVertexPositions, sUvs, sIndices);
}
