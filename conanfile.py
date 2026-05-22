from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps, cmake_layout


class ConanSampleProject(ConanFile):
    name = "conan-sample-project"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("sfml/2.6.1")
        self.requires("imgui/1.91.6-docking")
        self.requires("imgui-sfml/2.6")

    def layout(self):
        cmake_layout(self)
