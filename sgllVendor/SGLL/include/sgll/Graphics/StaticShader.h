#pragma once

#include "Shader.h"
#include <memory>

namespace SGLL
{
	class StaticShader
	{
	public:
		static void init(const std::string& colorVertexPath = "../SGLL/assets/shaders/ColorVertex.glsl", const std::string& colorFragmentPath = "../SGLL/assets/shaders/ColorFragment.glsl",
			const std::string& textureVertexPath = "../SGLL/assets/shaders/TextureVertex.glsl", const std::string& textureFragmentPath = "../SGLL/assets/shaders/TextureFragment.glsl");

		static std::shared_ptr<Shader> getTextureShader()
		{
			return sTextureShader;
		}

		static std::shared_ptr<Shader> getColorShader()
		{
			return sColorShader;
		}

	private:
		static std::shared_ptr<Shader> sTextureShader;

		static std::shared_ptr<Shader> sColorShader;
	};
}