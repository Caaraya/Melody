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
	
	void update();

    void pressKey(unsigned int keyID);
    void releaseKey(unsigned int keyID);
	
	void setMouseCoords(float x, float y);
	
	// returns true if key is held down
    bool isKeyDown(unsigned int keyID);
	
	// returns true is key is pressed in that frame
    bool isKeyPressed(unsigned int keyID);
	
	glm::vec2 getMouseCoords() const { return _mouseCoords; }
private:
    // returns true if key was held down
    bool wasKeyDown(unsigned int keyID);
	
    std::unordered_map<unsigned int, bool> _keyMap;
	std::unordered_map<unsigned int, bool> _previousKeyMap;
	glm::vec2 _mouseCoords;
};

}