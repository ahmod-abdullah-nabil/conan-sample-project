# conan-sample-project

A project template using **Conan 2 + CMake + SFML + Dear ImGui + ImGui-SFML**.

## Prerequisites

- [Conan 2](https://conan.io/) (`pip install conan`)
- CMake 3.21+
- A C++17 compiler (MSVC, GCC, Clang)

## Build Instructions

```bash
# Install dependencies and generate CMake toolchain
conan install . --output-folder=build --build=missing

# Configure
cmake --preset conan-default
# Or manually:
# cmake -B build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake

# Build
cmake --build --preset conan-release
# Or manually:
# cmake --build build --config Release
```

## Project Structure

```
.
├── CMakeLists.txt        # CMake build configuration
├── conanfile.py          # Conan package manager recipe
├── include/              # Project headers
├── src/
│   └── main.cpp          # Application entry point
└── README.md
```
