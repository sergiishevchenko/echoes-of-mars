#include "engine/core/Application.hpp"
#include "engine/core/Log.hpp"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    eom::logInfo("Starting ECHOES OF MARS");
    eom::Application app;
    return app.run();
}
