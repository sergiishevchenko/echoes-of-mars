#include "game/GameApp.hpp"

#include "engine/core/Log.hpp"
#include "engine/core/Time.hpp"
#include "engine/platform/Input.hpp"

namespace eom {

void GameApp::initialize() {
    logInfo("GameApp ready (Stage 0 shell)");
}

void GameApp::update(float deltaSeconds, const Input& input, const Time& time) {
    (void)input;

    fpsLogTimer_ += deltaSeconds;
    if (fpsLogTimer_ >= 1.0f) {
        logInfo("dt=%.4f s | fps=%.1f | time=%.1f s", deltaSeconds,
                time.framesPerSecond(), time.totalSeconds());
        fpsLogTimer_ = 0.0f;
    }
}

void GameApp::shutdown() {
    logInfo("GameApp shutdown");
}

}  // namespace eom
