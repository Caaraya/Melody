#pragma once

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

    bool isKeyPressed(unsigned int keyID);
private:
    std::unordered_map<unsigned int, bool> _keyMap;
};

}