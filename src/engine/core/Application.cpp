#include "engine/core/Application.hpp"

#include "engine/core/Log.hpp"

#include <SDL3/SDL.h>

namespace eom {

int Application::run() {
    if (!initialize()) {
        shutdown();
        return 1;
    }

    logInfo("ECHOES OF MARS — Stage 0 running (close window or press Escape)");

    while (running_) {
        processEvents();
        if (!running_) {
            break;
        }

        time_.tick();
        update();
        render();
        window_.swapBuffers();
    }

    shutdown();
    return 0;
}

bool Application::initialize() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        logError("SDL_Init failed: %s", SDL_GetError());
        return false;
    }

    WindowConfig config;
    config.title = "ECHOES OF MARS";
    config.width = 1280;
    config.height = 720;

    if (!window_.create(config)) {
        return false;
    }

    if (!graphics_.initialize()) {
        return false;
    }

    graphics_.setViewport(window_.width(), window_.height());
    time_.reset();
    game_.initialize();
    running_ = true;
    return true;
}

void Application::shutdown() {
    game_.shutdown();
    window_.destroy();
    SDL_Quit();
    logInfo("Application shutdown complete");
}

void Application::processEvents() {
    input_.beginFrame();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        input_.handleEvent(event);

        if (event.type == SDL_EVENT_WINDOW_RESIZED) {
            graphics_.setViewport(event.window.data1, event.window.data2);
        }
    }

    if (input_.quitRequested() || input_.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
        running_ = false;
    }
}

void Application::update() {
    game_.update(time_.deltaSeconds(), input_, time_);
}

void Application::render() {
    graphics_.clear(0.45f, 0.18f, 0.12f, 1.0f);
}

}  // namespace eom
