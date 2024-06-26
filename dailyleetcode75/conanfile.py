from conan import ConanFile

class MoxPPRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "PremakeDeps"

    def requirements(self):
        self.requires("nlohmann_json/3.11.2")

    def configure(self):
        # This only works on windows (we added this so that you can see
        # how to change settings of packages)
        # self.options["spdlog"].wchar_support = True
        pass
