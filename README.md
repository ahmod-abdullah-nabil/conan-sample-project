# Conan + CMake + SFML 3 + ImGui (Docking) + ImGui-SFML

A C++ project template using Conan 2 for dependency management. Works in both **VS Code** (GCC/MinGW) and **Visual Studio** (MSVC).

## Dependencies

| Library | Version | Notes |
|---------|---------|-------|
| SFML | 3.0.2 | Graphics, window, audio, network |
| ImGui | 1.91.8-docking | Docking branch (dockable windows, viewports) |
| ImGui-SFML | 3.0 | ImGui backend for SFML 3 |

## Prerequisites

- [Conan 2](https://conan.io/) — `pip install conan`
- [CMake 3.23+](https://cmake.org/)
- A C++20 compiler:
  - **Windows (VS Code):** GCC via [MSYS2](https://www.msys2.org/) (ucrt64)
  - **Windows (Visual Studio):** MSVC (comes with Visual Studio)

## Setup

### First time only: create a MinGW Conan profile

If you want to use GCC in VS Code, create a profile at `~/.conan2/profiles/mingw`:

```ini
[settings]
arch=x86_64
build_type=Release
compiler=gcc
compiler.cppstd=20
compiler.libcxx=libstdc++11
compiler.version=15
os=Windows

[conf]
tools.cmake.cmaketoolchain:generator=MinGW Makefiles
```

Adjust `compiler.version` to match your GCC version (`g++ --version`).

### Install dependencies

```bash
# For VS Code (GCC/MinGW)
conan install . --build=missing --profile=mingw -s build_type=Debug

# For Visual Studio (MSVC)
conan install . --build=missing -s build_type=Debug
conan install . --build=missing -s build_type=Release
```

Run whichever ones you need. You can run all three if you use both IDEs.

## Building

### VS Code

1. Open the project folder
2. Ctrl+Shift+P → **"CMake: Select Configure Preset"** → pick `conan-debug`
3. F7 to build

### Visual Studio

1. File → Open → CMake → select `CMakeLists.txt`
2. Select `conan-default` from the configuration dropdown in the toolbar
3. Ctrl+B to build

### Command Line

```bash
# GCC
cmake --preset conan-debug
cmake --build build/Debug

# MSVC
cmake --preset conan-default
cmake --build build --config Debug
```

## Project Structure

```
.
├── CMakeLists.txt            # Build configuration
├── conanfile.py              # Conan dependencies
├── .vscode/settings.json     # VS Code uses CMake presets
├── .gitignore                # Ignores build/ and CMakeUserPresets.json
├── assets/                   # Runtime assets (auto-copied next to exe)
│   └── fonts/
│       └── arial.ttf         # Put your font here
├── include/                  # Project headers
├── src/
│   └── main.cpp              # Entry point
└── README.md
```

## How It Works

- `conan install` downloads/builds dependencies and generates CMake presets
- Each preset carries the correct compiler, generator, and library paths
- `CMakeUserPresets.json` (gitignored) links to the generated presets
- The `assets/` folder is automatically copied next to the executable on every build

## Adding New Source Files

Add them to `CMakeLists.txt`:

```cmake
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game.cpp
    src/player.cpp
)
```

## Adding New Dependencies

1. Find the package on [Conan Center](https://conan.io/center)
2. Add it to `conanfile.py`:
   ```python
   self.requires("package/version")
   ```
3. Add `find_package()` and `target_link_libraries()` in `CMakeLists.txt`
4. Re-run `conan install`

## Notes

- The `build/` folder and `CMakeUserPresets.json` are gitignored — each developer generates their own by running `conan install`
- You cannot mix compilers: GCC-built libraries won't link with MSVC and vice versa. That's why separate presets exist.
- If presets disappear in VS Code, just re-run `conan install`
