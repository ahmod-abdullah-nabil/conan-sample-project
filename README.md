# Conan + CMake + SFML 3 + ImGui + ImGui-SFML Template

A portable project template that works with **any compiler** (GCC, MSVC, Clang) in both **VS Code** and **Visual Studio**.

## Prerequisites

- [Conan 2](https://conan.io/) (`pip install conan`)
- CMake 3.23+
- A C++20 compiler (MSVC, GCC, Clang)

## Setup

Install dependencies for your compiler. Run one or both:

```bash
# For MSVC (Visual Studio default)
conan install . --build=missing -s build_type=Debug
conan install . --build=missing -s build_type=Release

# For GCC/MinGW
conan install . --build=missing --profile=mingw -s build_type=Debug
conan install . --build=missing --profile=mingw -s build_type=Release
```

## Build

### VS Code
1. Open the folder
2. Select a configure preset (Ctrl+Shift+P → "CMake: Select Configure Preset")
3. Build (Ctrl+Shift+B or F7)

### Visual Studio
1. File → Open → CMake → select CMakeLists.txt
2. Select a configure preset from the toolbar dropdown
3. Build (Ctrl+B)

### Command Line
```bash
cmake --preset conan-default
cmake --build --preset conan-release
```

## Project Structure

```
.
├── CMakeLists.txt          # Build configuration
├── conanfile.py            # Conan dependencies
├── assets/                 # Runtime assets (copied to output)
│   └── fonts/
├── include/                # Project headers
├── src/
│   └── main.cpp            # Entry point
├── .vscode/settings.json   # VS Code CMake preset config
└── README.md
```

## Adding Dependencies

Edit `conanfile.py` and add to `requirements()`, then re-run `conan install`.
