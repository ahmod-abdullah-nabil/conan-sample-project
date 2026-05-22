cmake_minimum_required(VERSION 3.21)
project(conan-sample-project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED COMPONENTS graphics window system)
find_package(imgui REQUIRED)
find_package(ImGui-SFML REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ImGui-SFML::ImGui-SFML
        sfml::sfml
        imgui::imgui
)
