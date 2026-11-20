#include "engine/render/GraphicsContext.hpp"

#include "engine/core/Log.hpp"

#include <SDL3/SDL.h>
#include <glad/gl.h>

namespace eom {

bool GraphicsContext::initialize() {
    const int version = gladLoadGL(reinterpret_cast<GLADloadfunc>(SDL_GL_GetProcAddress));
    if (version == 0) {
        logError("Failed to load OpenGL functions with GLAD");
        return false;
    }

    logInfo("OpenGL loaded: %s", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    logInfo("GLSL: %s", reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)));
    logInfo("Renderer: %s", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
    return true;
}

void GraphicsContext::clear(float r, float g, float b, float a) const {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsContext::setViewport(int width, int height) const {
    glViewport(0, 0, width, height);
}

}  // namespace eom
