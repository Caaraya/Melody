#include "TextureCache.hpp"
#include "ImageLoader.hpp"
#include <iostream>

namespace Mengine {

TextureCache::TextureCache()
{
	
}

TextureCache::~TextureCache()
{
	
}

GLTexture TextureCache::getTexture(std::string texturePath)
{
	//lookup texture
	auto mit = _textureMap.find(texturePath);
	
	//check if its not in the map
	if (mit == _textureMap.end())
	{
		//load the texture
		GLTexture newTexture = ImageLoader::loadPNG(texturePath);
		
		//Insert it into the map
		_textureMap.insert(make_pair(texturePath, newTexture));
		
		return newTexture;
	}
	return mit->second;
}
}