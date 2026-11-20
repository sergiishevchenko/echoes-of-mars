#pragma once

#include <SDL3/SDL.h>

namespace eom {

class Input {
public:
    void beginFrame();
    void handleEvent(const SDL_Event& event);

    bool quitRequested() const;
    bool isKeyDown(int scancode) const;
    bool isKeyPressed(int scancode) const;

private:
    bool quitRequested_ = false;
    const bool* keyboardState_ = nullptr;
    int keyboardStateLength_ = 0;
    bool previousKeys_[512]{};
    bool currentKeys_[512]{};
};

}  // namespace eom
