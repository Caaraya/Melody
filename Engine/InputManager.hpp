#pragma once
#include <glm/glm.hpp>
#include <unordered_map>

namespace Mengine {

// Input manager stores a key map that maps SDL_Keys to booleans.
// If the value in the key map is true, then the key is pressed.
// Otherwise, it is released.
class InputManager
{
public:
    InputManager();
    ~InputManager();

    void pressKey(unsigned int keyID);
    void releaseKey(unsigned int keyID);
	
	void setMouseCoords(float x, float y);

    bool isKeyPressed(unsigned int keyID);
	
	glm::vec2 getMouseCoords() const { return _mouseCoords; }
private:
    std::unordered_map<unsigned int, bool> _keyMap;
	glm::vec2 _mouseCoords;
};

}