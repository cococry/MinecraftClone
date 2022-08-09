#include <SGLL/Display.h>
#include <SGLL/Input/Input.h>
#include <SGLL/Graphics/Renderer.h>
#include <SGLL/Graphics/StaticShader.h>
#include <SGLL/Graphics/RawModel.h>
#include <SGLL/Graphics/ModelLoader.h>
#include <SGLL/Graphics/Texture.h>
#include <SGLL/Graphics/TexturedModel.h>
#include <SGLL/Logging.h>

#include <glad/glad.h>

#include "Block.h"
#include "CubeModel.h"
#include "Camera.h"

#include <thread>

static Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));

static SGLL::Display display(1280.0f, 720.0f, "Minecraft");


static std::vector<Block> blocks;

static std::vector<glm::vec3> usedBlocks;

static glm::vec3 cameraPosition;

void generateTerrain()
{
	while (!display.closeRequested())
	{
		cameraPosition = camera.getPosition();
		for (int x = (int)(cameraPosition.x - 16); x < cameraPosition.x + 16; x++)
		{
			for (int z = (int)(cameraPosition.z - 16); z < cameraPosition.z + 16; z++)
			{
				if (std::find(blocks.begin(), blocks.end(), Block(x, 0.0f, z)) == blocks.end())
				{
					blocks.push_back(Block(x, 0.0f, z));
				}
			}
		}
	}
	
}

int main()
{
	
	display.setInputMode(GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	SGLL::Renderer::init("vendor/SGLL/SGLL/assets/shaders/ColorVertex.glsl", "vendor/SGLL/SGLL/assets/shaders/ColorFragment.glsl",
		"vendor/SGLL/SGLL/assets/shaders/TextureVertex.glsl", "vendor/SGLL/SGLL/assets/shaders/TextureFragment.glsl");
	
	CubeModel::init();

	std::shared_ptr<SGLL::Texture> texture = std::make_shared<SGLL::Texture>("assets/textures/textureAtlas.png");

	SGLL::StaticShader::getTextureShader()->use();
	SGLL::StaticShader::getTextureShader()->setUniformVector3f("uColor", glm::vec3(1.0f));
	SGLL::StaticShader::getTextureShader()->setUniformInt("uTexture", 0);


	glEnable(GL_DEPTH_TEST);

	std::thread generationThread(generateTerrain);
	


	while (!display.closeRequested())
	{
		display.pollEvents();
		display.swapBuffers();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

		if (SGLL::Keyboard::isKeyDown(SGLL::Key::Escape))
		{
			display.setOpen(false);
		}

		texture->bind();
		texture->activateSlot(0);
		SGLL::StaticShader::getTextureShader()->setUniformMatrix4f("uView", camera.getViewMatrix());
		
		for (Block block : blocks)
		{
			
			block.render();
		}
		
		camera.update();
	}

	generationThread.detach();



}