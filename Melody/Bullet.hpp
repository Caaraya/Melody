#pragma once

#include <glm/glm.hpp>
#include <SpriteBatch.hpp>

class Bullet
{
public:
	Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifeTime);
	~Bullet();
	
	void draw(Mengine::SpriteBatch& spriteBatch);
	
	//returns true when out of life
	bool update();
private:
	float _speed;
	glm::vec2 _direction;
	glm::vec2 _position;
	int _lifeTime;
};