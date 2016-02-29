#include "Errors.hpp"
#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>

void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	std::cin.get();
	SDL_Quit();
	exit(1);
}