#pragma once

#include "engine/core/Time.hpp"
#include "engine/platform/Input.hpp"
#include "engine/platform/Window.hpp"
#include "engine/render/GraphicsContext.hpp"
#include "game/GameApp.hpp"

namespace eom {

class Application {
public:
    int run();

private:
    bool initialize();
    void shutdown();
    void processEvents();
    void update();
    void render();

    Window window_;
    Input input_;
    Time time_;
    GraphicsContext graphics_;
    GameApp game_;
    bool running_ = false;
};

}  // namespace eom
