#include "engine/platform/Input.hpp"

#include <SDL3/SDL.h>

#include <algorithm>
#include <cstring>

namespace eom {

void Input::beginFrame() {
    std::memcpy(previousKeys_, currentKeys_, sizeof(currentKeys_));

    keyboardState_ = SDL_GetKeyboardState(&keyboardStateLength_);
    const int count =
        std::min(keyboardStateLength_, static_cast<int>(sizeof(currentKeys_)));
    for (int i = 0; i < count; ++i) {
        currentKeys_[i] = keyboardState_ != nullptr && keyboardState_[i];
    }
    for (int i = count; i < static_cast<int>(sizeof(currentKeys_)); ++i) {
        currentKeys_[i] = false;
    }
}

void Input::handleEvent(const SDL_Event& event) {
    if (event.type == SDL_EVENT_QUIT) {
        quitRequested_ = true;
    }
}

bool Input::quitRequested() const {
    return quitRequested_;
}

bool Input::isKeyDown(int scancode) const {
    if (scancode < 0 || scancode >= static_cast<int>(sizeof(currentKeys_))) {
        return false;
    }
    return currentKeys_[scancode];
}

bool Input::isKeyPressed(int scancode) const {
    if (scancode < 0 || scancode >= static_cast<int>(sizeof(currentKeys_))) {
        return false;
    }
    return currentKeys_[scancode] && !previousKeys_[scancode];
}

}  // namespace eom
