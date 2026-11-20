#pragma once

#include <string>

struct SDL_Window;
typedef struct SDL_GLContextState* SDL_GLContext;

namespace eom {

struct WindowConfig {
    std::string title = "ECHOES OF MARS";
    int width = 1280;
    int height = 720;
};

class Window {
public:
    Window() = default;
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    bool create(const WindowConfig& config);
    void destroy();

    void swapBuffers();
    void* nativeHandle() const;
    SDL_GLContext glContext() const;
    int width() const;
    int height() const;
    bool isOpen() const;

private:
    SDL_Window* window_ = nullptr;
    SDL_GLContext glContext_ = nullptr;
    int width_ = 0;
    int height_ = 0;
};

}  // namespace eom
