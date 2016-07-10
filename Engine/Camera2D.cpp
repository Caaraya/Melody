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
	
	// simple test to see if a box is in the camera view
	bool Camera2D::isBoxVisible(const glm::vec2& position, const glm::vec2 dimentions)
	{
		
		glm::vec2 scaledScreenDimentions = glm::vec2(_screenWidth, _screenHeight) / _scale;
		// The minimum distance before a collision occurs
		const float MIN_DISTANCE_X = dimentions.x / 2.0f + scaledScreenDimentions.x / 2.0f;
		const float MIN_DISTANCE_Y = dimentions.y / 2.0f + scaledScreenDimentions.y / 2.0f;

		// Center position of the agent
		glm::vec2 centerPos = position + dimentions / 2.0f;
		// center position of the camera
		glm::vec2 centerCameraPos = _position;
		// Vector from the input to the camera
		glm::vec2 distVec = centerPos - centerCameraPos;

		// Get the depth of the collision
		float xDepth = MIN_DISTANCE_X - std::abs(distVec.x);
		float yDepth = MIN_DISTANCE_Y - std::abs(distVec.y);

		// If either the depths are > 0, then we collided
		if (xDepth > 0 && yDepth > 0) {
		// collision
            return true;
        }
		return false;
	}
}