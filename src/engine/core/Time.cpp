#include "engine/core/Time.hpp"

#include <SDL3/SDL.h>

#include <algorithm>
#include <cstdint>

namespace eom {

void Time::reset() {
    startNs_ = SDL_GetTicksNS();
    previousNs_ = startNs_;
    currentNs_ = startNs_;
    deltaSeconds_ = 0.0f;
    fps_ = 0.0f;
    fpsAccumulated_ = 0.0f;
    fpsFrames_ = 0;
}

void Time::tick() {
    currentNs_ = SDL_GetTicksNS();
    const double delta =
        static_cast<double>(currentNs_ - previousNs_) / 1'000'000'000.0;
    previousNs_ = currentNs_;

    deltaSeconds_ = static_cast<float>(std::clamp(delta, 0.0, 0.1));

    fpsAccumulated_ += deltaSeconds_;
    ++fpsFrames_;
    if (fpsAccumulated_ >= 0.5f) {
        fps_ = static_cast<float>(fpsFrames_) / fpsAccumulated_;
        fpsAccumulated_ = 0.0f;
        fpsFrames_ = 0;
    }
}

float Time::deltaSeconds() const {
    return deltaSeconds_;
}

double Time::totalSeconds() const {
    return static_cast<double>(currentNs_ - startNs_) / 1'000'000'000.0;
}

float Time::framesPerSecond() const {
    return fps_;
}

}  // namespace eom
