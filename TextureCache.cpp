#include "TextureCache.hpp"
#include "ImageLoader.hpp"
#include <iostream>

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
		
		std::cout << "Used Cached Texture \n";
		
		return newTexture;
	}
	std::cout << "Loaded Texture \n";
	return mit->second;
}