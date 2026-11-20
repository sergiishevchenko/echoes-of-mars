#pragma once

namespace eom {

class GraphicsContext {
public:
    bool initialize();
    void clear(float r, float g, float b, float a) const;
    void setViewport(int width, int height) const;
};

}  // namespace eom
