#pragma once
#include <map>
#include "GLTexture.hpp"

namespace Mengine {
class TextureCache
{
public:
	TextureCache();
	~TextureCache();
	
	GLTexture getTexture(std::string texturePath);
	
private:
	std::map<std::string, GLTexture> _textureMap;
};
}