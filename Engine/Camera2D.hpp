#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Mengine {

	class Camera2D
	{
	public:
		Camera2D();
		~Camera2D();
		
		void init(int screenWidth, int screenHeight);
		
		void update();
		
		glm::vec2 convertScreenToWorld(glm::vec2 screenCoords);
		
		bool isBoxVisible(const glm::vec2& position, const glm::vec2 dimentions);
		
		//setters
		void setPosition(const glm::vec2& newPosition) { _position = newPosition; _needsMatrixChange = true; }
		void setScale(float newScale) { _scale = newScale; _needsMatrixChange = true;}
		
		//getters
		glm::vec2 getPosition(){ return _position; }
		float getScale(){ return _scale; }
		glm::mat4 getCameraMatrix(){ return _cameraMatrix; }
		
	private:
		int _screenWidth;
		int _screenHeight;
		bool _needsMatrixChange;
		float _scale;
		glm::vec2 _position;
		glm::mat4 _cameraMatrix;
		glm::mat4 _orthoMatrix;
	};
}