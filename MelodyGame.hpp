#pragma once

#include "Sprite.hpp"
#include <SDL2/SDL.h>
#undef main
#include <GL/glew.h>

enum class GameState {PLAY, QUIT};

class MelodyGame
{
public:
	MelodyGame();
	~MelodyGame();
	
	void run();
	
private:
	void initSystems();
	void gameLoop();
	void processInput();
	void drawGame();
	
	SDL_Window* _window = nullptr;
	int _screenWidth = 800;
	int _screenHeight = 600;
	GameState _gameState = GameState::PLAY;
	Sprite _sprite;
};