#pragma once
#include "GLTexture.hpp"

#include <string>

namespace Mengine {
	
	class ImageLoader
	{
	public:
		static GLTexture loadPNG(std::string filePath);
	};
}