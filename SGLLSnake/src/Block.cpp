#include "Block.h"

#include "CubeModel.h"

#include <SGLL/Graphics/StaticShader.h>
#include <glm/gtc/matrix_transform.hpp>

Block::Block(int x, int y, int z)
	: mX(x), mY(y), mZ(z)
{
	mModel = CubeModel::getModel();
}

Block::~Block()
{
}

void Block::render()
{
	SGLL::StaticShader::getTextureShader()->use();

	glm::mat4 modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(mX, mY, mZ));

	SGLL::StaticShader::getTextureShader()->setUniformMatrix4f("uModel", modelMatrix);

	glDrawElements(GL_TRIANGLES, mModel.getVertexCount(), GL_UNSIGNED_INT, nullptr);

}
