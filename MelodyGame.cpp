#include "MelodyGame.hpp"
#include <iostream>
#include <string>
#include "Errors.hpp"

MelodyGame::MelodyGame() : _screenWidth(800), _screenHeight(600), _time(0.0f)
{
	
}


MelodyGame::~MelodyGame()
{
	SDL_Quit();
}

void MelodyGame::run()
{
	initSystems();
	
	_sprites.push_back(new Sprite());
	_sprites.back()->init(-1.0f,-1.0f, 1.0f, 1.0f, "Textures/jimmyJump_pack/PNG/CharacterRight_Standing.png");
	
	_sprites.push_back(new Sprite());
	_sprites.back()->init(0.0f, -1.0f, 1.0f, 1.0f, "Textures/jimmyJump_pack/PNG/CharacterRight_Standing.png");
	
	//_playerTexture = ImageLoader::loadPNG("Textures/jimmyJump_pack/PNG/CharacterRight_Standing.png");
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
	
	initShaders();
}

void MelodyGame::initShaders()
{
	_colorProgram.compileShaders("Shaders/vertexShading.vert", "Shaders/fragShading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.addAttribute("vertexUV");	
	_colorProgram.linkShaders();
}

void MelodyGame::gameLoop()
{
	while(_gameState != GameState::QUIT)
	{
		processInput();
		_time += 0.001;
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
	
	_colorProgram.use();
	glActiveTexture(GL_TEXTURE0);
	
	GLint textureLocation = _colorProgram.getUniformLocation("mySampler");
	glUniform1i(textureLocation, 0);
	
	//sGLuint timeLocation = _colorProgram.getUniformLocation("time");
	
	//glUniform1f(timeLocation, _time);
	
	for(int i = 0; i < _sprites.size(); i++)
	{
		_sprites[i]->draw();
	}
	//_sprite.draw();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	_colorProgram.unuse();
	
	SDL_GL_SwapWindow(_window);
}