#pragma once

#include <cstdint>

namespace eom {

class Time {
public:
    void reset();
    void tick();

    float deltaSeconds() const;
    double totalSeconds() const;
    float framesPerSecond() const;

private:
    std::uint64_t startNs_ = 0;
    std::uint64_t previousNs_ = 0;
    std::uint64_t currentNs_ = 0;
    float deltaSeconds_ = 0.0f;
    float fps_ = 0.0f;
    float fpsAccumulated_ = 0.0f;
    int fpsFrames_ = 0;
};

}  // namespace eom
