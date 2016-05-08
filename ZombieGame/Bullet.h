#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <SpriteBatch.hpp>
#include <string>

class Human;
class Zombie;
class Agent;

const int BULLET_RADIUS = 5;

class Bullet
{
public:
    Bullet(glm::vec2 position, glm::vec2 direction, float damage, float speed);
    ~Bullet();

    // When update returns true, delete bullet
    bool update(const std::vector<std::string>& levelData, float deltaTime);

    void draw(Mengine::SpriteBatch& spriteBatch);

    bool collideWithAgent(Agent* agent);

    float getDamage() const { return _damage; }

private:

    bool collideWithWorld(const std::vector<std::string>& levelData);

    glm::vec2 _position;
    glm::vec2 _direction;
    float _damage;
    float _speed;
};

