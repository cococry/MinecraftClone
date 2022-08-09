#include "sgll/Graphics/StaticShader.h"

std::shared_ptr<SGLL::Shader> SGLL::StaticShader::sColorShader;
std::shared_ptr<SGLL::Shader> SGLL::StaticShader::sTextureShader;

namespace SGLL
{
	void StaticShader::init(const std::string& colorVertexPath, const std::string& colorFragmentPath,
		const std::string& textureVertexPath, const std::string& textureFragmentPath)
	{
		sColorShader = std::make_shared<Shader>(colorVertexPath, colorFragmentPath);
		sTextureShader = std::make_shared<Shader>(textureVertexPath, textureFragmentPath);
	}
}