#pragma once

#include "Human.h"
#include <InputManager.hpp>
#include <Camera2D.hpp>
#include "Bullet.h"

class Gun;

class Player : public Human
{
public:
    Player();
    ~Player();

    void init(float speed, glm::vec2 pos, Mengine::InputManager* inputManager, Mengine::Camera2D* camera, std::vector<Bullet>* bullets);

    void addGun(Gun* gun);

    void update(const std::vector<std::string>& levelData,
                std::vector<Human*>& humans,
                std::vector<Zombie*>& zombies,
				float deltaTime) override;
private:
    Mengine::InputManager* _inputManager;

    std::vector<Gun*> _guns;
    int _currentGunIndex;

    Mengine::Camera2D* _camera;
    std::vector<Bullet>* _bullets;

};

