#pragma once

#include "GLSLProgram.hpp"
#include "Sprite.hpp"
#include <SDL2/SDL.h>
#undef main
#include <GL/glew.h>
#include "GLTexture.hpp"
#include <vector>

enum class GameState {PLAY, QUIT};

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
	
	SDL_Window* _window = nullptr;
	int _screenWidth;
	int _screenHeight;
	float _time;
	GameState _gameState = GameState::PLAY;
	std::vector <Sprite*> _sprites;
	GLSLProgram _colorProgram;
};