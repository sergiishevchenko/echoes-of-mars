# ECHOES OF MARS

3D action-adventure built on a custom C++ engine (SDL3 + OpenGL 3.3 Core).

## Requirements

- CMake ≥ 3.20
- C++20 compiler (Apple Clang / MSVC / GCC)
- SDL3 (on Apple Silicon via `/opt/homebrew`: `brew install sdl3`)

## Build (macOS)

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/echoes_of_mars
```

Release:

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```

On Apple Silicon, CMake prefers SDL3 from `/opt/homebrew`.

Close the window or press Escape to quit.

## Docs

- `ARCHITECTURE.md` — engine architecture
- `LEARNING_NOTES.md` — learning notes
- `external/glad/README.md` — how GLAD was generated / how to regenerate
