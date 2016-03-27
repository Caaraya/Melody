#pragma once
#include "GLTexture.hpp"

#include <string>

class ImageLoader
{
public:
	static GLTexture loadPNG(std::string filePath);
	
};