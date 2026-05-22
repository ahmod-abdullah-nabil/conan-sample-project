from conan import ConanFile


class ConanSampleProject(ConanFile):
    name = "conan-sample-project"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("sfml/3.0.2")
        self.requires("imgui-sfml/3.0")
