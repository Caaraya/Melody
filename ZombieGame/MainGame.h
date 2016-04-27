#pragma once

#include <Window.hpp>
#include <GLSLProgram.hpp>
#include <Camera2D.hpp>
#include <InputManager.hpp>
#include <SpriteBatch.hpp>

#include "Player.h"
#include "Level.h"
#include "Bullet.h"

class Zombie;

enum class GameState {
    PLAY,
    EXIT
};

class MainGame
{
public:
    MainGame();
    ~MainGame();

    /// Runs the game
    void run();

private:
    /// Initializes the core systems
    void initSystems();

    /// Initializes the level and sets up everything
    void initLevel();

    /// Initializes the shaders
    void initShaders();

    /// Main game loop for the program
    void gameLoop();

    /// Updates all agents
    void updateAgents();

    /// Updates all bullets
    void updateBullets();

    /// Checks the victory condition
    void checkVictory();

    /// Handles input processing
    void processInput();

    /// Renders the game
    void drawGame();

    /// Member Variables
    Mengine::Window _window; ///< The game window
    
    Mengine::GLSLProgram _textureProgram; ///< The shader program

    Mengine::InputManager _inputManager; ///< Handles input

    Mengine::Camera2D _camera; ///< Main Camera

    Mengine::SpriteBatch _agentSpriteBatch; ///< Draws all agents

    std::vector<Level*> _levels; ///< vector of all levels

    int _screenWidth, _screenHeight;

    float _fps;

    int _currentLevel;

    Player* _player;
    std::vector<Human*> _humans; ///< Vector of all humans
    std::vector<Zombie*> _zombies; ///< Vector of all zombies
    std::vector<Bullet> _bullets;

    int _numHumansKilled; ///< Humans killed by player
    int _numZombiesKilled; ///< Zombies killed by player

    GameState _gameState;
};

