#include "MelodyGame.hpp"
#include <iostream>
#include <string>

void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	std::cin.get();
	SDL_Quit();
	exit(1);
}

MelodyGame::MelodyGame()
{
	
}


MelodyGame::~MelodyGame()
{
	
}

void MelodyGame::run()
{
	initSystems();
	_sprite.init(-0.6f,-0.6f, 0.4f, 0.4f);
	gameLoop();
}
	
void MelodyGame::initSystems()
{
	//Initialize everything
	SDL_Init(SDL_INIT_EVERYTHING);
	
	_window = SDL_CreateWindow("Melody Engine", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
	
	if(_window == nullptr)
	{
		fatalError("SDL Window could not be created");
	}
	
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	
	if(glContext == nullptr)
	{
		fatalError("SDL_GL Context could not be created");
	}
	
	GLenum error = glewInit();
	
	if(error != GLEW_OK)
	{
		fatalError("Could not initialize Glew");
	}
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	glClearColor(0.45f,0.6f,1.0f,1.0f);
}

void MelodyGame::gameLoop()
{
	while(_gameState != GameState::QUIT)
	{
		processInput();
		drawGame();
	}
}

void MelodyGame::processInput()
{
	SDL_Event evnt;
	while(SDL_PollEvent(&evnt))
	{
		switch(evnt.type)
		{
			case SDL_QUIT:
				_gameState = GameState::QUIT;
				break;
			case SDL_MOUSEMOTION:
				// evnt.motion.x, evnt.motion.y
				break;
		}
	}
}

void MelodyGame::drawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	_sprite.draw();
	
	SDL_GL_SwapWindow(_window);
}