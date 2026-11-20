#include "engine/platform/Window.hpp"

#include "engine/core/Log.hpp"

#include <SDL3/SDL.h>

namespace eom {

Window::~Window() {
    destroy();
}

bool Window::create(const WindowConfig& config) {
    destroy();

    if (!SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3) ||
        !SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3) ||
        !SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                             SDL_GL_CONTEXT_PROFILE_CORE)) {
        logError("Failed to set OpenGL attributes: %s", SDL_GetError());
        return false;
    }

#ifdef __APPLE__
    if (!SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS,
                             SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG)) {
        logError("Failed to set OpenGL forward-compatible flag: %s",
                 SDL_GetError());
        return false;
    }
#endif

    if (!SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1) ||
        !SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24)) {
        logError("Failed to set OpenGL buffer attributes: %s", SDL_GetError());
        return false;
    }

    window_ = SDL_CreateWindow(config.title.c_str(), config.width,
                               config.height,
                               SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (window_ == nullptr) {
        logError("Failed to create window: %s", SDL_GetError());
        return false;
    }

    glContext_ = SDL_GL_CreateContext(window_);
    if (glContext_ == nullptr) {
        logError("Failed to create OpenGL context: %s", SDL_GetError());
        destroy();
        return false;
    }

    if (!SDL_GL_MakeCurrent(window_, glContext_)) {
        logError("Failed to make OpenGL context current: %s", SDL_GetError());
        destroy();
        return false;
    }

    if (!SDL_GL_SetSwapInterval(1)) {
        logWarn("Failed to enable VSync: %s", SDL_GetError());
    }

    width_ = config.width;
    height_ = config.height;
    logInfo("Window created (%dx%d)", width_, height_);
    return true;
}

void Window::destroy() {
    if (glContext_ != nullptr) {
        SDL_GL_DestroyContext(glContext_);
        glContext_ = nullptr;
    }
    if (window_ != nullptr) {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
    width_ = 0;
    height_ = 0;
}

void Window::swapBuffers() {
    if (window_ != nullptr) {
        SDL_GL_SwapWindow(window_);
    }
}

void* Window::nativeHandle() const {
    return window_;
}

SDL_GLContext Window::glContext() const {
    return glContext_;
}

int Window::width() const {
    return width_;
}

int Window::height() const {
    return height_;
}

bool Window::isOpen() const {
    return window_ != nullptr && glContext_ != nullptr;
}

}  // namespace eom
