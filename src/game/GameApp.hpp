#pragma once

namespace eom {

class Input;
class Time;

class GameApp {
public:
    void initialize();
    void update(float deltaSeconds, const Input& input, const Time& time);
    void shutdown();

private:
    float fpsLogTimer_ = 0.0f;
};

}  // namespace eom
