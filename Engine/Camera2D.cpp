#include "Camera2D.hpp"

namespace Mengine {

	Camera2D::Camera2D() : _position(0,0),
	_cameraMatrix(1.0f),
	_scale(1.0f),
	_needsMatrixChange(1),
	_screenWidth(500),
	_screenHeight(500),
	_orthoMatrix(1.0f)
	{
		
	}


	Camera2D::~Camera2D()
	{
		
	}

	void Camera2D::init(int screenWidth, int screenHeight)
	{
		_screenWidth = screenWidth;
		_screenHeight = screenHeight;
		_orthoMatrix = glm::ortho(0.0f, (float)_screenWidth, 0.0f, (float)_screenHeight );
	}

	void Camera2D::update()
	{
		if(_needsMatrixChange)
		{
			glm::vec3 translate(-_position.x + _screenWidth/2, -_position.y + _screenHeight/2, 0.0f);
			_cameraMatrix = glm::translate(_orthoMatrix, translate);
			glm::vec3 scale(_scale, _scale, 0.0f);
			_cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * _cameraMatrix;
			_needsMatrixChange = false;
		}
	}
	
	glm::vec2 Camera2D::convertScreenToWorld(glm::vec2 screenCoords)
	{
		// invert y coordinates
		screenCoords.y = _screenHeight - screenCoords.y;
		// make 0 the center
		screenCoords -= glm::vec2(_screenWidth/2, _screenHeight/2);
		
		// apply scaling factor
		screenCoords /= _scale;
		
		// tranlate based on camera position
		screenCoords += _position;
		
		return screenCoords;
	}
}