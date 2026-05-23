cmake_minimum_required(VERSION 3.23)
project(conan-sample-project LANGUAGES CXX)

find_package(SFML REQUIRED)
find_package(ImGui-SFML REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ImGui-SFML::ImGui-SFML
    sfml::sfml
)

# Copy assets folder next to the executable after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/assets"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
    COMMENT "Copying assets to output directory"
)
