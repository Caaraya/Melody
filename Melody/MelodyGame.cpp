#include "MelodyGame.hpp"
#include <iostream>
#include <string>
#include "Errors.hpp"

MelodyGame::MelodyGame() : _maxFPS(60.0f), _screenWidth(800), _screenHeight(600), _time(0.0f)
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
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
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
	
	glClearColor(0.45f,0.6f,1.0f,1.0f);
	
	//set vsync
	SDL_GL_SetSwapInterval(1);
	
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
		float startTicks = SDL_GetTicks();
		processInput();
		_time += 0.001;
		drawGame();
		calculateFPS();
		
		//print once every 10 frames
		static int frameCounter = 0;
		frameCounter++;
		
		if(frameCounter == 10)
		{
		std::cout << _fps << std::endl;
		frameCounter = 0;
		}
		
		float frameTicks = SDL_GetTicks() -startTicks;
		// limit fps to max
		if(1000.0f/_maxFPS > frameTicks)
		{
			SDL_Delay(1000.0f/_maxFPS - frameTicks);
		}
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

void MelodyGame::calculateFPS()
{
	static const int NUM_SAMPLES = 10;
	static float frameTimes[NUM_SAMPLES];
	static int currentFrame = 0;
	
	static float prevTicks = SDL_GetTicks();
	float currentTicks; 
	currentTicks = SDL_GetTicks();
	
	_frameTime = currentTicks - prevTicks;
	frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;
	
	prevTicks = currentTicks;
	currentFrame++;
	
	int count;
	if(currentFrame < NUM_SAMPLES)
	{
		count = currentFrame;
	}
	else
	{
		count = NUM_SAMPLES;
	}
	
	float frameTimeAverage = 0;
	for (int i = 0; i < count; i++)
	{
		frameTimeAverage += frameTimes[i];
	}
	
	frameTimeAverage /= count;
	
	if (frameTimeAverage > 0)
	{
		_fps = 1000.0f / frameTimeAverage;
	}
	else
	{
		_fps = 60.0f;
	}
}