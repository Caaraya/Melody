#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <Mengine.hpp>
#include <GLSLProgram.hpp>
#include <GLTexture.hpp>
#include <Sprite.hpp>
#include <Window.hpp>
#include <InputManager.hpp>
#include <Timing.hpp>

#include <SpriteBatch.hpp>

#include <Camera2D.hpp>

#include <vector>

enum class GameState {PLAY, EXIT};

//Our example game class, just for testing purposes right now
class MelodyGame
{
public:
    MelodyGame();
    ~MelodyGame();

    void run();

private:
    void initSystems();
    void initShaders();
    void gameLoop();
    void processInput();
    void drawGame();

    Mengine::Window _window;
    int _screenWidth;
    int _screenHeight;
    GameState _gameState;

    Mengine::GLSLProgram _colorProgram;
    Mengine::Camera2D _camera;

    Mengine::SpriteBatch _spriteBatch;

    Mengine::InputManager _inputManager;
    Mengine::FpsLimiter _fpsLimiter;
    
    float _maxFPS;
    float _fps;
    float _time;
};

